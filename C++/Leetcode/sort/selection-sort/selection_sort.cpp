#include <iostream>

using namespace std;

/*
For ascending order = use min
for desc order = use max

Selection sort is about checking the min or max value and put it in the right index that we are comparing from outer loop.

in all possible cases - best, worst, avg case : On2 -
Selection sort is not at all adaptive.

The best way to remember is to know that you pick the min or max from the start and replace it with i..i(n) values.
i.e if [2,3,1,5], i=0 2 is min, then keep comparing until you find min and replace /swap i=0 with 1,
then 3 would be min, keep finding min which would be 2 and then i=1 would be 2 and so on.

Selection sort means selecting min and max and sorting based on that.
*/
 
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{

    int a[] = {20,14,-9, 16,3, -12,8}; // {64, 25, 12, 22, 11};

    int min;
    int temp;
    int size = sizeof(a) / sizeof(a[0]);
    // sizeof = total size of array in bytes.

    for (int i = 0; i < size; i++) {
        min = i;
        for (int j = i + 1; j < size; j++) {
            if (a[j] < a[min]) {
		min = j;
		// below steps performs unnecessary swap before determining or comparing with everyone and finding the min out of all.
		// temp = a[j];
                // a[j] = a[min];
                // a[min] = temp;
            }
        }
	swap(&a[min], &a[i]);
    }

    for (int i = 0; i < size; i++) {
        cout << a[i] << ",";
    }
    cout << endl;

    return 0;
}
