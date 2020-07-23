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
long long x[maxn];
long long D;

int main() {
    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        scanf("%d%lld", &n, &D);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &x[i]);
        }
        for (int i = n; i >= 1; i--) {
            long long num = x[i];
            D -= D % num;
        }
        printf("Case #%d: %lld\n", kase, D);
    }
    return 0;
}