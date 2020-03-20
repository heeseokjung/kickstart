#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

inline int query(int* rsum, int i, int j) {
    if(j == 0)
        return rsum[i];
    else
        return rsum[i] - rsum[j-1];
}

int main() {
    int TC;
    scanf("%d", &TC);
    for(int tc = 1; tc <= TC; ++tc) {
        int N, P;
        scanf("%d %d", &N, &P);
        vector<int> v(N);
        for(int i = 0; i < N; ++i)
            scanf("%d", &v[i]);
        sort(v.begin(), v.end());
        int rsum[N];
        rsum[0] = v[0];
        for(int i = 1; i < N; ++i)
            rsum[i] = rsum[i-1] + v[i];
        int min_diff = (int)1e9;
        for(int i = P-1, j = 0; i < N; ++i, ++j)
            min_diff = min(min_diff, v[i]*P - query(rsum, i, j));
        printf("Case #%d: %d\n", tc, min_diff);
    }
    return 0;
}