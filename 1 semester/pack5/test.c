#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(void)
{
    // выделяем блок памяти для 5 чисел int
    int m = 5;                  // количество элементов
    int n = m * sizeof(int);    // размер выделяемой памяти
    int *ptr = malloc(n);
    if (ptr)
    {
        // иницилизируем все байты нулями
        memset(ptr, 0, n);
        // проверяем инициализацию
        for (int i = 0; i < m; i++)
        {
            printf("%d ", ptr[i]);
        }
    }
    free(ptr);
    return 0;
}