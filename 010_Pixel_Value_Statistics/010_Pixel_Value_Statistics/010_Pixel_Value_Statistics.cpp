#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, const char *argv[]) {
	Mat src = imread("H:\\OpenCV_Learning\\gray.png", IMREAD_GRAYSCALE);
	if (src.empty()) {
		printf("could not load image... \n");
		return -1;
	}
	namedWindow("input", WINDOW_AUTOSIZE);
	imshow("input", src);

	double minVal; double maxVal; Point minLoc; Point maxLoc;
	minMaxLoc(src, &minVal, &maxVal, &minLoc, &maxLoc, Mat());
	printf("min: %.2f, max: %.2f \n", minVal, maxVal);
	printf("min loc: (%d, %d) \n", minLoc.x, minLoc.y);
	printf("max loc: (%d, %d)\n", maxLoc.x, maxLoc.y);

	// 彩色图像 三通道的 均值与方差
	src = imread("H:\\OpenCV_Learning\\test.jpg");
	Mat means, stddev;
	meanStdDev(src, means, stddev);
	printf("blue channel->> mean: %.2f, stddev: %.2f\n", means.at<double>(0, 0), stddev.at<double>(0, 0));
	printf("green channel->> mean: %.2f, stddev: %.2f\n", means.at<double>(1, 0), stddev.at<double>(1, 0));
	printf("red channel->> mean: %.2f, stddev: %.2f\n", means.at<double>(2, 0), stddev.at<double>(2, 0));

	// 将普通图像转为2值图像
	for (int row = 0; row < src.rows; row++) {
		for (int col = 0; col < src.cols; col++) {
			Vec3b bgr = src.at<Vec3b>(row, col);
			bgr[0] = bgr[0] < means.at<double>(0, 0) ? 0 : 255;
			bgr[1] = bgr[1] < means.at<double>(1, 0) ? 0 : 255;
			bgr[2] = bgr[2] < means.at<double>(2, 0) ? 0 : 255;
			src.at<Vec3b>(row, col) = bgr;
			
		}
	}
	imshow("binary_result", src);

	waitKey(0);
	return 0;
}