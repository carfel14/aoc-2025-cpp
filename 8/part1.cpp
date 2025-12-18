#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
#include <queue>

using namespace std;

class Point {
public:
    int idx;
    int x;
    int y;
    int z;

    Point(int idx_, int x_, int y_, int z_) 
        : idx(idx_), x(x_), y(y_), z(z_) {}
    

    friend std::ostream& operator<<(std::ostream& os, const Point& p);
    
};

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ", " << p.z << ")";
    return os;
}

class UnionFind {
    vector<int> parent, sz;
    public:
    UnionFind(int size) {
        parent.resize(size);
        sz.resize(size);
        for (int i = 0; i < size; i++) {
            parent[i] = i;
            sz[i] = 1;
        }
    }

    int find(int x) {
        if (parent[x] == x) return x;

        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return false;
        
        if (sz[a] < sz[b]) swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];

        return true;
    }

    int getSize(int i) {
        return sz[find(i)];
    }
};

class PointPair {
public:
    int i, j;
    double dist;

    PointPair(int i_, int j_, const vector<Point>& points)
        : i(i_), j(j_) {
        double dx = points[i].x - points[j].x;
        double dy = points[i].y - points[j].y;
        double dz = points[i].z - points[j].z;
        dist = std::sqrt(dx*dx + dy*dy + dz*dz);
    }

    friend std::ostream& operator<<(std::ostream& os, const PointPair& p);
};

std::ostream& operator<<(std::ostream& os, const PointPair& p) {
    os << "Indexes (" << p.i << "," << p.j << ')' <<  p.dist;
    return os;
}

struct CompareByDistanceMax {
    bool operator()(const PointPair& p1, const PointPair& p2) const {
        return p1.dist < p2.dist;
    }
};


int main() {
    ifstream in("input.txt");
    string line;
    vector<Point> points;
    int idx = 0;
    while(getline(in, line)) {
        int _x, _y, _z;
        sscanf(line.c_str(), "%d,%d,%d", &_x, &_y, &_z);
        points.emplace_back(idx, _x, _y, _z);
        idx++;
    }
    int n = points.size();
    UnionFind uf(n);

    priority_queue<PointPair, vector<PointPair>, CompareByDistanceMax> pq;
    // calculate distance of all points
    int k = 1000;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            PointPair pp = PointPair(i, j, points);
            // once calculated
            pq.push(pp);
            if (pq.size() > k) {
                pq.pop();
            }

        }
    }

    while (!pq.empty()) {
        auto pp = pq.top(); pq.pop();
        cout << "Indexes (" << points[pp.i].idx << "," << points[pp.j].idx << ") "
            << points[pp.i] << points[pp.j] << " dist=" << pp.dist << "\n";

        uf.unite(pp.i, pp.j);
    }

    priority_queue<int, vector<int>, greater<int>> pqLargestGroups;
    for (int i = 0; i < n; i++) {
        if (uf.find(i) == i) {          // i is a root
            pqLargestGroups.push(uf.getSize(i));
            // cout << "For i = " << i << ": " << uf.getSize(i) << '\n';
            if (pqLargestGroups.size() > 3) pqLargestGroups.pop();
        }
    }

    int ans = 1;

    while (!pqLargestGroups.empty()) {
        int pp = pqLargestGroups.top(); 
        pqLargestGroups.pop();
        ans *= pp;
    }

    cout << "Fokin ans is: " << ans << '\n';

    return 0;
}