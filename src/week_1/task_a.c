#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main() {
    int n = 0;
    scanf("%d", &n);
    size_t number_of_flowers = n;
    int32_t* flowers = (int32_t*) calloc(number_of_flowers, sizeof(int32_t));

    if(!flowers) {
       fprintf(stdout, "Unable create flowers array");
       return -1;
    }

    size_t repeats = 1;
    size_t firstFlower = 0;
    size_t lastFlower = 0;
    size_t frameStart = 0;
    size_t frameStop = 0;

    scanf("%d", &(flowers[0]));    
    for(size_t i = 1; i < number_of_flowers; i++){
        scanf("%d", &(flowers[i]));
        if(flowers[i] == flowers[i-1]){
            repeats++;
            if(repeats >= 3){
                if(lastFlower - firstFlower < frameStop - frameStart){
                    lastFlower = frameStop;
                    firstFlower = frameStart;
                }
                repeats = 2;
                frameStart = i - 1;
            }
        }else{
            repeats = 1;
        }
        frameStop = i;
    }

    free(flowers);

    if(lastFlower - firstFlower < frameStop - frameStart){
        lastFlower = frameStop;
        firstFlower = frameStart;
    }
    fprintf(stdout,"%zu %zu", firstFlower + 1, lastFlower + 1);

    return 0;
}