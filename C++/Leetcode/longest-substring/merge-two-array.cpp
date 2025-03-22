#include<iostream>

#include <vector>

using namespace std;


void print(vector<int> &v)
{
    for(auto i: v) {
        cout << i << ",";
    }
    cout << endl;
}
/*

    vector<int> a = {4,0,0,0,0,0}; //M=1, n = 5
    vector<int> b = {1,2,3,5,6};

        vector<int> a4 = {0,0,3,0,0,0,0,0,0};
	vector<int> b4 = {-1,1,1,1,2,3};
	//-1,0,0,1,1,1,
	*/

void merge(vector<int> &a, int m, vector<int> &b, int n)
{
    vector<int> ans(0);

    int left = 0;
    int right = 0;
    int index = 0;
    
    while(left < m && right < n) { //size != 0 not needed
        if(a[left] > b[right]) {
            ans.push_back(b[right]);
            right++;
        } else {
            ans.push_back(a[left]);
            left++;
        }
    }


    if(left < m) {
        for(int i = left; i < m; i++) {
            ans.push_back(a[i]);
        }
    }

    if(right < n) {
        for(int i = right; i < n; i++) {
            ans.push_back(b[i]);
        }
    }

    for(int i = 0; i < m+n; i++) {
        a[i] = ans[i];
    }
}

void switchElements(vector<int> &a, int tempValue, int index, int size)
{
    for(int i = index; i < size; i++) {
        int currentValue = a[i]; //0 , tempValue = 0
        a[i] = tempValue;
        tempValue = currentValue;
    }  
}

// Swap element and shift others to right approach, inefficient but just to coded for fun.
void mergeSorted(vector<int> &a, vector<int> &b, int m, int n)
{

    int size = m+n;

    int left = 0;
    int right = 0;


    if(n == 0) {
        print(a);
        return;
    }

    //using "m" as ceiling that would expand based on insertion of elements in a{}. this prevents left index to go beyond the last element and causing bugs to compare with 0s that are meant as extra space for b{} elements.
    int expand = m;

    //if first element is less and last element is less than first of b then just need to append
    //This condition doesn't stand correct for all test cases thus never to be tried.
    //if(a[0] < b[0] && a[m-1] <  b[n-1]) 

    
    if(a[0] > b[0] && a[m-1] > b[0] && m == n) { // m==n is important
        int index = 0;
        for(int i = m; i < m+n; i++) {
            a[i] = a[index];
            index++;
        }
	
        index = 0;
        for(int i = 0; i < m ; i++) {
            a[i] = b[index];
            index++;
        }

	print(a);
	return;
    }

    //approach of moving over all elements
    while(size != 0) {

        if(a[left] > b[right]) {

            //place and reposition all elements.
            int temp = a[left];
            a[left] = b[right];
            switchElements(a, temp, left+1, m+n);
            //replace index of right and left because right is taken n place
            right++;
            left++;
            expand++;

        } else {
            if(left+1 <= expand) {
                left++; //if left < right then move to the next element in b[right]
            }
        }
        size--;
    }

    if(right < n) {
        for(int i = right; i < n; i++) {
            a[left] = b[i];
            left++;
        }
    }
  
    print(a);
}

int main()
{
    vector<int> a = {1,2,3,0,0,0}; //m
    vector<int> b = {2,5,6};

    vector<int> a1 = {4,5,6,0,0,0}; //m=3, n =3
    vector<int> b1 = {1,2,3};

    vector<int> a2 = {4,0,0,0,0,0}; //M=1, n = 5
    vector<int> b2 = {1,2,3,5,6};

    vector<int> a3 = {1}; //m=1, n = 0
    vector<int> b3 = {};

    vector<int> a4 = {0,0,3,0,0,0,0,0,0};
    vector<int> b4 = {-1,1,1,1,2,3};

    vector<int> a6 = {1,2,3,0,0,0};
    vector<int> b6 = {4,5,6};

    vector<int> a5 = {1,2,4,5,6,0}; //5
    vector<int> b5 = {3}; //1

    // merge(a,3,b,3);
    // merge(a1,3,b1,3);
    // merge(a2, 1, b2, 5);
    // merge(a3, 1, b3, 0);
    // merge(a4, 3, b4, 6);


    // cout << "Final merge: " << endl;
    // print(a);
    // print(a1);
    // print(a2);
    // print(a3);
    // print(a4);

  
    cout << endl << "Using swap and shift technique: " << endl;
    mergeSorted(a,b,3,3);
    mergeSorted(a1,b1,3,3);
    mergeSorted(a2,b2,1,5);
    mergeSorted(a3,b3,1,0);
    mergeSorted(a4,b4,3,6);
    mergeSorted(a6,b6,3,3);
    mergeSorted(a5,b5,5,1);
    //print(a4);
}
