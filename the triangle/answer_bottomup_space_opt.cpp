// bottom up dynamic programming space optimization
// no need of a maxSum array, use last row of digit as maxSum array

#include <iostream>
#include <algorithm>
#define MAXN 101
using namespace std;

int digit[MAXN][MAXN];
int* maxSum;
int n;

int main() {
	int i,j;
	cin >> n;
	for(i=1; i<=n; i++)
		for(j=1;j<=i;j++)
			cin >> digit[i][j];

	maxSum = digit[n];
	for(i=n-1; i>=1; i--)
		for(j=1;j<=i;j++)
			maxSum[j] = max(maxSum[j], maxSum[j+1]) + digit[i][j];

	cout << maxSum[1] << endl;
}