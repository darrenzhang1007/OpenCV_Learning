cmake_minimum_required(VERSION 2.6)
#创建工程
project(testopencv)
#C++版本为 11
set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 4.5.5 REQUIRED) #找 OpenCV 4.0 安装路径
include_directories(${OpenCV_INCLUDE_DIRS}) #加载 OpenCV 4.0 的头文件


add_executable(testopencv install_test.cpp) #将程序生成可执行文件
target_link_libraries(testopencv ${OpenCV_LIBS}) #链接 lib 文件到可执行文件中