#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
	Mat src = imread("H:/OpenCV_Learning/test.jpg");
	if (src.empty()) {
		printf("could not load img...\n");
		return -1;
	}

	namedWindow("input", WINDOW_AUTOSIZE);
	imshow("input", src);

	Mat gray;
	cvtColor(src, gray, COLOR_BGR2GRAY);
	imwrite("gray.png", gray);
	
	waitKey(0);
	return 0;
}