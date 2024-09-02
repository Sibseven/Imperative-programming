#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node** createGraph(int n) {
    Node** graph = (Node**)malloc((n + 1) * sizeof(Node*));
    for (int i = 0; i <= n; i++) {
        graph[i] = NULL;
    }
    return graph;
}

void addEdge(Node** graph, int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = graph[u];
    graph[u] = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = u;
    newNode->next = graph[v];
    graph[v] = newNode;
}

int min(int a, int b) {
    return a < b ? a : b;
}

void dfs(int v, int p, int timer, int* tin, int* fup, int* parent, int* is_cutvertex, Node** graph) {
    tin[v] = fup[v] = timer++;
    int children = 0;

    for (Node* cur = graph[v]; cur != NULL; cur = cur->next) {
        int i = cur->vertex;
        if (i == p) {
            continue;
        }

        if (tin[i] == -1) {
            children++;
            parent[i] = v;
            dfs(i, v, timer, tin, fup, parent, is_cutvertex, graph);
            fup[v] = min(fup[v], fup[i]);

            if (fup[i] >= tin[v] && p != -1) {
                is_cutvertex[v] = 1;
            }
        } else {
            fup[v] = min(fup[v], tin[i]);
        }
    }

    if (p == -1 && children > 1) {
        is_cutvertex[v] = 1;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    if (m == 1) {
        int u, v;
        scanf("%d %d", &u, &v);
        printf("%d\n", 1);
        printf("%d", min(u, v));
        return 0;
    }

    Node** graph = createGraph(n);
    int* tin = (int*)malloc((n + 1) * sizeof(int));
    int* fup = (int*)malloc((n + 1) * sizeof(int));
    int* parent = (int*)malloc((n + 1) * sizeof(int));
    int* is_cutvertex = (int*)calloc(n + 1, sizeof(int));

    for (int i = 0; i <= n; i++) {
        tin[i] = fup[i] = -1;
        parent[i] = -1;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    int timer = 0;
    for (int i = 1; i <= n; i++) {
        if (tin[i] == -1) {
            dfs(i, -1, timer, tin, fup, parent, is_cutvertex, graph);
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (is_cutvertex[i]) {
            cnt++;
        }
    }

    printf("%d\n", cnt);
    for (int i = 1; i <= n; i++) {
        if (is_cutvertex[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");

    for (int i = 0; i <= n; i++) {
        Node* cur = graph[i];
        while (cur != NULL) {
            Node* temp = cur;
            cur = cur->next;
            free(temp);
        }
    }
    free(graph);
    free(tin);
    free(fup);
    free(parent);
    free(is_cutvertex);

    return 0;
}
