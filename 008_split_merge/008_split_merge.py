import cv2 as cv

src = cv.imread("H:\\OpenCV_Learning\\test.jpg")
cv.namedWindow("input", cv.WINDOW_AUTOSIZE)
cv.imshow("input", src)

# 蓝色通道为0
mv = cv.split(src)
mv[0][:, :] = 0  # 第0个通道的所有像素
dst1 = cv.merge(mv)
cv.imshow("output1", dst1)

# 绿色通道为0
mv = cv.split(src)
mv[1][:, :] = 0
dst2 = cv.merge(mv)
cv.imshow("output2", dst2)

# 红色通道为0
mv = cv.split(src)
mv[2][:, :] = 0
dst3 = cv.merge(mv)
cv.imshow("output3", dst3)

cv.mixChannels(src, dst3, [2, 0])  # 将输入矩阵的第3个通道数据复制到输出矩阵的第1个通道
cv.imshow("output4", dst3)

cv.waitKey(0)
cv.destroyAllWindows()