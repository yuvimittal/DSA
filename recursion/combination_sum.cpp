class Solution {
public:

    void combine(vector<int>& arr, int target,int index,vector<vector<int>> &ans, vector<int> &combination ){

        if(target == 0){
            ans.push_back(combination);
            return;
        }

        if(index>= arr.size() || target <0 ){
            return;
        }

        combination.push_back(arr[index]);
        combine(arr, target - arr[index], index, ans,combination);
        combination.pop_back();
        combine(arr, target, index+1, ans, combination);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combination;
        int index=0;
        combine(candidates, target,index ,ans,combination);
        return ans;
    }
};