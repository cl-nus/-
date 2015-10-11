// classic recursion problem
/*
m - number of apple, n - number of plates
case 1: n > m
f(m,n) = f(m,m)
case 2: n <= m there exists empty plate
f(m,n) = f(m,n-1)
case 3, n <= m, all plates have at least one apple
f(m,n) = f(m-n,n)
*/

#include <iostream>
using namespace std;

// m apples, n plates
int count (int m, int n) {
	if(m == 0 || n == 1)
		return 1;
	else if(m < n)
		return count(m,m);
	else
		return count(m,n-1) + count(m-n,n);
}

int main() {
	int t;
	int apples, plates;
	cin >> t;
	while (t--) {
		cin >> apples >> plates;
		cout << count(apples,plates) << endl;
	}
	return 0;
	
}