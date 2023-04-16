#include "include.hpp"

Board::Board(std::string _name,std::vector<std::vector<cv::Point> > _points,int _width, int _height, int _fps,int _count){
    width = _width;
    height = _height;
    fps = _fps;
    name = _name;
    image = cv::Mat::zeros(height,width,CV_8UC3);
    points = _points;
    count = _count;
    for(int i=0;i<height;i+=count){
        for(int j=0;j<width;j+=count){
            cv::Vec3b color = get_random_color();
            for(int count_x=0;count_x<count;count_x++){
                for(int count_y=0;count_y<count;count_y++){
                    image.at<cv::Vec3b>(i+count_x,j+count_y) = color;
                }
            }
        }
    }
}
Board::~Board(){

}
int Board::get_closest_num(int num){
    if(num%count==0){return num;}
    return (num/count)*count;
}
cv::Vec3d Board::get_random_color(){
    int r = rand() % 8;
    return cv::Vec3d(colors[r][0],colors[r][1],colors[r][2]);
}       
void Board::show(){
    cv::imshow("Board",image);
    std::vector<cv::Point> p = points[index];
    for(int i=0;i<(int)p.size();i++){
        cv::Vec3b color = get_random_color();
        int x = get_closest_num(p[i].x);
        int y = get_closest_num(p[i].y);
        for(int count_x=0;count_x<count;count_x++){
            for(int count_y=0;count_y<count;count_y++){
                image.at<cv::Vec3b>(y+count_y,x+count_x) = color;
            }
        }
    }
    index++;
}
