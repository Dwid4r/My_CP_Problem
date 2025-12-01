class Solution {
public:
    vector<int> v;
    int dp[205][20005];
    int target;

    bool go(int i, int cur) {
        if (cur == target) return true;
        if (i == v.size() || cur > target) return false;

        int &ret = dp[i][cur];
        if (~ret) return ret;

        bool take = go(i + 1, cur + v[i]);
        bool leave = go(i + 1, cur);

        return ret = take || leave;
    }

    bool canPartition(vector<int>& nums) {
        v = nums;
        int sum = 0;
        for (int x : nums) sum += x;

        if (sum % 2 != 0) return false;

        target = sum / 2;
        memset(dp, -1, sizeof(dp));

        return go(0, 0);
    }
};

