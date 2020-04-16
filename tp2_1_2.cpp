#include <stdio.h>
#include <stdlib.h>

#define N 4
#define M 5


int main(){

int f,c;
double mt[N][M];
double *p;

p = &mt[0][0];

for(f=0;f<N;f++){
    for(c=0;c<M;c++){
        printf("%d ",*(p+f*M+c));
    }
    printf("\n");
}


    scanf(" %c");

    return 0;
}