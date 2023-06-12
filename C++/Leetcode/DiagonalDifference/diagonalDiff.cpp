#include <iostream>
#include <vector>

/*
Given a square matrix, calculate the absolute difference between the sums of diagonals.
input N - n represents equal amount of rows and columns.

Example: N= 3 (rows, columns) - input matrix
                    {{11, 2, 4},
                    {4, 5, 6},
                    {10, 8, -12}};

1st diagonal - 11,5,-12 = 4
2nd diagonal - 4,5,10   = 19
---- Difference is |4-19| = 15

*/

using namespace std;

void DiagonalDiffUsingArray()
{

    int arr[3][3] = {{11, 2, 4},
                     {4, 5, 6},
                     {10, 8, -12}};

    // int result = diagonalDiff(reinterpret_cast<int*>(array), matrixN, matrixN);

    int diff = 0;
    int sum1 = 0;
    int sum2 = 0;

    for (int i = 0, j = 3 - 1; i < 3; i++, j--)
    {
        sum1 = sum1 + arr[i][i];
        sum2 = sum2 + arr[i][j];
    }

    cout << "the diff " << abs(sum1 - sum2) << endl;
}

void print2DVector(const vector<vector<int>> &TwoDVector)
{
    cout << "Printing Vector->" << endl;
    for (const auto &row : TwoDVector)
    {
        for (int element : row)
        {
            cout << element;
        }
        cout << endl;
    }
}

void DiagonalDiffUsingVector()
{
    int rows, columns;
    int sum1 = 0;
    int sum2 = 0;

    cout << "Enter Rows ";
    cin >> rows;
    cout << "Enter Colums ";
    cin >> columns;

    vector<vector<int>> TwoDVector(rows, vector<int>(columns));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cin >> TwoDVector[i][j];
        }
    }

    // printVector(TwoDVector); //To print a 2d vector

    for (int i = 0, j = TwoDVector.size() - 1; i < rows; i++, j--)
    {                             // Think of it X from top - matrix array format.
        sum1 += TwoDVector[i][i]; // 1- 0 0 | 2- 1 1 | 3- 2 2   ---> Iterration- index index
        sum2 += TwoDVector[i][j]; // 1- 0 2 | 2- 1 1 | 3- 2 0
    }
    cout << endl;
    cout << "Vector Ans: " << abs(sum1 - sum2) << endl;
}

int diagonalDiff(vector<vector<int>> matrixV)
{
    int sum1 = 0;
    int sum2 = 0;
    int size = matrixV.size(); 
    for (int i = 0; i < size; i++)
    {
        sum1 += matrixV[i][i];
        sum2 += matrixV[i][size-i-1];
    }
    return abs(sum1 - sum2);
}

int main()
{

    // DiagonalDiffUsingArray();
    // DiagonalDiffUsingVector();

    vector<vector<int>> myVector{
        {11, 2, 4}, {4, 5, 6}, {10, 8, -12}}; // answer 15

    vector<vector<int>> d4vector{{-1, 1, -7, -8}, {-10, -8, -5, -2}, {0, 9, 7, -1}, {4, 4, -2, 1}}; // answer 1

    cout << diagonalDiff(myVector) << endl;
    // print2DVector(d4vector);

    return 0;
}

void inputFromArray()
{

    /*
    in C++, arrays input uses delimiter of whitespace or newline, so you can directly take an input of 2D array by adding space.
    */

    int matrixN = 0;
    int array[matrixN][matrixN];

    cout << "How many rows and columns?" << endl;
    cin >> matrixN;
    for (int i = 0; i < matrixN; i++)
    {
        for (int j = 0; j < matrixN; j++)
        {
            cin >> array[i][j];
        }
    }
    // Printing 2d array
    for (int i = 0; i < matrixN; i++)
    {
        for (int j = 0; j < matrixN; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}
