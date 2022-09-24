#include<bits/stdc++.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <graphics.h>
#include <windows.h>
#include "mmsystem.h"
#include <iostream>
using namespace std;

#define MAX_M 100
#define MAX_N 100
// Permanent data type (unchange).
enum facing {   
	LEFT , RIGHT , UP , DOWN , STAY
};

int puzzle[3][3] , posX , posY , checker , cost;

// node -> data elements and linking components.
class node{ 
	public :
		int arr[3][3] , x , y , f;
		string way; /// count the number of moves.
		facing canFace;
		node(int a[3][3] , string way , facing canFace , int x , int y , int f){
//// pointer 'this' 

			this->f = f;
			this->way = way;
			this->canFace = canFace;
			this->x = x;
			this->y = y;
			for ( int i = 0; i < 3; i++){
				for ( int j = 0; j < 3; j++){
					arr[i][j] = a[i][j];
				}
			}
		}
		
		bool canMoveLeft(){
			return canFace != LEFT && y > 0 && cost > herStic();
		}
		bool canMoveRight(){
			return canFace != RIGHT && y < 2 && cost > herStic();
		}
		bool canMoveUp(){
			return canFace != UP && x > 0 && cost > herStic();
		}
		bool canMoveDown(){
			return canFace != DOWN && x < 2 && cost > herStic();
		}
		
		int herStic(){
			int sum = 0;
			if(checker == 1){
				if(arr[0][0] != 1) sum++;
				if(arr[0][1] != 2) sum++;
				if(arr[0][2] != 3) sum++;	//  1 2 3
				if(arr[1][0] != 8) sum++;	//  8   4
				if(arr[1][2] != 4) sum++;	//  7 6 5
				if(arr[2][0] != 7) sum++;
				if(arr[2][1] != 6) sum++;
				if(arr[2][2] != 5) sum++;
			}else{
				if(arr[0][1] != 1) sum++;
				if(arr[0][2] != 2) sum++;
				if(arr[1][0] != 3) sum++;	//  1 2
				if(arr[1][1] != 4) sum++;	//	3 4 5
				if(arr[1][2] != 5) sum++;	//	6 7 8
				if(arr[2][0] != 6) sum++;
				if(arr[2][1] != 7) sum++;
				if(arr[2][2] != 8) sum++;
			}
			return sum + f;
		}
		
		void moveLeft(){
			swap(arr[x][y] , arr[x][y-1]);
			y--;
			canFace = RIGHT;
			way += "l";
			f++;
		}
		void moveRight(){
			swap(arr[x][y] , arr[x][y+1]);
			y++;
			canFace = LEFT;
			way += "r";
			f++;
		}
		void moveUp(){
			swap(arr[x][y] , arr[x-1][y]);
			x--;
			canFace = DOWN;
			way += "u";
			f++;
		}
		void moveDown(){
			swap(arr[x][y] , arr[x+1][y]);
			x++;
			canFace = UP;
			way += "d";
			f++;
		}
		
		bool checkFinish(){
			if(checker == 1){
				for ( int i = 0; i < 3; i++){
					if(arr[0][i] != i+1 || arr[2][i] != 7-i) return false;
				}
				return arr[1][0] != 8 || arr[1][2] != 4 ? false : true;
			}else{
				for ( int i = 0; i < 3; i++){
					if(arr[0][i] != i || arr[1][i] != i+3 || arr[2][i] != i+6) return false;
				}
				return true;
			}
			
		}
};


void moveLeft(){
	swap(puzzle[posX][posY] , puzzle[posX][posY-1]);
	posY--;
}
void moveRight(){
	swap(puzzle[posX][posY] , puzzle[posX][posY+1]);
	posY++;
}
void moveUp(){
	swap(puzzle[posX][posY] , puzzle[posX-1][posY]);
	posX--;
}
void moveDown(){
	swap(puzzle[posX][posY] , puzzle[posX+1][posY]);
	posX++;
}

////   Get the value from S[i][j] and move those value to puzzle[i][j]
////   Get the MAXIMUM cost of auto solve algorithm.
////   Check whether the value of puzzle[i][j] is valid or not.

void initPuzzle(State *S){
	int i,j;

for ( i = 0; i < S->m; i ++){
		for ( j = 0; j < S->n; j ++){
			puzzle[i][j] = S->A[i][j]-1;
			cout << puzzle[i][j]+1 << " ";
		}
		cout << endl;
	}
//	fclose(f);
	cout << "Enter the maximum cost of algorithm (50)"<<endl;
	cost = 50;
	
	bool checked = true;
	int sum = 0;
	for ( int i = 0; i < 3; i++){
		for ( int j = 0; j < 3; j++){
			sum += puzzle[i][j];
			
// If the value is higher than 8 ( 9 in screen display ) -> break;
			if(puzzle[i][j] > 8) {
				checked = false;
				break;
			}
		}
	}
// The sum of all value must be 36 (int 3x3 mode). If not, return to initPuzzle.	
	if(sum != 36 || checked == false){
		cout << endl<<"Invalid input, please try again." << endl;
		return initPuzzle(&*S);
	}
	
// Get the coordinate of 0 in array puzzle.
	for ( int i = 0; i < 3; i++){
		for ( int j = 0; j < 3; j++){
			if(puzzle[i][j] == 0){
				posX = i;
				posY = j;
				return;
			}
		}
	}
}

///  Display the puzzle game (not in BGI window) for testing.
void prin(){
	for ( int i = 0; i < 3; i++){
		for ( int j = 0; j < 3; j++){	
			cout << puzzle[i][j] << " ";
		}
		cout << endl;
	}
}
		
		
bool checkFinish(){
	int counter1 = 0, counter2 = 0;
	
//	for ( int j = 0; j < 3; j++){
//		if(puzzle[0][j] == j+1) counter1++;     //  1 2 3 
//	}
//	
//	for ( int j = 0; j < 3; j++){				//  1 2 3
//		if(puzzle[2][j] == 7-j) counter1++;     // 
//	}											//  7 6 5
//	
//	
//	if(puzzle[1][0] == 8){						//  1 2 3
//		counter1++;								//  8
//	} 											//  7 6 5
//	
//	
//	if(puzzle[1][2] == 4) {						//  1 2 3
//		counter1++;								//  8   4
//	}											//  7 6 5
//	if(counter1 == 8) return true;////true
		
		
	for ( int i = 0; i < 3; i++){
		if(puzzle[0][i] == i) counter2++;		//  0 1 2
		if(puzzle[1][i] == i+3) counter2++;		//  3 4 5
		if(puzzle[2][i] == i+6) counter2++;		//  6 7 8
	}
	if(counter2 == 8) return true;
	return false;
}


int countStart(){
//	2 4 5
//	1 8 7
//	6 3 ..
	int sum = 0;
	for ( int q = 0; q < 8; q ++){
		int row = q / 3;
		int col = q % 3;
		int counter = puzzle[row][col];

		for ( int i = 0; i < 3; i++){
			for ( int j = 0; j < 3; j++){
				if( (i > row && counter > puzzle[i][j] && puzzle[i][j] != 0 )  ){
					sum++;
				} else if(row == i && j > col && puzzle[i][j] < counter && puzzle[i][j] != 0){
					sum++;
				}
			}
		}
	}
	return sum;
}
