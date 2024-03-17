#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n) {
    int m = n * n;
    int dirs[5] = {0, 1, 0, -1, 0}, k = 0;
    vector<vector<int>> res(n, vector<int>(n, 0));
    int x = 0, y = 0;
    for (int h = 1; h <= m; h++) {
        res[x][y] = h;
        int i = x + dirs[k], j = y + dirs[k + 1];
        if (i < 0 || i >= n || j < 0 || j >= n || res[i][j] != 0) {
            k = (k + 1) % 4;
        }
        x += dirs[k];
        y += dirs[k + 1];
    }
    return res;
}

