class Solution {
public:
//mean doesn not work for all
    int minMoves2(vector<int>& nums) {
        int sum=0,res=0;
        sort(nums.begin(),nums.end());
        int median = nums[nums.size()/2];
       
        for(int i=0;i<nums.size();i++){
           int  diff = abs(median - nums[i]);
            res += diff;
        }
        return res;
    }
};