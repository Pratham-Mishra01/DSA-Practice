class Solution {
public:

    int firstpos(vector<int> &nums,int k)
    {
        int low=0,high=nums.size()-1;
        
        int first=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==k)
            {
                first=mid;
                high=mid-1;
            }
            else if(nums[mid]>k)
            {
                high=mid-1;
            }
            else
            low=mid+1;

        }
        return first;
    }
    int lastpos(vector<int> &nums,int k)
    {
        int low=0,high=nums.size()-1;
        int last=-1;
        

        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==k)
            {
                last=mid;
                low=mid+1;
            }
            else if(nums[mid]<k)
            {
                low=mid+1;
            }
            else
            high=mid-1;
        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n1=firstpos(nums,target);
        int n2=lastpos(nums,target);
        vector<int>ans;
        ans.push_back(n1);
        ans.push_back(n2);

        return ans;
    }
};
