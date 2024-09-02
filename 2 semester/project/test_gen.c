#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MAX_VERTICES 200000
#define MAX_EDGES 200000

int main() {
    int num_vertices = MAX_VERTICES;
    int num_edges = MAX_VERTICES-4;

    srand(42);  // Устанавливаем начальное значение генератора случайных чисел для воспроизводимости

    FILE *file = fopen("input.txt", "w");
    if (!file) {
        printf("Ошибка при открытии файла для записи.\n");
        return 1;
    }

    fprintf(file, "%d %d\n", num_vertices, num_edges);
    int n = 1;
    int now_edge = 1;
    for (int i = 2; i < num_edges; ++i) {

        fprintf(file, "%d %d\n", 1, i);
    }

    fclose(file);
    printf("Тест успешно записан в файл input.txt.\n");

    return 0;
}
