#include "stack.h"

// Функции для задания 2
int push(Stack* s, int value) {
    if (is_full(s)) return 0;
    s->data[++s->top] = value;
    return 1;
}

int find_max_even(Stack* s) {
    int max_even = INT_MIN;
    for (int i = 0; i <= s->top; i++) {
        if (s->data[i] % 2 == 0 && s->data[i] > max_even) {
            max_even = s->data[i];
        }
    }
    return max_even;
}

void task2() {
    Stack stack;
    int max_size;

    printf("\n=== Задание 2 ===\n");
    printf("Введите размер стека: ");
    scanf("%d", &max_size);
    init_stack(&stack, max_size);

    int choice;
    do {
        printf("\nМеню задания 2:\n");
        printf("1. Добавить элемент\n");
        printf("2. Просмотреть стек\n");
        printf("3. Найти макс. четный\n");
        printf("4. Вернуться\nВыберите: ");

        if (scanf("%d", &choice) != 1) {
            clear_input_buffer();
            printf("Ошибка ввода!\n");
            continue;
        }

        switch(choice) {
            case 1:
                if (is_full(&stack)) {
                    printf("Стек полон!\n");
                    break;
                }
                int val;
                printf("Значение: ");
                if (scanf("%d", &val) == 1) {
                    push(&stack, val);
                    printf("Добавлено\n");
                } else {
                    clear_input_buffer();
                    printf("Ошибка!\n");
                }
                break;
            case 2:
                print_stack(&stack, "Текущий стек");
                break;
            case 3: {
                int res = find_max_even(&stack);
                if (res != INT_MIN) printf("Максимум: %d\n", res);
                else printf("Четных нет!\n");
                break;
            }
            case 4: break;
            default: printf("Неверно!\n");
        }
    } while (choice != 4);

    free(stack.data);
}