import numpy as np
import pinocchio as pin
from ament_index_python import get_package_share_directory
import os

model = pin.buildModelFromUrdf(os.path.join(get_package_share_directory('armvision_description'),'urdf',"armvision.urdf"))
data = model.createData()
ee = model.getFrameId("end_effector")

lo, hi = model.lowerPositionLimit, model.upperPositionLimit
rng = np.random.default_rng(0)

for _ in range(5):
    q = rng.uniform(lo, hi)
    pin.framesForwardKinematics(model, data, q)
    M = data.oMf[ee]
    p = M.translation
    quat = pin.Quaternion(M.rotation)  # x, y, z, w
    print(f"q={np.round(q, 3)}  pos=({p[0]:.4f}, {p[1]:.4f}, {p[2]:.4f})  "
          f"quat=({quat.x:.4f}, {quat.y:.4f}, {quat.z:.4f}, {quat.w:.4f})")