#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<int> res;
    int x = 0, y = 0;
    int dirs[5] = {0, 1, 0, -1, 0}, k = 0;
    for (int h = 0; h < m * n; h++) {
        res.push_back(matrix[x][y]);
        matrix[x][y] = 200;
        int i = x + dirs[k], j = y + dirs[k + 1];
        if (i < 0 || i >= m || j < 0 || j >= n || matrix[i][j] == 200) {
            k = (k + 1) % 4;
        }
        x += dirs[k];
        y += dirs[k + 1];
    }
    return res;
}

int main() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    auto res = spiralOrder(matrix);
    for (auto x : res) {
        cout << x << " ";
    }
}