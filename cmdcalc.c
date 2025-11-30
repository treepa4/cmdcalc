#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void ErrorIncorrectInput(){
	printf("Ошибка: Неверный ввод!");
}
int main(int argc, char* argv[]) {
	if ((argc <= 5) || (strcmp(argv[argc-2], "-k") != 0)) {
		ErrorIncorrectInput();
		return 1;
	}

}
