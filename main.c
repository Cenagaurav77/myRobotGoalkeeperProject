#include<stdio.h>
#include<stdlib.h>
#include "image.h"
#include "his.h"
Image_t * readImage(const char* bmpFileName);
void writeImage(const char* bmpFileName, Image_t *imgStructData);
int getHistogram(const char* imgName, int channel, int binSize, Histogram_t* histogram);
void destroyImageFromMemory(Image_t *im);
int main(){
	struct roboticGoalkeeperLoadImage *imgData = readImage("issue3BMP.bmp");
	struct histogramRoboticGoalkeeperImage *hist;
	hist->binSize = binsize;
	int a = getHistogram("issue3BMP.bmp", (imgData->bitsPerPixel)/8, hist->binSize, hist);
	if(a == 0){
		printf("Everything went fine!!!!!");
	}else{
		printf("problem with the argument or any internal error");
	}
	writeImage("issue3BMP.bmp", imgData);
	destroyImageFromMemory(imgData);
	return 0;
}
