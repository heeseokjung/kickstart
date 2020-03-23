#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, P;
vector<int> s[50];
int cache[50][1501];

int dp(int i, int j) {
    if(i < 0)
        return 0;
    if(j == 0)
        return cache[i][j] = 0;
    if(cache[i][j] != -1)
        return cache[i][j];
    int mx = 0;
    for(int k = 0; k <= j && k <= K; ++k) {
        int cur = (k > 0 ? s[i][k-1] : 0);
        mx = max(mx, cur + dp(i-1, j-k));
    }
    return cache[i][j] = mx;
}

int main() {
    int TC;
    scanf("%d", &TC);
    for(int tc = 1; tc <= TC; ++tc) {
        scanf("%d %d %d", &N, &K, &P);
        for(int i = 0; i < N; ++i) {
            int x;
            for(int j = 0; j < K; ++j) {
                scanf("%d", &x);
                s[i].push_back(x);
            }
            for(int j = 1; j < K; ++j)
                s[i][j] += s[i][j-1];
        }
        for(int i = 0; i < N; ++i)
            for(int j = 0; j <= P; ++j)
                cache[i][j] = -1;
        printf("Case #%d: %d\n", tc, dp(N-1, P));
        for(int i = 0; i < N; ++i)
            s[i].clear();
    }
    return 0;
}