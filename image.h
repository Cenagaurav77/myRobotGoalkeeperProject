#ifndef IMAGE
#define IMAGE
#include <stdint.h>
#define Num_planes 1
#define Compression 0
#define Pixelbytesize Height*Width*24/8
#define X_res_PixelsPerMeter 0x130B //2835 , 72 DPI
#define Y_res_PixelsPerMeter 0x130B //2835 , 72 DPI
#define Pixel 0xFF
#pragma pack(push,1)
typedef struct header1{
	char signature[2];
	uint32_t filesize;
	uint32_t reserved;
	uint32_t fileoffset_to_pixelarray;
} fileheader;
typedef struct header2{
	uint32_t dibheadersize;
    	uint32_t width;
    	uint32_t height;
    	uint16_t planes;
    	uint16_t bitsperpixel;
    	uint32_t compression;
    	uint32_t imagesize;
    	uint32_t y_res_PixelsPerMeter;
    	uint32_t x_res_PixelsPerMeter;
    	uint32_t numcolorspallette;
    	uint32_t mostimpcolor;
} bitmapinfoheader;
typedef struct combinedHeader{
    	fileheader fileheader;
    	bitmapinfoheader bitmapinfoheader;
} bitmap;
#pragma pack(pop)
typedef struct roboticGoalkeeperLoadImage{
	int width;
	int height;
	int bitsPerPixel;
	int size;	
	int stride;
	unsigned char data[];
}Image_t;
Image_t * readImage(const char* bmpFileName);
void writeImage(const char* bmpFileName, Image_t *imgStructData);
void destroyImageFromMemory(Image_t *im);
#endif