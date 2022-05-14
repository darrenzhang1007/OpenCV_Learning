#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
	Mat src = imread("H:\\OpenCV_Learning\\test.jpg");
	if (src.empty()) {
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("input", WINDOW_AUTOSIZE);
	imshow("input", src);

	Mat dst;
	// X Flip µ¹Ó°
	flip(src, dst, 0);
	imshow("x-flip", dst);

	// Y Flip ¾µÏñ
	flip(src, dst, 1);
	imshow("y-flip", dst);

	// XY Flip ¶Ô½Ç
	flip(src, dst, -1);
	imshow("xy_flip", dst);

	waitKey(0);
	destroyAllWindows();
	return 0;
}