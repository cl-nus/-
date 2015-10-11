#include <iostream>
using namespace std;

struct plant {
    int x;
    int y;

   
};

plant p[5001];
int h,l,n;

int compare(const void* e1,const void* e2)
{
    if (((*(plant*)e1).x - (*(plant*)e2).x)==0)
    {
        return (*(plant*)e1).y - (*(plant*)e2).y;
    }
    else
        return (*(plant*)e1).x - (*(plant*)e2).x;
}

int steps(int i,int j,int n)
{
    plant temp;
    int x,y;
    x = p[j].x - p[i].x;
    y = p[j].y - p[i].y;
    temp.x = p[j].x+x;
    temp.y = p[j].y+y;


    int count = 1;
    while (++count)
    {
        if (!bsearch(&temp,p,n,sizeof(plant),compare))
        {
            if (temp.x>h||(temp.y<1||temp.y>l))
            {
                return count;
            }
            return -1;
        }
        temp.x += x;
        temp.y += y;
    }
}

int main()
{
    scanf("%d %d",&h,&l);
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d %d",&p[i].x,&p[i].y);
    }
    qsort(p,n,sizeof(plant),compare);
    int max = 2;
    for (int i=0;i<n-2;i++)
    {
        for (int j=i+1;j<n-1;j++)
        {
            //optimize
            int x,y;
            x = p[j].x - p[i].x;
            y = p[j].y - p[i].y;
            if (p[i].x-x>=1&&(p[i].y-y<=l&&p[i].y-y>=1))
                continue;
            if (p[i].x+max*x>h)
                break;
            if (p[i].y+max*y>l||p[i].y+max*y<1)
                continue;

            int temp = steps(i,j,n);
            if (temp>max)
            {
                max = temp;
            }

        }
    }
    if (max>=3)
        cout<<max<<endl;
    else
        cout<<"0"<<endl;
    return 0;
}