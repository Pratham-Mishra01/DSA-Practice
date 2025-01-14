class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind=-1;
        int n=nums.size();
        //finding breakpoint
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1])
            {
                ind=i;
                break;
            }
        }

        //incase there is no breakpoint
        if(ind==-1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }

        //finding the smallest element greater than breakpoint
        for(int i=n-1;i>ind;i--)
        {
            if(nums[i]>nums[ind]){
            swap(nums[i],nums[ind]);
            break;}
        }
        reverse(nums.begin()+ind+1,nums.end());
        
    }
};