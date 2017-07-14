#ifndef _SLL_C_
#define _SLL_C_
#include "sll.h"

sll* sll_New(){
	sll* L = NULL;
	L = malloc(sizeof(sll));
	if (L){
		L->head = NULL;
		L->tail = NULL;
		L->size = 0;
	}
	return L;
}

slln* sll_NewNode(size_t type, void* data, void (*delet)(void*), void (*print)(void*)){
	slln* node = NULL;
	node = malloc(sizeof(slln));
	if (node){
		node->type = type;
		node->data = data;
		node->delet = delet;
		node->print = print;
	}
	return node;
}

#endif
