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
int n, k;
int m[maxn];

bool check(int mid) {
    int res = 0;
    for (int i = 2; i <= n; i++) {
        int diff = m[i] - m[i - 1];
        int cnt = diff % mid == 0 ? (diff / mid - 1) : diff / mid;
        res += max(cnt, 0);
    }
    return res <= k;
}

int main() {
    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &m[i]);
        }
        int ans = 1e9;
        int l = 1, r = 1e9;
        int cnt = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid - 1;
                ans = min(ans, mid);
            } else {
                l = mid + 1;
            }
        }
        printf("Case #%d: %d\n", kase, ans);
    }
    return 0;
}
