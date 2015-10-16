//O(nlogn)

#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int key) {
	int mid;
    if (arr[right] <= key)
        return right + 1;
    while (left < right)
    {
        mid = left + (right - left) / 2;
        if (arr[mid] <= key)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int LOS(int d[], int n) {
	int i = 0, len = 1;
	int end[n+1];
    end[1] = d[0]; //初始化：长度为1的LOS末尾为d[0]
    for (i = 1; i < n; i++)
    {
        int pos = binarySearch(end, 1, len, d[i]); //找到插入位置
        end[pos] = d[i];
        if (len < pos) //按需要更新LOS长度
            len = pos;
    }
    return len;
}

int main() {
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++) {
		cin >> arr[i];
	} 
	cout << LOS(arr,n) << endl;

}
