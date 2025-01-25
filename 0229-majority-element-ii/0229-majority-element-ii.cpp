class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0,cnt2=0;
        int el1=INT_MIN, el2=INT_MIN;

        for(int i=0;i<nums.size();i++)
        {
            if(cnt1==0 && nums[i]!=el2)
            {el1=nums[i];
                cnt1=1;
            }
            else if(cnt2==0 && nums[i]!=el1)
            {
                el2=nums[i];
                cnt2=1;
            }
            else if(nums[i]==el1)
            cnt1++;
            else if(nums[i]==el2)
            cnt2++;

            else
            {
                cnt1--;
                cnt2--;

            }
        }

            vector<int>ans;
            int cnt11=0,cnt22=0;
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]==el1) cnt11++;
                if(nums[i]==el2) cnt22++;


            }
            int threshold=(int)(nums.size()/3)+1;
            if(cnt11>=threshold) ans.push_back(el1);
            if(cnt22>=threshold) ans.push_back(el2);

            sort(ans.begin(),ans.end());
            return ans;
        
    }
};