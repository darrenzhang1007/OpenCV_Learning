#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
	// 打开摄像头
	VideoCapture capture(0); 

	// 打开文件
	//VideoCapture capture;
	//capture.open("H:\\OpenCV_Learning\\012_Vedio_Read_Wri\\vtest.avi");
	if (!capture.isOpened()) {
		printf("could not read this video file...\n");
		return -1;
	}
	int w = static_cast<int>(capture.get(CAP_PROP_FRAME_WIDTH));
	int h = static_cast<int>(capture.get(CAP_PROP_FRAME_HEIGHT));
	/*Size S = Size((int)capture.get(CAP_PROP_FRAME_WIDTH),
		(int)capture.get(CAP_PROP_FRAME_HEIGHT));*/
	int fps = capture.get(CAP_PROP_FPS);
	int type = VideoWriter::fourcc('m', 'p', '4', 'v');
	printf("current fps : %d \n, current type : %d \n", fps, type);
	VideoWriter writer("test.mp4", type, fps, Size(w, h), true);

	Mat frame;
	namedWindow("camera-demo", WINDOW_AUTOSIZE);
	while (capture.read(frame)) {
		imshow("camera-demo", frame);
		writer.write(frame);
		char c = waitKey(50);
		if (c == 27) {
			break;
		}
	}
	capture.release();
	writer.release();
	waitKey(0);
	return 0;
}