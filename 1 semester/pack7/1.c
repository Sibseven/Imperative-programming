#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node_S{
    char value[8];
    int key;
} Node;
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    Node* all_nodes = (Node*)malloc(sizeof(Node)*(n+10));
    for (int i = 0; i<n; i++){
        scanf("%d %s", &all_nodes[i].key, all_nodes[i].value);
    }
    for (int i = 0; i < n; i++){
        for (int j = 1; j < n; j++ ){
            if (all_nodes[j-1].key > all_nodes[j].key){
                Node temp = all_nodes[j-1];
                all_nodes[j - 1] = all_nodes[j];
                all_nodes[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d %s\n", all_nodes[i].key, all_nodes[i].value);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}