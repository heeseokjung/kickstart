#include <cstdio>
#include <vector>
using namespace std;

inline int ceil(int x, int y) {
    return x % y ? x/y + 1 : x/y;
}

int main() {
    int TC;
    scanf("%d", &TC);
    for(int tc = 1; tc <= TC; ++tc) {
        int N, K;
        scanf("%d %d", &N, &K);
        vector<int> v(N);
        for(int i = 0; i < N; ++i)
            scanf("%d", &v[i]);
        vector<int> diff(N-1);
        int max_diff = 0;
        for(int i = 0; i < N-1; ++i) {
            diff[i] = v[i+1] - v[i];
            max_diff = (max_diff < diff[i] ? diff[i] : max_diff);
        }
        int p = 1, q = max_diff;
        while(p < q) {
            int r = (p + q)/2;
            int sum = 0;
            for(int i = 0; i < N-1; ++i)
                sum += (ceil(diff[i], r) - 1);
            if(sum <= K)
                q = r;
            else
                p = r+1;
        }
        printf("Case #%d: %d\n", tc, p);
    }
    return 0;
}