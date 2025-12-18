#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ifstream in("input.txt");
    string line;
    vector<pair<long long, long long>> limits;

    while(getline(in, line)) {
        if (line.empty()) break;
        long long a;
        long long b;
        sscanf(line.c_str(), "%jd-%jd", &a, &b);
        limits.emplace_back(a, b);
    }

    sort(limits.begin(), limits.end());

    // will try to merge limits
    vector<pair<long long, long long>> merged;
    long long ll = limits[0].first;
    long long ul = limits[0].second;
    for (int i = 1; i < limits.size(); i++) {
        if (limits[i].first > ul){
            merged.emplace_back(ll, ul);
            ll = limits[i].first;
            ul = limits[i].second;
        } else {
            ul = max(ul, limits[i].second);
        }
    }
    merged.emplace_back(ll, ul);
    long long count = 0;
    for (auto &[ll, ul] : merged) {
        // cout << ll << "-" << ul << '\n';
        count += (ul - ll + 1);
    }
    cout << "Total Ingredients: " << count << '\n';
}
