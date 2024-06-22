#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> binary(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            binary[i] = nums[i] % 2;
        }
        
        unordered_map<int, int> count_map;
        count_map[0] = 1;
        int prefix_sum = 0;
        int result = 0;
        
        for (int num : binary) {
            prefix_sum += num;
            if (count_map.find(prefix_sum - k) != count_map.end()) {
                result += count_map[prefix_sum - k];
            }
            count_map[prefix_sum]++;
        }
        
        return result;
    }
};
