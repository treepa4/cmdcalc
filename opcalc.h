#pragma once
#include <stddef.h>

int sum(int a, int b);
int sub(int a, int b);
int prod(int a,int b);
int rem(int a, int b);

int calculate(int a, char op, int b);
void decode_and_print(int *results, size_t count, int key);
