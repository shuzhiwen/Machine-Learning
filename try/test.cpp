#include "opencv2/core/core.hpp"  
#include "opencv2/objdetect/objdetect.hpp"  
#include "opencv2/highgui/highgui.hpp"  
#include "opencv2/imgproc/imgproc.hpp"  
#include <fstream>  
#include <iostream>  
  
using namespace std;
using namespace cv;
  
int main() {
  //定义级联分类器
	CascadeClassifier face_detector;
	//加载分类器
	face_detector.load("dst/cascade.xml");
	//判断分类器是否加载成功
	if (face_detector.empty()) {
		std::cerr << "load detector failed!!!" << std::endl;
		return -1;
	}
 
	//获取训练集的原始尺寸，作为分类器的最小尺寸，这样能得到最佳的检测效果（不是必须的）
	Size original_size = face_detector.getOriginalWindowSize();
 
	Mat image = imread("test.jpg", IMREAD_COLOR);
 
	Mat image_gray;
	cvtColor(image, image_gray, COLOR_BGR2GRAY);
	
	//用于保存检测到的目标窗口
	std::vector<Rect> faces;
	//进行多尺度人脸检测
	face_detector.detectMultiScale(image_gray, faces, 1.1, 3, 0 | CASCADE_SCALE_IMAGE, original_size);
 
	//将检测到的目标窗口逐个绘制到原图上
	for (size_t i = 0; i < faces.size(); i++) {
		rectangle(image, faces[i], Scalar(0, 0, 255), 2, 8, 0);
	}
 
	imshow("detect result", image);
	waitKey(0);
}