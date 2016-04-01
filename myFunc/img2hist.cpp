//功能：从路径中读取图片，然后创建其对应的直方图

CvHistogram* img2hist(char* path){
	IplImage* src = cvLoadImage(path);
	IplImage* hsv = cvCreateImage(cvGetSize(src), 8, 3);
	cvZero(hsv);
	cvCvtColor(src, hsv, CV_BGR2HSV);
	IplImage* h_plane = cvCreateImage(cvGetSize(src), 8, 1);
	IplImage* s_plane = cvCreateImage(cvGetSize(src), 8, 1);
	IplImage* v_plane = cvCreateImage(cvGetSize(src), 8, 1);
	IplImage* planes[] = { h_plane, s_plane };
	cvSplit(hsv, h_plane, s_plane, v_plane, 0);

	int h_bins = binNum;
	int s_bins = binNum;

	CvHistogram* hist;
	{
		int hist_size[] = { h_bins, s_bins };
		float h_ranges[] = { 0, 180 };
		float s_ranges[] = { 0, 255 };
		float* ranges[] = { h_ranges, s_ranges };
		hist = cvCreateHist(2, hist_size, CV_HIST_ARRAY, ranges);
	}
	cvCalcHist(planes, hist);
	cvNormalizeHist(hist, 1);

	cvReleaseImage(&src);
	cvReleaseImage(&hsv);
	cvReleaseImage(&h_plane);
	cvReleaseImage(&s_plane);
	cvReleaseImage(&v_plane);
	//cvReleaseImage(planes);
	return hist;
}
