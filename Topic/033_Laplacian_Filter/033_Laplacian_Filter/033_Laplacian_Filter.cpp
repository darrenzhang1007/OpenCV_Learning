#include <opencv2/opencv.hpp>
#include <iostream>

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

	Mat blured, dst;
	GaussianBlur(src, blured, Size(3, 3), 0);
	// ΪʲôҪ����127.0�����׵�������Ĳ����С��ֱ���������һƬ���
	// Ŀ�ģ�������� ԭͼ + 127
	Laplacian(blured, dst, CV_32F, 1, 1.0, 127.0, BORDER_DEFAULT);
	convertScaleAbs(dst, dst);
	imshow("result", dst);

	waitKey(0);
	destroyAllWindows();
	return 0;
}