#include <stdio.h>
#include <stdlib.h>

char* concat (char* pref , char* suff ){
    while (*pref != '\0'){
        pref++;
    }
    while (*suff != '\0'){
        *pref = *suff;
        pref++;
        suff++;
    }
    *pref = '\0';
    return pref;
}
int main(){
    int n;
    scanf("%d", &n);
    char* s = malloc(10000001 * sizeof(char));
    scanf("%s", s);
    char* p = s;
    char s2[101];
    for (int i = 0; i < n - 1; i++){
        scanf("%s", s2);
        s = concat(s,s2);
    }
    printf("%s", p);
    free(p);
}