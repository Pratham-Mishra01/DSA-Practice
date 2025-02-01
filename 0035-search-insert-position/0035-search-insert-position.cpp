class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        int mid;
        int first=nums.size();
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(nums[mid]==target)
            return mid;
            else if(nums[mid]>target)
            {high=mid-1;
            first=mid;}
            else
            low=mid+1;

        }
        return first;

    }
};