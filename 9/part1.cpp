    // track upper leftmost and rightmost
    // track lower leftmost and rightmost
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Point {
public:
    int x, y;

    Point(int x_, int y_) :
    x(x_), y(y_) {}

    friend std::ostream& operator<<(std::ostream& os, const Point &p);
};

std::ostream& operator<<(std::ostream& os, const Point &p) {
    os << "Point(" << p.x << ", " << p.y << ")";
    return os;
}

int main() {
    ifstream in("input.txt");
    string line;

    Point upperLeftmost(INT_MAX / 2, INT_MAX / 2);
    Point upperRightmost(0, 0);
    Point lowerLeftmost(0, 0);
    Point lowerRightmost(0, 0);

    while (getline(in, line))   {
        int x, y;
        sscanf(line.c_str(), "%d,%d", &x, &y);
        Point p(x, y);

        if ((p.x + p.y) < (upperLeftmost.x + upperLeftmost.y)) {
            upperLeftmost = p;
        }
        if ((p.x + p.y) > (lowerRightmost.x + lowerRightmost.y)) {
            lowerRightmost = p;
        }
        if ((p.x - p.y) > (upperRightmost.x - upperRightmost.y)) {
            upperRightmost = p;
        }
        if ((p.y - p.x) > (lowerLeftmost.y - lowerLeftmost.x)) {
            lowerLeftmost = p;
        }

    }

    long long area1 = ((long long)lowerRightmost.x - upperLeftmost.x + 1) * (lowerRightmost.y - upperLeftmost.y + 1);
    long long area2 = ((long long)upperRightmost.x - lowerLeftmost.x + 1) * (lowerLeftmost.y - upperRightmost.y + 1);
    cout << upperLeftmost << '\n' << lowerRightmost << '\n' << area1 << '\n';
    cout << upperRightmost << '\n' << lowerLeftmost << '\n' << area2 << '\n'; 

    cout << "Max area is: " << max(area1, area2) << '\n';


    return 0;
}