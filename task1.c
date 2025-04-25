#include "stack.h"

// Ôóíêöèè äëÿ çàäàíèÿ 1
int push_sorted_asc(Stack* s, int value) {
    if (is_full(s)) return 0;
    if (!is_empty(s) && value < s->data[s->top]) return 0;
    s->data[++s->top] = value;
    return 1;
}

void merge_stacks_desc(Stack* s1, Stack* s2, Stack* result) {
    int idx1 = 0, idx2 = 0;
    while (idx1 <= s1->top || idx2 <= s2->top) {
        int val1 = (idx1 <= s1->top) ? s1->data[idx1] : INT_MAX;
        int val2 = (idx2 <= s2->top) ? s2->data[idx2] : INT_MAX;
        if (val1 <= val2) {
            result->data[++result->top] = val1;
            idx1++;
        } else {
            result->data[++result->top] = val2;
            idx2++;
        }
    }
}

void sort_vozr() {
    Stack stack1, stack2, stack3;
    int max_size;

    printf("\n=== Çàäàíèå 1 ===\n");
    printf("Ââåäèòå ìàêñèìàëüíûé ðàçìåð ñòåêîâ: ");
    scanf("%d", &max_size);

    init_stack(&stack1, max_size);
    init_stack(&stack2, max_size);
    init_stack(&stack3, max_size * 2);

    int choice;
    do {
        printf("\nÌåíþ çàäàíèÿ 1:\n");
        printf("1. Äîáàâèòü â 1-é ñòåê (ïî âîçðàñòàíèþ)\n");
        printf("2. Äîáàâèòü âî 2-é ñòåê (ïî âîçðàñòàíèþ)\n");
        printf("3. Ïîêàçàòü ñòåêè\n");
        printf("4. Ñîçäàòü 3-é ñòåê (ïî óáûâàíèþ)\n");
        printf("5. Âåðíóòüñÿ\nÂûáåðèòå: ");

        if (scanf("%d", &choice) != 1) {
            clear_input_buffer();
            printf("Îøèáêà ââîäà!\n");
            continue;
        }

        switch(choice) {
            case 1: case 2: {
                Stack* s = (choice == 1) ? &stack1 : &stack2;
                int val;
                printf("Ââåäèòå çíà÷åíèå: ");
                if (scanf("%d", &val) != 1) {
                    clear_input_buffer();
                    printf("Îøèáêà!\n");
                    break;
                }
                if (push_sorted_asc(s, val)) printf("Óñïåøíî\n");
                else printf("Îøèáêà äîáàâëåíèÿ!\n");
                break;
            }
            case 3:
                print_stack(&stack1, "Ñòåê 1");
                print_stack(&stack2, "Ñòåê 2");
                print_stack(&stack3, "Ñòåê 3");
                break;
            case 4:
                stack3.top = -1;
                merge_stacks_desc(&stack1, &stack2, &stack3);
                printf("Îáúåäèíåííûé ñòåê ñîçäàí!\n");
                break;
            case 5: break;
            default: printf("Íåâåðíûé âûáîð!\n");
        }
    } while (choice != 5);

    free(stack1.data);
    free(stack2.data);
    free(stack3.data);
}
