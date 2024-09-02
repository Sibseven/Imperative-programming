#include <stdio.h>
#include <stdlib.h>
#undef max
int max(int a, int b){
    if (a>=b){
        return a;
    }
    return b;
}

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}
void shuffle(int* arr, int n){
    srand (time(NULL));
    for (int i = 0; i < n; i++){
        int swap_ind = rand() % n;
        swap(&arr[i], &arr[swap_ind]);
    }
}

typedef struct Node{
    int value;
    int h;
    int counter;
    struct Node* l;
    struct Node* r;
} Node;

typedef struct my_arr{
    int *arr;
    int now_free;
} my_arr;

void add_my_arr(my_arr* arr, int value){
    arr->arr[arr->now_free] = value;
    arr->now_free++;
}

Node* rotation_left(Node* root){
    Node* temp = root ->r;
    root ->r = root -> r -> l;
    temp ->l = root;
    return temp;
}

Node* rotation_right(Node* root){
    Node* temp = root->l;
    root->l =root ->l->r;
    temp -> r = root;
    return temp;
} 

void update_height(Node* root){
    int h = 0;
    if (root->l != NULL){
        h = max(h, root->l->h);
    }
    if (root->r != NULL){
        h = max(h, root->r->h);
    }
    root->h = h + 1;
}

Node *rebalance(Node* root){
    int hr, hl;
    hl = root->l == NULL?0:root->l->h;
    hr = root->r == NULL?0:root->r->h;
    if (abs(hl - hr) <= 1){
        update_height(root);
        return root;
    }
    if (hr > hl){
        int hrl, hrr;
        hrl = root->r->l == NULL?0:root->r->l->h;
        hrr = root->r->r == NULL?0:root->r->r->h;
        if (hrl == hrr+1){
            root->r = rotation_right(root->r);
        }
        root = rotation_left(root);
        update_height(root->l);
        update_height(root);
    }
    else{
        int hll, hlr;
        hll = root->l->l == NULL? 0 : root->l->l->h;
        hlr = root->l->r == NULL? 0 : root->l->r->h;
        if(hlr == hll + 1){
            root->l = rotation_left(root->l);
            root = rotation_right(root);
            update_height(root->r);
            update_height(root);
        }
    }
    return root;
}

Node* add(Node* root, int value){
    if (root == NULL){
        Node* new = (Node*) calloc(1, sizeof(Node));
        new -> value = value;
        new -> h = 1;
        new ->counter = 1;
        return new;
    }
    if (root->value > value){
        root->l = add(root->l, value);
    }
    else if (root->value < value){
        root->r = add(root->r, value);
    }
    else{
        root->counter++;
    }
    return rebalance(root);

}
void in_order_traversal(struct Node* root, my_arr *arr) {
    if (root != NULL) {
        in_order_traversal(root->l, arr);
        for(int i = 0; i < root->counter; i++){
            add_my_arr(arr, root->value);
        }
        in_order_traversal(root->r, arr);
        free(root);
    }
}
void free_tree(Node* root)

int main(){
    FILE *input = fopen("input.bin", "rb");
    FILE *output = fopen("output.bin", "wb");
    int n;
    fread(&n, sizeof(int), 1, input);
    my_arr res_arr;
    res_arr.arr = calloc(n, sizeof(int));
    fread(res_arr.arr, sizeof(int), n, input);
    shuffle(res_arr.arr, n);
    Node* root = NULL;
    for (int i = 0; i < n; i++){
        root = add(root, res_arr.arr[i]);
    }
    res_arr.now_free = 0;
    in_order_traversal(root, &res_arr);
    fwrite(res_arr.arr, sizeof(int), n, output);
    free(res_arr.arr);
    fclose(input);
    fclose(output);
    return 0;
}