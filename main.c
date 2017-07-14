#include "main.h"

int main(int argc, char *argv[]) {
	int* a = malloc(sizeof(int));
	*a = 42;
	sll* L = sll_New();

	slln* node = sll_NewNode(0,a,NULL,NULL);
	L->head = node;
	L->tail = node;
	L->size ++;
	printf("a = %d\n", *(int*)(L->head)->data);
	return 0;
}
