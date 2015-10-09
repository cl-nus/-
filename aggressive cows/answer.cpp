#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAXN 100008

int a[MAXN];
int n,c;

// check that if the minimum distance is x, whether we can put c cows in n positions
bool check(int x)
{
    int cnt = 1;
    int p = a[0];
    for (int i=1; i<n; i++)
    {
        if (a[i] >= p+x)
        {
            cnt++;
            p = a[i];
        }
    }
    if (cnt >= c)
        return true ;
    
    return false ;
}

int main()
{
    cin >> n >> c;

    for(int i=0; i<n; i++)
        cin >> a[i];

    sort(a, a+n);
    int l = 0, r = (a[n-1]-a[0])/(c-1), mid;
    while (l <= r)
    {
        mid = (l+r)/2;
        if(check(mid))
            l = mid+1;
        else
            r = mid-1;
    }
    cout << l-1 << endl;
    return 0;
}