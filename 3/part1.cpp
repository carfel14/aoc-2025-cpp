#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main() {
    ifstream in("input.txt");
    string line;
    long long count = 0;

    while(getline(in, line)) {
        int maxFirstIndex = 0;
        for (int i = 0; i < line.size() - 1; i++) {
            if (line[i] > line[maxFirstIndex]) {
                maxFirstIndex = i;
            }
        }
        int maxSecondIndex = maxFirstIndex + 1;
        for (int i = maxFirstIndex + 1; i < line.size(); i++) {
            if (line[i] > line[maxSecondIndex]) {
                    maxSecondIndex = i;
            }
        }
        int lineValue = ((line[maxFirstIndex] - 48) * 10) + (line[maxSecondIndex] - 48);
        cout << "Line value: " << lineValue << '\n';
        count += lineValue; 
    }
    cout << "Total Count: " << count << '\n';
    return 0;
}