#ifndef HIS
#define HIS
#define binsize 256
typedef struct histogramRoboticGoalkeeperImage{
	int frequency;
	int binSize;
}Histogram_t;
int getHistogram(const char* imgName, int channel, int binSize, Histogram_t* histogram);
#endif