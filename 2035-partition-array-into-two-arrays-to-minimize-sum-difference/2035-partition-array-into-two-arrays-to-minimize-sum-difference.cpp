class Solution {
public:

    void generate(vector<int>& nums,
                  vector<vector<int>>& dp)
    {
        int m = nums.size();

        dp[0].push_back(0);

        for(int x : nums)
        {
            for(int cnt = m; cnt >= 1; cnt--)
            {
                for(int sum : dp[cnt - 1])
                {
                    dp[cnt].push_back(sum + x);
                }
            }
        }
    }

    int minimumDifference(vector<int>& nums)
    {
        int m = nums.size() / 2;

        int total = 0;

        for(int x : nums)
            total += x;

        vector<int> left(nums.begin(),
                         nums.begin() + m);

        vector<int> right(nums.begin() + m,
                          nums.end());

        vector<vector<int>> leftDP(m + 1);
        vector<vector<int>> rightDP(m + 1);

        generate(left, leftDP);
        generate(right, rightDP);

        for(int i = 0; i <= m; i++)
        {
            sort(rightDP[i].begin(),
                 rightDP[i].end());
        }

        int ans = INT_MAX;

        // i elements from left
        for(int i = 0; i <= m; i++)
        {
            // m-i elements from right
            int need = m - i;

            for(int s1 : leftDP[i])
            {
                int target = total / 2 - s1;

                auto it = lower_bound(
                    rightDP[need].begin(),
                    rightDP[need].end(),
                    target
                );

                if(it != rightDP[need].end())
                {
                    int s2 = *it;

                    int s = s1 + s2;

                    ans = min(ans,
                              abs(total - 2 * s));
                }

                if(it != rightDP[need].begin())
                {
                    --it;

                    int s2 = *it;

                    int s = s1 + s2;

                    ans = min(ans,
                              abs(total - 2 * s));
                }
            }
        }

        return ans;
    }
};