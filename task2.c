#include "stack.h"

// Ôóíêöèè äëÿ çàäàíèÿ 2
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

void max_chetn() {
    Stack stack;
    int max_size;

    printf("\n=== Çàäàíèå 2 ===\n");
    printf("Ââåäèòå ðàçìåð ñòåêà: ");
    scanf("%d", &max_size);
    init_stack(&stack, max_size);

    int choice;
    do {
        printf("\nÌåíþ çàäàíèÿ 2:\n");
        printf("1. Äîáàâèòü ýëåìåíò\n");
        printf("2. Ïðîñìîòðåòü ñòåê\n");
        printf("3. Íàéòè ìàêñ. ÷åòíûé\n");
        printf("4. Âåðíóòüñÿ\nÂûáåðèòå: ");

        if (scanf("%d", &choice) != 1) {
            clear_input_buffer();
            printf("Îøèáêà ââîäà!\n");
            continue;
        }

        switch(choice) {
            case 1:
                if (is_full(&stack)) {
                    printf("Ñòåê ïîëîí!\n");
                    break;
                }
                int val;
                printf("Çíà÷åíèå: ");
                if (scanf("%d", &val) == 1) {
                    push(&stack, val);
                    printf("Äîáàâëåíî\n");
                } else {
                    clear_input_buffer();
                    printf("Îøèáêà!\n");
                }
                break;
            case 2:
                print_stack(&stack, "Òåêóùèé ñòåê");
                break;
            case 3: {
                int res = find_max_even(&stack);
                if (res != INT_MIN) printf("Ìàêñèìóì: %d\n", res);
                else printf("×åòíûõ íåò!\n");
                break;
            }
            case 4: break;
            default: printf("Íåâåðíî!\n");
        }
    } while (choice != 4);

    free(stack.data);
}
