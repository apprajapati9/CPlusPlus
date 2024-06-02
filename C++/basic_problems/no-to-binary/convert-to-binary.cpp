#include <iostream>
#include <vector>

using namespace std;

//TODO: try for negative numbers as well.
void convert(int n)
{
    vector<int> binary;
    

    while (n > 0) //number itself 0, thus stop.
    {
        
        binary.push_back(n % 2);
       
        n = n / 2;
    }

    for (int i = binary.size() - 1; i >= 0; i--)
    {
        cout << binary[i];
    }
}

int main()
{

    long number;
    cout << "Enter a num to convert into binary" << endl;
    cin >> number;

    convert(number);

    cout << endl;
}