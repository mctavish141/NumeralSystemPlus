#include <stdio.h>
#include <stdlib.h>

typedef struct memory_s {
    char *mas;
    int count;
} memory_s;

typedef struct heap_s {
    char mas[100];
    int count;
    int check;
    memory_s *memory;
} heap_s;

int main () {
    memory_s *m1 = malloc(sizeof(memory_s));
    m1->mas = "123";
    m1->count = 4;
    
    heap_s *h1 = malloc(sizeof(heap_s));
    h1->memory = m1;
    h1->count = h1->memory->count;
    
    printf("%d", h1->count); // Выведется 4
    
    return 0;
}
