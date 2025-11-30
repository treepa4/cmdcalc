#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "opcalc.h"
#include <limits.h>

int sum(int a, int b){
	return a+b;
}
int sub(int a, int b){
	return a-b;
}
int prod(int a,int b){
	return a*b;
}
int rem(int a, int b){
	return a%b;
}

int calculate(int a, char op, int b) {
    switch (op) {
        case '+':
            return sum(a, b);
        case '-':
            return sub(a, b);
        case '*':
            return prod(a, b);
        case '%':
            if (b == 0) {
                return 1;
            }
            return rem(a, b);
        default:
            return 1;
    }
}
void decode_and_print(int* results, size_t count, int key) {
    if (!results || count <= 0) {
        printf("Нет данных для декодирования.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        int decoded = results[i] - key;
        printf("Ответ №%d: %d\n", i + 1, decoded);
    }
    char* str = (char*)malloc(count + 1);
    if (!str) {
        printf("Ошибка памяти\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        str[i] = (char)(results[i] - key);
    }
    str[count] = '\0';
    printf("Результирующая строка: %s\n", str);

    free(str);
    
}
