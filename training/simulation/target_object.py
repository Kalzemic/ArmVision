import omni.usd
from pxr import Usd, UsdGeom



class TargetObject:
    def __init__(self, target_path):

        stage = omni.usd.get_context().get_stage()
        print("Context:", omni.usd.get_context())
        print("Stage:", stage)
        print("Stage type:", type(stage))
        print("get_stage:", omni.usd.get_context().get_stage)
        self.prim = stage.GetPrimAtPath(target_path)
        if not self.prim.IsValid():
            raise ValueError(f"Invalid target path: {target_path}")
        
        cache = UsdGeom.XformCache(Usd.TimeCode.Default())

    
        self.pos = cache.GetLocalToWorldTransform(self.prim).ExtractTranslation()

    def __getitem__(self, key):
        return self.pos[key]