// read_show.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int artc, char** argv) {
	Mat src = imread("H:/OpenCV_Learning/001_read_show/test.jpg", IMREAD_GRAYSCALE);

	if (src.empty()) {
		print("could not load image...\n");
		return -1;
	}
	namedWindow("input", WINDOW_AUTOSIZE);
	imshow("input", src);
	waitKey(0);
    return 0;
}