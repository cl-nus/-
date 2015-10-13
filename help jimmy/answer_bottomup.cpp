#include <iostream>  
#include <algorithm>  
#include <cstring>  
#include <cstdlib>  
#include <cstdio>  
 
using namespace std;  
typedef long long ll;  
const int maxn = 1000 + 10;  
const int maxx = 20000 + 10;  
const int INF = 1000000;  
struct P{  
    int x, y, h;  
    bool operator < (const P& p2) const {
        return h > p2.h;
    }
};  
P k[maxn];  
int n, sx, sh, maxh;  
int dp[maxn][2 + 10];  
void Init()  
{  
    dp[0][0] = dp[0][1] = 0;  
    for( int i=1; i<n; ++i )  
    {  
        dp[i][0] = dp[i][1] = INF;  
    }  
}  
void solve()  
{  
    Init();  
    bool sleft, sright;  
    int ans = INF;  
    for( int i=0; i<n-1; ++i )  
    {  
        sleft = sright = false;  
        for( int j=i+1; j<n; ++j )  
        {  
            if( (sleft && sright) || k[i].h-k[j].h>maxh )  
            {  
                break;  
            }  
            if( !sleft && k[j].x<=k[i].x && k[i].x<=k[j].y && k[i].h!=k[j].h )  
            {  
                if( j==n-1 )  
                    ans = min(ans, dp[i][0]+k[i].h);  
                else  
                {  
                    dp[j][0] = min(dp[i][0]+k[i].h-k[j].h+k[i].x-k[j].x, dp[j][0]);  
                    dp[j][1] = min(dp[i][0]+k[i].h-k[j].h+k[j].y-k[i].x, dp[j][1]);  
                }  
                sleft = true;  
            }  
            if( !sright && k[j].x<=k[i].y && k[i].y<=k[j].y && k[i].h!=k[j].h )  
            {  
                if( j==n-1 )  
                    ans = min(ans, dp[i][1]+k[i].h);  
                else  
                {  
                    dp[j][0] = min(dp[i][1]+k[i].h-k[j].h+k[i].y-k[j].x, dp[j][0]);  
                    dp[j][1] = min(dp[i][1]+k[i].h-k[j].h+k[j].y-k[i].y, dp[j][1]);  
                }  
                sright = true;  
            }  
        }  
    }  
    printf("%d\n", ans);  
}  

int main()  
{  
    int T;  
    scanf("%d", &T);  
    while( T-- )  
    {  
        scanf("%d %d %d %d", &n, &sx, &sh, &maxh);  
        for( int i=0; i<n; ++i )  
        {  
            scanf("%d %d %d", &k[i].x, &k[i].y, &k[i].h);  
        }  
        k[n].x = k[n].y = sx;  
        k[n].h = sh;  
  
        k[n+1].x = -maxx;  
        k[n+1].y = maxx;  
        k[n+1].h = 0;  
  
        n += 2;  
        sort(k, k+n);  
  
        solve();  
    }  
    return 0;  
}  