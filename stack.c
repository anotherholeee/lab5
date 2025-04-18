#include "stack.h"

// Общие функции стека
void init_stack(Stack* s, int size) {
    s->data = (int*)malloc(size * sizeof(int));
    if (!s->data) exit(1);
    s->top = -1;
    s->max_size = size;
}

int is_full(Stack* s) { return s->top == s->max_size - 1; }
int is_empty(Stack* s) { return s->top == -1; }

void print_stack(Stack* s, const char* name) {
    printf("\n%s (top->bottom):\n", name);
    if (is_empty(s)) {
        printf("Пуст\n");
        return;
    }
    for (int i = s->top; i >= 0; i--) {
        printf("%d\n", s->data[i]);
    }
}

void clear_input_buffer() {
    while (getchar() != '\n');
}