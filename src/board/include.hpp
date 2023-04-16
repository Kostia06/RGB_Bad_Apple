#ifndef BOARD_HPP
#define BOARD_HPP

#include <string>
#include <vector>

#include <opencv2/opencv.hpp>

class Board{
private:
    int index=0;
    int width,height,fps;
    std::string name;
    std::vector<std::vector<cv::Point> > points;
    int colors[8][3] = {
        {255,0,0},
        {0,255,0},
        {0,0,255},
        {255,255,0},
        {255,0,255},
        {0,255,255},
        {255,255,255},
        {0,0,0},
    };
    int count = 5;
    cv::Mat image;
    int get_closest_num(int num);
    cv::Vec3d get_random_color();
public: 
    Board(std::string _name,std::vector<std::vector<cv::Point> > _points,int _width, int _height, int _fps,int _count);
    ~Board();

    void show();
};


#endif

