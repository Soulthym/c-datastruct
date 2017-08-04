#ifndef _SLL_C_
#define _SLL_C_
#include "sll.h"

void func(void) {
	printf("_");
}

sll_* new(void) {
	sll_ *new = malloc(sizeof(sll_));
	new->head = NULL;
	new->tail = NULL;
	new->size = 0;
	return new;
}

const struct sll sll = {
    .func = func
};

#endif
