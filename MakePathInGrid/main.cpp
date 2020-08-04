#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;

int minCost(vector<vector<int>>& grid);

int main() {
    vector<vector<int>> grids0 = {{1,1,1,1},
                                  {2,2,2,2},
                                  {1,1,1,1},
                                  {2,2,2,2}};
    vector<vector<int>> grids1 = {{1,1,3},
                                  {3,2,2},
                                  {1,1,4}};
    vector<vector<int>> grids2 = {{1,2},
                                  {4,3}};
    vector<vector<int>> grids3 = {{2,2,2},
                                  {2,2,2}};
    vector<vector<int>> grids4 = {{4}};

    int r0 = minCost(grids0);
    cout << "grids0: " << r0 << endl;

    int r1 = minCost(grids1);
    cout << "grids1: " << r1 << endl;

    int r2 = minCost(grids2);
    cout << "grids2: " << r2 << endl;

    int r3 = minCost(grids3);
    cout << "grids3: " << r3 << endl;

    int r4 = minCost(grids4);
    cout << "grids4: " << r4 << endl;

    assert(r0 == 3);
    assert(r1 == 0);
    assert(r2 == 1);
    assert(r3 == 3);
    assert(r4 == 0);

    return 0;
}

struct Node {
    int x, y;
    int dist;

    Node(int x, int y, int dist): x(x), y(y), dist(dist) {}
    bool operator>(const Node& n) const { return dist > n.dist; }
};

int minCost(vector<vector<int>>& grid) {
    int row = grid.size(), col = grid.back().size();
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0},  {-1, 0}};

    vector<vector<bool>> visited(row, vector<bool>(col, false));

    priority_queue<Node, vector<Node>, greater<>> q;
    q.push(Node(0, 0, 0));
    visited[0][0] = true;

    int minCost = 0x3f3f3f3f;
    while (not q.empty()) {
        Node top = q.top();
        if (top.x == row - 1 and top.y == col - 1) {
            minCost = top.dist;
            break;
        }
        visited[top.x][top.y] = true;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = top.x + directions[i][0], ny = top.y + directions[i][1];
            if (nx < 0 or nx >= row or ny < 0 or ny >= col)
                continue;
            if (visited[nx][ny])
                continue;

            int dist = top.dist + ((i + 1 == grid[top.x][top.y]) ? 0 : 1);
            q.push(Node(nx, ny, dist));
        }
    }

    return minCost;
}