#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int increments = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] <= nums[i - 1]) {
                int needed_increment = nums[i - 1] - nums[i] + 1;
                nums[i] += needed_increment;
                increments += needed_increment;
            }
        }
        return increments;
    }
};
