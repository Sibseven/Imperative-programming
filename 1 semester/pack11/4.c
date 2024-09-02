#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef int (*compar)(const void *, const void *);
int ll_cmp(const void *a, const void *b){
    long long a1 = *(long long *)a;
    long long b1 = *(long long *)b; 
    if (a1 > b1){
        return 1;
    }
    else if (a1 < b1){
        return -1;
    }
    else{
        return 0;
    }
    
}


int cmpstr(void const *a, void const *b) { 
    char const *a1 = *(char const **)a;
    char const *b1 = *(char const **)b;
    return strcmp(a1, b1);
}

int cmpstr_lower_bound(void const *a, void const *b){
    char *a1 = *(char **)a;
    char *b1 = (char *)b;
    return strcmp(a1, b1);
}

int lower_bound(void *elems, void* search, int n, size_t size, compar func){
    int left = 0, right = n - 1;
    while (left < right){
        int mid = (left + right)/2;
        void *nowptr = (void *)(((char*)elems) + mid*size);
        // char **test = (char **)nowptr;
        // char teeeest = **test;
        if (func(nowptr, search) >= 0){
            right = mid;// смещаем границы 
        }
        else{
            left = mid +1;
        }
    }
    void *nowptr = (void *)(((char*)elems) + left*size);
    while (func(nowptr, search) < 0){//идем до ближайщего большего элемента
        if (left == n){
            return n;
        }
        nowptr = (void *)(((char*)elems) + left*size);
        left++;
    }
    return left;
    
}

int main(){
    FILE *input = freopen("input.txt", "r", stdin);
    FILE *output = freopen("output.txt", "w", stdout);
    int n1, n2, q1, q2;
    long long nums[100005] = {0};
    char *strings[100005];

    scanf("%d", &n1);
    for(int i = 0; i < n1; i++){
        scanf("%lld", &nums[i]);
    }
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++){
        strings[i] = calloc(32, sizeof(char));
        scanf("%s", strings[i]);
    }
    qsort(nums, n1, sizeof(long long), ll_cmp);
    qsort(strings, n2, sizeof(char*), cmpstr);
    scanf("%d", &q1);
    for (int i = 0; i < q1; i++){
        long long now;
        scanf("%lld", &now);
        printf("%d\n", lower_bound(nums, &now, n1, sizeof(long long int), ll_cmp));
    }
    scanf("%d", &q2);
    for (int i = 0; i < q2; i++){
        char now[32];
        scanf("%s", now);
        printf("%d\n", lower_bound(strings, now, n2, sizeof(char *), cmpstr_lower_bound));
    }
    fclose(input);
    fclose(output);
    return 0;
}