//
//  main.cpp
//  OpenCV_prac2
//
//  Created by HYEJI on 2021/10/20.
//

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


using namespace std;
using namespace cv;

int main() {
    Mat img = imread("lena.png");
    
    if (img.empty()) {
        printf("Image read failed");
        exit(-1);
    }
    
    
    
    imshow("image", img);
    waitKey(0);
    return 0;
}
