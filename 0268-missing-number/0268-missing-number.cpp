class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int orgsum = n*(n+1)/2,sum=0;
        for(auto it:nums){
            sum+=it;
        }
        return orgsum-sum;
    }
};