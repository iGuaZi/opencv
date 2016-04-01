//功能：显示创建好的直方图
//hist：创建好的直方图
//windName: 显示直方图窗口的名字

void dispHist(CvHistogram* hist, char* windName){
	if (!hist || (!windName))
		exit(0);
	int scale = 10;
	int h_bins = hist->mat.dim[0].size;
	int s_bins = hist->mat.dim[1].size;
	IplImage* histImg = cvCreateImage(cvSize(h_bins * scale, s_bins * scale), 8, 3);
	cvZero(histImg);

	//display
	float max_val = 0;
	cvGetMinMaxHistValue(hist, 0, &max_val);
	for (int h = 0; h < h_bins; h++){
		for (int s = 0; s < s_bins; s++){
			float bin_val = cvGetReal2D(hist->bins, h, s);
			int intensity = cvRound(bin_val * 255 / max_val);
			cvRectangle(
				histImg,
				cvPoint(h*scale, s*scale),
				cvPoint((h + 1)*scale - 1, (s + 1)*scale - 1),
				CV_RGB(intensity, intensity, intensity),
				CV_FILLED);
		}
	}
	cvNamedWindow(windName);
	cvShowImage(windName, histImg);
}
