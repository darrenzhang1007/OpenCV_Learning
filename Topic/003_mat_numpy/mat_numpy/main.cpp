#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
	Mat src = imread("H:/OpenCV_Learning/test.jpg");
	if (src.empty()) {
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("input", WINDOW_AUTOSIZE);
	imshow("input", src);

	// 创建方法 - 克隆
	Mat m1 = src.clone();

	// 复制
	Mat m2;
	src.copyTo(m2);

	// 赋值法
	Mat m3 = src;

	// 创建空白图像
	Mat m4 = Mat::zeros(src.size(), src.type()); // 创建的图像与src的大小类型相同
	Mat m5 = Mat::zeros(Size(512, 512), CV_8UC3); // 创建空白图像，大小自己指定，CV_8UC3:图像dtype
	Mat m6 = Mat::ones(Size(512, 512), CV_8UC3); // 创建

	// 自定义卷积核
	Mat kernel = (
		Mat_<char>(3, 3) 
		<< 
		0, -1, 0,
		-1, 5, -1,
		0, -1, 0);

	waitKey(0);
	return 0;
}
