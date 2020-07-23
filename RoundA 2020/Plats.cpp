#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 2e5 + 7;
const int maxm = 1e6 + 7;
const long long llINF = 9223372036854775807;
const int INF = 2147483647;
const long long mod = 1e9 + 9;
const double pi = acos(-1.0);

int T;
int n, k, p;
int val[57][57];
int dp[57][1507];
int pre[57][57];

int main() {
    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        memset(dp, 0, sizeof(dp));
        scanf("%d%d%d", &n, &k, &p);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                scanf("%d", &val[i][j]);
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                pre[i][j] = pre[i][j - 1] + val[i][j];
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = p; j >= 0; j--) {
                for (int num = 0; num <= k; num++) {
                    if (j >= num) {
                        dp[i][j] = max(dp[i][j], dp[i - 1][j - num] + pre[i][num]);
                    }
                }
            }
        }

        printf("Case #%d: %d\n",kase,dp[n][p]);
    }
    return 0;
}
