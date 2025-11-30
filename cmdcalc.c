#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "opcalc.h"

void ErrorIncorrectInput(){
	printf("Ошибка: Неверный ввод!");
}
int main(int argc, char* argv[]) {
	if (argc < 5) {
		ErrorIncorrectInput();
		return 1;
	}

	if (strcmp(argv[argc - 2], "-k") != 0) {
    		ErrorIncorrectInput();
    		return 1;
	}
	int expr_count = (argc - 3) / 3;

	if ((argc - 3) % 3 != 0) {
    		ErrorIncorrectInput();
    		return 1;
	}

        int key = atoi(argv[argc-1]);
	//int expr_count = (argc - 3) / 3;
	int* results = (int*)malloc(sizeof(int) * expr_count);

        if (!results) {
        	printf("Ошибка памяти\n");
        	return 1;
        }
	int idx = 0;
	for (int i = 1; i < argc - 2; i += 3) {
    		int a = atoi(argv[i]);
    		int b = atoi(argv[i+2]);
    		char op = argv[i+1][0];
   		int res;

    		switch(op) {
        		case '+': res = sum(a,b); break;
        		case '-': res = sub(a,b); break;
        		case '*': res = prod(a,b); break;
        		case '%': 
            		if (b == 0) {
                		printf("Ошибка: Деление на 0!\n");
                		free(results);
                		return 1;
            		}
            		res = rem(a,b); 
            		break;
        		default:
            		ErrorIncorrectInput();
            		free(results);
            		return 1;
    		}

    		results[idx++] = res;
	}

	decode_and_print(results, expr_count, key);
	free(results);
        return 0;
		
}
