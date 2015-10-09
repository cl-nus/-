#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

#define MAXN 1012

int n;
struct Seg {
	double left, right;
} s[MAXN];

bool operator < (const Seg& a, const Seg& b){
	return a.left < b.left;
}

int solve() {
	int ans; double min_right; // min_right is the minimum position of the right vertex of line segments

	sort(s, s+n);  // sort according to the left vertex of line segments
	ans = 1; min_right = s[0].right; // radr number is 1

	for (int i=1; i<n; i++) {
		if (s[i].left <= min_right) {
			min_right = min(min_right, s[i].right);
		} else {
			ans ++;
			min_right = s[i].right;
		}

	}
	return ans;
}

int main() {
	int d;
	int x,y,count=0;
	bool flag;

	while (1) {
		count++;
		cin >> n >> d;
		if(n == 0 && d == 0)
			break;
		flag = true;

		for (int i=0; i<n; i++) {
			cin >> x >> y;
			if (y >d) {
				flag = false; // not possible for radar to cover island
			} else {
				s[i].left = x - sqrt(d*d - y*y);
				s[i].right = x + sqrt(d*d - y*y);
			}
		}

		if (flag) {
			cout << "Case " << count << ":" << " " << solve() << endl;
		} else {
			cout << "Case " << count << ":" << -1 << endl;
		}

	}

	return 0;

}