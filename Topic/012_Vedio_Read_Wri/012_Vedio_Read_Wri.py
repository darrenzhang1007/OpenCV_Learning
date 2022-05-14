import cv2 as cv
import numpy as np

# capture = cv.VideoCapture("H:\\OpenCV_Learning\\012_Vedio_Read_Wri\\vtest.avi")
capture = cv.VideoCapture(0)
height = capture.get(cv.CAP_PROP_FRAME_HEIGHT)
width = capture.get(cv.CAP_PROP_FRAME_WIDTH)
count = capture.get(cv.CAP_PROP_FRAME_COUNT)
fps = capture.get(cv.CAP_PROP_FPS)
type = capture.get(cv.CAP_PROP_FORMAT)
print(height, width, count, fps, type)
out = cv.VideoWriter("test.mp4", cv.VideoWriter_fourcc('D', 'I', 'V', 'X'),  # mp4编码格式，官网文档可查
                     15, (np.int(width), np.int(height)), True)
while True:
    ret, frame = capture.read()
    if ret is True:
        cv.imshow("vedio_show", frame)
        out.write(frame)
        c = cv.waitKey(50)
        if c == 27:
            break
    else:
        break

capture.release() # 释放资源
out.release()


