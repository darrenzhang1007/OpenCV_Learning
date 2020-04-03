import cv2
import numpy as np

image = cv2.imread("H:\\OpenCV_Learning\\test.jpg")
cv2.namedWindow("input", cv2.WINDOW_AUTOSIZE)
cv2.imshow("input", image)

h, w = image.shape[:2]
src = cv2.GaussianBlur(image, (3, 3), 1)
dst = cv2.Laplacian(src, cv2.CV_32F, ksize=3, delta=127)
dst = cv2.convertScaleAbs(dst)

result = np.zeros([h, w*2, 3], dtype=image.dtype)
result[0:h, 0:w, :] = image
result[0:h, w:w*2, :] = dst
cv2.imshow("result", result)
cv2.imwrite("laplacian.png", result)

cv2.waitKey(0)
cv2.destroyAllWindows()