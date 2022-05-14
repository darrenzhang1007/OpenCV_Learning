#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, const char *argv[]) {
	Mat src = imread("H:\\OpenCV_Learning\\test.jpg");
	if (src.empty()) {
		printf("could not load img...\n");
		return -1;
	}
	namedWindow("input", WINDOW_AUTOSIZE);
	imshow("input", src);

	Mat gray, gray_f;
	cvtColor(src, gray, COLOR_BGR2GRAY); // 转化为灰度图像
	gray.convertTo(gray, CV_32F); // 转化为浮点数类型数组

	// scale and shift by NORM_MINMAX
	Mat dst = Mat::zeros(gray.size(), CV_32FC1);
	normalize(gray, dst, 1.0, 0, NORM_MINMAX);
	Mat result = dst * 255;
	result.convertTo(dst, CV_8UC1); // 浮点数类型图像显示会有问题
	imshow("NORM_MINMAX", dst);
	 
	// scale and shift by NORM_INF
	normalize(gray, dst, 1.0, 0, NORM_INF);
	result = dst * 255;
	result.convertTo(dst, CV_8UC1);
	imshow("NORM_INF", dst);

	// scale and shift by NORM_L1
	normalize(gray, dst, 1.0, 0, NORM_L1);
	result = dst * 10000000;
	result.convertTo(dst, CV_8UC1);
	imshow("NORM_L1", dst);

	// scale and shift by NORM_L2
	normalize(gray, dst, 1.0, 0, NORM_L2);
	result = dst * 10000;
	result.convertTo(dst, CV_8UC1);
	imshow("NORM_L2", dst);

	waitKey(0);
	return 0;
}