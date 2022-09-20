#include <iostream>
#include <vector>

using namespace std;

/*
    Given an array of integers nums sorted in non-decreasing order,
    find the starting and ending position of a given target value.

    if target is not found then return [-1,-1]

    must write an alorithm with o(log n) runtime complexity
*/

class Solution
{

public:
    vector<int> searchRange(vector<int> &numbs, int target)
    {

        vector<int> v;

        int start = 0;
        int end = numbs.size() - 1;

        int middle = -1;
        int value = -1;

        int f = -1;
        int l = -1;

        while (start <= end)
        {
            middle = (start + end) / 2;

            if (target < numbs[middle])
            {
                end = middle - 1;
            }
            else if (target > numbs[middle])
            {
                start = middle + 1;
            }
            else
            {
                value = middle;
                break;
            }
        }

        if (value == -1)
        {
            v.push_back(f);
            v.push_back(l);
            return v;
        }

        if (numbs[middle + 1] == target)
        {
            for (int i = middle; i <= end; i++)
            {
                if (numbs[i] == target)
                {
                    l = i;
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            l = middle;
        }

        if (numbs[middle - 1] == target)
        {
            for (int i = middle; i >= 0; i--)
            {
                if (numbs[i] == target)
                {
                    f = i;
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            f = middle;
        }

        // v.push_back(binary_search(numbs, target, true));
        // v.push_back(binary_search(numbs, target, false));
        return {f, l};
    }

    //This function does work perfectly but, leetcode doesn't accept this solution because of time restrictions.
    int binary_search(vector<int> &nums, int target, bool isLeft)
    {
        printVect(nums);
        int start = 0;
        int end = nums.size() - 1;
        int middle;

        // [5,7,7,8,8,8]

        // middle = 7 , start = 5, end = 8, target = 8

        int value = -1;

        while (start <= end)
        {
            middle = (start + end) / 2; // 0+5/2 = 2  --- middle = 7  || 2. (3+5)/2 = 8/2=4 m = 4(8) || 3.

            if (target < nums[middle])
            {                     // 1 = 8 < 7
                end = middle - 1; // 1 = start = 2+1 = 3,
            }
            else if (target > nums[middle])
            {
                start = middle + 1;
            }
            else
            {
                value = middle;
                if (isLeft)
                { // if want to go left, then minimize right, if want to go right, then minimize left size.
                    end = middle - 1;
                    // to check the first element where there will be no middle, far left 3+5/2= 8/2 = 4
                }
                else
                {
                    start = middle + 1;
                    // to check the last element where there will be no middle, far right 5+5/2 = 5 = same position so it means we reached the end
                }
            }
        }
        return value;
    }

    void printVect(vector<int> &v)
    {
        cout << "[";
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i];
            if (i != v.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
};

int main()
{

    Solution *so = new Solution();

    int sizeOfVector = 0;
    vector<int> data;

    cout << "How many elements in an array?" << endl;
    cin >> sizeOfVector;

    int input;
    for (int i = 0; i < sizeOfVector; i++)
    {
        cin >> input;
        data.push_back(input);
    }

    int target;
    cout << "Enter target =";
    cin >> target;
    cout << endl;

    data = so->searchRange(data, target);
    so->printVect(data);
}