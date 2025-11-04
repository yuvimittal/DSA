class Solution {
public:

    void rec(int n, int k, vector<vector<int>> &ans,vector<int> comb){

        if(k==0){
            ans.push_back(comb);
            return;
        }
        if(n == 0){
            return;
        }

        //else the memory limit exceeds
        if(n < k) return;

        comb.push_back(n);
        rec(n-1,k-1,ans,comb);

        //coz we need k terms only
        comb.pop_back();
        rec(n-1,k,ans,comb);

        // comb.push_back(n-1);
    }

    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> ans;
        vector<int> comb;
        rec(n,k,ans,comb);
        return ans;

    }
};