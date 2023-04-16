#include <stdio.h>
#include <stdlib.h>
#include <string>

#include <opencv2/opencv.hpp>
#include "video/include.hpp"
#include "board/include.hpp"

int main(int argc, char *argv[]){
	if(argc != 4){
		printf("Usage: %s <filename> <mode> <pixel size>\n", argv[0]);
	}
	std::string filename = argv[1];
	int mode = atoi(argv[2]);
	int pixel_size = atoi(argv[3]);
	if(mode == 1){cv::namedWindow("Video",cv::WINDOW_NORMAL);}
	cv::namedWindow("Sound",cv::WINDOW_NORMAL);
	cv::namedWindow("Board",cv::WINDOW_NORMAL);
	Video video(filename);
	Board board(filename,video.get_points(),video.frame_width,video.frame_height,video.fps,pixel_size);
	while(1){
		int key = cv::waitKey(100/video.fps);
		if (key == 'p') {
            while (true) {
                int key2 = cv::waitKey(30);
                if (key2 == 'p') break;
            }
        }
		board.show();
		video.sound();
		if(mode==1){video.show();}
	}
	return 0;
}
