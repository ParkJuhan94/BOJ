#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

struct Loc {
	int x, y;
	Loc(int a, int b) {
		x = a;
		y = b;
	}
};
queue<Loc> Q;

int main() {
	int test, n, m, sx, sy, xx, yy, cnt = 0;
	int res = 0;	

	scanf("%d", &test);
	for (a = 1; a <= test; a++) {
		scanf("%d %d %d %d", &n, &m, &sx, &sy);
		vector<vector<char>> arr(n + 1, vector<char>(m + 1, 0));
		vector<vector<int>> map(n + 1, vector<int>(m + 1, 0));
		vector<vector<int>> dis(n + 1, vector<int>(m + 1, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf(" %c", &arr[i][j]);
				if (arr[i][j] == 'X') {
					map[i][j] = 1;
				}
			}
		}
		Q.push(Loc(sx, sy));
		map[sx][sy] = 1;
		while(!Q.empty()){
			Loc tmp = Q.front();
			Q.pop();
			for (int i = 0; i < 4; i++) {
				xx = tmp.x + dx[i];
				yy = tmp.y + dy[i];
				if (map[xx][yy] == 0 && xx >= 1 && xx <= n && yy >= 1 && yy <= m) {
					Q.push(Loc(xx, yy));
					map[xx][yy] = 1;
					dis[xx][yy] = dis[tmp.x][tmp.y] + 1;
				}
			}

			if (arr[xx][yy] == 'A') {
				sx = xx;
				sy = yy;
				cnt += dis[xx][yy];
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {						
						if (arr[i][j] == 'X') {
							map[i][j] = 1;
						}
						else {
							map[i][j] = 0;							
						}
						dis[i][j] = 0;
					}
				}
			}
			else if (arr[xx][yy] == 'B') {
				sx = xx;
				sy = yy;
				cnt += dis[xx][yy];
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						if (arr[i][j] == 'X') {
							map[i][j] = 1;
						}
						else {
							map[i][j] = 0;
						}
						dis[i][j] = 0;
					}
				}
			}
			else if (arr[xx][yy] == 'C') {
				sx = xx;
				sy = yy;
				cnt += dis[xx][yy];
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						if (arr[i][j] == 'X') {
							map[i][j] = 1;
						}
						else {
							map[i][j] = 0;
						}
						dis[i][j] = 0;
					}
				}
			}
		}
		

	}
}
