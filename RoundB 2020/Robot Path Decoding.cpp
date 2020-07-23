#include <bits/stdc++.h>
#include <bits/extc++.h>
#include <ostream>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 2e5 + 7;
const int maxm = 2e6 + 7;
const long long llINF = 9223372036854775807;
const int INF = 2147483647;
const long long mod = 1e9 + 9;
const double pi = acos(-1.0);

int T;

struct node {
    pair<long long, long long> move;
    int cnt;
    int sign;

    node() {
        move = make_pair(0, 0);
        cnt = 0;
        sign = 0;
    }
};

vector<node> v;
char s[maxn];

int main() {
#ifndef ONLINE_JUDGE
    //freopen("1.in", "r", stdin);
    //freopen("1.out","w",stdout);
#endif
    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        v.clear();
        scanf("%s", s + 1);
        int len = strlen(s + 1);
        for (int i = 1; i <= len; i++) {
            node tmp;
            if (s[i] >= '0' && s[i] <= '9') {
                tmp.cnt = s[i] - '0';
            } else if (s[i] == '(') {
                tmp.sign = 1;
            } else if (s[i] == ')') {
                tmp.sign = -1;
            } else if (s[i] == 'N') {
                tmp.move = make_pair(0, -1);
            } else if (s[i] == 'S') {
                tmp.move = make_pair(0, 1);
            } else if (s[i] == 'E') {
                tmp.move = make_pair(1, 0);
            } else if (s[i] == 'W') {
                tmp.move = make_pair(-1, 0);
            }
            v.push_back(tmp);
        }
/*
        for (node x:v) {
            printf("(%lld %lld), %d, %d\n", x.move.first, x.move.second, x.cnt, x.sign);
        }
*/
        vector<node> s;

        for (int i = 0; i < v.size(); i++) {
            node x = v[i];
            if (x.sign == -1) {
                int l = s.size() - 1;
                while (s[l].sign != 1) {
                    l--;
                }
                int cnt = s[l - 1].cnt;
                pair<long long, long long> tmp = make_pair(0, 0);
                for (int j = l + 1; j < s.size(); j++) {
                    tmp.first = (tmp.first + s[j].move.first + 1000000000ll) % 1000000000;
                    tmp.second = (tmp.second + s[j].move.second + 1000000000ll) % 1000000000;
                }
                tmp.first = (1ll * tmp.first * cnt) % 1000000000;
                tmp.second = (1ll * tmp.second * cnt) % 1000000000;
                while (s.size() != l - 1) {
                    s.pop_back();
                }
                node Node;
                Node.move = tmp;
                s.push_back(Node);
            } else {
                s.push_back(x);
            }
        }


        pair<long long, long long> ans_pair = make_pair(0, 0);
        for (node x:s) {
            ans_pair.first = (ans_pair.first + x.move.first + 1000000000) % 1000000000;
            ans_pair.second = (ans_pair.second + x.move.second + 1000000000) % 1000000000;
        }
        printf("Case #%d: %lld %lld\n", kase, ans_pair.first + 1, ans_pair.second + 1);

    }
    return 0;
}