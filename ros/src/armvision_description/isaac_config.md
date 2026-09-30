ArmVision — Isaac Sim side configuration
=========================================

Architecture
------------
ros2_control (ROS side)                         Isaac Sim (stage side)
  robo_controller  -- effort -->  TopicBasedSystem  -- /isaac_joint_command -->  SubscribeJointState -> ArticulationController
  (computed torque)               (hardware plugin) <-- /isaac_joint_states ---  ReadJointState -> PublishJointState
                                                    <-- /clock ----------------  PublishClock

Isaac Sim has no native ros2_control plugin. The TopicBasedSystem plugin bridges
over topics. Isaac IGNORES the <ros2_control> block in the URDF, and the URDF
importer does NOT create any Action Graph. Re-importing the URDF means redoing
everything below.


1. Topic names (must match by hand on both sides)
-------------------------------------------------
  Commands : /isaac_joint_command   (xacro: joint_commands_topic  <-> Isaac: SubscribeJointState.topicName)
  States   : /isaac_joint_states    (xacro: joint_states_topic    <-> Isaac: PublishJointState.topicName)
  Clock    : /clock                 (ROS2PublishClock default)

  ROS side lives in urdf/armvision_ros2_control.xacro, which also sets
  trigger_joint_command_threshold = -1 (always publish; required for effort-only
  command interfaces).


2. Action Graph: /Graph/ROS_Control
-----------------------------------
Single graph, pipeline stage OnDemand, evaluator "execution".
EVERYTHING is triggered by OnPhysicsStep, NOT OnPlaybackTick.
  (With OnPlaybackTick the clock ticks once per rendered frame (~16 Hz here),
   the controller runs at that rate, and the arm flails.)

  Nodes:
    OnPhysicsStep           isaacsim.core.nodes.OnPhysicsStep
    Context                 isaacsim.ros2.bridge.ROS2Context
    ReadSimTime             isaacsim.core.nodes.IsaacReadSimulationTime
    PublishClock            isaacsim.ros2.bridge.ROS2PublishClock
    ReadJointState          isaacsim.sensors.physics.IsaacReadJointState      (prim -> articulation root)
    PublishJointState       isaacsim.ros2.bridge.ROS2PublishJointState        (topic /isaac_joint_states)
    SubscribeJointState     isaacsim.ros2.bridge.ROS2SubscribeJointState      (topic /isaac_joint_command)
    ArticulationController  isaacsim.core.nodes.IsaacArticulationController   (targetPrim -> articulation root)

  Script Editor script to (re)build it:

    import omni.usd, omni.graph.core as og
    from pxr import UsdPhysics

    stage = omni.usd.get_context().get_stage()
    roots = [p.GetPath() for p in stage.Traverse() if p.HasAPI(UsdPhysics.ArticulationRootAPI)]
    assert len(roots) == 1, f"expected 1 articulation root, found {roots}"
    ROOT = roots[0]

    G = "/Graph/ROS_Control"
    if stage.GetPrimAtPath(G):
        stage.RemovePrim(G)

    K = og.Controller.Keys
    og.Controller.edit(
        {"graph_path": G, "evaluator_name": "execution",
         "pipeline_stage": og.GraphPipelineStage.GRAPH_PIPELINE_STAGE_ONDEMAND},
        {
            K.CREATE_NODES: [
                ("OnPhysicsStep",          "isaacsim.core.nodes.OnPhysicsStep"),
                ("Context",                "isaacsim.ros2.bridge.ROS2Context"),
                ("ReadSimTime",            "isaacsim.core.nodes.IsaacReadSimulationTime"),
                ("PublishClock",           "isaacsim.ros2.bridge.ROS2PublishClock"),
                ("ReadJointState",         "isaacsim.sensors.physics.IsaacReadJointState"),
                ("PublishJointState",      "isaacsim.ros2.bridge.ROS2PublishJointState"),
                ("SubscribeJointState",    "isaacsim.ros2.bridge.ROS2SubscribeJointState"),
                ("ArticulationController", "isaacsim.core.nodes.IsaacArticulationController"),
            ],
            K.CONNECT: [
                ("OnPhysicsStep.outputs:step",         "PublishClock.inputs:execIn"),
                ("Context.outputs:context",            "PublishClock.inputs:context"),
                ("ReadSimTime.outputs:simulationTime", "PublishClock.inputs:timeStamp"),

                ("OnPhysicsStep.outputs:step",         "ReadJointState.inputs:execIn"),
                ("ReadJointState.outputs:execOut",     "PublishJointState.inputs:execIn"),
                ("Context.outputs:context",            "PublishJointState.inputs:context"),
                ("ReadSimTime.outputs:simulationTime", "PublishJointState.inputs:timeStamp"),
                ("ReadJointState.outputs:jointNames",         "PublishJointState.inputs:jointNames"),
                ("ReadJointState.outputs:jointPositions",     "PublishJointState.inputs:jointPositions"),
                ("ReadJointState.outputs:jointVelocities",    "PublishJointState.inputs:jointVelocities"),
                ("ReadJointState.outputs:jointEfforts",       "PublishJointState.inputs:jointEfforts"),
                ("ReadJointState.outputs:jointDofTypes",      "PublishJointState.inputs:jointDofTypes"),
                ("ReadJointState.outputs:stageMetersPerUnit", "PublishJointState.inputs:stageMetersPerUnit"),
                ("ReadJointState.outputs:sensorTime",         "PublishJointState.inputs:sensorTime"),

                ("OnPhysicsStep.outputs:step",         "SubscribeJointState.inputs:execIn"),
                ("Context.outputs:context",            "SubscribeJointState.inputs:context"),
                ("OnPhysicsStep.outputs:step",         "ArticulationController.inputs:execIn"),
                ("SubscribeJointState.outputs:jointNames",      "ArticulationController.inputs:jointNames"),
                ("SubscribeJointState.outputs:effortCommand",   "ArticulationController.inputs:effortCommand"),
                ("SubscribeJointState.outputs:positionCommand", "ArticulationController.inputs:positionCommand"),
                ("SubscribeJointState.outputs:velocityCommand", "ArticulationController.inputs:velocityCommand"),
            ],
            K.SET_VALUES: [
                ("PublishJointState.inputs:topicName",   "/isaac_joint_states"),
                ("SubscribeJointState.inputs:topicName", "/isaac_joint_command"),
            ],
        },
    )

    for node, rel in (("ReadJointState", "inputs:prim"), ("ArticulationController", "inputs:targetPrim")):
        stage.GetPrimAtPath(f"{G}/{node}").CreateRelationship(rel).SetTargets([ROOT])

  What the script does:
    1. Finds the articulation root: the prim with ArticulationRootAPI. Aborts
       unless there is exactly one; that path is used as the robot target.
    2. Deletes an existing /Graph/ROS_Control first, so rerunning is safe.
    3. Creates the graph as OnDemand + "execution" (what OnPhysicsStep needs).
    4. Shared helpers:
         - ROS2Context: the ROS 2 connection, wired into PublishClock,
           PublishJointState and SubscribeJointState.
         - IsaacReadSimulationTime: sim-time stamp for /clock and /isaac_joint_states.
    5. State out: IsaacReadJointState reads names, positions, velocities, efforts,
       DOF types, meters-per-unit and sensor time from the articulation and feeds
       all of them into ROS2PublishJointState on /isaac_joint_states.
    6. Commands in: ROS2SubscribeJointState on /isaac_joint_command; its joint
       names and effort/position/velocity outputs go into
       IsaacArticulationController. Only efforts are sent; the position and
       velocity arrays arrive empty and are ignored.
    7. ReadJointState.inputs:prim and ArticulationController.inputs:targetPrim
       both target the articulation root from step 1.
    8. OnPhysicsStep triggers PublishClock, ReadJointState (-> PublishJointState),
       SubscribeJointState and ArticulationController: one physics step = one
       /clock tick = one state publish = one command applied.

  It does NOT touch joint drives, physics rate, the physics variant, or anything
  on the ROS side.


3. Physics rate
---------------
PhysicsScene -> Physx Scene -> Time Steps Per Second  (default 60 Hz).
This IS the control rate: one physics step = one /clock tick = one controller update.

    import omni.usd
    from pxr import UsdPhysics, PhysxSchema
    stage = omni.usd.get_context().get_stage()
    RATE = 500
    for s in (p for p in stage.Traverse() if p.IsA(UsdPhysics.Scene)):
        PhysxSchema.PhysxSceneAPI.Apply(s).CreateTimeStepsPerSecondAttr().Set(RATE)

  If no PhysicsScene prim exists: Create -> Physics -> Physics Scene, then rerun.

  Matching ROS settings (both must be >= physics rate):
    robo_controller/config/robo_controller.yaml   update_rate: 1000   (INTEGER — 1000.0 crashes the CM)
    armvision_description/launch/isaac.launch.py  freq = 1000.0       (trajectory sampling)


4. Joint drives (checklist — verify after every import)
-------------------------------------------------------
  - joint_1..3 drive stiffness = 0 and damping = 0 (effort control; nonzero gains
    make Isaac's PD fight robo_controller). The URDF importer may set gains.
  - drive maxForce high enough for gravity torques (previous import: 30 Nm, from
    URDF <limit effort>). Isaac silently clips above it.
  - armvision prim "Physics" variant is not "none".

  Dump script:

    import omni.usd
    from pxr import UsdPhysics
    stage = omni.usd.get_context().get_stage()
    for p in stage.Traverse():
        if p.IsA(UsdPhysics.RevoluteJoint):
            d = UsdPhysics.DriveAPI.Get(p, "angular")
            g = lambda a: a.Get() if a and a.HasAuthoredValue() else "unset(0)"
            print(p.GetName(), "stiffness", g(d.GetStiffnessAttr()), "damping", g(d.GetDampingAttr()),
                  "maxForce", g(d.GetMaxForceAttr()))


5. Run order
------------
  1. Isaac: open saved stage, press Play   (/clock must exist first)
  2. ros2 launch armvision_description isaac.launch.py

  Humble controller_manager (2.54.x) with use_sim_time sleeps on the ROS clock.
  Without /clock its loop never runs: load_controller hangs, spawners time out
  after 10 s and robo_controller is left loaded but inactive.


6. Sanity checks
----------------
  ros2 topic hz /clock                        # ~= physics rate x real-time factor
  ros2 topic hz /isaac_joint_command          # same as /clock
  ros2 topic info /isaac_joint_command -v     # 1 publisher (ros2_control) + 1 subscriber (Isaac)
  ros2 control list_controllers               # robo_controller + joint_state_broadcaster active
  ros2 topic echo /joint_states --once        # arm holding still


7. Save the stage
-----------------
The graph and physics settings exist ONLY in the Isaac stage. Save it (File ->
Save As) outside urdf/armvision_1/ — the URDF importer and colcon build both
overwrite that directory.
