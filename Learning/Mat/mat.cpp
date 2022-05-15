#include <opencv2/opencv.hpp> //加载OpenCV 4.0头文件
#include <iostream>

using namespace std;
using namespace cv; // opencv的命名空间

int main(int argc, char **argv)
{
    // 一、Mat类的介绍
    // 1. 创建Mat类
    cv::Mat a1;                                 // 创建一个名为a的矩阵头
    a1 = cv::imread("../../resource/lena.png"); // 向a中赋值图像数据，矩阵指针指向像素数据
    cv::Mat a2 = a1;                            // 只复制矩阵头，并命名为b

    // 2. 声明一个指定类型的Mat类
    cv::Mat a3 = Mat_<double>(3, 3); // 创建一个3×3的矩阵用于存放double类型的数据

    // 3. 通过OpenCV数据类型创建Mat类
    cv::Mat a4(640, 640, CV_8UC3); // 创建一个640×640的3通道矩阵用于存放彩色图像
    cv::Mat a5(3, 3, CV_8UC1);     // 创建一个3×3的8位无符号整数的单通道矩阵
    cv::Mat a6(3, 3, CV_8U);      // 创建一个3×3的8位无符号整数的单通道矩阵，C1标识可以省略

    // 二、 Mat类的构造
    // 1. 默认构造函数
    cv::Mat b1; // CV::Mat::Mat();

    // 2. 根据输入矩阵尺寸和类型构造
    cv::Mat b2(640, 640, CV_8UC3); // cv::Mat::Mat(int rows, int cols, int type);

    // 用Size() 结构构造Mat类 -> Size(rows列, cols行)
    cv::Mat b3(Size(480, 640), CV_8UC3); // cv::Mat::Mat(Size size(), int type);

    // 3. 利用已有矩阵构造
    /*
        cv::Mat::Mat(const Mat & m);
        cv::Mat::Mat(const Mat & m, const Range & rowRange, const Range & colRange=Range::all());

        Args:
            m: 已经构建完成的Mat类矩阵数据
            rowRange: 在矩阵m中需要截取的行数范围，e.g. Range(2, 5)
            colRange: 在矩阵m中需要截取的列数范围，e.g. Range(2, 5)
    */
    cv::Mat b4(b3, Range(2, 5), Range(2, 5)); // 从a中截取部分数据构造b
    cv::Mat b5(b3, Range(2, 5));              // 默认最后一个参数构造c

    // 三、 Mat类的赋值 -> 构建完Mat类后，变量里并没有数据，需要将数据赋值给它。
    // 1. 构造时赋值 cv::Mat::Mat(int rows, int cols, int type, const Scalar & s);
    cv::Mat c1(2, 2, CV_8UC3, cv::Scalar(0, 0, 255)); // 创建一个三通道矩阵，每个像素都是 (0, 0, 255)
    cv::Mat c2(2, 2, CV_8UC2, cv::Scalar(0, 255));    // 创建一个二通道矩阵，每个像素都是 (0, 255)
    cv::Mat c3(2, 2, CV_8UC1, cv::Scalar(255));       // 创建一个单通道矩阵，每个像素都是 (255)
    // Scalar结构中变量的个数一定要与定义中的通道数相对应

    // 2. 枚举法赋值
    cv::Mat c4 = (cv::Mat_<int>(3, 3) << 1, 2, 3, 4, 5, 6, 7, 8, 9);
    cv::Mat c5 = (cv::Mat_<double>(2, 2) << 1.0, 2.0, 3.0, 4.0);
    // 采用枚举法时，输入的数据个数要与矩阵元素个数相同，此方法适用于矩阵数据较少的情况下

    // 3. 循环法赋值：对矩阵中的每一个元素进行赋值，
    cv::Mat c6 = cv::Mat_<int>(3, 3); // 定义一个3×3的矩阵
    for (int i = 0; i < c6.rows; i++)
    {
        for (int j = 0; j < c6.rows; j++)
        {
            c6.at<int>(i, j) = i + j;
        }
    }

    // 4. 类方法赋值：快速赋值，初始化指定的矩阵。
    cv::Mat c7 = cv::Mat::eye(3, 3, CV_8UC1); // 构建单位矩阵，
    cv::Mat c8 = (cv::Mat_<int>(1, 3) << 1, 2, 3);
    cv::Mat c9 = cv::Mat::diag(c8);             // 构建对角矩阵，其参数是Mat类型的一维变量，用来存放对角元素的数值
    cv::Mat c10 = cv::Mat::ones(3, 3, CV_8UC1);  // 构建全为1的矩阵
    cv::Mat c11 = cv::Mat::zeros(3, 3, CV_8UC1); // 构建全为0的矩阵

    // 5. 利用数组进行赋值
    float c12[8] = {5, 6, 7, 8, 1, 2, 3, 4};
    cv::Mat c13 = cv::Mat(2, 2, CV_32FC2, c12);
    cv::Mat c14 = cv::Mat(2, 4, CV_32FC1, c12);

    // 四：Mat类支持的运算
    // 1. Mat类的加减乘除运算
    cv::Mat d1 = (cv::Mat_<int>(3, 3) << 1, 2, 3, 4, 5, 6, 7, 8, 9);
    cv::Mat d2 = (cv::Mat_<int>(3, 3) << 1, 2, 3, 4, 5, 6, 7, 8, 9);
    cv::Mat d3 = (cv::Mat_<double>(3, 3) << 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7, 8, 9);
    cv::Mat d4 = (cv::Mat_<double>(3, 3) << 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7, 8, 9);
    cv::Mat d5, d6, d7, d8, d9;
    d5 = d1 + d2;
    d6 = d3 - d4;
    d7 = 2 * d1;
    d8 = d4 / 2.0;
    d9 = d1 - 1;

    // 2. Mat类矩阵的乘法
    cv::Mat d10, d11;
    double k;
    d10 = d3 * d4;
    k = d1.dot(d2); // 点积
    d11 = d1.mul(d2); // 按位乘

    cout << k << endl;
    cout << d10 << endl;
    cout << d11 << endl;

    return 0;
}