/* dfs problem with pruning to speed up dfs */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool rowFlags[9][10];  //rowFlags[i][num] = true means on the ith row, the number has appeared
bool colFlags[9][10];  //colFlags[i][num] = true means on the ith column, the number has appeared
bool blockFlags[9][10]; // colFlags[i][num] = true means in the ith 9-cell-block, number has appeared

int board[9][9];

struct Pos {
	int r, c;
	Pos(int rr, int cc): r(rr),c(cc) {}
};

vector<Pos> blankPos; // all blank cells with no numbers being placed yet

inline int getBlockNum(int r, int c)
{ // get 9-cell block number
	int rr = r/3;
	int cc = c/3;
	return rr * 3 + cc;
}

void setAllFlags(int i, int j, int num, bool b)
{
	rowFlags[i][num] = b;
	colFlags[i][num] = b;
	blockFlags[getBlockNum(i,j)][num] = b;
}

// check whether num can be placed at position i, j
bool isOk(int i, int j, int num)
{
	return !rowFlags[i][num] && !colFlags[i][num] && !blockFlags[getBlockNum(i,j)][num];
}

bool dfs(int n) {
	if (n < 0) { // base case of recursion, no more blank cells
		return true;
	}
	int r = blankPos[n].r;
	int c = blankPos[n].c;

	for (int num = 1; num <= 9; num++) {
		if (isOk(r,c,num)) {
			board[r][c] = num;
			setAllFlags(r, c, num, true);
			// recursion
			if (dfs(n-1)) {
				return true;
			}
			// out of inner-recursion, reset flag to false
			setAllFlags(r, c, num, false);
		}
	}
	return false;
}

int main()
{
	int t;
	cin >> t;
	while ( t-- ) {
		memset(rowFlags,0,sizeof(rowFlags));
		memset(colFlags,0,sizeof(colFlags));
		memset(blockFlags,0,sizeof(blockFlags));

		blankPos.clear();
		for (int i=0; i<9; i++) {
			for (int j=0; j<9; j++) {
				char c;
				cin >> c;
				board[i][j] = c - '0';
				if (board[i][j]) {
					setAllFlags(i,j,board[i][j], true);
				} else {
					blankPos.push_back(Pos(i,j));
				}
			}
		}
		if (dfs(blankPos.size() - 1)) {
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					cout << char(board[i][j]+'0');
				}
				cout << endl;
			}
		}
	}
}