#include "stack.h"

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int choice;
    do {
        printf("\n=== Главное меню ===\n");
        printf("1. Задание 1 - Два стека с объединением\n");
        printf("2. Задание 2 - Поиск макс. четного\n");
        printf("3. Выход\nВыберите: ");

        if (scanf("%d", &choice) != 1) {
            clear_input_buffer();
            printf("Ошибка!\n");
            continue;
        }

        switch(choice) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: printf("Выход...\n"); break;
            default: printf("Неверный выбор!\n");
        }
    } while (choice != 3);

    return 0;
}