#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ifstream in("input.txt");
    bool catchLine = true;
    string line;
    vector<string> board;

    while (getline(in, line)) {
        board.push_back(line);
    }

    int n = board[0].size();
    board[1][board[0].find('S')] = '|';

    int count = 0;
    for (int i = 2; i < board.size(); i += 2) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == '^') {
                if (board[i - 1][j] == '|') {
                    board[i + 1][j + 1] = board[i + 1][j - 1] = '|';
                    count++;
                }
            } else if (board[i - 1][j] == '|') board[i + 1][j] = '|';
        }
    }


    for (auto &line : board) {
        cout << line << '\n';
    }

    cout << "Final number of beams: " << count << '\n';

    return 0;
}