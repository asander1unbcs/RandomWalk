/* This program takes in a random number and generates a path from A-Z across a 2D array accordingly.
Author: Anne Sanderson 
Student no: 3564244
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomWalk(int n, int row, int col, int count, int a[n][n]);

int main () {
	int n;
	printf("How big is the grid?\n");
	scanf("%d", &n);
	//printf("n = %d\n", n);
	int a[n][n];
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			a[row][col] = '.';
		}
	}
	srand(time(NULL));
	randomWalk(n, 0, 0, 0, a); 
	printf("\nAnd here's what you've won!\n");
	for (int row = 0; row < n; row++){ //row
		for (int col = 0; col < n; col++) {//column
			printf("%c ", a[row][col]);
		}
		printf("\n");
	}
	return 1;
}

int randomWalk(int n, int row, int col, int count, int a[][n]) {
	int r = (rand()%4) + 1;
	//printf("%c going %d... \n", a[row][col], r);
		if (count < 26) {
			//DEBUG STUFF
			/*
			if((col+1 < n && a[row][col+1] != '.') || (col+1 >= n && a[row][0] != '.')){
				printf("Can't go right\n");
			}
			else{
				printf("CAN go right\n");
			}
			
			if((col - 1 >= 0 && a[row][col-1] != '.') || (col-1 < 0 && a[row][n-1] != '.')){
				printf("Can't go left\n");
			}
			else{
				printf("CAN go left\n");
			}
			
			if((row + 1 < n && a[row+1][col] != '.') || (row + 1 >= n && a[0][col] != '.')){
				printf("Can't go down\n");
			}
			else{
				printf("CAN go down\n");
			}
			
			if((row - 1 >= 0 && a[row-1][col] != '.') ||  (row - 1 < 0 && a[n-1][col] != '.')){
				printf("Can't go up\n");
			}
			else{
				printf("CAN go up\n");
			}
			*/
			//DEBUG STUFF ENDS
			if (a[row][col] <= '.') {
					a[row][col] = 'A' + count;
					//printf("becomes %c \n", a[row][col]);
			}
			
			if (((col+1 < n && a[row][col+1] != '.') || (col+1 >= n && a[row][0] != '.')) && ((col - 1 >= 0 && a[row][col-1] != '.') || (col-1 < 0 && a[row][n-1] != '.')) && ((row + 1 < n && a[row+1][col] != '.') || (row + 1 >= n && a[0][col] != '.')) && ((row - 1 >= 0 && a[row-1][col] != '.') ||  (row - 1 < 0 && a[n-1][col] != '.'))){				
				printf("Congrats, %c, you played yourself\n", ('A' + count));
				return 1;
			} 
			else{
				switch(r) {		
					case 1: 
						if (col+1 < n && a[row][col+1] == '.' ) { //go right & don't wrap	
							//printf("Going right\n");
							if (randomWalk(n, row, col+1, ++count, a) ){
								return 1;
							}	
							break;
						}
						else if (col+1 >= n && a[row][0] == '.') { //go right and DO wrap	
							//printf("Wrapping right\n");	
							if (randomWalk(n, row, 0, ++count, a) ){
								return 1;
							}
							break;
						}
						else{
							if (randomWalk(n, row, col, count, a) ){
								return 1;
							}
							break;
						}
							
					case 2:
						if (col-1 >= 0 && a[row][col-1] == '.') { //go left & don't wrap
							//printf("Going left\n");
							if (randomWalk(n, row, col-1, ++count,a) ){
								return 1;
							}	
							break;
						}
						else if (col-1 < 0 && a[row][n-1] == '.') { //go left and DO wrap	
							//printf("Wrapping left\n");
							if (randomWalk(n, row, n-1, ++count,a) ){
								return 1;
							}
							break;		
						}
						else{
							if (randomWalk(n, row, col, count, a) ){
								return 1;
							}
							break;
						}
						
					case 3:	
						if (row+1 < n && a[row+1][col] == '.') { //go down & don't wrap	
							//printf("Going down\n");
							if (randomWalk(n, row+1, col, ++count,a) ){
								return 1;
							}
							break;
						}
						else if (row+1 >= n && a[0][col] == '.') { //go down and DO wrap	
							//printf("Wrapping down\n");
							if (randomWalk(n, 0, col, ++count,a) ){
								return 1;
							}
							break;
						}
						else{
							if (randomWalk(n, row, col, count, a) ){
								return 1;
							}
							break;
						}
						
					case 4:	
						if (row-1 >= 0 && a[row-1][col] == '.') { //go up & don't wrap
							//printf("Going up\n");
							if (randomWalk(n, row-1, col, ++count,a) ){
								return 1;
							}	
							break;
						}
						else if (row-1 < 0 && a[n-1][col] == '.') { //go up and DO wrap	
							//printf("Wrapping up\n");
							if (randomWalk(n, n-1, col, ++count,a) ){
								return 1;
							}
							break;
						}
						else{
							if (randomWalk(n, row, col, count, a) ){
								return 1;
							}
							break;
						}	
				}
			}
			
		
	}
	//printf("a[row][col] = %c, r = %d\n", a[row][col], r);	
	return 0;
}	 
			
	
	 

