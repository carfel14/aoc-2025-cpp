#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int main() {
    ifstream in("input.txt");
    string line;
    vector<pair<long long, long long>> limits;
    int count = 0;

    while(getline(in, line)) {
        if (line.empty()) break;
        long long a;
        long long b;
        sscanf(line.c_str(), "%lld-%lld", &a, &b);
        limits.emplace_back(a, b);
    }

    while(getline(in, line)) {
        long long number;
        sscanf(line.c_str(), "%jd", &number);

        for (auto &[ll, ul] : limits) {
            if (number >= ll && number <= ul) {
                count++;
                break;
            }
        }
    }

    cout << "Total Ingredients: " << count << '\n';
}
