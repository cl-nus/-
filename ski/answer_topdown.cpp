// dynamic programming top down with memozaition
#include <iostream>
using namespace std;

int h[101][101];//输入的高度值   
int dis_sk[101][101];//记录了每个点可以滑行的最大距离   
int dx[]={-1,1,0,0};//为了方便上下左右侧的滑行的最大距离而使用的方便数组   
int dy[]={0,0,-1,1}; 
int r,c;//输入的行和列

bool in_bound(int i,int j){   
   return i >= 0 && i < r && j >= 0 && j < c;    
}  

int dis(int i,int j){   
    int temp;   
    if(dis_sk[i][j])//如果已经求出来了，直接返回   
        return dis_sk[i][j];   
    for(int k = 0; k < 4; k++){   
        if(in_bound(i+dx[k],j+dy[k])){//如果没有越界   
            if(h[i][j] > h[i+dx[k]][j+dy[k]]){//如果顺着该侧可以滑   
               temp = dis(i+dx[k],j+dy[k]);//递归求dis(i+dx[k],j+dy[k])，并保存在临时变量temp中   
               dis_sk[i][j] = dis_sk[i][j] > temp ? dis_sk[i][j] : temp + 1;//如果dis[i][j]比temp小，则取temp+1   
            }   
        }   
    }   
    return dis_sk[i][j];   
}  

int main(){   
  int max_dis = 0;   
  int temp;   
  int i,j;   
  cin >> r >> c;   
  for(i = 0; i < r; i++)   
      for(j = 0; j < c; j++){   
        cin >> h[i][j];   
        dis_sk[i][j] = 0;   
      }   
  
  for(i = 0; i < r; i++)   
      for(j = 0; j < c; j++){   
          temp = dis(i,j);   
          max_dis = max(max_dis, temp);   
      }   
  
  cout << max_dis + 1 << endl;   
  return 0;   
}  