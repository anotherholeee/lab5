#include "stack.h"

// ������� ��� ������� 2
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

    printf("\n=== ������� 2 ===\n");
    printf("������� ������ �����: ");
    scanf("%d", &max_size);
    init_stack(&stack, max_size);

    int choice;
    do {
        printf("\n���� ������� 2:\n");
        printf("1. �������� �������\n");
        printf("2. ����������� ����\n");
        printf("3. ����� ����. ������\n");
        printf("4. ���������\n��������: ");

        if (scanf("%d", &choice) != 1) {
            clear_input_buffer();
            printf("������ �����!\n");
            continue;
        }

        switch(choice) {
            case 1:
                if (is_full(&stack)) {
                    printf("���� �����!\n");
                    break;
                }
                int val;
                printf("��������: ");
                if (scanf("%d", &val) == 1) {
                    push(&stack, val);
                    printf("���������\n");
                } else {
                    clear_input_buffer();
                    printf("������!\n");
                }
                break;
            case 2:
                print_stack(&stack, "������� ����");
                break;
            case 3: {
                int res = find_max_even(&stack);
                if (res != INT_MIN) printf("��������: %d\n", res);
                else printf("������ ���!\n");
                break;
            }
            case 4: break;
            default: printf("�������!\n");
        }
    } while (choice != 4);

    free(stack.data);
}