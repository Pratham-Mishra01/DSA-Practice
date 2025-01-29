class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<std::vector<int>> ans;
        std::sort(nums.begin(), nums.end());  // Start with the smallest permutation
        int n = nums.size();

        ans.push_back(nums);  // Store the first permutation

        while (true) {
            int ind = -1;  // Breakpoint index

            // Step 1: Find the rightmost index (ind) where nums[ind] < nums[ind+1]
            for (int i = n - 2; i >= 0; i--) {
                if (nums[i] < nums[i + 1]) {
                    ind = i;
                    break;
                }
            }

            // If no such index is found, we are at the last permutation
            if (ind == -1) break;

            // Step 2: Find the smallest number greater than nums[ind] to the right
            for (int i = n - 1; i > ind; i--) {
                if (nums[i] > nums[ind]) {
                    std::swap(nums[i], nums[ind]);
                    break;
                }
            }

            // Step 3: Reverse the suffix after index ind
            std::reverse(nums.begin() + ind + 1, nums.end());

            // Step 4: Store the next permutation
            ans.push_back(nums);
        }

        return ans;
    }
};