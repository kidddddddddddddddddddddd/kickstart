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

int T;
int n, Q;
long long a[maxn];
struct node {
    int l, r;
    long long sum1, sum2;
} seg_tree[maxn << 2];

void push_up(int root) {

    if ((seg_tree[root << 1].r - seg_tree[root << 1].l + 1) % 2 == 1) {
        seg_tree[root].sum1 = seg_tree[root << 1].sum1 - seg_tree[root << 1 | 1].sum1;
        seg_tree[root].sum2 = seg_tree[root << 1].sum2 - seg_tree[root << 1 | 1].sum2;
    } else {
        seg_tree[root].sum1 = seg_tree[root << 1].sum1 + seg_tree[root << 1 | 1].sum1;
        seg_tree[root].sum2 = seg_tree[root << 1].sum2 + seg_tree[root << 1 | 1].sum2;
    }
}

void build(int root, int l, int r) {
    seg_tree[root].l = l;
    seg_tree[root].r = r;
    if (l == r) {
        seg_tree[root].sum1 = a[l];
        seg_tree[root].sum2 = a[l] * l;
        return;
    }
    int mid = (l + r) >> 1;
    build(root << 1, l, mid);
    build(root << 1 | 1, mid + 1, r);
    push_up(root);
}

void modify(int root, int x, int val) {
    if (seg_tree[root].l == x && seg_tree[root].r == x) {
        seg_tree[root].sum1 = val;
        seg_tree[root].sum2 = val * x;
        return;
    }
    int mid = (seg_tree[root].l + seg_tree[root].r) >> 1;
    if (x <= mid) {
        modify(root << 1, x, val);
    }
    if (x > mid) {
        modify(root << 1 | 1, x, val);
    }
    push_up(root);
}

long long query_sum1(int root, int l, int r) {
    if (l <= seg_tree[root].l && seg_tree[root].r <= r) {
        return seg_tree[root].sum1;
    }
    long long res = 0, res_l = 0, res_r = 0;
    int mid = (seg_tree[root].l + seg_tree[root].r) >> 1;
    if (l <= mid) {
        res_l += query_sum1(root << 1, l, r);
    }
    if (r > mid) {
        res_r += query_sum1(root << 1 | 1, l, r);
    }
    if ((seg_tree[root << 1].r - seg_tree[root << 1].l + 1) % 2 == 1) {
        return res_l - res_r;
    } else {
        return res_l + res_r;
    }
}

long long query_sum2(int root, int l, int r) {
    if (l <= seg_tree[root].l && seg_tree[root].r <= r) {
        return seg_tree[root].sum2;
    }
    long long res = 0, res_l = 0, res_r = 0;
    int mid = (seg_tree[root].l + seg_tree[root].r) >> 1;
    if (l <= mid) {
        res_l += query_sum2(root << 1, l, r);
    }
    if (r > mid) {
        res_r += query_sum2(root << 1 | 1, l, r);
    }
    if ((seg_tree[root << 1].r - seg_tree[root << 1].l + 1) % 2 == 1) {
        return res_l - res_r;
    } else {
        return res_l + res_r;
    }
}

int main() {
#ifndef ONLINE_JUDGE
//    freopen("1.in", "r", stdin);
//    freopen("1.out","w",stdout);
#endif

    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        scanf("%d%d", &n, &Q);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
        }
        build(1, 1, n);

        long long ans = 0;
        while (Q--) {
            char s[5];
            scanf("%s", s);
            if (s[0] == 'Q') {
                int l, r;
                scanf("%d%d", &l, &r);
                long long res_1 = query_sum1(1, l, r);
                long long res_2 = query_sum2(1, l, r);
                if (l & 1) {
                    ans += res_2 - res_1 * (l - 1);
                } else {
                    ans -= res_2 - res_1 * (l - 1);
                }
            } else {
                int x, val;
                scanf("%d%d", &x, &val);
                modify(1, x, val);
            }
        }
        printf("Case #%d: %lld\n", kase, ans);

    }
    return 0;
}

