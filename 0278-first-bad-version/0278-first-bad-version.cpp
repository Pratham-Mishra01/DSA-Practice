// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n==1)
        {
            if(isBadVersion(1))
            return 1;
        }
        int low=1,high=n;
        int mid;
        int first;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(isBadVersion(mid))
            {
                high=mid-1;
                first=mid;
            }
            else if(!isBadVersion(mid))
            {
                low=mid+1;
            }

        }
        return first;
    }
};