class Solution {
public:
bool incremovable (vector<int>& nums) {
    if (nums.size() <= 1) return true;
    for(int i=0;i<nums.size()-1;i++){

        if(nums[i] >= nums[i+1]) return false;
    }
    return true;
}
    int incremovableSubarrayCount(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        for(int start=0;start<n;start++){
            for(int end=start;end<n;end++){
                    vector<int>temp;
                for(int i=0;i<n;i++){
                    if(i<start || i > end) temp.push_back(nums[i]);
                }
                if(incremovable(temp)) count++;
            }
        }
        return count;
    }
};