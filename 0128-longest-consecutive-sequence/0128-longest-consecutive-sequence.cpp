class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int curr = 1;
        int longest = 1;
        if(nums.size() == 0){
            return 0;
        }
        for(int i = 1; i<nums.size() ; i++){
            if(nums[i] == nums[i-1]){
                continue;
            }
            else if(nums[i] == nums[i-1] +1){
                curr++;
            }
            else{
                longest = max(longest,curr);
                curr = 1;
            }
        }
        longest = max(longest,curr);
        return longest;
    }
}; 