#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<vector<bool>> readInput();

int main() {
    int count = 0;
    vector<vector<bool>> grid = readInput();
    int height = grid.size();
    int width = grid[0].size();

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (!grid[j][i]) continue;
            int neighbours = 0;
            for (int xDiff = -1; xDiff < 2; xDiff++) {
                for (int yDiff = -1; yDiff < 2; yDiff++) {
                    int x = j + xDiff;
                    int y = i + yDiff;
                    if ((xDiff == 0 && yDiff == 0) || x < 0 || x >= width || y < 0 || y >= height) continue;
                    if (grid[x][y]) neighbours++;
                }
            }
            if (neighbours < 4) count++;
        }
    }

    cout << count << " rolls can be accessed\n";
}

vector<vector<bool>> readInput() {
    ifstream in("input.txt");
    string line;
    vector<vector<bool>> grid;

    while(getline(in, line)) {
        vector<bool> lineVector(line.size());
        for (int i = 0; i < line.size(); i++) {
            lineVector[i] = line[i] == '@' ? 1 : 0;
        }
        grid.push_back(lineVector);
    }

    return grid;
}