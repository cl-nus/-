#include<iostream>
#include<algorithm>


using namespace std;

struct Cow {
    int num1,num2;
    int index;
};

bool cmp1(Cow x,Cow y)
{
    return x.num1 > y.num1;
}

bool  cmp2(Cow x,Cow y)
{
    return x.num2 > y.num2;
}

/*
template <typename T>
void quickSort(T arr[], int left, int right) {
    int i = left, j = right;
    T tmp;
    T pivot = arr[(left + right)/2];
    
    // partition
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };
    
    // recursion
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}
*/

int main(){

    int n,k;
    Cow cows[5000];
    cin >> n >> k;
    
    for(int i=0;i<n;i++)
    {
        cows[i].index = i+1;
        cin >> cows[i].num1 >> cows[i].num2;
    }
    
    sort(cows,cows+n,cmp1);
    sort(cows,cows+k,cmp2);
    
    cout << cows[0].index <<endl;
    return 0;
}