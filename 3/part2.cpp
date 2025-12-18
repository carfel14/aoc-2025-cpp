#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main() {
    ifstream in("input.txt");
    string line;
    long long total = 0;

    while(getline(in, line)) {
        int currIndex = 0;
        long long joltage = 0;
        for (int i = 0; i < 12; i++) {
            int room = line.size() - 11 + i;
            int maxIndex = currIndex;
            for (int j = currIndex; j < room; j++) {
                if (line[j] > line[maxIndex]) {
                    maxIndex = j;
                }
            }
            joltage = joltage * 10 + (line[maxIndex] - 48);
            currIndex = maxIndex + 1;
        }
        // cout << "Line value: " << joltage << '\n';
        total += joltage;
    }
    // cout << "Total Count: " << total << '\n';
    return 0;
}