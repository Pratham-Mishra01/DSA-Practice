class Solution {
public:
int mostFrequentEven(vector<int>& nums) {
        map<int,int> mpp;
        int val=INT_MIN;
        int freq=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0)
            {
                mpp[nums[i]]++;
                if(mpp[nums[i]]>freq || mpp[nums[i]]==freq && nums[i]<val)
                {
                    val=nums[i];
                    freq=mpp[nums[i]];
                }
            } 
        }
       if(freq==0)
       {
        return -1;
       }
       else
       return val;
    }
};