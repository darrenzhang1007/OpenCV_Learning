import cv2 as cv
import numpy as np

src = cv.imread("H:\\OpenCV_Learning\\test.jpg")
cv.namedWindow("input", cv.WINDOW_AUTOSIZE)
cv.imshow("input", src)

# X-Flip
dst_x = cv.flip(src, 0)
cv.imshow("x-flip", dst_x)

# Y-Flip
dst_y = cv.flip(src, 1)
cv.imshow("y-filp", dst_y)

# xy-Flip
dst_xy = cv.flip(src, -1)
cv.imshow("xy-filp", dst_xy)

# custom y-Flip
h, w, ch = src.shape
dst = np.zeros(src.shape, src.dtype)
for row in range(h):
    for col in range(w):
        b, g, r = src[row, col]
        dst[row, w-col-1] = [b, g, r]
cv.imshow("Custom-Y-Flip", dst)

cv.waitKey(0)
cv.destroyAllWindows()