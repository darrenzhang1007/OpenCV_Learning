#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
	Mat src = imread("F:/Êý¾Ý¼°/pic/1_Handshaking_Handshaking_1_35.jpg");
	imshow("input", src);
	waitKey(0);
	destroyAllWindows();

	return 0;

}