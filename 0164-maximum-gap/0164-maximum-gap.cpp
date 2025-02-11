class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;  // If less than two elements, return 0
        
        vector<int> buckets[10];  // Buckets array to store numbers
        vector<int> ans;
        int index;
        
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());
        
        // If all elements are the same, there is no gap
        if (maxVal == minVal) return 0;

        // Place numbers into the appropriate buckets based on their first digits
        for (int i = 0; i < nums.size(); i++) {
            index = (nums[i] - minVal) / 10;  // Calculate the index based on the value
            // If index is greater than 9, place it in the last bucket
            if (index >= 10) {
                index = 9;
            }
            buckets[index].push_back(nums[i]);
        }

        // Sort the elements within each bucket
        for (int i = 0; i < 10; i++) {
            sort(buckets[i].begin(), buckets[i].end());
        }
        
        // Rebuild the sorted list from the buckets
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < buckets[i].size(); j++) {
                ans.push_back(buckets[i][j]);  // Use push_back to insert elements into ans
            }
        }
        
        // Find the maximum gap between consecutive elements
        int maxGap = ans[1] - ans[0];  // Initialize maxGap with the first gap
        for (int i = 1; i < ans.size() - 1; i++) {
            int sub = ans[i + 1] - ans[i];
            if (sub > maxGap) {
                maxGap = sub;
            }
        }
        
        return maxGap;
    }
};