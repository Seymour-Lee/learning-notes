class Solution {
public:
    int divide(int dividend, int divisor) {
        int result = 0;
        bool sign = (dividend > 0 && divisor > 0) 
                 || (dividend < 0 && divisor < 0)? true: false;
        if(dividend == 0 || divisor == 0) return 0;
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        long dvd = labs(dividend);
        long dvr = labs(divisor);
        result = solution(dvd, dvr);
        return sign? result: -result;
    }
    
private:
    int solution(long dvd, long dvr){
        if(dvd < dvr) return 0;
        if(dvd == dvr || dvr + dvr > dvd) return 1;
        int ans = 1;
        long sum = dvr;
        while(dvd > sum + sum){
            ans += ans;
            sum += sum;
        }
        return ans + solution(dvd-sum, dvr);
    }
};