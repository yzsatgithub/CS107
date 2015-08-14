#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void* lsearch(void* key, void* base, int n, int elemSize){
    for(int i = 0; i < n; i++){
        void* elemAddr = (char*)base + i * elemSize;
        if(memcmp(key, elemAddr, elemSize) == 0)   return elemAddr;
    }
    return NULL;
}

int main(){
    int array[5] = {1, 2, 3, 4, 5};
    int key = 4;
    void* index = lsearch(&key, array, 6, sizeof(int));
    printf("%d\n", *((int* )index));

    return 0;
}
