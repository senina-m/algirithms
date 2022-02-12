#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>

typedef struct Repetition{
    int32_t type;
    size_t repititions;
    struct Repetition* next;
} Repetition;

Repetition* node_create( int32_t type, size_t repititions) {
    Repetition* node = malloc(sizeof(Repetition));
    node->type = type;
    node->repititions = repititions;
    return node; 
}

void list_add_front(Repetition** old, int32_t type, size_t repititions) {
    Repetition* new_node = node_create(type, repititions);
    new_node->next = *old;
    *old = new_node;
}

void list_destroy( Repetition* list ) {
    Repetition* tmp = NULL;
    while(list){
        tmp = list-> next;
        free(list);
        list = tmp;
    }
}

Repetition* find_node(Repetition* list, int32_t type){
    Repetition* tmp = NULL;
    while(list){
        tmp = list-> next;
        if(list->type == type) return list;
        list = tmp;
    }
    return NULL;
}

typedef struct {
    int32_t type;
    size_t row;
} Flower;

Flower* init_flower_array(number_of_flowers){
    Flower* flowers = calloc(number_of_flowers, sizeof(Flower));
    return flowers;
}

void clear_flower_array(Flower* flower){
    free(flower);
}

int main() {
   int n = 0;
   scanf("%d", &n);
   size_t number_of_flowers = n;
   Flower* flowers = init_flower_array(number_of_flowers);
   if(!flowers) {
       fprintf(stdout, "Unable create flowers array");
       return -1;
   }

    // read flowers
   for(size_t i = 0; i < number_of_flowers; i++){
        scanf("%d", &(flowers[i].type));
   }

    for(size_t i = 0; i < number_of_flowers; i++){
        Repetition* repetitions = node_create(flowers[i].type, 1);
        size_t k = i + 1;
        while(k < number_of_flowers){
            Repetition* repetition = find_node(repetitions, flowers[k].type);
            if(!repetition) {
                list_add_front(&repetitions, flowers[k].type, 0); 
                repetition = repetitions;
            }
            repetition->repititions += 1;

            if(repetition->repititions >= 3){
                flowers[i].row = k - i - 1;
                break;
            }
            k++;
        }
        if (k == number_of_flowers) flowers[i].row = k - i - 1;
        list_destroy(repetitions);
    }

    size_t max_row = 0;
    size_t first_flower = 0;
    for(size_t i = 0; i < number_of_flowers; i++){
        printf("%zu ", flowers[i].row);
        if(max_row < flowers[i].row){
            first_flower = i;
            max_row = flowers[i].row;
        }
    }

    fprintf(stdout,"The shoot has to be from flower %zu to flower %zu.", first_flower, first_flower + max_row);

   return 0;
}