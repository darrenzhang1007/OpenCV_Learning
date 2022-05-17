#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace cv;

int main()
{
    Mat img = imread("../resource/lena.png");
    if (img.empty())
    {
        cout << "请确认图像文件名是否正确" << endl;
        return -1;
    }
    Mat gray_img, hsv_img, yuv_img, lab_img, img32;

    img.convertTo(img32, CV_32F, 1.0 / 255); // 将CV_8U类型转换为CV_32F类型
    // img32.convertTo(img, CV_8U, 255); // 将CV_32F类型转换为CV_8U类型
    cvtColor(img32, hsv_img, COLOR_BGR2HSV);
    cvtColor(img32, yuv_img, COLOR_BGR2YUV);
    cvtColor(img32, lab_img, COLOR_BGR2Lab);
    cvtColor(img32, gray_img, COLOR_BGR2GRAY);

    imshow("原图", img32);
    imshow("hsv_img", hsv_img);
    imshow("yuv_img", yuv_img);
    imshow("lab_img", lab_img);
    imshow("gray_img", gray_img);

    waitKey(0);
    return 0;
}