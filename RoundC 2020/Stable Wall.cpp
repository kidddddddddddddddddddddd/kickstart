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
int R, C;
int N;
char pic[57][57];
int deg[30];
vector<char> ans;
set<int> G[30];
map<char, bool> mp;
queue<int> Q;

void init() {
    memset(deg, 0, sizeof(deg));
    ans.clear();
    for (int i = 0; i < 30; i++)
        G[i].clear();
    mp.clear();
}

int main() {
#ifndef ONLINE_JUDGE
//    freopen("1.in", "r", stdin);
//    freopen("1.out","w",stdout);
#endif
    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        init();
        scanf("%d%d", &R, &C);
        for (int i = 1; i <= R; i++) {
            scanf("%s", pic[i] + 1);
        }
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                mp[pic[i][j]] = true;
                if (i != R) {
                    if (pic[i][j] != pic[i + 1][j]) {
                        if (G[pic[i + 1][j] - 'A'].find(pic[i][j] - 'A') == G[pic[i + 1][j] - 'A'].end()) {
                            G[pic[i + 1][j] - 'A'].insert(pic[i][j] - 'A');
                            deg[pic[i][j] - 'A']++;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < 26; i++) {
            if (deg[i] == 0 && mp.count('A' + i)) {
                Q.push(i);
            }
        }
        while (!Q.empty()) {
            int cur = Q.front();
            Q.pop();
            ans.push_back(cur);
            for (int x:G[cur]) {
                if (--deg[x] == 0) {
                    Q.push(x);
                }
            }
        }

        if (ans.size() == mp.size()) {
            printf("Case #%d: ", kase);
            for (int x:ans) {
                printf("%c", x + 'A');
            }
            printf("\n");
        } else {
            printf("Case #%d: -1\n", kase);
        }

    }
    return 0;
}

