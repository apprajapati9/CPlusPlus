#include <iostream>

using namespace std;

void print(int *a, int size){
    cout << endl;
    for(int i =0; i < size; i++) {
	cout << a[i] << ",";
    }
    cout << endl;
}

int* merger(int *a, int size1, int* b, int size2)
{

    int totalSize = size1 + size2;
    int *merger = new int[totalSize]{0};

    print(merger, totalSize);
    
    int index = 0;
    int x = 0;
    int y = 0;
    while(size1 != 0 && size2 != 0) {

        if(a[x] < b[y] || a[x] == b[y]) {
            merger[index] = a[x];
            x++;
            size1--;
        } else {
            merger[index] = b[y];
            y++;
            size2--;
        }
	//cout << "went in";
        index++;
    }

    if(size1 > 0) {
        for(int i = 0; i < size1; i++) {
            merger[index] = a[x];
            index++;
            x++;
        }
    }

    if(size2 > 0) {
        for(int i = 0; i < size2; i++) {
            merger[index] = b[y];
            index++;
            y++;
        }
    }

    return merger;
}


int main()
{
    cout << "Hello world!" << endl;

    int a[] = {1,4,23,43,50,55};
    int b[] = {3,20,21,23,44,51,88,99};

    int size1 = sizeof(a)/ sizeof(a[0]);
    int size2 = sizeof(b)/ sizeof(b[0]);


    int *m = merger(a, size1, b, size2);

    for(int i =0 ; i < size1+ size2; i++) {
        cout << m[i] << ",";
    }
    cout << endl;

    return 0;
}
