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
int n;
int h[maxn];

int main() {
    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &h[i]);
        }
        int cnt = 0;
        for (int i = 2; i < n; i++) {
            if (h[i] > h[i - 1] && h[i] > h[i + 1]) {
                cnt++;
            }
        }
        printf("Case #%d: %d\n", kase, cnt);
    }
    return 0;
}