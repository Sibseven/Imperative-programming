#include <stdio.h>
#include <string.h>
#pragma pack(push, 1)

typedef struct fail{
    char name[21];
    long long size;
    char if_directory;
    long long creation_time;
    long long modification_time;
    char if_hidden;
} fail_s;

int main(){
    FILE *inputt = fopen("input.txt", "rb");
    FILE *output = fopen("output.txt", "wb");
    int n;
    fread(&n, sizeof(int), 1, inputt);
    long long needed_creation_time, needed_modification_time;
    fread(&needed_creation_time, sizeof(long long), 1, inputt);
    fread(&needed_modification_time, sizeof(long long), 1, inputt);
    fail_s all_files[1001];
    fail_s* all_needed_files[1001];
    for (int i = 0; i < n; i++){
        fread(&all_files[i], sizeof(fail_s), 1, inputt);
    }
    int now_free = 0;
    for (int i = 0; i < n; i++){
        if (all_files[i].if_directory == 0 && all_files[i].if_hidden == 0 && all_files[i].creation_time >= needed_creation_time && all_files[i].modification_time <= needed_modification_time){
            all_needed_files[now_free] = &all_files[i];
            now_free++;
        }
    }
    for (int i = 0; i < now_free - 1; i++){
        for (int j = i+1; j < now_free; j++){
            if (strcmp(all_needed_files[i]->name, all_needed_files[j]->name) > 0){
                fail_s* pointer = all_needed_files[i];
                all_needed_files[i] = all_needed_files[j];
                all_needed_files[j] = pointer;
            }
        }
    }
    for (int i; i < now_free; i++){
        fwrite(all_needed_files[i], sizeof(fail_s), 1, output);
    }
    fclose(inputt);
    fclose(output);
    return 0;
}
