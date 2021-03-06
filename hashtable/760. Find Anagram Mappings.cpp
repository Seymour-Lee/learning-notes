class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> valb2idx;
        for(int i = 0; i < B.size(); i++) valb2idx[B[i]] = i;
        vector<int> ans(A.size(), 0);
        for(int i = 0; i < A.size(); i++) ans[i] = valb2idx[A[i]];
        return ans;
    }
};

class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> num2idx;
        for(int i = 0; i < B.size(); i++) num2idx[B[i]] = i;
        vector<int> ans;
        for(auto a: A) ans.push_back(num2idx[a]);
        return ans;
    }
};