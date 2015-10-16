//O(n^2) dynamic programming

#include <iostream>
#include <algorithm>
using namespace std;

int los(int arr[], int len)  
{  
    int longest[len];  
    for (int i=0; i<len; i++)  
        longest[i] = 1;  
  
    for (int j=1; j<len; j++) {  
        for (int i=0; i<j; i++) {  
            if (arr[j]>arr[i] && longest[j]<longest[i]+1){ //注意longest[j]<longest[i]+1这个条件，不能省略。  
                longest[j] = longest[i] + 1; //计算以arr[j]结尾的序列的最长递增子序列长度  
            }  
        }  
    }  
  
    int maxLen = *max_element(longest,longest+len);
    
    return maxLen;  
}  


int main() {
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++) {
		cin >> arr[i];
	}
	cout << los(arr,n) << endl;
}