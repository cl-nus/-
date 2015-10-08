/*
count the number of occurrences such that the difference of two integers(possibly duplicate) is equal to a given integer
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
	int n, T, element;
	vector<int> vec;
	vector<int> subtractVec;
	int count = 0; 
	cin >> n >> T;
	for (int i=0; i<n; i++) {
    	cin >> element;
    	vec.push_back(element);
	}


	sort(vec.begin(), vec.end());
	
	for(int i=0; i<n-1;i++) {
		subtractVec.push_back(vec[i+1]-vec[i]);
	}

	for(int i=0;i<n-1;i++) {
		if(subtractVec[i] == T)
			count++;
	}
	

	cout << count << endl;

}