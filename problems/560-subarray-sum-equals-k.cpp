class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0, count = 0;
        for (int n : nums) {
            sum += n;
            if (mp.count(sum - k)) count += mp[sum - k];
            mp[sum]++;
        }
        return count;
    }
};
