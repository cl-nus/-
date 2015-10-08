//内存是个限制，只有3000k。 所以每次将arr填满时，quicksort，将最小的前k个数位置在前k个位置。将剩余数据都到后k个位置，重复以上操作。

/*
void qsort (void* base, size_t num, size_t size,int (*compar)(const void*,const void*));

Sorts the num elements of the array pointed to by base, each element size bytes long, 
using the compar function to determine the order.
*/
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int arr[100000];

int cmp(const void * a,const void * b)
{
	return *(int *)a - *(int *)b;
}

int main() {
	int n, k;
	cin >> n >> k;

	for(int i=0; i<k; i++) {
		cin >> arr[i];
	}

	n -= k;

	qsort(arr,k,sizeof(arr[0]),cmp);

	while (n > 0) {
		if (n >= k) {
			for (int i=k; i<2*k;i++)
				cin >> arr[i];
			n -= k;
			qsort(arr,2*k,sizeof(arr[0]), cmp);
		} else {
			for (int i=k; i<k+n;i++) 
				cin >> arr[i];
			qsort(arr,k+n,sizeof(arr[0]),cmp);
			n = 0;			
		}
	}

	cout << arr[k-1] << endl;
	return 0;

}