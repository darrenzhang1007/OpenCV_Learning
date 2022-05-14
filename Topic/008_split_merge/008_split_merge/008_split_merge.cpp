#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, const char *argv[]) {
	Mat src = imread("H:\\OpenCV_Learning\\test.jpg");
	if (src.empty()) {
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("input", WINDOW_AUTOSIZE);
	imshow("input", src);

	vector<Mat> mv;
	Mat dst1, dst2, dst3;
	// 蓝色通道为0
	split(src, mv);
	mv[0] = Scalar(0);
	merge(mv, dst1);
	imshow("output1", dst1);

	// 绿色通道为0
	split(src, mv);
	mv[1] = Scalar(0);
	merge(mv, dst2);
	imshow("output2", dst2);

	// 红色通道为0
	split(src, mv);
	mv[2] = Scalar(0);
	merge(mv, dst3);
	imshow("output3", dst3);

	waitKey(0);
	return 0;
}