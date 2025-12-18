#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

long long expoloreRanges(long long ll, long long ul) {
    long long n = 0;
    int ll_digits = log10(ll) + 1;
    int ul_digits = log10(ul) + 1;

    if ((ll_digits % 2) && (ul_digits % 2)) return 0;
    if (ll_digits != ul_digits) {
        if (ll_digits % 2) {
            ll = (int) pow(10, ll_digits);
            ll_digits++;
        } else {    
            ul = (int) pow(10, ul_digits - 1) - 1;
            ul_digits--;
        }
    }

    long long base =  pow(10LL, (long long)ll_digits / 2LL);

    long long first_lower = ll / base;
    long long second_lower = ul / base;
    // cout << first_lower << " || " << second_lower << '\n';
    long long first_upper = ll % base;
    long long second_upper = ul % base;
    // cout << first_upper << " || " << second_upper << '\n';

    long long lower = first_lower + 1;
    long long upper = second_lower;

    n += second_lower - first_lower;
    if (first_lower >= first_upper){
        n++;
        lower--;
    } 
    if (second_lower > second_upper){
        n--;
        upper--;
    } 
    long long S = 0;
    long long sum = 0;

    S = (1LL * n * (upper + lower)) / 2; 
    // cout << "lower: " << lower << '\n';
    // cout << "upper: " << upper << '\n';
    // cout << "n: " << n << '\n';
    // cout << "S: " << S << '\n';
    // cout << "Multiplier: " << base + 1 << '\n';
    sum = S * (base + 1);
    // cout << "ll: " << ll << '\n';
    // cout << "ul: " << ul << '\n';
    // cout << "inner sum: " << sum << '\n';

    return sum;
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
        total += expoloreRanges(ll, ul);
    }
    cout << "Fokin Total: " << total << '\n';
    return 0;
}