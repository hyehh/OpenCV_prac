//
//  main.cpp
//  OpenCV_prac5
//
//  Created by HYEJI on 2021/10/23.
//

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char* argv[]) {
    
    cv::VideoCapture cap(0);
    
    if (!cap.isOpened()) {
        std::cerr << "Could not open camera" << std::endl;
        return -1;
    }
    
    cv::namedWindow("webcam", 1);
    cv:: CascadeClassifier face_classifier;
    
    face_classifier.load("haarcascades_frontalface_default.xml");
    cv::Mat frame;
    for(;;) {
        
    }
    bool frame_valid = true;
    try{
        cap >> frame;
    }catch (cv::Exception&e) {
        std::cerr << "Exception occurred. Ignoring frame..." << e.err << std::endl;
        frame_valid = false;
    }
    
    cv::Mat grayframe;
    cv::cvtColor(frame, grayframe, COLOR_BGR2GRAY);
    cv::equalizeHist(grayframe, grayframe);
    
    std::vector <cv::Rect> faces;
    
    face_classifier.detectMultiScale(grayframe, faces,
    1.1, // increase search scale by 10% each passs
    3, // merge groups of three detections
    CASCADE_FIND_BIGGEST_OBJECT | CASCADE_SCALE_IMAGE,
    cv:: Size(30, 30)
    );
    // draw the results
    for (int i = 0; i < faces.size(); i++) {
    cv:: Point Ib(faces[i].x + faces[i].width, faces[i].y + faces[i].height);
    cv::Point tr(faces[i].x, faces[i].y);
        cv:: rectangle(frame, Ib, tr, cv:: Scalar (0, 255, 0), 3, 4, 0);
    }
    // print the output
    cv::imshow("webcam", frame);
}
