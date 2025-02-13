class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }

        vector<vector<int>> buckets(nums.size() + 1); // Fixed allocation

        for (auto [num, freq] : freqMap) {
            if (freq > 0 && freq <= nums.size()) { // Prevent out-of-bounds access
                buckets[freq].push_back(num);
            }
        }

        vector<int> result;
        for (int i = nums.size(); i >= 1 && result.size() < k; i--) {
            if (!buckets[i].empty()) {
                for (int num : buckets[i]) {
                    result.push_back(num);
                    if (result.size() == k) return result;
                }
            }
        }
        return result;
    }
};
