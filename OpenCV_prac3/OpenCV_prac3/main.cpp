//
//  main.cpp
//  OpenCV_prac3
//
//  Created by HYEJI on 2021/10/21.
//

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int ac, char** av) {
    
    VideoCapture cap(0);
    cap.set(1920, CAP_PROP_FRAME_WIDTH) ;
    cap.set(1080, CAP_PROP_FRAME_HEIGHT);
   if(!cap.isOpened()) //'변수 이름', isOpened() 함수가 카메라 정보가 있는지 없는지 판단
   {
       printf("Can't open the camera");
       return -1;
   }
   Mat img ;
    
   while(1) // VideoCapture 로부터 프레임을 받아온다.
   {
       cap >> img;  //카메라 정보를 Img 라는 행렬에 저장
       imshow("Camera", img);
       if(waitKey(1) == 27) // 딜레이 타임
           break;
   }
   
   return 0;
}
