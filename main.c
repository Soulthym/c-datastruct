#include "main.h"

void delInt(void *d) {
	free(d);
}

void printInt(void *d) {
	printf("%d", *(int*)d);
}

int main(int argc, char *argv[]) {
	sll* L = SLL.new();
	SLL.print(L);
	*(int*)SLL.append(L, SLLN.new(0, malloc(sizeof(int)), delInt, printInt))->data = 2;
	SLL.print(L);
	*(int*)SLL.prepend(L, SLLN.new(0, malloc(sizeof(int)), delInt, printInt))->data = 1;
	SLL.print(L);
	*(int*)SLL.append(L, SLLN.new(0, malloc(sizeof(int)), delInt, printInt))->data = 3;
	SLL.print(L);
	SLL.delhead(L);
	SLL.print(L);
	*(int*)SLL.insert(L, SLLN.new(0, malloc(sizeof(int)), delInt, printInt), L->tail)->data = 1;
	SLL.print(L);
	int i;
	for(i = 0; i < L->size; i++)
		printf("%d, ",*(int*)SLL.get(L, i)->data);
	printf("\n");
	SLL.del(L);
	return 0;
}
