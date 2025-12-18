#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> lines;
    long long ans = 0;
    {
        ifstream in("input.txt");
        string line;
        while (getline(in, line)) {
            lines.push_back(line);
        }
    }
    int n = lines.size();
    vector<pair<int, char>> operators;
    for (int i = 0; i < lines[n - 1].size(); i++) {
        if (lines[n - 1][i] != ' ') operators.emplace_back(i, lines[n - 1][i]);
    }
    operators.emplace_back(lines[n - 1].size(), ' ');

    for (int i = 0; i < operators.size() - 1; i++) {        
        long long value = (operators[i].second == '+' ? 0 : 1);
        for (int j = 0; j < n - 1; j++) {
           long long actual = stoll(lines[j].substr(operators[i].first, operators[i + 1].first - operators[i].first));
           if (operators[i].second == '+') value += actual;
           else value *= actual;
        }
        ans += value;
    }

    cout << "Total: " << ans << '\n';

    return 0;
}