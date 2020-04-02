#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
	Mat src = imread("H:\\OpenCV_Learning\\test.jpg");
	if (src.empty()) {
		printf("could not load img...\n");
		return -1;
	}
	namedWindow("input", WINDOW_AUTOSIZE);
	imshow("input", src);

	Mat robert_x = (Mat_<int>(2, 2) << 
		1, 0,
		0, -1);
	Mat robert_y = (Mat_<int>(2, 2) << 
		0, -1,
		1, 0);

	Mat prewitt_x = (Mat_<char>(3, 3) <<
		-1, 0, 1,
		-1, 0, 1,
		-1, 0, 1);

	Mat prewitt_y = (Mat_<char>(3, 3) <<
		-1, -1, -1,
		0, 0, 0,
		1, 1, 1);

	Mat robert_grad_x, robert_grad_y, prewitt_grad_x, prewitt_grad_y;
	filter2D(src, robert_grad_x, CV_16S, robert_x);
	filter2D(src, robert_grad_y, CV_16S, robert_y);
	convertScaleAbs(robert_grad_x, robert_grad_x);
	convertScaleAbs(robert_grad_y, robert_grad_y);

	filter2D(src, prewitt_grad_x, CV_32F, prewitt_x);
	filter2D(src, prewitt_grad_y, CV_32F, prewitt_y);
	convertScaleAbs(prewitt_grad_x, prewitt_x);
	convertScaleAbs(prewitt_grad_x, prewitt_y);
	printf("image gradient...");

	imshow("robert x", robert_grad_x);
	imshow("robert y", robert_grad_y);
	imshow("prewitt x", prewitt_grad_x);
	imshow("prewitt y", prewitt_grad_y);

	waitKey(0);
	destroyAllWindows();
	return 0;
}