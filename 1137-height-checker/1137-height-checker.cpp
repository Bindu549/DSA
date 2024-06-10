#include <vector>
#include <algorithm>

class Solution {
public:
    int heightChecker(std::vector<int>& heights) {
        std::vector<int> expected = heights;
        std::sort(expected.begin(), expected.end());
        int c = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] != expected[i]) {
                c++;
            }
        }
        return c;
    }
};
