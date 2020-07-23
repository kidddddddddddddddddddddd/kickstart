#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 2e5 + 7;
const int maxm = 2e6 + 7;
const long long llINF = 9223372036854775807;
const int INF = 2147483647;
const long long mod = 1e9 + 9;
const double pi = acos(-1.0);

int T;
int W, H, L, U, R, D;

double log_of_factorial[maxn];
double P_rightmost_i[maxn], P_bottommost_i[maxn];

double log_of_P(int x, int y) {
    return log_of_factorial[x + y - 2] - log_of_factorial[x - 1] - log_of_factorial[y - 1] - (x + y - 2);
}

int main() {
#ifndef ONLINE_JUDGE
    //freopen("1.in", "r", stdin);
    //freopen("1.out","w",stdout);
#endif
    for (int i = 1; i <= 200000; i++) {
        log_of_factorial[i] = log_of_factorial[i - 1] + log2(i);
    }

    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        scanf("%d%d%d%d%d%d", &W, &H, &L, &U, &R, &D);
        P_bottommost_i[1] = pow(2, log_of_P(1, H));
        for (int i = 2; i <= W; i++) {
            P_bottommost_i[i] = P_bottommost_i[i - 1] + 0.5 * pow(2, log_of_P(i, H - 1));
        }
        P_rightmost_i[1] = pow(2, log_of_P(W, 1));
        for (int i = 2; i <= H; i++) {
            P_rightmost_i[i] = P_rightmost_i[i - 1] + 0.5 * pow(2, log_of_P(W - 1, i));
        }
        double ans = 0;
        int line = D;
        for (int i = L - 1; i >= 1; i--) {
            line++;
            if (line > H) {
                break;
            }
            if (line == H) {
                ans += P_bottommost_i[i];
            } else {
                ans += pow(2, log_of_P(i, line));
            }
        }
        line = U;
        for (int i = R + 1; i <= W; i++) {
            line--;
            if (line < 1) {
                break;
            }
            if (i == W) {
                ans += P_rightmost_i[line];
            } else {
                ans += pow(2, log_of_P(i, line));
            }
        }
        printf("Case #%d: %.12lf\n", kase, ans);
    }
    return 0;
}