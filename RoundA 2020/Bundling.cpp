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
int n, k;
char s[maxn];
int cnt;
long long ans;
struct node {
    int son[30];
    int sum;
    int depth;
} Trie[maxm];

void insert() {
    int cur = 1;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        int c = s[i] - 'A';
        if (!Trie[cur].son[c]) {
            Trie[cur].son[c] = ++cnt;
        }
        Trie[Trie[cur].son[c]].depth = Trie[cur].depth + 1;
        cur = Trie[cur].son[c];
    }
    Trie[cur].sum++;
}

void dfs(int cur) {
    for (int i = 0; i < 26; i++) {
        if (Trie[cur].son[i]) {
            dfs(Trie[cur].son[i]);
        }
    }
    int cur_cnt = Trie[cur].sum;
    if (Trie[cur].sum == 0) {
        for (int i = 0; i < 26; i++) {
            Trie[cur].sum += Trie[Trie[cur].son[i]].sum;
        }
    }
    long long num = Trie[cur].sum / k;
    ans += num * Trie[cur].depth;
    Trie[cur].sum %= k;
}

int main() {
#ifndef ONLINE_JUDGE
    //freopen("1.in", "r", stdin);
    //freopen("1.out","w",stdout);
#endif
    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        memset(Trie, 0, sizeof(Trie));
        cnt = 1;
        ans = 0;
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++) {
            scanf("%s", s);
            insert();
        }
        dfs(1);
        printf("Case #%d: %lld\n", kase,ans);
    }
    return 0;
}
