import cv2 as cv
import numpy as np

image = np.zeros((512, 512, 3), dtype=np.uint8)

cv.rectangle(image, (100, 100), (300, 300), (255, 0, 0), 2, cv.LINE_8, 0)  # 左上角点，右下角点，颜色，线宽，绘制线条方式， 位移
cv.circle(image, (256, 256), 50, (0, 0, 255), 2, cv.LINE_8, 0)  # 圆心，半径，颜色...
cv.ellipse(image, (256, 256), (150, 50), 72, 0, 180, (0, 255, 0), 2, cv.LINE_8, 0)  # 中心点，长短轴，旋转角度，起始角度
cv.imshow("image", image)
cv.waitKey(0)

image[:, :, :] = 0;
cv.rectangle(image, (100, 100), (300, 300), (255, 0, 0), -1, cv.LINE_8, 0)  # 左上角点，右下角点，颜色，线宽，绘制线条方式
cv.circle(image, (256, 256), 50, (0, 0, 255), -1, cv.LINE_8, 0)
cv.ellipse(image, (256, 256), (150, 50), 360, 0, 360, (0, 255, 0), -1, cv.LINE_8, 0)
cv.imshow("image", image)
cv.waitKey(0)

for i in range(1000):
    # image[:, :, :] = 0
    x1 = np.random.randn() * 512
    y1 = np.random.randn() * 512
    x2 = np.random.randn() * 512
    y2 = np.random.randn() * 512

    b = np.random.randint(0, 256)
    g = np.random.randint(0, 256)
    r = np.random.randint(0, 256)
    # cv.line(image, (np.int(x1), np.int(y1)), (np.int(x2), np.int(y2)), (b, g, r), 4, cv.LINE_8, 0)
    cv.rectangle(image, (np.int(x1), np.int(y1)), (np.int(x2), np.int(y2)), (b, g, r), 1, cv.LINE_8, 0)
    cv.imshow("image", image)
    c = cv.waitKey(20)
    if c == 27:
        break

cv.imshow("image", image)
cv.waitKey(0)
cv.destroyAllWindows()