class Solution {
public:
    string getPermutation(int n, int k) {
        string str = "";
        for(char ch = '1'; ch < '1' + n; ch++) str += ch;
        while(--k) next_permutation(str.begin(), str.end());
        return str;
    }
};

class Solution {
public:
    string getPermutation(int n, int k) {
        string str = "";
        for(char ch = '1'; ch < '1' + n; ch++) str += ch;
        while(--k) gen(str);
        return str;
    }
    
private:
    void gen(string &str){
        int prev = str.size()-2;
        while(prev >= 0 && str[prev] >= str[prev+1]) prev--;
        reverse(str.begin()+prev+1, str.end());
        int next = prev+1;
        while(str[next] <= str[prev]) next++;
        swap(str[prev], str[next]);
    }
};

class Solution {
public:
    string getPermutation(int n, int k) {
        string ans = "";
        vector<int> a;
        for(int i = 1; i <= n; i++) a.push_back(i);
        while(--k) next_permutation(a.begin(), a.end());
        for(auto e: a) ans += char(e+'0');
        return ans;
    }
};

class Solution {
public:
    string getPermutation(int n, int k) {
        string ans = "";
        vector<int> a;
        for(int i = 1; i <= n; i++) a.push_back(i);
        while(--k) next_permutation(a.begin(), a.end());
        for(auto e: a) ans += char(e+'0');
        return ans;
    }
};