#include <stdio.h>

typedef struct elem_list{
    double value;
    int next_index;    
} elem_list;

int main(){
    int n, f;
    elem_list all_elems[100010];
    scanf("%d %d", &n, &f);
    for (int i =0; i < n; i++){
        float val = 0.0;
        int index;
        scanf("%f %d", &val, &index);
        all_elems[i].value = val;
        all_elems[i].next_index = index;
    }
    for (int i = f; i != -1; i = all_elems[i].next_index){
        printf("%0.3lf\n", all_elems[i].value);
    }
    return 0;
}