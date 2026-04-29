// UID: 24BCS11540

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> rangeSumQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        int n = arr.size();
        vector<int> prefix(n), ans;
        
        prefix[0] = arr[0];
        
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + arr[i];
        }
        
        for (auto &q : queries)
        {
            int l = q[0], r = q[1];
            if (l == 0) ans.push_back(prefix[r]);
            else ans.push_back(prefix[r] - prefix[l - 1]);
        }
        
        return ans;
        
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> queries(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> queries[i][0] >> queries[i][1];
    }

    Solution sol;
    vector<int> ans = sol.rangeSumQueries(arr, queries);

    for (int x : ans) {
        cout << x << "\n";
    }

    return 0;
}
