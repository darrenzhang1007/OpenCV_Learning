import cv2 as cv

src = cv.imread("../test.jpg")
cv.namedWindow("input", cv.WINDOW_AUTOSIZE)
cv.imshow("input", src)

gray = cv.cvtColor(src, cv.COLOR_BGR2GRAY)
cv.imshow("gray", gray)
cv.imwrite("gray_py.png", gray)
cv.waitKey(0)
cv.destroyAllWindows()