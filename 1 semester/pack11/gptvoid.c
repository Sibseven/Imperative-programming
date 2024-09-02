#include <stdio.h>
#include <stdlib.h>
int main() {
    long  array[] = {112, 235, 366, 475, 523};
    long  *intPtr = array;  // int pointer 
    char *str[6] = {0};
    str[0] = calloc(35, sizeof(char));
    str[1] = calloc(35, sizeof(char));
    str[2] = calloc(35, sizeof(char));
    str[3] = calloc(35, sizeof(char));
    str[0] = "rrrrty";
    str[1] = "ttrerere";
    str[2] = "erjdfgdfg";
    str[3] = "weew";
    // Convert the int pointer to a void pointer
    void *voidPtr = (void *)str;
    void *nowptr = (void *)(((char*)voidPtr) + 1*8);
    // Calculate the offset (in bytes) for the void pointer
    size_t offset = ((char *)voidPtr - (char *)&array[0]);

    printf("Offset in bytes: %s\n", (char *)nowptr);
    printf("%s", str[2]);
    return 0;
}
