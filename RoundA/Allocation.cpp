#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int TC;
    scanf("%d", &TC);
    for(int tc = 1; tc <= TC; ++tc) {
        int N, B;
        scanf("%d %d", &N, &B);
        vector<int> v(N);
        for(int i = 0; i < N; ++i)
            scanf("%d", &v[i]);
        sort(v.begin(), v.end());
        int sum = 0, count = 0;
        for(int i = 0; i < N; ++i) {
            if(sum + v[i] <= B) {
                sum += v[i];
                count++;
            } else {
                break;
            }
        }
        printf("Case #%d: %d\n", tc, count);
    }
    return 0;
}