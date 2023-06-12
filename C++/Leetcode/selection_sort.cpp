#include <iostream>

using namespace std;

int main()
{

    int a[5] = {64, 25, 12, 22, 11};

    int min;
    int temp;
    int size = sizeof(a) / sizeof(a[0]);
    // sizeof = total size of array in bytes.

    for (int i = 0; i < size; i++)
    {
        min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (a[j] < a[min])
            {
                temp = a[j];
                a[j] = a[min];
                a[min] = temp;
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        cout << a[i] << endl;
    }

    return 0;
}