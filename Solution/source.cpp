#pragma warning(disable: 6031)
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
//#include "graph.h"

#define MAX 25
using namespace std;

typedef struct Point {
	int x, y;
} Point;

int N;
int danji[MAX * MAX];
int map[MAX][MAX];
Point pList[MAX * MAX];
int cnt;

void DFS(int x, int y)
{
	if (x >= 0 && x < N && y >= 0 && y < N && map[y][x] == 1) {
		map[y][x] = 0;
		cnt++;
		DFS(x - 1, y);
		DFS(x + 1, y);
		DFS(x, y - 1);
		DFS(x, y + 1);
	}
}

int main()
{
	int k = 0, l = 0;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &map[i][j]);

			if (map[i][j] == 1) {
				pList[k].x = j;
				pList[k].y = i;
				k++;
			}
		}
	}

	for (int i = 0; i < k; i++) {
		DFS(pList[i].x, pList[i].y);
		if (cnt) {
			danji[l++] = cnt;
			cnt = 0;
		}
	}
	sort(danji, danji + l);
	printf("%d\n", l);
	for (int i = 0; i < l; i++)
		printf("%d\n", danji[i]);
	
	return 0;
}