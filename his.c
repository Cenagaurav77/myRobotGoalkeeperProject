#include<stdio.h>
#include "his.h"
int getHistogram(const char* imgName, int channel, int binSize, Histogram_t* histogram){

	printf("Hey");
	FILE *fp = fopen(imgName, "rb");	
	unsigned char header[54];
    	fread(header, sizeof(unsigned char), 54, fp);

	int magicIdent1 = header[0];
	int magicIdent2 = header[1];
	int width = header[18];
    	int height = header[22];
	int size = header[34];
	int stride = (width*channel)+(width%4);					//channel used for stride

	unsigned char data1[size];
	fread(data1, sizeof(unsigned char), size, fp);

	histogram->frequency = 0;						//Histogram_t reference variable used to access Histogram_t member
    	int blue[height][width];						//channel 1 array declaration
    	int green[height][width];						//channel 2 array declaration
    	int red[height][width];							//channel 3 array declaration
    	int image2DArray[height][stride];					//2D array of image data
	int index = 0;            

    	for(int i=0; i<height; i++){
		for (int j=0; j<stride; j++){
			image2DArray[i][j] = data1[index];			//Transferring image data stored in 1D array to 2D array
            		index++;
        	}
    	}
    	printf("\n");

// blue color
	printf("Histogram of blue color,");					//Channel 1
	int countB;    
    	for(int i=0; i<height; i++){						//Adding elements to the blue array
		countB=0;
		for(int j=0; j<stride; j+=3){
			blue[i][countB] = image2DArray[i][j];			//Image pixel data transferred to blue channel array
			countB++;
		}
    	}
	for(int l=0; l<binSize; l++){						//binSize used
		histogram->frequency=0;						//Frequency of pixel data refreshed to 0 everytime for new pixel
    		for(int i=0; i<height; i++){
			for(int j=0; j<width; j++){
				if(l == blue[i][j]){
					histogram->frequency++;			//Frequency count
				}
			}
    		}
		if(l%21==0){
			printf("\n");
		}
		printf("%d:%d  ",l,histogram->frequency);			//Printing pixel data and its frequency
	}
    	printf("\n");
	printf("\n");
  
//green color
	printf("Histogram of green color,");					//Channel 2
    	int countG;
    	for(int i=0; i<height; i++){						//Adding elements to the green array
		countG=0;
		for(int j=1; j<stride; j+=3){
			green[i][countG] = image2DArray[i][j];			//Image pixel data transferred to green channel array
			countG++;
		}
    	}
    	for(int l=0; l<binSize; l++){						//binSize used
		histogram->frequency=0;						//Frequency of pixel data refreshed to 0 everytime for new pixel
    		for(int i=0; i<height; i++){
			for(int j=0; j<width; j++){
				if(l == green[i][j]){
					histogram->frequency++;			//Frequency count
				}
			}
    		}
		if(l%21==0){
			printf("\n");
		}
		printf("%d:%d  ",l,histogram->frequency);			//Printing pixel data and its frequency
	}
    	printf("\n");
	printf("\n");

//red color
	printf("Histogram of red color,");					//Channel 3
	int countR;
    	for(int i=0; i<height; i++){						//Adding elements to the green array
		countR=0;
		for(int j=2; j<stride; j+=3){
			red[i][countR] = image2DArray[i][j];			//Image pixel data transferred to red channel array
			countR++;
		}
    	}
    	for(int l=0; l<binSize; l++){						//binSize used
		histogram->frequency=0;						//Frequency of pixel data refreshed to 0 everytime for new pixel
    		for(int i=0; i<height; i++){
			for(int j=0; j<width; j++){
				if(l == red[i][j]){
					histogram->frequency++;			//Frequency count
				}
			}
    		}
		if(l%21==0){
			printf("\n");
		}
		printf("%d:%d  ",l,histogram->frequency);			//Printing pixel data and its frequency
	}
	printf("\n");
	if(magicIdent1 == 66 && magicIdent2 == 77){				//Authentication of a file
		return 0;
	}else{
		return -1;
	}
}