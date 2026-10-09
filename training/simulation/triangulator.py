import cv2 
import numpy as np
from capture import StereoCapture

class Triangulator:
    def __init__(self):
        
        self.stereo = cv2.StereoSGBM_create(
            minDisparity=0,
            numDisparities=128,
            blockSize=7,
            P1=8 * 1 * 7**2,
            P2=32 * 1 * 7**2,
            disp12MaxDiff=1,
            uniquenessRatio=10,
            speckleWindowSize=100,
            speckleRange=2,
            preFilterCap=31,
            mode=cv2.STEREO_SGBM_MODE_SGBM_3WAY
        )

    def __call__(self, left_image, right_image, capture: StereoCapture):
        
        left_gray = cv2.cvtColor(left_image, cv2.COLOR_RGB2GRAY)
        right_gray = cv2.cvtColor(right_image, cv2.COLOR_RGB2GRAY)

        disparity = self.stereo.compute(left_gray, right_gray).astype(np.float32) / 16.0

        
        fx, _ = capture.focal_length

        depth = np.full(disparity.shape, np.nan, dtype=np.float32)
        valid = disparity > 0.0
        if np.any(valid):
            depth[valid] = (fx * capture.baseline) / disparity[valid]

        mask = np.isnan(depth).astype(np.uint8) * 255
        depth[np.isnan(depth)] = 0.0
        depth = cv2.inpaint(depth, mask, inpaintRadius=3, flags=cv2.INPAINT_TELEA)

        depth = depth[:, :, np.newaxis]

        rgbd = np.concatenate((left_image, depth), axis=2)

        return rgbd