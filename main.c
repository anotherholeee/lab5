#include "stack.h"

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int choice;
    do {
        printf("\n=== ������� ���� ===\n");
        printf("1. ������� 1 - ��� ����� � ������������\n");
        printf("2. ������� 2 - ����� ����. �������\n");
        printf("3. �����\n��������: ");

        if (scanf("%d", &choice) != 1) {
            clear_input_buffer();
            printf("������!\n");
            continue;
        }

        switch(choice) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: printf("�����...\n"); break;
            default: printf("�������� �����!\n");
        }
    } while (choice != 3);

    return 0;
}