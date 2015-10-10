// bottom up dynamic programming

#include <iostream>
#include <algorithm>
#define MAXN 101
using namespace std;

int digit[MAXN][MAXN];
int maxSum[MAXN][MAXN];
int n;

int main() {
	int i,j;
	cin >> n;
	for(i=1; i<=n; i++)
		for(j=1;j<=i;j++)
			cin >> digit[i][j];

	// last row
	for(i=1; i<=n; i++)
		maxSum[n][i] = digit[i][j];
	for(i=n-1; i>=1; i--)
		for(j=1;j<=i;j++)
			maxSum[i][j] = max(maxSum[i+1][j], maxSum[i+1][j+1]) + digit[i][j];

	cout << maxSum[1][1] << endl;
}