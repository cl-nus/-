#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

#define MAXN 108

struct Box {
	int v, w; // value, weight
	double density;
};

Box boxes[MAXN];

int n, c;
double totalw = 0.0, totalv = 0.0;


bool operator < (const Box &a, const Box &b) {
	return a.density < b.density;
}

int main() {
	cin >> n >> c;
	for (int i=0; i<n; i++) {
		cin >> boxes[i].v >> boxes[i].w;
		boxes[i].density = 1.0 * boxes[i].v / boxes[i].w;
	}

	sort(boxes, boxes+n);

	for (int i=n-1; i>=0; i--) {
		if (totalw + boxes[i].w <= c) {
			totalw += boxes[i].w;
			totalv += boxes[i].v;
		} else {
			totalv += boxes[i].density * (c-totalw);
			totalw = c;
			break;
		}
	}

	cout << fixed << setprecision(1) << totalv << endl;
	return 0;

}
