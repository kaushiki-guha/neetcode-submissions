class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int curSum = 0;
        int l = 0, r = numbers.size() - 1;
        while (l < r){
            curSum = numbers[l] + numbers[r];
            if (curSum > target)
                r--;
            else if (curSum < target)
                l++;
            else
                return {l+1, r+1};
        }
        return {};
    }
};
