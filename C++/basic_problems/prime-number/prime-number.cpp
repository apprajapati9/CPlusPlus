#include <iostream>
#include <math.h>
#include <vector>

using namespace std;
/*
This program is using Sieve of Eratosthenes algorithm to print range of prime till a given number.
*/

int main()
{

    vector<int> nums;
    unsigned int n;
    cout << "Enter upper bound (positive) " << endl;
    cin >> n;

    for (int i = 0; i <= n; i++)
    {
        nums.push_back(i);
    }

    nums[0] = 0;
    nums[1] = 0;

    for (unsigned int i = 2; i <= sqrt(n); i++) //sqrt is optimization to stop after sqrt of n, bcz there's never going to be a factor
    {
        for (int j = i; j*i <= n; j++)  //this loops does 2*2,2*3,2*4 ... 2*n.. and run till only i.e 2? 50*2 = 100 so run till 50 only. 
        {
            if (nums[i] != 0 && i * j <= n)
            {
                // cout << i * j << ",--";
                nums[i * j] = 0;
            }
        }
        // cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
        {
            cout << nums[i] << ", ";
        }
    }

    cout << endl;
}