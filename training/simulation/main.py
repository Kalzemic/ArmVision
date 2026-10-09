import omni.replicator.core as rep
import cv2
import numpy as np
import asyncio
from local import sim_path
from capture import StereoCapture


async def main():
    capture = StereoCapture(
        # "/armvision/Geometry/world/base_link/base_plate/rgb_camera/left_camera/Camera",
        # "/armvision/Geometry/world/base_link/base_plate/rgb_camera/right_camera/Camera"
        '/Root/CameraRig/RightCamera',
        '/Root/CameraRig/LeftCamera'
    )

    stereo = cv2.StereoSGBM_create(
        minDisparity=0,
        numDisparities=128,
        blockSize=5,
        P1=8 * 5 * 5,
        P2=32 * 5 * 5,
        disp12MaxDiff=-1,
        uniquenessRatio=0,
        speckleWindowSize=0,
        speckleRange=0,
        preFilterCap=63,
        mode=cv2.STEREO_SGBM_MODE_SGBM_3WAY
    )

    await rep.orchestrator.step_async()

    left_image, right_image, depth_gt = capture()

    left_gray = cv2.cvtColor(left_image, cv2.COLOR_RGB2GRAY)
    right_gray = cv2.cvtColor(right_image, cv2.COLOR_RGB2GRAY)
    # left_gray = cv2.rotate(left_gray, cv2.ROTATE_90_COUNTERCLOCKWISE)
    # right_gray = cv2.rotate(right_gray, cv2.ROTATE_90_COUNTERCLOCKWISE)
    disparity = stereo.compute(left_gray, right_gray).astype(np.float32) / 16.0

    valid = disparity > 0.0

    # disparity_filtered = disparity.copy()
    # disparity_filtered[~valid] = 0.0
    # disparity_filtered = cv2.medianBlur(disparity_filtered, 5)

    # valid = disparity_filtered > 1.0

    fx, fy = capture.focal_length

    depth = np.full(disparity.shape, np.nan, dtype=np.float32)

    if np.any(valid):
        depth[valid] = (fx * capture.baseline) / disparity[valid]

    # Near = bright, far = dark, invalid = black
    heatmap = np.zeros(depth.shape, dtype=np.uint8)

    if np.any(valid):
        min_depth = depth[valid].min()
        max_depth = depth[valid].max()

        normalized = (depth[valid] - min_depth) / (max_depth - min_depth + 1e-8)

        heatmap[valid] = ((1.0 - normalized) * 255).astype(np.uint8)

    # Disparity visualization
    disp_vis = np.zeros_like(disparity, dtype=np.uint8)

    if np.any(valid):
        dmin = disparity[valid].min()
        dmax = disparity[valid].max()

        disp_vis[valid] = (
            (disparity[valid] - dmin) /
            (dmax - dmin + 1e-8) * 255
        ).astype(np.uint8)

    print("baseline:", capture.baseline)
    print("fx:", fx)
    print("fy:", fy)
    print("valid disparity pixels:", np.count_nonzero(valid))

    if np.any(valid):
        print("disparity range:", disparity[valid].min(), disparity[valid].max())
        print("depth range:", depth[valid].min(), depth[valid].max())

    output_dir = sim_path

    cv2.imwrite(f"{output_dir}/left.png", cv2.cvtColor(left_image, cv2.COLOR_RGB2BGR))
    cv2.imwrite(f"{output_dir}/right.png", cv2.cvtColor(right_image, cv2.COLOR_RGB2BGR))
    cv2.imwrite(f"{output_dir}/disparity.png", disp_vis)
    cv2.imwrite(f"{output_dir}/depth.png", heatmap)


asyncio.ensure_future(main())