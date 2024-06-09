#include<bits/stdc++.h>
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        std::unordered_map<int, int> remainder_count;
        remainder_count[0] = 1;
        int prefix_sum = 0;
        int count = 0;

        for (int num : nums) {
            prefix_sum += num;
            int remainder = prefix_sum % k;
            
            if (remainder < 0) {
                remainder += k;
            }

            if (remainder_count.find(remainder) != remainder_count.end()) {
                count += remainder_count[remainder];
                remainder_count[remainder] += 1;
            } else {
                remainder_count[remainder] = 1;
            }
        }

        return count;
    }
};