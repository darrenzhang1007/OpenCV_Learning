import cv2 as cv
import numpy as np

src = cv.imread("H:\\OpenCV_Learning\\test.jpg", cv.IMREAD_GRAYSCALE)
cv.namedWindow("input", cv.WINDOW_AUTOSIZE)
cv.imshow("input", src)

min, max, minLoc, maxLoc = cv.minMaxLoc(src)
print("min:%.2f, max: %.2f" %(min, max))
print("min Loc:", minLoc)
print("max Loc:", maxLoc)

means, stddev = cv.meanStdDev(src)
print("mean: %.2f, stddev: %.2f" %(means, stddev))
src[np.where(src < means)] = 0
src[np.where(src > means)] = 255
cv.imshow("binary", src)

cv.waitKey(0)
cv.destroyAllWindows()