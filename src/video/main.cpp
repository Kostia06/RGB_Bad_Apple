#include "include.hpp"

Video::Video(std::string filename){
	this->filename = filename;
	cap = cv::VideoCapture(filename);
	error(!cap.isOpened(),"Error: Could not open video file");
	frame_width = int(cap.get(cv::CAP_PROP_FRAME_WIDTH));
	frame_height = int(cap.get(cv::CAP_PROP_FRAME_HEIGHT));
	fps = cap.get(cv::CAP_PROP_FPS);
	total_frames = cap.get(cv::CAP_PROP_FRAME_COUNT);
}
Video::~Video(){
	cap.release();
}
void Video::show(){
	cv::Mat frame = frames[index];
	cv::imshow("Video",frame);
	index++;
}
void Video::sound(){
	cv::Mat sound_frame = music[index];
	cv::imshow("Sound",sound_frame);
}
void Video::error(int coundtion,std::string msg){
	if(!coundtion)return;
	std::string BOLD_RED = "\033[1;31m";
	std::cout <<BOLD_RED<< msg << std::endl;
	exit(1);		
}
std::vector<std::vector<cv::Point> > Video::get_points(){
	std::vector<std::vector<cv::Point> > array_points;	
	for(int i=0;i<total_frames;i++){
		cv::Mat frame,sound_frame,resized_frame,gray_frame, thresh_frame, mask_frame, masked_frame;
		cap.read(frame);
		frames.push_back(frame);
		cap.retrieve(sound_frame, cv::CAP_PROP_POS_MSEC);
		music.push_back(sound_frame);
		frame.convertTo(frame, CV_8U);
		cv::cvtColor(frame, gray_frame, cv::COLOR_BGR2GRAY);
		cv::threshold(gray_frame, thresh_frame, 0, 255, cv::THRESH_BINARY);
		cv::inRange(frame, cv::Scalar(0, 0, 0), cv::Scalar(30, 30, 30), mask_frame);
		cv::bitwise_and(thresh_frame, thresh_frame, masked_frame, mask_frame);
		std::vector<cv::Point> points;
		cv::findNonZero(masked_frame, points);
		array_points.push_back(points);

		int percent = (i*100)/total_frames;
		std::cout << "\rGetting frames: " << percent << "%" << std::flush;
	}			
	cap.release();
	return array_points;
}
