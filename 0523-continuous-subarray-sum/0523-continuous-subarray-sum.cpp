class Solution {//logic used is if preSum[i]%k and presum[j]%k give the same remainder than the array between them must be divisible by k
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>modmap; //used to store the index of the mod value instead of the frequency in the previous one this solution is completely aligned along the fact that we want an array greater than or equal to length 2
        modmap[0]=-1;
        int preSum=0;
        int mod;
        for(int i=0;i<nums.size();i++)
        {
            preSum+=nums[i];
            mod=preSum % k;
            if(mod<0)
            mod=mod+k;
            if(modmap.find(mod)!=modmap.end())
            {
                if(i-modmap[mod]>1)
                return true;
            }
            else
            modmap[mod]=i; // storing the index of the mod

        }
        return false;
    }
};