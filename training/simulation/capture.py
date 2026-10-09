import omni.replicator.core as rep 
import omni.usd
from pxr import Usd, UsdGeom

class StereoCapture:
    def __init__(self, left_path, right_path, resolution=(640,480)):

        # capture setup
        self.resolution = resolution
        left_product = rep.create.render_product(left_path, resolution)
        right_product  = rep.create.render_product(right_path, resolution)

        self.left_rgb = rep.AnnotatorRegistry.get_annotator('rgb')
        self.right_rgb = rep.AnnotatorRegistry.get_annotator('rgb')

        self.left_rgb.attach([left_product])
        self.right_rgb.attach([right_product])

        self.render_products = (left_product, right_product)



        # focal length
        W, H = resolution
        stage = omni.usd.get_context().get_stage()

        camera = UsdGeom.Camera.Get(stage, left_path)

        focal_length = camera.GetFocalLengthAttr().Get()

        horizontal_aperture = camera.GetHorizontalApertureAttr().Get()
        vertical_aperture = camera.GetVerticalApertureAttr().Get()

        self.focal_length = (focal_length / horizontal_aperture * W, focal_length / vertical_aperture * H)


        # baseline distance
        left_camera_prim = stage.GetPrimAtPath(left_path)
        right_camera_prim = stage.GetPrimAtPath(right_path)

        cache = UsdGeom.XformCache(Usd.TimeCode.Default())

        left_position = cache.GetLocalToWorldTransform(left_camera_prim).ExtractTranslation()
        right_position = cache.GetLocalToWorldTransform(right_camera_prim).ExtractTranslation()

        self.baseline = (right_position - left_position).GetLength()

        #depth product
        self.depth_gt = rep.AnnotatorRegistry.get_annotator("distance_to_camera")
        self.depth_gt.attach([left_product])


    def __call__(self):
        

        left = self.left_rgb.get_data()
        right = self.right_rgb.get_data()
        depth_gt = self.depth_gt.get_data()
        return left[:, :, :3].copy(), right[:, :, :3].copy(), depth_gt.copy()




