#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;
int countGoodArrays(vector<int> arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(201, 0));

    if (arr[0] == 0) {
        for (int x = -100; x <= 100; x++) {
            dp[0][x + 100] = 1;
        }
    } else {
        dp[0][arr[0] + 100] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int x = -100; x <= 100; x++) {
            if (arr[i] != 0 && arr[i] != x) continue;

            int currentWays = 0;
            if (x - 1 >= -100) currentWays = (currentWays + dp[i - 1][x - 1 + 100]) % MOD;
            currentWays = (currentWays + dp[i - 1][x + 100]) % MOD;
            if (x + 1 <= 100) currentWays = (currentWays + dp[i - 1][x + 1 + 100]) % MOD;

            dp[i][x + 100] = currentWays;
        }
    }

    int result = 0;
    for (int x = -100; x <= 100; x++) {
        result = (result + dp[n - 1][x + 100]) % MOD;
    }

    return result;
}

int main() {
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout << countGoodArrays(v) << endl;  // Expected output: 9
    return 0;
}
