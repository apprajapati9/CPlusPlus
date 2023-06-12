#include <iostream>
#include <vector>

/*
1572. Matrix diagonal sum (Leetcode)

Given a square matrix M, return the sum of the matrix diagonals.

Only include the sum of all the elements on the primary diagonal and
all the elements on the secondary diagonal that are not part of the primary diagonal.

*/

using namespace std;

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

int diagonalSum(vector<vector<int>> &mat)
{
    int sum = 0;
    int size = mat.size();

    for (int i = 0, j = mat.size() - 1; i < mat.size(); i++, j--)
    {
        sum += mat[i][i] + mat[i][j];
    }

    if (mat.size() % 2 != 0)
    {
        sum -= mat[size / 2][size / 2];
    }

    return sum;
}
// Better approach.
int diagonalSumSingleTraverse(vector<vector<int>> &matrix)
{
    int size = matrix.size();
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += matrix[i][i] + matrix[i][size - i - 1]; // 3-0-1 = 2, 3-1-1 = 1, 3-2-1 = 0
    }
    if (size % 2 != 0)
    {
        return sum - matrix[size / 2][size / 2];
    }
    return sum;
}

int main()
{

    vector<vector<int>> mat{
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; // Answer=25

    vector<vector<int>> mat2{
        {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}}; // Answer=8

    vector<vector<int>> mat3{
        {5}}; // Answer=5

    cout << "Diagonal Sum=" << diagonalSum(mat);
    cout << endl;
    cout << "Diagonal Sum=" << diagonalSum(mat2);
    cout << endl;
    cout << "Diagonal Sum=" << diagonalSum(mat3);

    cout << endl;
    cout << "=Single Traverse approach=" << endl;
    cout << "Diagonal Sum=" << diagonalSumSingleTraverse(mat) << endl;
    cout << "Diagonal Sum=" << diagonalSumSingleTraverse(mat2) << endl;
    cout << "Diagonal Sum=" << diagonalSumSingleTraverse(mat3) << endl;
    ;
    cout << endl;
}
