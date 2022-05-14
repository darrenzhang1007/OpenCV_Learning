import cv2 as cv
import numpy as np
from matplotlib import pyplot as plt


src = cv.imread("H:\\OpenCV_Learning\\test.jpg")
gray = cv.cvtColor(src, cv.COLOR_BGR2GRAY)
cv.namedWindow("input", cv.WINDOW_AUTOSIZE)
cv.imshow("input", gray)
dst = cv.equalizeHist(gray)
cv.imshow("eq", dst)
cv.waitKey(0)
cv.destroyAllWindows()