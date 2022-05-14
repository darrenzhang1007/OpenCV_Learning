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

	// �������� - ��¡
	Mat m1 = src.clone();

	// ����
	Mat m2;
	src.copyTo(m2);

	// ��ֵ��
	Mat m3 = src;

	// �����հ�ͼ��
	Mat m4 = Mat::zeros(src.size(), src.type()); // ������ͼ����src�Ĵ�С������ͬ
	Mat m5 = Mat::zeros(Size(512, 512), CV_8UC3); // �����հ�ͼ�񣬴�С�Լ�ָ����CV_8UC3:ͼ��dtype
	Mat m6 = Mat::ones(Size(512, 512), CV_8UC3); // ����

	// �Զ�������
	Mat kernel = (
		Mat_<char>(3, 3) 
		<< 
		0, -1, 0,
		-1, 5, -1,
		0, -1, 0);

	waitKey(0);
	return 0;
}
