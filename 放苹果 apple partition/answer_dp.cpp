#include <iostream>
using namespace std;
const int maxn=11;
int a[maxn][maxn];

void init()
{
    for(int i=0;i<=10;i++)
        a[0][i]=1,a[i][1]=1;
    for(int i=1;i<maxn;i++)
        for(int j=2;j<=maxn;j++)
            if(j<=i)
                a[i][j]=a[i][j-1]+a[i-j][j];
            else
                a[i][j]=a[i][i];
}

int main()
{
    init();
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        cout<<a[n][m]<<endl;
    }
    return 0;
}
