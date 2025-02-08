class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
     vector<vector<int>>ans;
     sort(nums.begin(),nums.end());
     int n=nums.size();
     int j,k;
     int sum;
     for(int i=0;i<n;i++)
     {
        //skip duplicates whenever we increment i
        if(i!=0 && nums[i-1]==nums[i])
        continue;

        j=i+1;
        k=n-1;
        while(j<k)
        {
            sum=nums[i]+nums[j]+nums[k];
           
            if(sum<0)
            {
                j++;
            }
            else if(sum>0)
           { k--; }

            else if(sum==0)
            {
                vector<int> temp={nums[i],nums[j],nums[k]};
                ans.push_back(temp);
                //updating only 1 among j and k would surely give us an answer other than 0 if the values are unique i.e. j-1!=j or k-1!=k therefore we update both j and k together
                j++;
                k--;

                //skipping duplicates
                while(j<k && nums[j]==nums[j-1])
                {j++;}

                while(j<k && nums[k+1]==nums[k])
               { k--; }
            }



        }

     }
        return ans;
    }
};