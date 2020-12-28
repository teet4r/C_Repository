#pragma once
#include <cstdio>

#define FRESH 0
#define VISITED 1
#define CONNECTED 1
using namespace std;

class Graph {
private:
	int vN;
	int *vList = NULL;
	int **matrix = NULL;
public:
	Graph(int vN) {
		this->vN = vN;

		vList = new int[vN + 1]();
		matrix = new int*[vN + 1]();
		for (int i = 1; i < vN + 1; i++)
			matrix[i] = new int[vN + 1]();
	}
	~Graph() {
		delete[] vList;
		for (int i = 1; i < vN + 1; i++)
			delete[] matrix[i];
		delete[] matrix;
	}
	void connect(int v1, int v2) {
		matrix[v1][v2] = CONNECTED;
		matrix[v2][v1] = CONNECTED;
	}
	void DFS(int start) {
		vList[start] = VISITED;
		printf("%d ", start);

		for (int j = 1; j < vN + 1; j++)
			if (vList[j] == FRESH && matrix[start][j] == CONNECTED) {
				DFS(j);
			}
	}
	void BFS(int start) {
		int *queue = new int[vN + 1];
		int front = 0, rear = 0;

		vList[start] = VISITED;
		queue[rear++] = start;
		while (front < rear) { // 큐가 비어있을 때까지
			start = queue[front++];
			printf("%d ", start);

			for (int i = 1; i < vN + 1; i++)
				if (vList[i] == FRESH && matrix[start][i] == CONNECTED) {
					queue[rear++] = i;
					vList[i] = VISITED;
				}
		}
		delete[] queue;
	}
};