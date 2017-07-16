#include "main.h"
//#include <stdio.h>
//#include <stdlib.h>

void printInt(void* i) {
	printf("%d",*(int*)(i));
}

void deleteInt(void* i){
	free(i);
}

int main(int argc, char *argv[]) {
	int *a = malloc(sizeof(int)), *b = malloc(sizeof(int));
	*a = 42;
	*b = 13;
	sll* L = sll_New();
	void (*pInt)(void*) = printInt;
	void (*dInt)(void*) = deleteInt;
	slln* node = sll_NewNode(0,a,dInt,pInt);
	L->append(L,node);
	node = sll_NewNode(0,b,dInt,pInt);
	L->append(L,node);
	L->print(L);
	return 0;
}
