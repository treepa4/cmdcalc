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
		char* op = argv[i+1];
		int b = atoi(argv[i+2]);
		int res;
		if (strcmp(op, "+") == 0) res = sum(a, b);
		else if (strcmp(op, "-") == 0) res = sub(a, b);
		else if (strcmp(op, "*") == 0) res = prod(a, b);
		else if (strcmp(op, "%") == 0) {
			if (b == 0) {
				free(results);
        		        return 1;
			}	
			res = rem(a, b);
		}
		else {
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
