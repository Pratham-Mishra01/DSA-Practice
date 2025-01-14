class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int lastSmaller=INT_MIN;
        int longest=1;
        int cnt;
        if(n==0)
        return 0;
        for(int i=0;i<n;i++)
        {
            
            if(nums[i]-1==lastSmaller)
            {
                cnt++;
                lastSmaller=nums[i];

            }
            else if(nums[i]!=lastSmaller)
            {
                lastSmaller=nums[i];
                cnt=1;
            }
            longest=max(longest,cnt);
        }
   return longest; }
};