#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {

    public: 

        bool isValidSudoku(vector<vector<string>> &sudoku) {

            int size = sudoku.size();

            for(auto i: sudoku){
                unordered_set<string> set;

                for(auto j : i){

                    if(set.count(j)) return false;
        
                    if(j != ".")
                        set.insert(j);
                    }
            }

            int counter = 0;
            for (int i = 0; i < size; i++) {

                unordered_set<string> set;
                for (int j = 0; j < size; j++) {
                    //[0,0], [0,1]

                    string s = sudoku[j][counter]; // 0,1,02,03,05

                    if(set.count(s))
                        return false;
                    
                    if(s != "."){
                        set.insert(s);
                    }
                }
                counter++;
            }

        
        // // now 3x3 -- printing this output to visualize. If not wanted, remove cout << calls.
        for (int i = 0; i < size/3; i++){

                //0, 1 , 2 
                //0,1, 0, 2, 03
                for (int j = 0; j < size / 3; j++){

                    int col = i * 3; // 0*3 = 0, 1*3= 3, 2*3= 6 // 0/3/6
                    int row = j * 3; 
                    unordered_set<string> set;

                    for (int c = col; c < col + 3; c++){

                        for (int r = row; r < row + 3; r++){

                            string s = sudoku[c][r]; //column /row

                            if(set.count(s))
                                return false;

                            if(s != "."){
                                set.insert(s);
                            }
                            //cout << s << " ";
                        }
                        //cout << endl;
                    }
                    //cout << endl;
                }
                //cout << endl;
            }

            return true;
        
        }

};

int main () {
	//printf("Hello World");

	//vector<vector<char>> sudoku(9, vector<char>(9, 48));
	vector < vector < string >> sudoku = {
		{"1", "2", ".", ".", "3", ".", ".", ".", "."},
		{"4", ".", ".", "5", ".", ".", ".", ".", "."},
		{".", "9", "1", ".", ".", ".", ".", ".", "3"},
		{"5", ".", ".", ".", "6", ".", ".", ".", "4"},
		{".", ".", ".", "8", ".", "3", ".", ".", "5"},
		{"7", ".", ".", ".", "2", ".", ".", ".", "6"},
		{".", ".", ".", ".", ".", ".", "2", ".", "."},
		{".", ".", ".", "4", "1", "9", ".", ".", "8"},
		{".", ".", ".", ".", "8", ".", ".", "7", "9"}
	};

	vector < vector < string >> sudoku2 = {
		{"1", "2", ".", ".", "3", ".", ".", ".", "."},
		{"4", ".", ".", "5", ".", ".", ".", ".", "."},
		{".", "9", "1", ".", ".", ".", ".", ".", "3"},
		{"5", ".", ".", ".", "6", ".", ".", ".", "4"},
		{".", ".", ".", "8", ".", "3", ".", ".", "5"},
		{"7", ".", ".", ".", "2", ".", ".", ".", "6"},
		{".", ".", ".", ".", ".", ".", "2", ".", "."},
		{".", ".", ".", "4", "1", "9", ".", ".", "8"},
		{".", ".", ".", ".", "8", ".", ".", "7", "9"}
	};

	vector < vector < string >> validSudoku =
	{	{"1","2",".",".","3",".",".",".","."},
		{"4",".",".","5",".",".",".",".","."},
		{".","9","8",".",".",".",".",".","3"},
		{"5",".",".",".","6",".",".",".","4"},
		{".",".",".","8",".","3",".",".","5"},
		{"7",".",".",".","2",".",".",".","6"},
		{".",".",".",".",".",".","2",".","."},
		{".",".",".","4","1","9",".",".","8"},
		{".",".",".",".","8",".",".","7","9"}
	};



// 	for (auto i:validSudoku)
// 	{
// 		for (auto j:i)
// 		{
// 			cout << j << " ";
// 		}
// 		cout << endl;
// 	}

	Solution s;

	cout << endl << "validSudoku->" << s.isValidSudoku (validSudoku) << endl;
	cout << endl << "sudoku2-> " << s.isValidSudoku (sudoku2) << endl;
	cout << endl << "sudoku->" << s.isValidSudoku (sudoku) << endl;

	return 0;
}
