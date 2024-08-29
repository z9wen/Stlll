#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        std::size_t n = grid.size();
        std::size_t m = grid[0].size();
        
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < m; j++) {
                // Check the condition with the cell below
                if (i < n - 1 && grid[i][j] != grid[i + 1][j]) {
                    return false;
                }
                // Check the condition with the cell to the right
                if (j < m - 1 && grid[i][j] == grid[i][j + 1]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution s;

    // Test case 1
    vector<vector<int>> grid1 = {{1, 0, 2}, {1, 0, 2}};
    assert(s.satisfiesConditions(grid1) == true);
    cout << "Test case 1 passed." << endl;

    // Test case 2
    vector<vector<int>> grid2 = {{1, 1, 1}, {0, 0, 0}};
    assert(s.satisfiesConditions(grid2) == false);
    cout << "Test case 2 passed." << endl;

    // Test case 3
    vector<vector<int>> grid3 = {{1}, {2}, {3}};
    assert(s.satisfiesConditions(grid3) == false);
    cout << "Test case 3 passed." << endl;

    return 0;
}