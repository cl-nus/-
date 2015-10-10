// top down dynamic programming - recursion with memozation

#include <iostream>
#include <algorithm>
#define MAXN 101
using namespace std;

int digit[MAXN][MAXN];
int maxHere[MAXN][MAXN];
int n;

int maxSum(int i, int j) {
	// return already computed value of maxSum at (i,j)
	if(maxHere[i][j] != -1)
		return maxHere[i][j];
	// last row 
	if(i == n)
		maxHere[i][j] = digit[i][j];
	else {
		int x = maxSum(i+1, j);
		int y = maxSum(i+1, j+1);
		maxHere[i][j] = max(x, y) + digit[i][j];
	}
	return maxHere[i][j];

}

int main() {
	int i,j;
	cin >> n;
	for(i=1; i<=n; i++)
		for(j=1;j<=i;j++)
			cin >> digit[i][j];
	cout << maxSum(1,1) << endl;
}