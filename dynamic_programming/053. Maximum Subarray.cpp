class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> sums;
        sums.push_back(nums[0]);
        
        for(int i = 1; i <nums.size(); i++){
            sums.push_back(max(nums[i], nums[i]+sums[i-1]));
        }
        
        int result = INT_MIN;
        for(int i = 0; i < sums.size(); i++)
            result = max(result, sums[i]);
        
        return result;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> dp(nums.size(), nums[0]);
        for(int i = 1; i < nums.size(); i++)
            dp[i] = max(dp[i-1]+nums[i], nums[i]);
        return *max_element(dp.begin(), dp.end());
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int cur, prev = nums[0];
        int ans = nums[0];
        for(decltype(nums.size()) i = 1; i < nums.size(); i++){
            cur =  max(nums[i], prev+nums[i]);
            ans = max(cur, ans);
            prev = cur;
        }
        return ans;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int ans = nums[0];
        int cur = nums[0];
        for(int i = 1; i < nums.size(); i++){
            cur = max(nums[i], cur+nums[i]);
            ans = max(ans, cur);
        }
        return ans;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        // dp[i] = maxSubarray end with nums[i]
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) dp[i] = max(dp[i-1]+nums[i], nums[i]);
        return *max_element(dp.begin(), dp.end());
    }
};