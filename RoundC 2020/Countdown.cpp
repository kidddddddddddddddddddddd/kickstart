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
int a[maxn];

int main() {
#ifndef ONLINE_JUDGE
	//freopen("1.in","r",stdin);
//    freopen("1.out","w",stdout);
#endif
    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        int ans = 0;
        bool flag = false;
        for (int i = 1; i <= n; i++) {
            if (a[i] == k) {
                flag = true;
                continue;
            }
            if (flag) {
                if (a[i] != a[i - 1] - 1) {
                    flag = false;
                    continue;
                }
                if (a[i] == 1) {
                    flag = false;
                    ans++;
                }
            }
        }
        printf("Case #%d: %d\n", kase, ans);
    }
    return 0;
}

