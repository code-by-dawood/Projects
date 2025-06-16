#include<stdio.h>
#include<stdlib.h>

#define max 100
#define vis 1

void insertEdge(int arr[max][max], int u, int v);
void deleteEdge(int arr[max][max], int u, int v);
void BFS(int arr[max][max], int start);
void DFS(int arr[max][max], int start);
void DFSUtil(int arr[max][max], int start, int visited[max]);

void insertEdge(int arr[max][max], int u, int v)
{
    arr[u][v] = 1;
    arr[v][u] = 1;
}

void deleteEdge(int arr[max][max], int u, int v)
{
    arr[u][v] = 0;
    arr[v][u] = 0;
}

void BFS(int arr[max][max], int start)
{
    int queue[max];
    int visited[max] = {0};
    int front = 0, rear = 0;

    visited[start] = vis;
    queue[rear++] = start; // enqueue first element

    while (front < rear)
    {
        int current = queue[front++]; // dequeue
        printf("%d ", current);

        for (int i = 0; i < max; i++)
        {
            if (arr[current][i] == 1 && !visited[i])
            {
                visited[i] = vis;
                queue[rear++] = i; // enqueue
            }
        }
    }
    printf("\n");
}

void DFS(int arr[max][max], int start)
{
    int visited[max] = {0};
    DFSUtil(arr, start, visited);
    printf("\n");
}

void DFSUtil(int arr[max][max], int start, int visited[max])
{
    visited[start] = vis;
    printf("%d ", start);

    for (int i = 0; i < max; i++)
    {
        if (arr[start][i] == 1 && !visited[i])
        {
            DFSUtil(arr, i, visited);
        }
    }
}

int main()
{
    int graph[max][max] = {0};

    insertEdge(graph, 0, 1);
    insertEdge(graph, 0, 2);
    insertEdge(graph, 1, 2);
    insertEdge(graph, 2, 3);

    printf("BFS starting from node 2:\n");
    BFS(graph, 2);

    printf("DFS starting from node 2:\n");
    DFS(graph, 2);

    return 0;
}
