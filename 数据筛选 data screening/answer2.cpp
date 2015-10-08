// use STL instead of quicksort of c standard library

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, k, num, n1;
    vector<int> vec;
    cin >> n >> k;
    n1 = n;
    for (int i = 0; i <= n/100000; i++){
        n1 = n > 100000 ? 100000 : n;
        for (int j = 0; j < n1; j++){
            cin >> num;
            vec.push_back(num);
        }
        sort(vec.begin(), vec.end());
        vec.erase(vec.begin() + k - 1 , vec.end());
        n -= n1;
        if (n <= 0){
            cout << vec[k-1]<<endl;
            break;	
        }	
    }
}