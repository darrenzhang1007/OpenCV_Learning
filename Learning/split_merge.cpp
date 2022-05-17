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
        cout << "请确认图像文件名称是否正确" << endl;
        return -1;
    }

    Mat hsv_img;
    cvtColor(img, hsv_img, COLOR_BGR2HSV);
    Mat imgs0, imgs1, imgs2;       // 用于存放数组类型的结果
    Mat imgv0, imgv1, imgv2;       // 用于存放vetcor 类型的结果
    Mat result0, result1, result2; // 多通道合并的结果

    // 输入数组参数的多通道分离与合并
    Mat imgs[3];
    split(img, imgs);
    imgs0 = imgs[0];
    imgs1 = imgs[1];
    imgs2 = imgs[2];
    imshow("B channel", imgs0);
    imshow("G channel", imgs1);
    imshow("R channel", imgs2);

    imgs[2] = img;           // 将数组中的图像通道数变成不一致
    merge(imgs, 3, result0); // 合并图像

    Mat zero = cv::Mat::zeros(img.rows, img.cols, CV_8UC1);
    imgs[0] = zero;
    imgs[2] = zero;
    merge(imgs, 3, result1); // 用于还原G通道的真实情况，合并结果为绿色
    imshow("result1", result1);

    // 输入 vector 参数的多通道分离与合并
    vector<Mat> imgv;
    split(hsv_img, imgv);
    imgv0 = imgv.at(0);
    imgv1 = imgv.at(1);
    imgv2 = imgv.at(2);
    imshow("HSV-H channel", imgv0); // 显示分离后H通道的像素值
    imshow("HSV-S channel", imgv1); // 显示分离后H通道的像素值
    imshow("HSV-V channel", imgv2); // 显示分离后H通道的像素值

    imgv.push_back(hsv_img); // 将vector中的图像通道数变成不一致
    merge(imgv, result2);    // 合并图像
    // imshow("result2", result2);

    waitKey(0);
    return 0;
}