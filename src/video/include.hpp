#ifndef VIDEO_HPP
#define VIDEO_HPP

#include <vector>
#include <string>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>

class Video{
public:
    std::string filename;
    int index = 0;
    cv::VideoCapture cap;
    std::vector<cv::Mat> frames;
    std::vector<cv::Mat> music;
    int frame_width, frame_height,fps,total_frames;
    Video(std::string filename);
    ~Video();

    void sound();
    void show();
    void error(int coundtion,std::string msg);
    std::vector<std::vector<cv::Point> > get_points();
};




#endif

