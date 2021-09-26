#include <stdlib.h>
#include <stdio.h>
#define p1 0.5
#define p2 20
int main(){

	int isitFirst;
	float a=0,b,n,count,sum=0;


	FILE *fp1,*fp2;
	fp1=fopen("input.txt","r");
	fp2=fopen("output.txt","w");
		
	if ((fp1==NULL || fp2==NULL))
		{
        	printf("Error occured during opening the files\n");			// Checking of opening files
        	exit (1);         
		}	
		
	isitFirst = 1;											// At the first time, file operations have to be done 
		 
	while(!(feof(fp1))){
		if(isitFirst){
			fscanf(fp1,"%f ",&a);						// if the file operations done at the first time then "a" will be the first value to be read
			fprintf(fp2,"%.4f ",a);						// n will be the second value to be read
			fscanf(fp1,"%f ",&n);
			sum+=a;
			}
		else{											
			sum += a;									
														// if the file operations have not done at the first time , then last read n value which is not confirm to condition	
														// will be executed as first value which is "a" 
														
			fscanf(fp1,"%f ",&n);						// at the last loop we assign n to a
			}
		b= (a + n) / 2;
		count = 1;
								
		while (!(b > a*(1+p1) || b < a*(1-p1) || a > n*p2 || a < n/p2) && !feof(fp1) )	
			{  
			sum += n;
			count++;												
			a = sum / count;										//  if the last read "n" could satisfy the given condition and the program does not reach the EOF
																	//	then continue to read and add it to the avarage value which is "a"
			fprintf(fp2,"%.4f ",n);					                
			fscanf(fp1,"%f ",&n);			
			b = (sum+n)/(count+1);				 
					
			}
				
		if(!(b > a*(1+p1) || b < a*(1-p1) || a > n*p2 || a < n/p2)){
			
			fprintf(fp2,"%.4f Average: %.4f ",n,b);						//if the program did exit because EOF,but the last "n" value satisfies the condition then print "n" and "b"
			
			}
		else{
			
			fprintf(fp2," Average: %.4f \n%.4f ",a,n);					// if it doesnt satisfy the condition then print avarage and switch to new line then print "n"
			sum =0;
			a = n;														// if the n does not meet the given condition, it will be the first value in the
																		// new line so we assign "n" to the "a"
																		
			isitFirst = 0;													// we assign 0 to firstTime to indicate we entered the loop before
			
			}				
		}
	
		fclose(fp1);
		fclose(fp2);
	
		return 0;
}
	
	
