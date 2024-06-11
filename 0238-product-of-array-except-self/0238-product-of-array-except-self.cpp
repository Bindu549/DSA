#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);

        int leftProduct = 1;
        int i = 0;
        for (auto it : nums) {
            result[i] = leftProduct;
            leftProduct *= it;
            ++i;
        }

        int rightProduct = 1;
        i = n - 1;
        for (auto it = nums.rbegin(); it != nums.rend(); ++it) {
            result[i] *= rightProduct;
            rightProduct *= *it;
            --i;
        }

        return result;
    }
};
