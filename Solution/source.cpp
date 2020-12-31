#pragma warning(disable: 6031)
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
//#include "graph.h"

//using namespace std;

typedef struct Point {
	int x, y;
} Point;

int T;
int m, n, k;
Point p;
int area[50][50];
Point visited[2501];
int check, cnt;

void DFS(int x, int y)
{
	if (x >= 0 && x < m && y >= 0 && y < n &&
		area[y][x] == 1) {
		check++;
		area[y][x] = 0;
		DFS(x - 1, y);
		DFS(x + 1, y);
		DFS(x, y - 1);
		DFS(x, y + 1);
	}
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &m, &n, &k);
		for (int i = 0; i < k; i++) {
			scanf("%d%d", &p.x, &p.y);
			visited[i] = p;
			area[p.y][p.x] = 1;
		}
		for (int i = 0; i < k; i++) {
			DFS(visited[i].x, visited[i].y);
			if (check > 0)
				cnt++;
			check = 0;
		}
		printf("%d\n", cnt);
		cnt = 0;
	}
	
	return 0;
}