class Solution {
public:

    void merge(int start, int mid, int end,vector<int>& nums){

        vector<int> ans;
        int left= start;
        int right= mid+1;

        while(left<=mid && right<= end){
        if(nums[left] <= nums[right]){
            ans.push_back(nums[left]);
            left++;
        }else{
            ans.push_back(nums[right]);
            right++;
        }
        }

        while(left<=mid){
            ans.push_back(nums[left]);
            left++;
        }

        while(right<= end){
            ans.push_back(nums[right]);
            right++;        
        }

        for(int i = start, j = 0; i <= end; i++, j++) {
          nums[i] = ans[j];
            }
    }

    void mergeSort(int start, int end,vector<int>& nums ){
        
        if(start>= end){
            return;
        }
        int mid = start + (end-start)/2;
        mergeSort(start,mid , nums);
        mergeSort(mid+1, end, nums);
        merge(start, mid, end, nums);
    }


    vector<int> sortArray(vector<int>& nums) {
        
        int start =0;
        int end= nums.size()-1;
        mergeSort(start, end, nums);

        return nums;

    }
};