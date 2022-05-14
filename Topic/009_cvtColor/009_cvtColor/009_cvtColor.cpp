#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, const char * argv[]) {
	Mat src = imread("H:\\OpenCV_Learning\\test.jpg");
	if (src.empty()) {
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("input", WINDOW_AUTOSIZE);
	imshow("input", src);

	// BGR to HSV
	Mat hsv_result;
	cvtColor(src, hsv_result, COLOR_BGR2HSV);
	imshow("hsv_result", hsv_result);

	// BGR to YUV
	Mat yuv_result;
	cvtColor(src, yuv_result, COLOR_BGR2YUV);
	imshow("yuv_result", yuv_result);

	// BGR to YCrCB
	Mat ycrcb_result;
	cvtColor(src, ycrcb_result, COLOR_BGR2YCrCb);
	imshow("ycrcb_result", ycrcb_result);

	// inRange
	Mat src2 = imread("H:\\OpenCV_Learning\\009_cvtColor\\green.jpg");
	Mat hsv_result2;
	imshow("src2", src2);
	cvtColor(src2, hsv_result2, COLOR_BGR2HSV);
	Mat mask;
	inRange(hsv_result2, Scalar(35, 43, 46), Scalar(77, 255, 255), mask);
	imshow("mask", mask);
	
	Mat dst;
	bitwise_and(src2, src2, dst, mask);
	imshow("dst", dst);

	waitKey(0);
	return 0;

}