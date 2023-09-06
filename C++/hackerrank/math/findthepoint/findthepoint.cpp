#include <bits/stdc++.h>

using namespace std;

/* Problem statement: 

Consider points p = p(x), p(y) and q = q(x), q(y). Find the inverse R(x, y) point at 180 degree ration from point p around q.

input: First line integer, n, denoting the number of sets of points.
        each of n, subsequent lines contain four space-separated integers that describe the respective value of px, py, qx and qy.
        defining p = p(x), p(y) and q = q(x), q(y).

output: int[2] = x and y coordinates of the reflected point R. 
*/

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
    This is where the calculation happens.
    Graphing the points really helps to solve this problem. 
    https://oercommons.s3.amazonaws.com/media/courseware/relatedresource/file/imth-6-1-9-6-1-coordinate_plane_plotter/index.html
    Above website has a nice graph that you can add point and visualize the answer. 
*/
vector<int> findPoint(int px, int py, int qx, int qy) {
    vector<int> mVector;
    mVector.push_back(qx*2-px);
    mVector.push_back(qy*2-py);
    return mVector;
}

int main()
{
    ofstream fout("./out.txt");

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    for (int n_itr = 0; n_itr < n; n_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int px = stoi(first_multiple_input[0]);

        int py = stoi(first_multiple_input[1]);

        int qx = stoi(first_multiple_input[2]);

        int qy = stoi(first_multiple_input[3]);

        vector<int> result = findPoint(px, py, qx, qy);

        for (size_t i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
