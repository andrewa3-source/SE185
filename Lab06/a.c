#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    
    
    srand(time(0));
    int num;
    num = rand() % 4 +1;
    printf("%d", num);

    return 0;
}