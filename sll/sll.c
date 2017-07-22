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
		L->append = sll_Append;
		L->prepend = sll_Prepend;
		L->print = sll_Print;
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

slln* sll_Append(sll* L, slln* node) {
	if (node != NULL && L != NULL) {
		
		if (L->size > 0) {
			L->tail->nxt = node;
		} else {
			L->head = node;
		}
		L->tail = node;
		L->size ++;
	}
	return node;
}

slln* sll_Prepend(sll* L, slln* node){
	if (node != NULL && L != NULL) {
		node->nxt = L->head;
		if (L->size == 0){
			L->tail = node;
		}
		L->head = node;
		L->size++;
	}
	return node;
}

void sll_Print(sll* L) {
	slln* curr;
	
	printf("%p : \n\thead: %p\n\ttail: %p\n\tsize: %zu\ndata:\n[",L,L->head,L->tail,L->size);
	for(curr = L->head; curr != NULL; curr = curr->nxt) {
		curr->print(curr->data);
		if (curr != L->tail){
			printf(", ");
		} else {
			printf("]");
		}
	}
}

#endif
