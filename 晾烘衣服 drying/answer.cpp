#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100008
int a[MAX];
int n,k;

bool check(int ans) {
    int now = 0; // time needed for drying
    for (int i=0; i<n; i++) {
        // we need to use a radiator
        if (a[i] > ans) {
            // time required for ith cloth, note ceiling(a,k) = (a-1)/k + 1
            now += (a[i]-ans-1) / (k-1) + 1;
        }
        if (now > ans)
            return false;
    }
    return true;
}


int main() {
    int left = 0, right = 0;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (a[i] > right)
            right = a[i];
    }
    
    cin >> k;
    // to avoid division by zero
    if (k == 1)
        cout << right << endl;
    else {
        left = *min_element(a, a+n);
        // binary search
        while ( left < right) {
            int mid = (left + right) >> 1;
            if (check(mid))
                right = mid;
            else
                left = mid;
        }
        cout << right << endl;
    }
    
    return 0;
}