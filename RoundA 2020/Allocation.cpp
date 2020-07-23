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
int A[maxn];
int B;

int main() {
    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        scanf("%d%d", &n, &B);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
        }
        sort(A + 1, A + 1 + n);
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (B >= A[i]) {
                cnt++;
                B -= A[i];
            }
        }
        printf("Case #%d: %d\n", kase, cnt);
    }
    return 0;
}
