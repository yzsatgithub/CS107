#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void swap(void* vp1, void* vp2, int size){
    char buffer[size];
    memcpy(buffer, vp1, size);
    memcpy(vp1, vp2, size);
    memcpy(vp2, buffer, size);
}

int main(){
    int a = 10;
    int b = 30;
    printf("%d, %d\n", a, b);
    swap(&a, &b, sizeof(int));
    printf("%d, %d\n", a, b);
    double c = 0.125;
    double d = 1.245;
    printf("%f, %f\n", c, d);
    swap(&c, &d, sizeof(double));
    printf("%f, %f\n", c, d);
    return 0;
}
