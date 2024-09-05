#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> missingRolls(std::vector<int>& rolls, int mean, int n) {
        std::size_t m = rolls.size();
        int sum = 0;
        for (std::size_t i = 0; i < m; i++) {
            sum += rolls[i];
        }
        int total = mean * (static_cast<int>(m) + n);
        int remaining = total - sum;
        if (remaining < n || remaining > 6 * n) {
            return {};
        }
        std::vector<int> result(static_cast<std::size_t>(n), remaining / n); 
        for (int i = 0; i < remaining % n; i++) {
            result[static_cast<std::size_t>(i)]++;
        }
        return result;
    }
};

int main() {
    Solution s;
    std::vector<int> rolls = {3, 2, 4, 3};
    int mean = 4;
    int n = 2;
    std::vector<int> result = s.missingRolls(rolls, mean, n);
    for (std::size_t i = 0; i < result.size(); i++) { 
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
}
