#include <stdio.h>
#include <string.h>
typedef struct Label_s {
    char name [16]; //имя автора (заканчивается нулём)
    int age ; //возраст автора (сколько лет)
} Label ;

typedef struct NameStats_s {
    int cntTotal ;//сколько всего подписей
    int cntLong ;//сколько подписей с именами длиннее 10 букв
} NameStats ;

typedef struct AgeStats_s {
    int cntTotal ;//сколько всего подписей
    int cntAdults ; //сколько подписей взрослых (хотя бы 18 лет)
    int cntKids ;//сколько подписей детей (меньше 14 лет)
} AgeStats ;

void calcStats ( const Label * arr , int cnt , NameStats * oNames , AgeStats * oAges ){
    for (int i = 0; i < cnt; i++){
        if (strlen(&arr[i].name) > 10){
            oNames->cntLong += 1;
        }
        if (arr[i].age >= 18){
            oAges->cntAdults += 1;
        }
        if (arr[i].age < 14){
            oAges->cntKids += 1;
        }
    }
    printf("names: total = %d\n", oNames->cntTotal);
    printf("names: long = %d\n", oNames->cntLong);
    printf("ages: total = %d\n", oAges->cntTotal);
    printf("ages: adult = %d\n", oAges->cntAdults);
    printf("ages: kid = %d\n", oAges->cntKids);
}

int main (){
    AgeStats age_stats_v;
    NameStats name_stats_v;
    name_stats_v.cntLong = 0;
    age_stats_v.cntTotal = 0, age_stats_v.cntKids = 0, age_stats_v.cntAdults = 0;
    scanf("%d", &age_stats_v.cntTotal);
    name_stats_v.cntTotal = age_stats_v.cntTotal;
    char age_word[100];
    Label names[1001];
    for (int i = 0; i < age_stats_v.cntTotal; i++){
        scanf("%16s %d %s", &names[i].name, &names[i].age, age_word);
    }
    calcStats(names, age_stats_v.cntTotal, &name_stats_v, &age_stats_v);
}