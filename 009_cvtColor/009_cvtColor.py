import cv2 as cv

src = cv.imread("H:\\OpenCV_Learning\\009_cvtColor\\green.jpg")
cv.namedWindow("BGR", cv.WINDOW_AUTOSIZE)
cv.imshow("BGR", src)

# BGR to HSV
hsv_result = cv.cvtColor(src, cv.COLOR_BGR2HSV)
cv.imshow("hsv_result", hsv_result)

# BGR to YUV
yuv_result = cv.cvtColor(src, cv.COLOR_BGR2YUV)
cv.imshow("yuv_result", yuv_result)

# BGR to YCrCB
ycrcb_result = cv.cvtColor(src, cv.COLOR_BGR2YCrCb)
cv.imshow("ycrcb_result", ycrcb_result)

# inRange
mask = cv.inRange(hsv_result, (35, 43, 46), (77, 255, 255))  # 将绿色保存
cv.imshow("mask", mask)
dst = cv.bitwise_and(src, src, mask=mask)
cv.imshow("dst", dst)

cv.waitKey(0)
cv.destroyAllWindows()