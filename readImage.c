#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "image.h"
Image_t * readImage(const char* bmpFileName){

	FILE *fp = fopen(bmpFileName, "rb");						//Read the file in binary mode 
	Image_t *img = (Image_t*) malloc(sizeof(Image_t));				//Allocate a memory to a struct
	unsigned char header[54];							//Array for header of bitmap file
    	fread(header, sizeof(unsigned char), 54, fp);					//Store the header values in header from file pointing to a given file of size 54 bytes

   	img->width = header[18];
    	img->height = header[22];
	img->bitsPerPixel = header[28];
	img->size = header[34];
	img->stride = (img->width*3)+(img->width%4);					//bytes in a row
	
	unsigned char data1[img->size];							//Array for bitmap image data
	fread(data1, sizeof(unsigned char), img->size, fp);				//Store the image data in an array(data1) from file pointing to a given file
	for(int i=0; i<img->size; i++){
		img->data[i] = data1[i];						//Store the array data to a struct member
	}

	return img;
}

void writeImage(const char* bmpFileName, Image_t *imgStructData){
	FILE *fp = fopen("test.bmp","wb");						//open the file in write mode				
    	bitmap *imgbitmap  = (bitmap*)malloc(sizeof(bitmap));				//for header
    	strcpy(imgbitmap->fileheader.signature,"BM");					//Assigning values of header bit wise
    	imgbitmap->fileheader.filesize = imgStructData->size+sizeof(bitmap);
    	imgbitmap->fileheader.fileoffset_to_pixelarray = sizeof(bitmap);
    	imgbitmap->bitmapinfoheader.dibheadersize =sizeof(bitmapinfoheader);
    	imgbitmap->bitmapinfoheader.width = imgStructData->width;
    	imgbitmap->bitmapinfoheader.height = imgStructData->height;
    	imgbitmap->bitmapinfoheader.planes = Num_planes;
    	imgbitmap->bitmapinfoheader.bitsperpixel = imgStructData->bitsPerPixel;
    	imgbitmap->bitmapinfoheader.compression = Compression;
    	imgbitmap->bitmapinfoheader.imagesize = imgStructData->size;
    	imgbitmap->bitmapinfoheader.y_res_PixelsPerMeter = Y_res_PixelsPerMeter;
    	imgbitmap->bitmapinfoheader.y_res_PixelsPerMeter = X_res_PixelsPerMeter;
    	imgbitmap->bitmapinfoheader.numcolorspallette = 0;
    	fwrite(imgbitmap, 1, sizeof(bitmap),fp);					//writing data(header values) of imgbitmap to the file opened in write mode 
	fwrite(imgStructData->data,1,imgStructData->size,fp);				//write image data to the file opened in write mode
    	fclose(fp);
    	free(imgbitmap);
}

void destroyImageFromMemory(Image_t *im){
	
	free(im);
}
