//
//	draw text sample
//
#ifdef WIN32
	#include <SDKDDKVer.h>
	#include <Windows.h>
	#ifdef _DEBUG
		#pragma comment(lib, "opencv_core246d.lib")
		#pragma comment(lib, "opencv_highgui246d.lib")
	#else
		#pragma comment(lib, "opencv_core246.lib")
		#pragma comment(lib, "opencv_highgui246.lib")
	#endif
#endif

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

void draw_text(cv::Mat &canvas, const char *str, int x, int y, float scale = 1.0)
{
	int w = 2;
	for(int dy = -w; dy <= w; ++dy) {
		for (int dx = -w; dx <= w; ++dx) {
			cv::putText(canvas, str, cv::Point(x+dx,y+dy), cv::FONT_HERSHEY_SIMPLEX, scale, cv::Scalar(0,0,0), 2, CV_AA);
		}
	}

	cv::putText(canvas, str, cv::Point(x,y), cv::FONT_HERSHEY_SIMPLEX, scale, cv::Scalar(255,255,255), 2, CV_AA);
}

int main(int argc, char* argv[])
{
	cv::Mat canvas;
	canvas = cv::imread("nike.jpg", -1);
	if (canvas.empty()) {
		std::cerr << "cv::imread() failed...filename=nike.jpg" << std::endl;
		return -1;
	}

	draw_text(canvas, "nike.jpg", 10, 30);

	cv::imwrite("result.jpg", canvas);

	return 0;
}



