#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 2e5 + 7;
const int maxm = 3e7 + 7;
const long long llINF = 9223372036854775807;
const int INF = 2147483647;
const long long mod = 1e9 + 9;
const double pi = acos(-1.0);
const int offset = 1e7 + 7;

int T;
int pre[maxn];
int n;
int a[maxn];
int cnt[maxm];

int main() {
#ifndef ONLINE_JUDGE
//    freopen("1.in", "r", stdin);
//    freopen("1.out","w",stdout);
#endif

    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        long long ans = 0;
        int min_val = 0;
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + a[i];
        }

        cnt[offset]++;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 3163; j++) {
                //pre[i] - pre[x] == squre [j]
                int num = pre[i] - j * j;
                if (num < min_val) {
                    break;
                }
                ans += cnt[num + offset];
            }
            cnt[pre[i] + offset]++;
            min_val = min(min_val, pre[i]);
        }
        for (int i = 0; i <= n; i++) {
            cnt[pre[i] + offset]--;
        }
        printf("Case #%d: %lld\n", kase, ans);
    }
    return 0;
}

