#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{	
	VideoCapture cap(0);
		
	if (cap.isOpened() == false)
	{
		cout << "Cannot open the video camera" << endl;
		cin.get(); 
		return -1;
	}

	double dWidth = cap.get(CAP_PROP_FRAME_WIDTH); 
	double dHeight = cap.get(CAP_PROP_FRAME_HEIGHT); 

	cout << "Resolution of the video : " << dWidth << " x " << dHeight << endl;

	string window_name = "My Camera Feed";
	namedWindow(window_name); 

	while (true)
	{
		Mat frame;
		bool bSuccess = cap.read(frame);  

		if (bSuccess == false)
		{
			cout << "Video camera is disconnected" << endl;
			cin.get(); 
			break;
		}

		imshow(window_name, frame);

		if (waitKey(10) == 27)
		{
			cout << "Esc key is pressed by user. Stoppig the video" << endl;
			break;
		}
	}

	return 0;

}