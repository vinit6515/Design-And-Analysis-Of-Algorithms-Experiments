#include <stdio.h>
#include <limits.h>
#define vertices 6
int minDist(int dist[], int pre[]) {
int minimum = INT_MAX, min, i;
for (i = 0; i < vertices; i++)
if (pre[i] == 0 && dist[i] <= minimum)
minimum = dist[i], min = i;
return min;
}
void printSolution(int dist[]) {
printf("Vertex \t\t Distance from Source\n");
for (int i = 0; i < vertices; i++)
printf("%d \t\t\t\t %d\n", i, dist[i]);
}
void dijkstra(int graph[vertices][vertices], int src) 
{
int dist[vertices];
int pre[vertices];
for (int i = 0; i < vertices; i++)
{
dist[i] = INT_MAX;
pre[i] = 0;
}
dist[src] = 0;
for (int count = 0; count < vertices - 1; count++)
{
int u = minDist(dist, pre);
pre[u] = 1;
for (int v = 0; v < vertices; v++)
if (pre[v] == 0 && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] <
dist[v])
dist[v] = dist[u] + graph[u][v];
printSolution(dist);
}
}
int main() {
printf("Vinit Shah C3-2 C183 60004220097\n");
int graph[vertices][vertices] = {
{0, 3, 9, 5, 0, 0 },
{3, 0, 4, 3, 7, 0 },
{9, 4, 0, 2, 2, 2 },
{5, 3, 2, 0, 6, 8 },
{0, 7, 2, 6, 0, 5 },
{0, 0, 2, 8, 5, 0 }
};
dijkstra(graph, 0);
return 0;
}