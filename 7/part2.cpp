#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

string print128(__int128 x) {
    if (x == 0) { return "0"; }
    string s;
    if (x < 0) { s += '-'; x = -x; }

    while (x > 0) {
        s.push_back('0' + x % 10);
        x /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    ifstream in("input.txt");
    bool catchLine = true;
    string line;
    vector<string> board;

    while (getline(in, line)) {
        board.push_back(line);
    }

    int n = board[0].size();
    int initialPos = board[0].find('S');
    board[1][initialPos] = '|';
    vector<__int128> timelines(n, 0ll);
    timelines[initialPos] = 1ll;
    
    for (int i = 2; i < board.size(); i += 2) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == '^') {
                if (board[i - 1][j] == '|') {
                    board[i + 1][j + 1] = board[i + 1][j - 1] = '|';
                    timelines[j - 1] += timelines[j];
                    timelines[j + 1] += timelines[j];
                    timelines[j] = 0ll;
                }
            } else if (board[i - 1][j] == '|') board[i + 1][j] = '|';
        }
    }


    for (auto &line : board) {
        cout << line << '\n';
    }
 
    cout << "Final number of timelines: " << print128(accumulate(timelines.begin(), timelines.end(), (__int128)0)) << '\n';

    return 0;
}