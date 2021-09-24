#include<stdio.h>
#include<stdlib.h>

#define SAMPLE_NO 10
// function that finds the slope according to given values 
float findSlope(float x1, float y1, float x2, float y2){
	if(x1 == x2){
		return (y2 - y1) / (0.000001);
	}
	else{
		return (y2 - y1) / (x2 - x1);
	}
    									
}
// function that determines the class 
int whichClass(float x, float y, float x1, float y1, float x2, float y2){
	float d;
	d=(x-x1)*(y2-y1)-(y-y1)*(x2-x1);
	
	if(d<0){
		return 1;									// function finds the side of entering (x,y) coordinates according to given formula
			}										//we will check whether it belongs class 1 or class 2 in last while loop of the program
		
	if(d>0){
		return 2;
	}
}


int main(){
	int i;
	float xsum,ysum,x,y,xavg1,yavg1,xavg2,yavg2,xmid,ymid,slope,yFin,inputX,inputY; // xsum:Sum of the x coordinates in class 1, 
	//ysum:Sum of the x coordinates in class 1 
	                                                                                  
	
	for(i=0; i<SAMPLE_NO; i++){
		printf("Enter %d .sample coordinates in Class 1 : \n",i+1);
		
		scanf("%f %f",&x,&y);
		xsum = xsum + x;				// taking x inputs for class 1 , adding them each other and assigning to xsum
		ysum = ysum + y;                // taking y inputs for class 1 , adding them each other and assigning to ysum
	}
	
	xavg1 = xsum / SAMPLE_NO ;
	yavg1 = ysum / SAMPLE_NO ;			// we find the middle point of the samples belong to Class 1 (xavg1,yavg1)
	
	xsum = 0;
	ysum = 0;							// we make xsum and ysum zero because we will use it in class2 to sum x and y coordinates which belong to Class2
	
	for(i=0; i<SAMPLE_NO; i++){
		printf("Enter %d .sample coordinates in Class 2 : \n",i+1);		
		scanf("%f %f",&x,&y);
		xsum = xsum + x; 				// taking x,y inputs for class 1 , adding them each other and assigning to xsum and ysum
		ysum= ysum + y;
	}
	
	xavg2 = xsum / SAMPLE_NO ;			// we find the middle point of the samples belong to Class 2 (xavg2,yavg2)
	yavg2 = ysum / SAMPLE_NO ;		
	
	xmid = (xavg1 + xavg2)/2;
	ymid = (yavg1 + yavg2)/2;			// finding the middle point (xmid,ymid) of the line that unites points which are (xavg1,yavg1) and (xavg2,yavg2)
	
		// finding the slope of the line that unites the middle points 
 //	((the slope of the seperating line will be (-1)*(1/slope) because they are perpendicular to each other))
	
	slope = findSlope(xavg1,yavg1,xavg2,yavg2);
	
	   //	We have to find two more for comparing with user's input and using whichClass function 
	//so that we will use the formula  y-y1 = m(x-x1) to find one more point except middle point by putting 0 to formula.

	
		yFin = ( (-1)*(1/slope) )*(0 - xmid) + ymid;
	
	while(1){
		printf("Enter the test coordinates \n");
		if (scanf("%f %f",&inputX,&inputY)== 2 ){
			
			if(whichClass(inputX,inputY,xmid,ymid,0,yFin) == whichClass(xavg1,yavg1,xmid,ymid,0,yFin)){		//if entered point in the same side with (xavg1,yavg1) it means it is in the class 1 as well
			printf("Class 1 \n");	
			}
			else{
			printf("Class 2 \n");		// we assume that entered coordinates will be on the line so we can say if it is not in class 1 
		 								//then it is in class 2			
				}		
		}
		else {
			return -1;		// Exit from the program
		}
	} 
	
	

		
	return 0;
}
