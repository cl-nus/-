#include <iostream>
#include <memory.h>
#include <algorithm>
#include <stdio.h>
#define MAXN 75
using namespace std;


int minstep, w, h;
char board[MAXN+2][MAXN+2];
bool mark[MAXN+2][MAXN+2];

//direction
int to[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};


/*
now_x, now_y current position
end_x, end_y target position
step current number of steps
f direction
*/
void search(int now_x, int now_y, int end_x, int end_y, int step, int f) {
	if(step > minstep) {
		return;
	}
	if(now_x == end_x && now_y == end_y) {
		if(minstep > step) {
			minstep = step;
			return;
		}
	}
	// 0 east 1 south 2 west 3 north 
	for(int i=0;i<4;i++) {
		int x = now_x + to[i][0];
		int y = now_y + to[i][1];
		if((x>-1)&&(x<w+2) && (y>-1) && (y<h+2)&&(((board[y][x] = ' ')&&(mark[y][x] == false))||((x==end_x)&&(y==end_y)&&(board[y][x]=='X')))) {
			mark[y][x] = true;

			// same direction, no need to increment step
			if(f==i) {
				search(x,y,end_x,end_y,step,i);
			} else {
				search(x,y,end_x,end_y,step+1,i);
			}
			search(x,y,end_x,end_y,step+1,i);
			//backtrack
			mark[y][x] = false;

		}
	}
}

int main() {
	int boardNum = 0;
	while(scanf("%d %d", &w,&h)) {
		if(w==0 && h==0)
			break;
		boardNum++;
		printf("Board #%d:\n",boardNum);
		int i,j;
		for(i=0;i<MAXN+2;i++){
			board[0][i] =board[i][0] =' ';
		}
		for(i=1;i<=h;i++) {
			getchar();
			for(j=1;j<=w;j++) {
				board[i][j] = getchar();
			}
		}
		for(i=0;i<=w;i++)
			board[h+1][i+1] = ' ';
		for(i=0;i<=h;i++)
			board[i+1][w+1] = ' ';

		int begin_x, begin_y, end_x, end_y, count = 0;
		while(scanf("%d %d %d %d",&begin_x,&begin_y,&end_x,&end_y) && begin_x>0) {
			count++;
			minstep = 100000;
			memset(mark,false,sizeof(mark));

			search(begin_x,begin_y,end_x,end_y,0,-1);
			if(minstep < 100000)
				printf("Pair %d: %d segments.\n",count,minstep);
			else
				printf("Pair %d: impossible.\n",count);
		}
		printf("\n");
	}
	return 0;

}

