#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct P {
    int x;
    int y;
}P;

inline int absl(int x) {
    return x < 0 ? -x : x;
}

bool operator<(P p1, P p2) {
    return absl(p1.y - p1.x) < absl(p2.y - p2.x);
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
        priority_queue<P> pq;
        for(int i = 0; i < N-1; ++i) {
            P p;
            p.x = v[i]; p.y = v[i+1];
            pq.push(p);
        }
        int count = 0;
        while(count < K) {
            int x = pq.top().x;
            int y = pq.top().y;
            pq.pop();
            int m = (x + y)/2;
            if(x != m && y != m) {
                pq.push(P{x, m});
                pq.push(P{m, y});
            } else {
                pq.push(P{x, y});
                break;
            }
            count++;
        }
        printf("Case #%d: %d\n", tc, absl(pq.top().y - pq.top().x));
    }
    return 0;
}