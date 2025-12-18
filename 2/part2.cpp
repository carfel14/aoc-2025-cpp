#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

bool isInvalid(long long number) {
    int digits = log10(number) + 1;

    for (int i = 2; i <= digits; i++) {
        if ((digits % i) != 0) continue;
        int portion_size = digits / i;
        long long past_portion;
        int flag = true;

        for (int j = 0; j < digits; j += portion_size) {
            long long actual_portion = (number / (long long) pow(10, j)) % (long long) pow(10, portion_size);
            if (j != 0 && actual_portion != past_portion) {
                flag = false;
                break;
            }
            past_portion = actual_portion;
        }

        if (flag) return true;
    }
    return false;
}

int main() {
    ifstream in("input.txt");
    vector<pair<long long,long long>> limits;
    string str;

    while (getline(in, str, ',')) {
        long long ll;
        long long ul;
        sscanf(str.c_str(), "%jd-%jd", &ll, &ul);
        limits.push_back(make_pair(ll, ul));
    }
    long long total = 0;
    for (auto &[ll, ul] : limits) {
        for (long long i = ll; i <= ul; i++) {
            if (isInvalid(i)) {
                total += i;
                cout << i << '\n';
            }
        }
    }
    cout << "Fokin Total: " << total << '\n';
    return 0;
}