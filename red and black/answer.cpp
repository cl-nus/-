#include <iostream>
using namespace std;

int r,c;
char ch[22][22];

int search(int m,int n)
{
    if (ch[m][n]=='#')
        return 0;
    else
        ch[m][n] ='#';
    return 1 + search(m-1,n) + search(m+1,n) + search(m,n-1) + search(m,n+1);
}

int main()
{
    while (true)
    {
        cin>>c>>r;
        if (r==0&&c==0)
            break;
        int m,n;
        memset(ch,'#',sizeof ch);
        for (int i=1;i<=r;i++)
        {
            for (int j=1;j<=c;j++)
            {
                cin>>ch[i][j];
                if (ch[i][j]=='@')
                {
                    m = i;
                    n = j;
                }
            }
        }
        
        int count = search(m,n);
        
        cout<<count<<endl;
    }
    
    return 0;
}
