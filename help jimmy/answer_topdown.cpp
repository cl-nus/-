// top down dynamic programming with memoization

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stdlib.h>

using namespace std;

#define MAXN 1000
#define INFINITE 1000000

int t,n,x,y,maxHeight;

struct Platform {
	int Lx, Rx, h;
	 
	bool operator < (const Platform& p2) const {
		return h > p2.h;
	}
};



Platform platforms[MAXN+10];
int leftMinTime[MAXN+10];
int rightMinTime[MAXN+10];


int minTime(int l, bool bLeft) {
	int y = platforms[l].h;
	int x,i;
	if(bLeft)
		x = platforms[l].Lx;
	else
		x = platforms[l].Rx;


	for(i = l+1; i <= n; i++) {
		if(platforms[i].Lx <= x && platforms[i].Rx >= x)
			break;
	}

	if(i <= n) {
		if(y-platforms[i].h > maxHeight)
			return INFINITE;
	}
	else {
		if (y > maxHeight)
			return INFINITE;
		else 
			return y;
	}

	int nLeftTime = y - platforms[i].h + x - platforms[i].Lx;
	int nRightTime = y - platforms[i].h + platforms[i].Rx - x;
	
	if (leftMinTime[i] == -1)
		leftMinTime[i] = minTime(i, true);
	
	if (rightMinTime[i] == -1)
		rightMinTime[i] = minTime(i, false);
	
	nLeftTime += leftMinTime[i];
	nRightTime += rightMinTime[i];
	
	if (nLeftTime < nRightTime)
		return nLeftTime;
	
	return nRightTime;
}

int main() {
	cin >> t;
	int i,j;
	for(i=0; i<t;i++) {
		memset(leftMinTime, -1, sizeof(leftMinTime));
		memset(rightMinTime,-1,sizeof(rightMinTime));
		cin >> n >> x >> y >> maxHeight;
		
		platforms[0].Lx = x;
		platforms[0].Rx = x;
		platforms[0].h = y;

		for(j=1; j<=n; j++) {
			cin >> platforms[j].Lx >> platforms[j].Rx >> platforms[j].h;
			 
		}
		sort(platforms, platforms+n+1);
		cout << minTime(0,true) <<endl;
	}
	return 0;
}