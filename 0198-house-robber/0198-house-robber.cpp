
class Solution {
public:
    int rob(vector<int>& nums) {
        int evenSum = 0;
        int oddSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                evenSum += nums[i];
                evenSum = max(evenSum, oddSum); 
            } else {
                oddSum += nums[i];
                oddSum = max(evenSum, oddSum); 
            }
        }
        return max(evenSum, oddSum);
    }
};
