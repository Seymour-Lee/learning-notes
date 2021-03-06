class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        
        string cur = strs[0];
        for(int i = 1; i < strs.size(); i++){
            while(strs[i].substr(0, cur.size()) != cur){
                cur = cur.substr(0, cur.size()-1);
                if(cur == "") return "";
            }
        }
        
        return cur;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        string ans = strs[0];
        for(int i = 1; i < strs.size(); i++){
            int j = 0;
            while(j < min(ans.size(), strs[i].size()) && ans[j] == strs[i][j]) j++;
            ans = ans.substr(0, j);
        }
        return ans;
    }
};

class Trie{
public:
    Trie(){
        children = vector<Trie*>(26, nullptr);
        end = false;
    }
    
    void insert(string str){
        Trie *node = this;
        for(auto c: str){
            int i = c-'a';
            if(node->children[i] == nullptr) node->children[i] = new Trie();
            node = node->children[i];
        }
        node->end = true;
    }
    
    string longestPrefix(){
        string ans = "";
        Trie *node = this;
        while(node->end == false){
            int counter = 0;
            int next = -1;
            for(int i = 0 ; i < node->children.size(); i++){
                if(node->children[i]) counter++;
                if(node->children[i] && next == -1) next = i;
            }
            if(counter == 0 || counter > 1) break;
            ans += string(1, 'a'+next);
            node = node->children[next];
        }
        return ans;
    }
    
private:
    vector<Trie *> children;
    bool end;
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie *trie = new Trie();
        for(auto str: strs) trie->insert(str);
        return trie->longestPrefix();
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        string ans = strs.back(); strs.pop_back();
        for(auto str: strs){
            int i = 0;
            while(i < min(ans.size(), str.size()) && ans[i] == str[i]) i++;
            ans = ans.substr(0, i);
        }
        return ans;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        string ans = strs[0];
        for(int i = 1; i < strs.size(); i++){
            int j = 0;
            while(j < min(ans.size(), strs[i].size()) && ans[j] == strs[i][j]) j++;
            ans = ans.substr(0, j);
        }
        return ans;
    }
};

class Trie{
public:
    Trie(): cs(vector<Trie *>(26, nullptr)), end(false){}
    
    void insert(string str){
        auto node = this;
        for(auto c: str){
            int i = c - 'a';
            if(node->cs[i] == nullptr) node->cs[i] = new Trie();
            node = node->cs[i];
        }
        node->end = true;
    }
    
    string prefix(){
        auto node = this;
        string ans = "";
        while(node->end == false){
            int counter = 0;
            int pos = -1;
            for(int i = 0; i < node->cs.size(); i++){
                auto p = node->cs[i];
                if(p) counter++;
                if(p && pos == -1) pos = i;
            }
            if(counter == 0 || counter > 1) break;
            ans += ('a'+pos);
            node = node->cs[pos];
        }
        return ans;
    }
    
private:
    vector<Trie *> cs;
    bool end;
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie *trie = new Trie();
        for(auto str: strs) {
            if(str == "") return "";
            trie->insert(str);
        }
        return trie->prefix();
    }
};