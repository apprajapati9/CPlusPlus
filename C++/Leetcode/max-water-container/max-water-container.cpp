/*
Container with most water

You are given an integer array heights where heights[i] represents the height of the i-th bar. There are n vertical lines drawn such that the endpoints of the i-th bar are (i,0) and (i, height[i])

You may choose any two bars to form a container. Return the maximum amount of water a container can store.

Find two lines that together form a container such that the container contains the most water.
*/

#include <iostream>
#include <vector>

using namespace std;

void getArrData(vector<vector<int>>& vec)
{

    vector<int> arr = {1,8,6,2,5,4,8,3,7}; //Ans is 49
    vector<int> arr2  = {1,7,2,5,4,7,3,6}; // ans is 36
    vector<int> arr3 = {2,2,2};

    vector<vector<int>> mVector;

    //In vector vec.end() points at the top of elements, begin() adds elements at the end, like push_back method
    vec.insert(vec.end(),arr);
    vec.insert(vec.end(),arr2);
    vec.insert(vec.end(),arr3);


    /*
     vector<vector<int>>* vec = new vector<vector<int>>(rows,vector<int>(cols,0)); //To dynamically allocate 2d array

     (*vec)[i][j] // to access elements after deref.
    */
}

int findMin(int a, int b)
{
    return a > b ?  b : a;
}

/*
To solve this problem, the important thing to understand is that besides the minimum value between 2 indices, you have to calculate how many indices are between those two.

Forumla is as follows:
    Water = min(height[i], height[j]) * (j-i)

    where j and i are indexes. You have to calculate how much water is between 2 numbers by deteriming the min between 2 numbers and then how big the container is, is determined by knowing how many indexes are in between which is j-i.

    If values are at 0[8] and 4[6]
    then water would be
    min(8,6) = 6
    4-0 = 4
    4*6= 24.
*/


//On2 solution - inefficient
void findMostWater(vector<vector<int>>& heights)
{
    cout << "Bruteforce solution: " << endl;
    int water = 0;

    for(int i = 0; i < heights.size(); i++) {
        for(int j = 0; j < heights[i].size(); j++) {

            for(int k = j+1; k < heights[i].size(); k++) {

                int min  = findMin(heights[i][j], heights[i][k]);
                int w = k - j;
                int ans = min * w;
                if(ans > water) {
                    water = ans;
                }
            }

        }
        cout << "Ans: " << water <<  endl;
        water = 0;

    }
}

// On solution because there's no extra iteration for indices.
void findMostWaterUsing2Pointers(vector<vector<int>> &heights)
{
    cout << "O(n) solution: " << endl;
    int water = 0;

    int size = heights.size();

    for(int i = 0; i < size; i++) {

        for(int j = 0; j < heights[i].size(); j++) {

            int left = 0;
            int right = heights[i].size() - 1;

            while(left != right) {

                int l = heights[i][left];
                int r = heights[i][right];

                int distance = right - left;
                int min = findMin(l,r);

                if((distance * min) > water) {
                    water = distance * min;
                }

                if(l < r) {
                    left++;
                } else {
                    right--;
                }

            }

        }
        cout << "Pointer Ans: " << water <<  endl;
        water = 0;

    }
}

int main()
{

    int rows = 0;
    int cols = 0;
    vector<vector<int>> vec = vector<vector<int>>(rows,vector<int>(cols,0));

    getArrData(vec);

    for(auto i : vec) {
        for(auto j: i) {
            cout << j << ",";
        }
        cout << endl;
    }

    findMostWater(vec);

    findMostWaterUsing2Pointers(vec);

    return 0;
}
