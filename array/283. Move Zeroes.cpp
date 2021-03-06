class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.empty()) return;
        int tail = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0) nums[tail++] = nums[i]; 
        }
        for(int i = tail; i < nums.size(); i++){
            nums[i] = 0;
        }
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i = 0, j = 0; j < nums.size() && i <= j; j++){
            if(nums[j] != 0) swap(nums[i++], nums[j]);
        }
    }
};