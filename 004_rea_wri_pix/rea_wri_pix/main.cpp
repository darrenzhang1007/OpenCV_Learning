#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
	Mat src = imread("H:\\OpenCV_Learning\\test.jpg");
	if (src.empty()) {
		printf("could not load img...\n");
		return -1;
	}
	namedWindow("input", WINDOW_AUTOSIZE);
	imshow("input", src);

	// 直接读取图像像素：速度慢
	int height = src.rows;
	int width = src.cols;
	int ch = src.channels();
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			if (ch == 3) {
				Vec3b bgr = src.at<Vec3b>(row, col); // 获取3个字节类型的值，先行后列，
				bgr[0] = 255 - bgr[0]; // 色彩取反 
				bgr[1] = 255 - bgr[1];
				bgr[2] = 255 - bgr[2];
				src.at<Vec3b>(row, col) = bgr;
			}
			else if (ch == 1) {
				int gray = src.at<uchar>(row, col);
				src.at<uchar>(row, col) = 255 - gray;
			}
		}
	}
	imshow("output", src);

	// 指针读取
	Mat result = Mat::zeros(src.size(), src.type()); // 创建一个空白图像
	int blue = 0, green = 0, red = 0;
	int gray;
	for (int row = 0; row < height; row++) {  
		uchar* curr_row = src.ptr<uchar>(row); // 获取这一行所有像素点的像素块的首地址；这一行第一个像素的地址
		uchar* result_row = result.ptr<uchar>(row);
		for (int col = 0; col < width; col++) {
			if (ch == 3) {
				blue = *curr_row++;
				green = *curr_row++;
				red = *curr_row++;

				*result_row++ = blue;
				*result_row++ = green;
				*result_row++ = red;
			}
			else if (ch == 1) {
				gray = *curr_row++;
				*result_row++ = gray;
			}
		}
	}
	imshow("result", result);

	waitKey(0);
	return 0;
}