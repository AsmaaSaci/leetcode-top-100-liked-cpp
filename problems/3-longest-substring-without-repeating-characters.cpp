class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mp(256, -1);
        int left = 0, ans = 0;
        for (int right = 0; right < s.size(); right++) {
            if (mp[s[right]] >= left) left = mp[s[right]] + 1;
            mp[s[right]] = right;
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
