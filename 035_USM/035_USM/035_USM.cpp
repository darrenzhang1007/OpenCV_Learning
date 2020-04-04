#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int artc, char** argv) {
	Mat src = imread("H:\\OpenCV_Learning\\test.jpg");
	if (src.empty()) {
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("input", WINDOW_AUTOSIZE);
	imshow("input", src);

	Mat blur_img, usm;
	GaussianBlur(src, blur_img, Size(3, 3), 25);
	addWeighted(src, 1.5, blur_img, -0.5, 0, usm);
	imshow("mask img", usm);

	waitKey(0);
	destroyAllWindows();
	return 0;

}