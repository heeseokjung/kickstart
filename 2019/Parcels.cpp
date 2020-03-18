#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

int R, C;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int arr[250][250];
int dist[250][250];

bool bfs(vector<pair<int, int> >& src, int K) {
    for(int i = 0; i < R; ++i)
        for(int j = 0; j < C; ++j)
            dist[i][j] = -1;
    queue<pair<int, int> > q;
    for(int i = 0; i < (int)src.size(); ++i) {
        dist[src[i].first][src[i].second] = 0;
        q.push(src[i]);
    }
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        if(dist[r][c] > K)
            return false;
        for(int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr > R-1 || nc < 0 || nc > C-1)
                continue;
            if(dist[nr][nc] == -1) {
                dist[nr][nc] = dist[r][c] + 1;
                q.push(pair<int, int>(nr, nc));
            }
        }
    }
    return true;
}

int main() {
    int TC;
    cin >> TC;
    for(int tc = 1; tc <= TC; ++tc) {
        cin >> R >> C;
        vector<pair<int, int> > src;
        string s;
        for(int i = 0; i < R; ++i) {
            cin >> s;
            for(int j = 0; j < C; ++j) {
                arr[i][j] = s[j] - '0';
                if(arr[i][j])
                    src.push_back(pair<int, int>(i, j));
            }
        }

        int p = 0, q = R + C;
        while(p < q) {
            printf("tc: %d p: %d q: %d r: %d check: %d\n", tc, p, q, (p+q)/2, bfs(src, (p+q)/2));
            int r = (p+q)/2;
            if(bfs(src, r))
                q = r;
            else
                p = r+1;
        }
        printf("Case #%d: %d\n", tc, q);
    }
    return 0;
}