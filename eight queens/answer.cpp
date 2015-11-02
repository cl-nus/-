#include <iostream>

using namespace std;

int ColumnForRow[9] = {0};

// check if the column allocated for row i violates the required condition
bool check(int i) {
	int j;
	for (j=1; j<i; j++) {
		if (ColumnForRow[i] == ColumnForRow[j] ||
			(ColumnForRow[i] - ColumnForRow[j]) == (i-j) ||
			(ColumnForRow[j] - ColumnForRow[i]) == (i-j)) {
			break;
		}
	}
	return ( i==j ? true : false);
}

// try to put in each column at current till check success
void placeQueen(int i) {
	for(ColumnForRow[i] = 1; ColumnForRow[i] <= 8; ColumnForRow[i]++) {
		if(check(i)) {
			// all queen are allocated
			if(i==8) {
				// print the solution
				for(int k=1; k<=8;k++) {
					cout<< "ColumnForRow " << k << " = " << ColumnForRow[k] << endl;
				}
				return;
			} else {
				placeQueen(i+1);
			}
		}
	}
	return;
}

int main() {
	placeQueen(1);

	return 0;

}