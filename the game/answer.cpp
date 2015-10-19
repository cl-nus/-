#include <iostream>
#include <algorithm>

using namespace std;


int minstep, w, h;
int board[][];


int to[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};


// 0 east 1 south 2 west 3 north 
for(int i=0;i<4;i++) {
	int x = now_x + to[i][0];
	int y = now_y + to[i][1];
	f = i;
}