
class Solution {
public:
    int findMaxConsecutiveOnes(std::vector<int>& nums) {
        int count = 0;
        int maxx = 0;
        
        for (auto it : nums) {
            if (it == 1)
                count++;
            else
                count = 0;
            
            maxx = std::max(maxx, count);
        }
        
        return maxx;
    }
};
