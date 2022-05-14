#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int artc, char** argv) {
	Mat src = imread("H:\\OpenCV_Learning\\test.jpg");
	if (src.empty()) {
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("input", WINDOW_AUTOSIZE);
	imshow("input", src);

	Mat edges;
	Canny(src, edges, 100, 300, 3, false);
	imshow("edge image", edges);

	waitKey(0);
	return 0;
}
