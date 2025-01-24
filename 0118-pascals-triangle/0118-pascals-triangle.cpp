class Solution {
public:

    vector<int> generateRow(int row)
    {   vector<int> ansRow;
        ansRow.push_back(1);
        long long temp=1;
        for(int col=1;col<row;col++)  
        {
            temp=temp*(row-col);
            temp=temp/col;
            ansRow.push_back(temp);
        }
    return ansRow;}
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++)
        {
            ans.push_back(generateRow(i));
        }

    return ans;}
};