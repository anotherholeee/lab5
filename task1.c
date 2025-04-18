#include "stack.h"

// ������� ��� ������� 1
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

void task1() {
    Stack stack1, stack2, stack3;
    int max_size;

    printf("\n=== ������� 1 ===\n");
    printf("������� ������������ ������ ������: ");
    scanf("%d", &max_size);

    init_stack(&stack1, max_size);
    init_stack(&stack2, max_size);
    init_stack(&stack3, max_size * 2);

    int choice;
    do {
        printf("\n���� ������� 1:\n");
        printf("1. �������� � 1-� ���� (�� �����������)\n");
        printf("2. �������� �� 2-� ���� (�� �����������)\n");
        printf("3. �������� �����\n");
        printf("4. ������� 3-� ���� (�� ��������)\n");
        printf("5. ���������\n��������: ");

        if (scanf("%d", &choice) != 1) {
            clear_input_buffer();
            printf("������ �����!\n");
            continue;
        }

        switch(choice) {
            case 1: case 2: {
                Stack* s = (choice == 1) ? &stack1 : &stack2;
                int val;
                printf("������� ��������: ");
                if (scanf("%d", &val) != 1) {
                    clear_input_buffer();
                    printf("������!\n");
                    break;
                }
                if (push_sorted_asc(s, val)) printf("�������\n");
                else printf("������ ����������!\n");
                break;
            }
            case 3:
                print_stack(&stack1, "���� 1");
                print_stack(&stack2, "���� 2");
                print_stack(&stack3, "���� 3");
                break;
            case 4:
                stack3.top = -1;
                merge_stacks_desc(&stack1, &stack2, &stack3);
                printf("������������ ���� ������!\n");
                break;
            case 5: break;
            default: printf("�������� �����!\n");
        }
    } while (choice != 5);

    free(stack1.data);
    free(stack2.data);
    free(stack3.data);
}