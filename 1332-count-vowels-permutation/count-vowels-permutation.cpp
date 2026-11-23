
class Solution {
public:
    long long mod = 1e9 + 7;
    long long dp[20001][5];

    long long solve(int rem, int last) {

        if(rem == 0) return 1;

        if(dp[rem][last] != -1) {
            return dp[rem][last];
        }

        long long ans = 0;

        if(last == 0) {
            ans = solve(rem-1, 1);
        }

        else if(last == 1) {
            ans = (solve(rem-1, 0) + solve(rem-1, 2)) % mod;
        }

        else if(last == 2) {
            ans = (solve(rem-1, 0) + solve(rem-1, 1)
                 + solve(rem-1, 3) + solve(rem-1, 4)) % mod;
        }

        else if(last == 3) {
            ans = (solve(rem-1, 2) + solve(rem-1, 4)) % mod;
        }

        else if(last == 4) {
            ans = solve(rem-1, 0);
        }

        return dp[rem][last] = ans % mod;
    }

    int countVowelPermutation(int n) {

        memset(dp, -1, sizeof(dp));

        long long ans = 0;

        for(int i = 0; i < 5; i++) {
            ans = (ans + solve(n-1, i)) % mod;
        }

        return ans;
    }
};
