class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        int n = nums.size();
        
        // If k is larger than the array size, take its modulo
        k = k % n;

        // Rotate the array manually without using built-in functions
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }

private:
    void reverse(std::vector<int>& nums, int start, int end) {
        while (start < end) {
            // Swap elements at start and end indices
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;

            // Move indices towards the center
            ++start;
            --end;
        }
    }
};
