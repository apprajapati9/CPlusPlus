#include <iostream>

using namespace std;

/*
#
##
###
####
#####
*/
void progressiveStaircase(int number)
{

    // Better
    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "#";
        }
        cout << endl;
    }

    // Different way
    //  for (int i = 0; i < number; i++){
    //      for (int j = 0; j < number; j++){
    //          if(i >= j){
    //              cout << "#";
    //          }
    //      }
    //      cout << endl;
    //  }
}

/*
#####
####
###
##
#
*/
void reverseStaircase(int number)
{
    for (int i = 0; i < number; i++)
    {
        for (int j = i; j < number; j++)
        {
            cout << "#";
        }
        cout << endl;
    }
}

/*
    #
   ##
  ###
 ####
#####
*/

void progressiveStaircaseRight(int number)
{

    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < number; j++)
        {
            if (i + j >= number - 1)
            {
                cout << "#";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    // for (int i = 0; i < number; i++){
    //     for (int j = i+1; j < number; j++){
    //         cout << " ";

    //     }
    //     for (int k = 0; k <= i; k++){
    //         cout << "#";
    //     }
    //     cout << endl;
    // }
}

/*
#####
 ####
  ###
   ##
    #
*/

void progressiveStaircaseLeft(int number)
{

    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < number; j++)
        {
            if (i <= j)
            {
                cout << "#";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    // for (int i = 0; i < number; i++){

    //     for (int k = i, d = 1; k > 0 && d <= i ; d++){
    //         cout << " ";
    //     }

    //     for (int j = i; j < number; j++){
    //         cout << "#";
    //     }
    //     cout << endl;
    // }
}
/*
     #
    ###
   #####
  #######
 #########
*/
// Proud to have it done myself. I= row, J=column.
void pyramid(int number)
{

    int row = number;
    number = number * 2;
    if (number % 2 == 0)
    { // normalizing number so has equal amount of number on both sides.
        number = number + 1;
    }
    int mid = number / 2; // not adding 1 because loop starts from 0. 5= 5/2= 2 = 0 1 2 3 4 = 2 mid
    cout << "row=" << row << " column=" << number << " mid=" << mid << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < number; j++)
        {
            if (j <= mid + i && j >= mid - i)
            {
                cout << "#";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void stairRecursion(int n)
{
    if (n <= 0)
    {
        return;
    }
    stairRecursion(n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << "#";
    }
    cout << endl;
}

int main()
{

    progressiveStaircase(5);
    cout << "-------" << endl;
    reverseStaircase(5);
    cout << "-------" << endl;
    progressiveStaircaseRight(5);
    cout << "-------" << endl;
    progressiveStaircaseLeft(5);
    cout << "-------" << endl;

    pyramid(5);
    cout << endl;

    cout << "------------" << endl;
    stairRecursion(5);

    return 0;
}