// 枚举问题 第一行灯的状态 确定所有灯的状态，再查最后一行灯是否全部熄灭。
#include <iostream>
using namespace std;

int puzzle[6][8], press[6][8];

bool guess() {
	int r,c;
	// from first row, calculate subsequent row
	for(r=1;r<5;r++)
		for(c=1;c<7;c++) {
			press[r+1][c] = (puzzle[r][c] + press[r][c-1] + press[r][c]
				+ press[r][c+1] + press[r-1][c]) % 2;
		}
	// check if last row's lights are all turned off
	for(c=1;c<7;c++)
		if((press[5][c-1]+puzzle[5][c]+press[5][c+1]+press[4][c]) % 2 != press[5][c])
			return false;

	return true;
}

// enumerate all possible states of first row light bulbs
void enumerate() {
	int c;
	bool success;
	for(c=1;c<7;c++)
		press[1][c] = 0;
	while(guess() == false) {
		press[1][1]++;
		c = 1;
		while (press[1][c] > 1) {
			press[1][c] = 0;
			c++;
			press[1][c]++;
		}
	}
	return;
}

int main() {
	int cases, i, r, c;
	cin >> cases;
	for(r=0;r<6;r++) 
		puzzle[r][0] = press[r][0] = press[r][7] = 0;
	for(c=1;c<7;c++)
		puzzle[0][c] = press[0][c] = 0;
	for(i=0;i<cases;i++) {
		for(r=1;r<6;r++)
			for(c=1;c<7;c++) 
				cin >> puzzle[r][c];
		
		enumerate();
		cout << "PUZZLE #" << (i+1) << endl;
		for(r=1;r<6;r++){
			for(c=1;c<7;c++)
				cout << press[r][c];
		    cout << endl;
		}

	}
	return 0;
}