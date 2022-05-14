import cv2 as cv

src = cv.imread("../test.jpg")
cv.namedWindow("input", cv.WINDOW_AUTOSIZE)
cv.imshow("input", src)
dst = cv.applyColorMap(src, cv.COLORMAP_COOL)
cv.imshow("output", dst)

color_image = cv.applyColorMap(src, cv.COLORMAP_JET)
cv.imshow("color_image", color_image)

cv.waitKey(0)
cv.destroyAllWindows()