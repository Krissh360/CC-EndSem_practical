// UID: 24BCS11540

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;

        for (int c : coins)
        {
            for (int i = c; i <= amount; i++)
            {
                if (dp[i-c] == INT_MAX) continue;
                dp[i] = min(dp[i], dp[i-c]+1);
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];

    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, amount;
    cin >> n >> amount;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    Solution sol;
    int ans = sol.coinChange(coins, amount);
    cout << ans << "\n";

    return 0;
}
