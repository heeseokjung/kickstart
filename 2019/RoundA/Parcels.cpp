#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int R, C;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int arr[250][250];
int dist[250][250];

inline int absl(int x) {
    return x < 0 ? -x : x;
}

bool is_possible(vector<pair<int, int> >& src, int K) {
    for(int i = 0; i < R; ++i)
        for(int j = 0; j < C; ++j)
            dist[i][j] = -1;

    queue<pair<int, int> > q;
    for(int i = 0; i < (int)src.size(); ++i) {
        dist[src[i].first][src[i].second] = 0;
        q.push(src[i]);
    }

    vector<pair<int, int> > imp;
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        if(dist[r][c] > K)
            imp.push_back(q.front());
        q.pop();
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

    if(imp.empty()) {
        return true;
    } else {
        int max_x = -100000, max_y = -100000;
        int min_x = 100000, min_y = 100000;
        for(int i = 0; i < (int)imp.size(); ++i) {
            int r = imp[i].first;
            int c = imp[i].second;
            imp[i].first = r + c;
            imp[i].second = r - c;
            max_x = (max_x < imp[i].first ? imp[i].first : max_x);
            max_y = (max_y < imp[i].second ? imp[i].second : max_y);
            min_x = (min_x > imp[i].first ? imp[i].first : min_x);
            min_y = (min_y > imp[i].second ? imp[i].second : min_y);
        }
        
        for(int i = 0; i < R; ++i) {
            for(int j = 0; j < C; ++j) {
                if(arr[i][j] == 0) {
                    int x = i + j;
                    int y = i - j;
                    int dist = max(max(absl(max_x - x), absl(max_y - y)), max(absl(min_x - x), absl(min_y - y)));
                    if(dist <= K)
                        return true;
                }
            }
        }

        return false;
    }
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
            int r = (p+q)/2;
            if(is_possible(src, r))
                q = r;
            else
                p = r+1;
        }
        printf("Case #%d: %d\n", tc, p);
    }
    return 0;
}