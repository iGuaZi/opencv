//功能：以各种方法比较两个hist，并将结果返回。

double* histCmp(CvHistogram* hist1, CvHistogram* hist2){
	double dist[4] = { 0.0 };
	char* histMethod[4] = { "CORREL", "CHISQR", "INTERSECT", "BHATTACHARYYA" };
	for (int i = 0; i < 4; i++){
		dist[i] = cvCompareHist(hist1, hist2, i);
		printf(" %f <---%s\n", dist[i], histMethod[i]);
	}
	printf("\n");
	return dist;
}
