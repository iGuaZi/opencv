//将变量名转化为字符串
//在字符格式中有用


#include "cv.h"
#include "highgui.h"
#define name_to_str(name_31415926)  (#name_31415926)

int main(){
	CvHistogram* hist_1 = img2hist(hand1);
	char* dst = name_to_str(hist_1);
	printf(dst);
}
