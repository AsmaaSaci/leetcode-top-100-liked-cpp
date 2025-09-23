class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) return {};
        vector<int> ans, sc(26), pc(26);
        for (char c : p) pc[c - 'a']++;
        for (int i = 0; i < s.size(); i++) {
            sc[s[i] - 'a']++;
            if (i >= p.size()) sc[s[i - p.size()] - 'a']--;
            if (sc == pc) ans.push_back(i - p.size() + 1);
        }
        return ans;
    }
};
