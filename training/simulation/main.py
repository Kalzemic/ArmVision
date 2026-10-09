import omni.replicator.core as rep
import cv2
import numpy as np
import asyncio
from local import sim_path
from capture import StereoCapture
from target_object import TargetObject
from triangulator import Triangulator
async def main():
    capture = StereoCapture(
        # "/armvision/Geometry/world/base_link/base_plate/rgb_camera/left_camera/Camera",
        # "/armvision/Geometry/world/base_link/base_plate/rgb_camera/right_camera/Camera"
        '/Root/CameraRig/LeftCamera',
        '/Root/CameraRig/RightCamera'
    )

    target = TargetObject('/Root/TargetObject')

    triangulator = Triangulator()
    await rep.orchestrator.step_async()

    left_image, right_image, depth_gt = capture()

    rgbd = triangulator(left_image=left_image, right_image=right_image, capture=capture)

    depth = rgbd[:, :, 3]
    # Near = bright, far = dark, invalid = black
    heatmap = np.zeros(depth.shape, dtype=np.uint8)

    # Near = bright, far = dark
    heatmap = np.zeros(depth.shape, dtype=np.uint8)

    min_depth = depth.min()
    max_depth = depth.max()

    normalized = (depth - min_depth) / (max_depth - min_depth + 1e-8)

    heatmap = ((1.0 - normalized) * 255).astype(np.uint8)



    # print("baseline:", capture.baseline)
    # print("fx:", fx)
    # print("fy:", fy)
    # print("valid disparity pixels:", np.count_nonzero(valid))

    # if np.any(valid):
    #     print("disparity range:", disparity[valid].min(), disparity[valid].max())
    #     print("depth range:", depth[valid].min(), depth[valid].max())


    print(f'Target Object Coordinates: {target.pos}')
    print(f'Camera Coordinates: {capture.pos}')

    gt_depth = abs(target[0] - capture.pos[0])
    
    h, w = depth.shape
    # region = depth[h//2-5:h//2+5, w//2-5:w//2+5]
    # center_depth = np.nanmedian(region)
    center_depth = depth[h // 2, w // 2]
    # h, w = disparity.shape
    # cx, cy = w // 2, h // 2

    # region = disparity[cy-30:cy+30, cx-30:cx+30]

    # print("Center disparity:", disparity[cy, cx])
    # print("Region disparity range:", np.min(region), np.max(region))
    # print("Region median:", np.median(region))

    print(f'ground truth depth: {gt_depth}')
    print(f'triangualted depth: {center_depth}')
    # print("Center disparity:", disparity[cy, cx])
    # print("Center depth:", depth[cy, cx])
    # print("Valid pixels:", np.count_nonzero(valid))    



    output_dir = sim_path

    cv2.imwrite(f"{output_dir}/left.png", cv2.cvtColor(left_image, cv2.COLOR_RGB2BGR))
    cv2.imwrite(f"{output_dir}/right.png", cv2.cvtColor(right_image, cv2.COLOR_RGB2BGR))
    cv2.imwrite(f"{output_dir}/depth.png", heatmap)


asyncio.ensure_future(main())