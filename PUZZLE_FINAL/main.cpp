#include <bits/stdc++.h>
#include <stdio.h>
#include <time.h>
#include <graphics.h>
#include <windows.h>
#include "mmsystem.h"
#include <iostream>
using namespace std;

#include <cstdlib>
#include <unistd.h>

#define MAX_M 100
#define MAX_N 100
int puzzle[3][3];

typedef struct{
	int m, n;
	int A[MAX_M][MAX_N];
	int r, c;
} State;


void init_state(State *S, char *fname){
	FILE *f;
	f=fopen(fname,"r");
	fscanf(f,"%d %d", &S->m, &S->n);
	for(int i = 0; i < S->m; i++)
		for(int j = 0; j < S->n; j++)
			fscanf(f,"%d", &S->A[i][j]);
	fscanf(f,"%d %d", &S->r, &S->c);
	fclose(f);
}



void print_state(State *S,int g,int pic, int puzzle[3][3], int autosolve){
	
//// If autosolve = 1, add all the value from S to array puzzle	
	if (autosolve == 1){
		for ( int i = 0; i < S->m; i ++){
			for ( int j = 0; j < S->n; j ++){
				S->A[i][j] = puzzle[i][j]; 
			}
		}
	}
//// Adjust the size of blocks
	int left,top,right,bottom,s,size;

	if ( g == 80 ){
		left=145, top=140, right=225, bottom=220;
		s=83;
		size =5;
	} else if ( g == 60){
		left=110, top=125, right=190, bottom=205;
		s = 83;
		size=5;
	} else if (g == 100){
		left=675, top=140, right=755, bottom=220;
		s=83;
		size =5;
	}
	
	for(int i=0; i < S->m; i++){
		for(int j=0; j < S->n; j++){
			settextstyle(8, 0, size);
				if( (autosolve == 0 && i == S->r && j == S->c) || (autosolve == 1 && S->A[i][j] == 9) ){
					setcolor(WHITE);
					setfillstyle(SOLID_FILL, BLACK);
					bar(left, top, right+3, bottom+3);
				}
			
			else if(S->A[i][j] == 1){
				if ( pic != 1){
					setcolor(BLACK);
					setfillstyle(SOLID_FILL, CYAN);	
					bar(left, top, right, bottom);							
					setbkcolor(CYAN);
					outtextxy(left+25, top+20, "1");
				}
				if ( pic == 1){
					if (g == 80 || g==100){
						readimagefile("xinloithay1_3x3.jpg", left,top,right+2,bottom+2);
					} else if (g == 60){
						readimagefile("xinloithay1_4x4.jpg", left,top,right+2,bottom+2);						
					}
				}
			}
			else if(S->A[i][j]==2){
				if ( pic != 1){
					setcolor(BLACK);
					setfillstyle(SOLID_FILL, CYAN);	
					bar(left, top, right, bottom);							
					setbkcolor(CYAN);
					outtextxy(left+25, top+20, "2");
				}
				if ( pic == 1){
					if (g == 80|| g==100){
						readimagefile("xinloithay2_3x3.jpg", left,top,right+2,bottom+2);
					} else if (g == 60){
						readimagefile("xinloithay2_4x4.jpg", left,top,right+2,bottom+2);						
					}
				}
			}		
			else if(S->A[i][j]==3){
				if ( pic != 1){
					setcolor(BLACK);
					setfillstyle(SOLID_FILL, CYAN);	
					bar(left, top, right, bottom);							
					setbkcolor(CYAN);
					outtextxy(left+25, top+20, "3");
				}
				if (pic == 1){
					if (g == 80|| g==100){
						readimagefile("xinloithay3_3x3.jpg", left,top,right+2,bottom+2);
					} else if (g == 60){
						readimagefile("xinloithay3_4x4.jpg", left,top,right+2,bottom+2);						
					}
				}
			}	
			else if(S->A[i][j]==4){
				if ( pic != 1){
					setcolor(BLACK);
					setfillstyle(SOLID_FILL, CYAN);	
					bar(left, top, right, bottom);							
					setbkcolor(CYAN);
					outtextxy(left+25, top+20, "4");
				}
				if (pic == 1){
					if (g == 80|| g==100){
						readimagefile("xinloithay4_3x3.jpg", left,top,right+2,bottom+2);
					} else if (g == 60){
						readimagefile("xinloithay4_4x4.jpg", left,top,right+2,bottom+2);						
					}
				}
			}			
			else if(S->A[i][j]==5){
				if ( pic != 1){
					setcolor(BLACK);
					setfillstyle(SOLID_FILL, CYAN);	
					bar(left, top, right, bottom);							
					setbkcolor(CYAN);
					outtextxy(left+25, top+20, "5");
				}
				if (pic == 1){
					if (g == 80|| g==100){
						readimagefile("xinloithay5_3x3.jpg", left,top,right+2,bottom+2);
					} else if (g == 60){
						readimagefile("xinloithay5_4x4.jpg", left,top,right+2,bottom+2);						
					}
				}	
			}
			else if(S->A[i][j]==6){
				if ( pic != 1){
					setcolor(BLACK);
					setfillstyle(SOLID_FILL, CYAN);	
					bar(left, top, right, bottom);							
					setbkcolor(CYAN);
					outtextxy(left+25, top+20, "6");
				}
				if (pic == 1){
					if (g == 80|| g==100){
						readimagefile("xinloithay6_3x3.jpg", left,top,right+2,bottom+2);
					} else if (g == 60){
						readimagefile("xinloithay6_4x4.jpg", left,top,right+2,bottom+2);						
					}
				}
			}
			else if(S->A[i][j]==7){
				if ( pic != 1){
					setcolor(BLACK);
					setfillstyle(SOLID_FILL, CYAN);	
					bar(left, top, right, bottom);							
					setbkcolor(CYAN);
					outtextxy(left+25, top+20, "7");
				}
				if (pic == 1){
					if (g == 80|| g==100){
						readimagefile("xinloithay7_3x3.jpg", left,top,right+2,bottom+2);
					} else if (g == 60){
						readimagefile("xinloithay7_4x4.jpg", left,top,right+2,bottom+2);						
					}
				}
			}
			else if(S->A[i][j]==8){
				if ( pic != 1){
					setcolor(BLACK);
					setfillstyle(SOLID_FILL, CYAN);	
					bar(left, top, right, bottom);							
					setbkcolor(CYAN);
					outtextxy(left+25, top+20, "8");
				}
				if (pic == 1){
					if (g == 80|| g==100){
						readimagefile("xinloithay8_3x3.jpg", left,top,right+2,bottom+2);
					} else if (g == 60){
						readimagefile("xinloithay8_4x4.jpg", left,top,right+2,bottom+2);						
					}
				}
			}
			else if(S->A[i][j]==9){
				if ( pic != 1){
					setcolor(BLACK);
					setfillstyle(SOLID_FILL, CYAN);	
					bar(left, top, right, bottom);							
					setbkcolor(CYAN);
					outtextxy(left+25, top+20, "9");
				}
				if (pic == 1){
					if (g == 80|| g==100){
						readimagefile("xinloithay9_3x3.jpg", left,top,right+2,bottom+2);
					} else if (g == 60){
						readimagefile("xinloithay9_4x4.jpg", left,top,right+2,bottom+2);						
					}
				}
			}
			else if(S->A[i][j]==10){
				if ( pic != 1){
					setcolor(BLACK);
					setfillstyle(SOLID_FILL, CYAN);	
					bar(left, top, right, bottom);							
					setbkcolor(CYAN);
					outtextxy(left+15, top+20, "10");
				}
				if ( pic == 1){
					if (g == 60){
						readimagefile("xinloithay10_4x4.jpg", left,top,right+2,bottom+2);
					}
				}
			}
			else if(S->A[i][j]==11){
				if ( pic != 1){
					setcolor(BLACK);
					setfillstyle(SOLID_FILL, CYAN);	
					bar(left, top, right, bottom);							
					setbkcolor(CYAN);
					outtextxy(left+15, top+20, "11");
				}
				if ( pic == 1){
					if (g == 60){
						readimagefile("xinloithay11_4x4.jpg", left,top,right+2,bottom+2);
					}
				}
			}
			else if(S->A[i][j]==12){
				if ( pic != 1){
					setcolor(BLACK);
					setfillstyle(SOLID_FILL, CYAN);	
					bar(left, top, right, bottom);							
					setbkcolor(CYAN);
					outtextxy(left+15, top+20, "12");
				}
				if ( pic == 1){
					if (g == 60){
						readimagefile("xinloithay12_4x4.jpg", left,top,right+2,bottom+2);
					}
				}
			}
			else if(S->A[i][j]==13){
				if ( pic != 1){
					setcolor(BLACK);
					setfillstyle(SOLID_FILL, CYAN);	
					bar(left, top, right, bottom);							
					setbkcolor(CYAN);
					outtextxy(left+15, top+20, "13");
				}
				if ( pic == 1){
					if (g == 60){
						readimagefile("xinloithay13_4x4.jpg", left,top,right+2,bottom+2);
					}
				}
			}
			else if(S->A[i][j]==14){
				if ( pic != 1){
					setcolor(BLACK);
					setfillstyle(SOLID_FILL, CYAN);	
					bar(left, top, right, bottom);							
					setbkcolor(CYAN);
					outtextxy(left+15, top+20, "14");
				}
				if ( pic == 1){
					if (g == 60){
						readimagefile("xinloithay14_4x4.jpg", left,top,right+2,bottom+2);
					}
				}
			}
			else if(S->A[i][j]==15){
				if ( pic != 1){
					setcolor(BLACK);
					setfillstyle(SOLID_FILL, CYAN);	
					bar(left, top, right, bottom);							
					setbkcolor(CYAN);
					outtextxy(left+15, top+20, "15");
				}
				if ( pic == 1){
					if (g == 60){
						readimagefile("xinloithay15_4x4.jpg", left,top,right+2,bottom+2);
					}
				}
			}
			else if(S->A[i][j]==16){
				if ( pic != 1){
					setcolor(BLACK);
					setfillstyle(SOLID_FILL, CYAN);	
					bar(left, top, right, bottom);							
					setbkcolor(CYAN);
					outtextxy(left+15, top+20, "16");
				}
				if ( pic == 1){
					if (g == 60){
						readimagefile("xinloithay16_4x4.jpg", left,top,right+2,bottom+2);
					}
				}
			}
			left+=s;
			right+=s;
		}
		left-=s*S->n;
		right-=s*S->n;
		top+=s;
		bottom+=s;
	}
}


int is_finished(State S){
	for(int i=0; i < S.m; i++)
	    for(int j=0; j <S.n; j++)
			if(S.A[i][j] != i*S.n +j+1){
				return 0;
				break;
			}
	return 1;
}


int up(State S, State *N){
	*N= S;
	if (N->r == 0){
		return 0;
	} else { 
		N->A[N->r][N->c] = N->A[N->r-1][N->c];
		N->A[N->r-1][N->c] = N->m * N->n;
		(N->r)--;
		return 1;
	}
}


int down(State S, State *N){
	*N= S;
	if (N->r == N->m -1){
		return 0;
	} else { 
		N->A[N->r][N->c] = N->A[N->r+1][N->c];
		N->A[N->r+1][N->c] = N->m * N->n;
		(N->r)++;
		return 1;
	}
}


int left(State S, State *N){
	*N= S;
	if (N->c == 0 ){
		return 0;
	} else { 
		N->A[N->r][N->c] = N->A[N->r][N->c-1];
		N->A[N->r][N->c-1] = N->m * N->n;
		(N->c)--;
		return 1;
	}
}


int right(State S, State *N){
	*N= S;
	if (N->c == N->m -1 ){
		return 0;
	} else { 
		N->A[N->r][N->c] = N->A[N->r][N->c+1];
		N->A[N->r][N->c+1] = N->m * N->n;
		(N->c)++;
		return 1;
	}
}


void restartbutton(){
	
	setcolor(RED);
	setfillstyle(SOLID_FILL,RED );
  	bar(420, 19, 510, 42 );
  	setbkcolor(RED);
	setcolor(WHITE);
  	settextstyle(8,0, 1);
  	outtextxy(430,21 , "ESCAPE");
}


int click_menu2(int autosolve){
	int x, y;
	if (autosolve ==0){
		while (1){
        	delay(0.00001);
			if (ismouseclick(WM_LBUTTONDOWN)){
            	getmouseclick(WM_LBUTTONDOWN, x, y);
            	cout << "x = " << x << ", y = " << y <<endl; 
            //// PUZZLE WITHOUT IMAGE
            	if ( x >= 175 && x <= 360 && y >= 145 && y <= 230 ){
            		PlaySound(TEXT("easymodesound.wav"),NULL,SND_SYNC);
            		return 80;
        			break;
        	//// PUZZLE WITH IMAGE 
    			} else if (x >= 160 && x <= 370 && y >= 260 && y <= 345){
    				PlaySound(TEXT("mediummodesound.wav"),NULL,SND_SYNC);
    				return 60;
    				break;
    		//// EXIT BUTTON_CLICK
				} else if ( x >= 233 && x <= 300 && y >= 508 && y <= 538){
					PlaySound(TEXT("menusound.wav"),NULL,SND_SYNC);
					exit(0);
			//// BACK TO PREVIOUS MENU
				} else if ( x >= 230 && x <= 300 && y >= 470 && y <= 495){
					PlaySound(TEXT("menusound.wav"),NULL,SND_ASYNC);
					return 1000;
				}
			}
		}
	} else {
		while (1){
        	delay(0.00001);
			if (ismouseclick(WM_LBUTTONDOWN)){
	           	getmouseclick(WM_LBUTTONDOWN, x, y);
	           	cout << "x = " << x << ", y = " << y <<endl;
	        ///// 3X3 AUTO SOLVE WITHOUT IMAGES
	           	if ( x >= 110 && x <= 455 && y >= 180 && y <= 235 ){
					PlaySound(TEXT("mediummodesound.wav"),NULL,SND_SYNC);
					return 100;
			///// 3X3 AUTO SOLVE WITH IMAGES
	        	} else if ( x >= 115 && x <= 450 && y >= 300 && y <= 350){
					PlaySound(TEXT("mediummodesound.wav"),NULL,SND_SYNC);
					return 101;
			///// EXIT BUTTON_CLICK
				}  else if ( x >= 230 && x <= 300 && y >= 470 && y <= 495){
					PlaySound(TEXT("menusound.wav"),NULL,SND_ASYNC);
					return 1000;
				}
			}
	    }
	}
}

int click_menu1(){
	int x, y;
		while (1){
        	delay(0.00001);
			if (ismouseclick(WM_LBUTTONDOWN)){
            	getmouseclick(WM_LBUTTONDOWN, x, y);
//  			cout << "x = " << x << ", y = " << y <<endl; 

            ///// PUZZLE GAME THAT CONTAIN NUMBERS ONLY
            	if ( x >= 125 && x <= 430 && y >= 155 && y <= 230 ){
            		PlaySound(TEXT("easymodesound.wav"),NULL,SND_ASYNC);
            		return 80;
        			break;
			///// PUZZLE GAME WITH IMAGE.
    			} else if (x >= 125 && x <= 430 && y >= 270 && y <= 355){
    				PlaySound(TEXT("easymodesound.wav"),NULL,SND_ASYNC);
    				return 60;
    				break;
    		///// EXIT BUTTON_CLICK
				} else if ( x >= 233 && x <= 300 && y >= 508 && y <= 538){
					PlaySound(TEXT("menusound.wav"),NULL,SND_SYNC);
					exit(0);
			///// AUTO SOLVE MODE
				} else if ( x >= 140 && x <= 400 && y >= 375 && y <= 450){
					PlaySound(TEXT("mediummodesound.wav"),NULL,SND_ASYNC);
					return 100;
				}
			}
		}
}


int click_pos(int x,int g){
/// Both 3x3 and 4x4 puzzles have the same size 
/// int g in this case can be used as size of puzzle
	if (g==60) g=80; 
	x /= g;
	x = x*g+g ;
	return x;
}

void restartbutton2(){
  	setbkcolor(RED);
	setcolor(WHITE);
  	settextstyle(8,0, 2);
  	outtextxy(215,305, "Play again");
}

void lose_theme_AS(int cnt){
	PlaySound(TEXT("lose_sound.wav"),NULL,SND_ASYNC);
	system("cls");
	cleardevice();
	readimagefile("testpic.jpg", 0,0,560,610);
	readimagefile("testpic - Copy.jpg", 560,0,1120,610);
	setcolor(RED);
	setbkcolor(BLACK);
	settextstyle(10, 0, 9);
	outtextxy(300, 200, "YOU LOSE!");
	setcolor(YELLOW);
	settextstyle(10, 0, 4);
	outtextxy(180, 300, "You moved more steps than autosolve did !");
	delay(5000);
}

void win_theme_AS(int cnt){
	cleardevice();
	system("cls");
	PlaySound(TEXT("victory.wav"),NULL,SND_ASYNC);
	readimagefile("testpic.jpg", 0,0,560,610);
	readimagefile("testpic - Copy.jpg", 560,0,1120,610);
	setcolor(GREEN);
	setbkcolor(BLACK);
	settextstyle(10, 0, 9);
	outtextxy(300, 200, "YOU WIN!");
	settextstyle(10, 0, 4);
	setcolor(YELLOW);
	outtextxy(180, 300, "You moved less steps than autosolve did !");
	delay(5000);
}

void win_theme(int cnt){
	
	cleardevice();
	readimagefile("wall2.jpg", 0,0,560,610);
	int x,y;
	setbkcolor(BLACK);
	settextstyle(10, 0, 8);
	setcolor(GREEN);
	outtextxy(100, 200, "YOU WIN!");
//// CONVERT INTEGER TO STRING
	char s[50];
	itoa(cnt,s,10);
	setcolor(GREEN);
	settextstyle( 10,0,3);						
	outtextxy(170,270,"Moved:");
	outtextxy(257,270,s);	
	outtextxy(293,270,"times.");
	restartbutton2();
	PlaySound(TEXT("victory.wav"),NULL,SND_ASYNC);
	while (1){
        delay(0.00001);
        
		if (ismouseclick(WM_LBUTTONDOWN)){
        	getmouseclick(WM_LBUTTONDOWN, x, y);
        	cout << endl << "x = " << x << ",y = "<<y<<endl;
        if ( x >= 215 && x <= 335 && y >= 305 && y <= 325){
			break;
			} 
		}
	}
}


int click_to_play(State *S,State N,int g,int cnt,int pic, int compare,int autosolve){
	
	setcolor(WHITE);
	setbkcolor(BLACK);
	setfillstyle(SOLID_FILL, BLACK);
	settextstyle(8,0,1);
	
	if ( g == 80){
		bar(80,430,505,455);
		outtextxy(80,435,"Press TAB to change to keypress mode");
	} else if ( g == 60){
		bar(70,490,500,525);
		outtextxy(85,500,"Press TAB to change to keypress mode");
	}
	
	int x, y, min_x, max_x, min_y, max_y,pc,pr,col,row;
	
	if ( g==80){	
		min_x = 145, max_x = 400, min_y = 160, max_y = 420;
	} else if ( g == 60){
		min_x = 110, max_x = 440, min_y = 150, max_y = 490;
	}
	cnt++; // count moved times

RES:	while (1){
        	delay(0.00001);

		//// left click	
	        if (ismouseclick(WM_LBUTTONDOWN)){
	            getmouseclick(WM_LBUTTONDOWN, x, y);
	            
	            if ( x >= min_x && x <= max_x && y >= min_y && y <= max_y ){
	            	cout << "left click " << x << " " << y << endl;	
					//// CONVERT NUMBER TO STRING 
					setcolor(WHITE);
					setbkcolor(BLACK);
					setfillstyle(SOLID_FILL, BLACK);
					settextstyle(8,0,1);
///// DISPLAY MOVED TIMES
					char s[100];
					itoa(cnt,s,10);
				
					if ( g == 80){	///// If in 3x3 mode
						if (cnt > compare && compare != 0){
							cout <<endl<< compare << endl;
							setcolor(YELLOW);
							outtextxy(290,400,s);
							outtextxy(220,400,"Moved:");
							setcolor(WHITE);
							
						} else {
							outtextxy(290,400,s);	
						}
					} else if ( g == 60){ ///// If in 4x4 mode.
						outtextxy(280,463,s);							
					}
//// Change coordinate x,y to specific numbers that easy for calculating	
	            	col = click_pos(x - min_x ,g) ;
					row = click_pos(y - min_y ,g) ;
	        ///// For both 3x3 and 4x4 mode 
	            	if ( g == 80 || g == 60){ 
		            	pr = (row/80)-1;
		            	pc = (col/80)-1;
		            } else {
		            	pr = (row/g)-1;
		            	pc = (col/g)-1;
					}
			/// for testing 
	            	cout << "c = " << col << "  r = " << row << ", row = " << pr <<" col = " << pc << endl;
	            }
	     ////// MOVING BLOCK     
				if (S->A[pr+1][pc] == S->A[S->r][S->c]){
					up(*S,&N);
					*S=N;
					cnt++;
				} else if (S->A[pr-1][pc] == S->A[S->r][S->c]){
					down(*S, &N);
					*S=N;
					cnt++;
				} else if (S->A[pr][pc+1] == S->A[S->r][S->c]){
					left(*S, &N);
					*S=N;
					cnt++;
				} else if (S->A[pr][pc-1] == S->A[S->r][S->c]){
					right(*S, &N);
					*S=N;
					cnt++;
				}
				print_state(&*S,g,pic,puzzle,0);
			}
			
////// PRESS TAB -> CLICK MODE
		if (GetAsyncKeyState(VK_TAB)){
			delay(200);
			return cnt;
		}
///// PRESS ESC TO GO BACK TO MENU 1
	else if ( GetAsyncKeyState(VK_ESCAPE)){
		usleep(200);
		PlaySound(TEXT("menusound.wav"),NULL,SND_ASYNC);
		return 0;
	} 

/////// FINISHED:			
			if(is_finished(*S)==1){
				return cnt;
			}
		}
		
}


void keypress_to_play(State S, State N, int g, int cnt,int pic, int compare, int autosolve){
	
REP:	
	setcolor(WHITE);
	settextstyle(8,0,1);
	setfillstyle(SOLID_FILL,BLACK);
	setbkcolor(BLACK);
	
//// CONVERT NUMBER TO STRING 
	char s[100];
	itoa(cnt,s,10);	
	
//// DISPLAY COUNT NUMBER DEPENDS ON GAME MODE	
	if ( g == 80){	
		if ( compare != 0 && cnt > compare){
			cout <<endl<< compare << endl;
			setcolor(YELLOW);
			outtextxy(220,400,"Moved:");
			outtextxy(290,400,s);
			setcolor(WHITE);
		} else {
			outtextxy(220,400,"Moved:");
			cout <<endl<<"Compare: "<< compare<<", cnt ="<<cnt << endl;
			outtextxy(290,400,s);
		}
			
	} else if ( g == 60){
		outtextxy(280,463,s);							
		outtextxy(210,463,"Moved:");	
		cout <<endl<<"Compare: "<< compare<<", cnt ="<<cnt << endl;

	}
/////// PRESS TAB TO CHANGE TO MOUSE CLICK MODE
	if ( g == 80){
		bar(80,430,505,455);
		outtextxy(90,435,"Press TAB to change to click mode");
	} else if ( g == 60){
		bar(70,490,500,525);
		outtextxy(90,500,"Press TAB to change to click mode");
	}

	print_state(&S,g,pic,puzzle,0);

	if (GetAsyncKeyState(VK_UP)){
		usleep(200);	
		if ( g == 80 && pic != 1) delay(200);
		if(down(S, &N)){
			down(S, &N);
			cnt++;
		}
		S=N;	
		print_state(&S,g,pic,puzzle,0);
		
	} else if (GetAsyncKeyState(VK_DOWN)){
		usleep(200);
		if ( g == 80 && pic != 1) delay(200);
		if(up(S, &N)){
			up(S, &N);
			cnt++;	
		}
		S=N;
		print_state(&S,g,pic,puzzle,0);
		
	} else if (GetAsyncKeyState(VK_LEFT)){
		usleep(200);
		if ( g == 80 && pic != 1) delay(200);
		if(right(S, &N)){
			right(S, &N);
			cnt++;
		} 
		S=N;	
		print_state(&S,g,pic,puzzle,0);
		
		
	} else if (GetAsyncKeyState(VK_RIGHT)){
		usleep(200);
		if ( g == 80 && pic != 1) delay(200);
		if(left(S, &N)){
			left(S, &N);
			cnt++;
		}
		S=N;
		print_state(&S,g,pic,puzzle,0);
		
		
////// INSTRUCTION IMAGE APPEARS WHEN PRESS i  ///ckjkjcnkjdcnkjcns
	} else if ( GetAsyncKeyState(105) && g == 80 && pic == 1){
		usleep(200);
			readimagefile("instruction.jpg", 144,139,393,388);
			delay(3000);
 
///// PRESS TAB TO CHANGE TO MOUSE CLICK MODE
	} else if (GetAsyncKeyState(VK_TAB)){
		delay(200);
		cnt =click_to_play(&S,N,g,cnt,pic,compare,autosolve);
		cnt--;
///// PRESS ESC TO GO BACK TO MENU 1
	} else if ( GetAsyncKeyState(VK_ESCAPE)){
		usleep(200);
		PlaySound(TEXT("menusound.wav"),NULL,SND_ASYNC);
		return;
	} 

///////// FINISHED
	if(is_finished(S)==1){
		delay(2000);
		print_state(&S,g,pic,puzzle,0);
		if (autosolve != 0){
			if (cnt <= compare) win_theme_AS(cnt);
			else lose_theme_AS(cnt);
			return;
		} 
		win_theme(cnt);
		return;
	}
	goto REP;	
}


int MENU1(int *g){
	
///////// EASY MODE
	setcolor(GREEN);
	settextstyle(10,0,4);
	setbkcolor(BLACK);
	outtextxy(135, 165, "ORIGINAL PUZZLE");
	settextstyle(8,0,2);
	outtextxy(195, 193, "with numbers");
	
/////////  MEDIUM MODE	
	setcolor(YELLOW);
	settextstyle(10,0,4);
	outtextxy(135, 280, "ORIGINAL PUZZLE");
	settextstyle(8,0,2);
	outtextxy(200, 310, "with pictures");
	
////////// PLAY WITH AUTOSOLVE ALROGITHM
	setcolor(RED);
	settextstyle(10,0,5);
	outtextxy(160, 380, "CHALLENGE");
	settextstyle(8,0,3);
	outtextxy(153, 417, "Play against bot");
	
///// EXIT GAME
	setcolor(RED);
	setfillstyle(SOLID_FILL,RED );
  	bar(233, 508, 300, 538 );
  	setbkcolor(RED);
	setcolor(WHITE);
  	settextstyle(8,0, 3);
  	outtextxy(238,510 , "EXIT");
  	
///// CHOOSE GAME MODE
	setcolor(WHITE);
	setbkcolor(BLACK);
	settextstyle(8,0,5);
	outtextxy(60,50,"CHOOSE GAME MODE");
	*g = click_menu1();
} 


int MENU2(int *g){
	cleardevice();
	readimagefile("testpic.jpg", 0,0,560,610);
	
///////// EASY MODE
	setcolor(GREEN);
	settextstyle(8,0,5);
	setbkcolor(BLACK);
	outtextxy(220, 150, "EASY");
	settextstyle(8,0,3);
	outtextxy(195, 193, "3x3 blocks");
	rectangle(175, 145, 360,230);
	
/////////  MEDIUM MODE	
	setcolor(YELLOW);
	settextstyle(8,0,5);
	outtextxy(195, 265, "MEDIUM");
	settextstyle(8,0,3);
	outtextxy(195, 305, "4x4 blocks");
	rectangle(165, 260, 375,340);
	
///// EXIT GAME
	setcolor(RED);
	setfillstyle(SOLID_FILL,RED );
  	bar(233, 508, 300, 538 );
  	setbkcolor(RED);
	setcolor(WHITE);
  	settextstyle(8,0, 3);
  	outtextxy(238,510 , "EXIT");
  	
//// BACK BUTTON	
  	setcolor(RED);
  	bar(233, 468, 300, 498 );
	setcolor(WHITE);
  	settextstyle(8,0, 3);
  	outtextxy(238,470 , "BACK");
  	
///// CHOOSE GAME MODE
	setcolor(WHITE);
	setbkcolor(BLACK);
	settextstyle(8,0,5);
	outtextxy(60,50,"CHOOSE GAME MODE");
	*g = click_menu2(0);
}


void AutoMENU(int *g){
	cleardevice();		
	readimagefile("testpic.jpg", 0,0,560,610);
	setcolor(WHITE);
	settextstyle(10,0,6);
	outtextxy(100, 40, "PUZZLE GAME");
	restartbutton();
///////// AUTO SOLVE WITHOUT IMAGE
	setcolor(GREEN);
	settextstyle(10,0,4);
	setbkcolor(BLACK);
	outtextxy(120, 185, "AUTO SOLVE PUZZLE");
	settextstyle(8,0,2);
	outtextxy(200, 213, "with numbers");
/////////  AUTO SOLVE WITH IMAGES
	setcolor(YELLOW);
	settextstyle(10,0,4);
	setbkcolor(BLACK);
	outtextxy(120, 300, "AUTO SOLVE PUZZLE");
	settextstyle(8,0,2);
	outtextxy(200, 330, "with picture");
///// BACK BUTTON
	setcolor(RED);
	setfillstyle(SOLID_FILL,RED );
  	bar(233, 468, 300, 498 );
  	setbkcolor(RED);
	setcolor(WHITE);
  	settextstyle(8,0, 3);
  	outtextxy(238,470 , "BACK");
	*g = click_menu2(1);
}

//==================================================================================================

// fixed data type (define by user).
enum facing {   
	LEFT , RIGHT , UP , DOWN , STAY
};

// posX,posY: Coordinate x,y of black cell (value = 9) in puzzle game.
int posX , posY , checker , cost;

// node -> data elements and linking components.
// The default accessibility of member variables and methods in class are private. 
class node{ 
	public :
		int arr[3][3] , x , y , f;
		string way; /// count moved times.
		facing cantMove; /// notify the position that cannot move to
		node(int a[3][3] , string way , facing cantMove , int x , int y , int f){
	/// get value to pointers.
			this->f = f;
			this->way = way;
			this->cantMove = cantMove; 
			this->x = x;
			this->y = y;
			for ( int i = 0; i < 3; i++){
				for ( int j = 0; j < 3; j++){
					arr[i][j] = a[i][j];
				}
			}
		}
		
//// If all conditions on the right side correct, return TRUE, if not then return FALSE
		bool canMoveLeft(){
			return cantMove != LEFT && y > 0 && cost > C();
		}
		bool canMoveRight(){
			return cantMove != RIGHT && y < 2 && cost > C();
		}
		bool canMoveUp(){
			return cantMove != UP && x > 0 && cost > C();
		}
		bool canMoveDown(){
			return cantMove != DOWN && x < 2 && cost > C();
		}
		
	//// Count the number of puzzles that in wrong position
		int C(){
		int sum = 0;
			if(checker == 0){
				if(arr[0][0] != 1) sum++;
				if(arr[0][1] != 2) sum++;
				if(arr[0][2] != 3) sum++;
				if(arr[1][0] != 4) sum++;	//  1 2
				if(arr[1][1] != 5) sum++;	//	3 4 5
				if(arr[1][2] != 6) sum++;	//	6 7 8
				if(arr[2][0] != 7) sum++;
				if(arr[2][1] != 8) sum++;
				if(arr[2][2] != 9) sum++;
			}
			return sum + f;
		}
		
		void moveLeft(){
			swap(arr[x][y] , arr[x][y-1]);	// swap positon
			y--;							// get present coordinate of y
			cantMove = RIGHT;				// notify that can't move black cell to the right side
			way += "l";						// has just moved black cell to the left
			f++;
		}
		void moveRight(){
			swap(arr[x][y] , arr[x][y+1]);
			y++;
			cantMove = LEFT;
			way += "r";
			f++;
		}
		void moveUp(){
			swap(arr[x][y] , arr[x-1][y]);
			x--;
			cantMove = DOWN;
			way += "u";
			f++;
		}
		void moveDown(){
			swap(arr[x][y] , arr[x+1][y]);
			x++;
			cantMove = UP;
			way += "d";
			f++;
		}
		
		bool checkFinish(){
			if(checker == 0){
				for ( int i = 0; i < 3; i++){
					if(arr[0][i] != i+1 || arr[1][i] != i+3+1 || arr[2][i] != i+6+1) return false;
				}
				return true;
			}
		}	
};

/// moving puzzles using swap function
void moveLeft(){
	swap(puzzle[posX][posY] , puzzle[posX][posY-1]);
	posY--; /// update the current position
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


void initPuzzle(State *S, State *N,int cost){
//   Convert value in S->A[i][j] to puzzle[i][j]
//   Check whether the value of puzzle[i][j] is valid or not.	
//   Get value for many data types 
REP:	int i, j;

	for ( i = 0; i < S->m; i ++){
		for ( j = 0; j < S->n; j ++){
			puzzle[i][j] = S->A[i][j];
			cout << puzzle[i][j] << " ";
		}
			cout << endl;
	}
	cout << "MAXIMUM cost of algorithm: "<<cost <<endl;/// for testing
	
// Get the coordinate of value 9 (black cell) in array puzzle.
	for ( int i = 0; i < S->m; i++){
		for ( int j = 0; j < S->n ; j++){
			if(puzzle[i][j] == 9){
				posX = i;
				posY = j;
				return;
			}
		}
	}
	
}

///  Display the puzzle game map (not in BGI window) for testing.
void prin(){
	for ( int i = 0; i < 3; i++){
		for ( int j = 0; j < 3; j++){	
			if (puzzle[i][j] == 9){
				cout<<".. ";
			} else {
			cout << puzzle[i][j] << " ";
			}
		}
		cout << endl;
	}
}
		
/// Check whether all puzzles are in correct position or not
bool checkFinish(){
	
	int counter1 = 0;
	for ( int i = 0; i < 3; i ++){
		if(puzzle[0][i] == i+1) counter1++;
		if(puzzle[1][i] == i+3+1) counter1++;
		if(puzzle[2][i] == i+6+1) counter1++;
	}
	if(counter1 == 9) return true;
	return false;
}


int checkcd(State S){
	
	/// Check conditions that required to make sure that A* can solve this puzzles.
	/// if the conditions are not satisfied, mix the elements in file randomly again.
	
	int N, B[10],k=0;
	for ( int i = 0; i< S.m; i ++){
		for ( int j = 0; j < S.n; j ++){
			B[k] = S.A[i][j];
			k++;
		}
	}
	
	for (int i = 0; i < k-1; i ++){
		if (B[i] == 9) continue;
		
		for ( int j = i +1; j < k; j++){
			if (B[i] > B[j]) N++;
		}
	}
	return N;/// if N divisible to 2 -> can solve 
}


void Moved_print_AI(){
	setbkcolor(BLACK);
	setcolor(WHITE);
	settextstyle(8,0,1);
	outtextxy(750,400,"Moved:");
}

void Graphic_decor(int g){
	if ( g == 80){
		readimagefile("testpic.jpg", 0,0,560,610);
		settextstyle(10,0,6);
		outtextxy(100, 40, "PUZZLE GAME");
		restartbutton();
		setbkcolor(BLACK);
		setcolor(YELLOW);
		settextstyle(8, 0, 1);
		outtextxy(210, 85, "- 3x3 mode -");
		PlaySound(TEXT("HesAPiratePiratesOfTheCaribbean_368mu.wav"),NULL,SND_ASYNC);
		settextstyle(10, 0, 6);
		
		
	} else if (g== 60){
		readimagefile("testpic.jpg", 0,0,560,610);
		settextstyle(10,0,6);
		outtextxy(100, 40, "PUZZLE GAME");
		restartbutton();
		setbkcolor(BLACK);
		setcolor(YELLOW);
		settextstyle(8, 0, 1);
		outtextxy(210, 85, "- 4x4 mode -");
		PlaySound(TEXT("HesAPiratePiratesOfTheCaribbean_368mu.wav"),NULL,SND_ASYNC);
		
	} else if ( g==100){
		readimagefile("testpic.jpg", 0,0,560,610);
		readimagefile("testpic - Copy.jpg", 560,0,1120,610);
		settextstyle(10,0,6);
		setcolor(WHITE);
		outtextxy(350, 40, "PUZZLE GAME");
		settextstyle(8,0,1);
		outtextxy(235, 116, "Player");
		outtextxy(745, 120, "AKT solve");
		setcolor(RED);
		setfillstyle(SOLID_FILL,RED );
  		bar(670, 19, 760, 42 );
  		setbkcolor(RED);
		setcolor(WHITE);
  		settextstyle(8,0, 1);
  		outtextxy(680,21 , "ESCAPE");
  		
		setbkcolor(BLACK);
		setcolor(RED);
		settextstyle(10, 0, 1);
		outtextxy(450, 85, "auto solve mode");
		PlaySound(TEXT("HesAPiratePiratesOfTheCaribbean_368mu.wav"),NULL,SND_ASYNC);
	}
}

//--------------MAIN PART OF AUTOSOLVE PUZZLE-----------------------------------------------------

int main_AS(State *S,State N, int g,char c){
	cost =40;
REP:;
	srand(time(NULL));
	int k=0, B[8];
		while(k<500){
			int ran=rand()%4;
			if(ran==0) up(*S, &N);
			if(ran==1) down(*S, &N);
			if(ran==2) left(*S, &N);
			if(ran==3) right(*S, &N);
			*S=N;	
			k++;
		}	
		
	k=0;
	
	int cnt = 0, i, j;
	bool check = checkFinish(); 	
	initPuzzle(&*S,&N,cost);
	
// checkcd function check whether the condition is satisfied or not. If not, randomize numbers again.
	if (checkcd(*S) % 2 ==1) goto REP;
	
	
///// adjust the solving speed display
	int delay_time =100;
	
// const clock-t count time when autosolve start.
	const clock_t begin_time = clock();
	string way = "";
	node nd(puzzle , "" , STAY , posX , posY , 0);
	vector <node> vt;
	vt.push_back(nd);

//// print graphic and numbers ( already mixed numbers randomly )
	cout << "Initial state: " << endl;
	
//// convert int cnt to string for outtextxy function
	char s[100];
	itoa(cnt,s,10);	
//// DISPLAY COUNT NUMBER
	setcolor(WHITE);	
	settextstyle(8,0,1);
	setfillstyle(SOLID_FILL,BLACK);
	setbkcolor(BLACK);
	outtextxy(750,400,"Moved:");
	
//////////// AUTO SOLVE (not display in screen) 
	while (!check && vt.size() != 0){ // vt.size get the size of vecto
		vector<node> open;
			int i = vt.size()-1;
			if(vt.at(i).checkFinish()){
				way = vt.at(i).way;
				check = true;
				break;
			}else{
				if(vt.at(i).canMoveUp()){
					node nd = vt.at(i);
					nd.moveUp();
					open.push_back(nd);
				}
				if(vt.at(i).canMoveDown()){
					node nd = vt.at(i);
					nd.moveDown();
					open.push_back(nd);
				}
				if(vt.at(i).canMoveRight()){
					node nd = vt.at(i);
					nd.moveRight();
					open.push_back(nd);
				}
				if(vt.at(i).canMoveLeft()){
					node nd = vt.at(i);
					nd.moveLeft();
					open.push_back(nd);
				}
			}
			
///// delete the last element of vecto
		vt.pop_back();
			
		for (int i = 0; i < open.size(); i++){
			for ( int j = i+1; j < open.size(); j++){
				if(open.at(i).C() <= open.at(j).C()){
					swap(open.at(i) , open.at(j));/// swap position
				}
			}
		}
		
		for (int i = 0; i < open.size(); i++){
			if(open.at(i).C() == open.at(open.size()-1).C())
			
///// push the element of vector to the last position
			vt.push_back(open.at(i));
		}
	}
	
////// CHECK THE CONDITION, IF NOT SATISFIED -> RANDOMIZE ELEMENTS AGAIN
	if(!check){
		cout << "Solving by autosolve algorithm failed, could not find the solution."<<endl;
		goto REP;
	}
	int l = 0;
	for ( int i = 0; i < S->m; i ++){
			for ( int j = 0; j < S->n ; j ++){
				B[l] = S->A[i][j] ;
				l++;
			}
		}
	print_state(&*S,g,c,puzzle,1);
	delay(2000);
///// way.length: count the number of moves in autosolve.	
	for ( int i = 0; i < way.length(); i++){
		if(way[i] == 'l'){
			moveLeft();
			print_state(&*S,g,c,puzzle,1);
			prin();
			cout << "MOVE LEFT" << endl << endl;
			delay(30);
			cnt++;
			Moved_print_AI();
			itoa(cnt,s,10);
			outtextxy(820,400,s);
		}else if(way[i] == 'r'){
			moveRight();
			print_state(&*S,g,c,puzzle,1);
			prin();
			cout << "MOVE RIGHT" << endl << endl;
			delay(30);
			cnt++;
			Moved_print_AI();
			itoa(cnt,s,10);
			outtextxy(820,400,s);
		}else if(way[i] == 'u'){
			moveUp();
			print_state(&*S,g,c,puzzle,1);
			prin();
			cout << "MOVE UP" << endl << endl;
			delay(30);
			cnt++;
			Moved_print_AI();
			itoa(cnt,s,10);
			outtextxy(820,400,s);
		}else if(way[i] == 'd'){
			moveDown();
			print_state(&*S,g,c,puzzle,1);
			prin();
			cout << "MOVE DOWN" << endl << endl;
			delay(30);
			cnt++;
			Moved_print_AI();
			itoa(cnt,s,10);
			outtextxy(820,400,s);
		}
	}
	
// Use int compare to compare moved times of auto solve to moved times of player.
	int compare = cnt;	
/// For testing and calculate time of solving puzzle
	cout << "AKT algorithm" << endl;
	cout << "Total steps = " << way.length() << endl;
	cout << "Calculated time = " << float( clock () - begin_time ) /  CLOCKS_PER_SEC << "s";
	l=0;
	for ( int i = 0; i < S->m; i ++){
		for ( int j = 0; j < S->n; j ++){
	/// Get the initial value of file that satisfied all coditions of auto solve
	/// and send it back to struct S
			S->A[i][j] = B[l];	
			l++;
		}
	}
	
	return compare;
}

//==================================================================================================
int main(){		

	initwindow(560, 610,"PUZZLE GAME");
	int re = 0;	/// uses for open/close BGI window in auto solve mode
START:
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	system("cls");
	int compare = 0, autosolve = 0, g, pic=0;
	State S, N;
	
	if (re == 1){
		closegraph();
		initwindow(560, 610,"PUZZLE GAME");
		re=0;
	}
	
//// CHOOSE GAME MODE
	readimagefile("wall2.jpg", 0,0,560,610);
	MENU1(&g);
	
	if ( g == 80 ){
		cleardevice();
		g = 0;
		MENU2(&g);
	} else if ( g== 60){
		cleardevice();
		g = 0;
		pic = 1;
		MENU2(&g);
	} else if ( g == 100){
		AutoMENU(&g);
		if (g == 1000) goto START;  // BACK BUTTON IN AUTO SOLVE MENU
		if ( g == 101){	// AUTO SOLVE WITH IMAGES.
			g =100;
			pic = 1;
		}
		closegraph();
		initwindow(1120, 610,"PUZZLE GAME"); /// BGI WINDOW FOR AUTO SOLVE MODE
		
	}
	if (g == 1000){ // IF CLICK AT MENU BUTTON, GO BACK TO MENU 1
		goto START;	
	} else if(g==80 || g == 100){
		init_state(&S, "C:\\Users\\antho\\Documents\\C\\test puzzle\\15\\15\\puzzle1.txt");

	} else if(g == 60){
		init_state(&S, "C:\\Users\\antho\\Documents\\C\\test puzzle\\15\\15\\puzzle2.txt");	} 

	cleardevice();
	Graphic_decor(g);
	
/// mix the position of elements in file randomly
	srand(time(NULL));
	int k=0;
		while(k<500){
			int ran=rand()%4;
			if(ran==0) up(S, &N);
			if(ran==1) down(S, &N);
			if(ran==2) left(S, &N);
			if(ran==3) right(S, &N);
			S=N;	
			k++;
		}	
		
	if ( g == 100){
		compare = main_AS(&S,N,g,pic);
		g=80;
		autosolve = 1;
		keypress_to_play(S,N,g,0,pic,compare,autosolve);
		re++;
		goto END;
	}	
	keypress_to_play(S,N,g,0,pic,compare,autosolve);
	
END:
	cleardevice();
	goto START;
	getch();
	closegraph();
	system("cls");
	return 0;
}
///click pos
///delay
