#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <locale.h>
#include <windows.h>

typedef struct {
    int* data;
    int top;
    int max_size;
} Stack;

// Общие функции стека
void init_stack(Stack* s, int size);
int is_full(Stack* s);
int is_empty(Stack* s);
void print_stack(Stack* s, const char* name);
void clear_input_buffer();

// Функции для задания 1
int push_sorted_asc(Stack* s, int value);
void merge_stacks_desc(Stack* s1, Stack* s2, Stack* result);
void task1();

// Функции для задания 2
int push(Stack* s, int value);
int find_max_even(Stack* s);
void task2();

#endif