#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int mod(int n) {
    return (n % 100 + 100) % 100;
}

int main() {
    int position = 50;
    int count = 0;

    ifstream in("input.txt");
    string line;

    while (getline(in, line)) {
        // parse
        char direction;
        int number;
        sscanf(line.c_str(), " %c%d", &direction, &number);

        // calculate clicks
        int rotations = (direction == 'R') ? number : -number;

        // full 100-step cycles: each crosses 0 once
        count += abs(rotations) / 100;

        int rem = rotations % 100;

        // positive remainder (moving right)
        if (rem > 0 && position + rem >= 100)
            count++;

        // negative remainder (moving left)
        if (rem < 0 && position > 0 && position + rem <= 0)
            count++;

        // update position on dial
        position = mod(position + rotations);
    }

    cout << "COUNT: " << count << '\n';
    return 0;
}
