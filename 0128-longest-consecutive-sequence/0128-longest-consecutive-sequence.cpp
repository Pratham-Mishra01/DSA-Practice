class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int cnt;
        unordered_set<int> st;  //we use set data structure to not tamper with array
        int longest=1;
        for(int i=0;i<n;i++)
        {
            st.insert(nums[i]);

        }
        for(auto it: st){
            if(st.find(it-1)==st.end())
            {
                cnt=1;
                int x=it;
                while(st.find(x+1)!=st.end()){   //possible mistake: using if statement instead of while
                    cnt++;
                    x++;
                }
                longest=max(longest,cnt);
            }
        }
        return longest;
    }
};