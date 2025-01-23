class Solution {
public:

    int binarySearch(vector<int>nums,int left,int right,int target)
    {
        //base condition should be at start to stop the recursion
        if(left>right)
            return -1;

        int mid=(left+right)/2;
        if(nums[mid]==target)
        return mid;
        else if(nums[mid]>target)
        return binarySearch(nums,left,mid-1,target);
        else
        return binarySearch(nums,mid+1,right,target);


    }
    int search(vector<int>& nums, int target) {
        return binarySearch(nums,0,nums.size()-1,target);
    }
};