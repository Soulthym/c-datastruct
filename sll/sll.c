#ifndef _SLL_C_
#define _SLL_C_
#include "sll.h"

sll* new(void) {
	sll *new = malloc(sizeof(sll));
	new->head = NULL;
	new->tail = NULL;
	new->size = 0;
	#if DEBUG
		printf("new single linked list at %p\n", new);
	#endif
	return new;
}

slln* newn(size_t type, void *data, void (*del)(void*), void (*print)(void*)) {
	slln* new = malloc(sizeof(slln));
	new->type = type;
	new->data = data;
	new->del = del;
	new->print = print;
	new->nxt = NULL;
	#if DEBUG
		printf("new node at %p, data at %p\n", new, data);
	#endif
	return new;
}

slln* append(sll* L, slln* N) {
	if (L != NULL && N != NULL) {
		if (L->tail) {
			L->tail->nxt = N;
		} else {
			L->head = N;
		}
		L->tail = N;
		L->size ++;
		#if DEBUG
			printf("appended node %p to list %p\n", N, L);
		#endif
		return N;
	}
	#if DEBUG
		printf("failed to append %p to list %p\n", N, L);
	#endif
	return NULL;
}

slln* prepend(sll* L, slln* N) {
	if (L != NULL && N != NULL) {
		N->nxt = L->head;
		if (L->tail == NULL) {
			L->tail = N;
		}
		L->head = N;
		L->size ++;
		#if DEBUG
			printf("prepended node %p to list %p\n", N, L);
		#endif
		return N;
	}
	#if DEBUG
		printf("failed to prepend %p to list %p\n", N, L);
	#endif
	return NULL;
}

void delnode(slln* N) {
	N->del(N->data);
	free(N);
	#if DEBUG
		printf("deleted node at %p\n",N);
	#endif
}

void emptyrec(slln* N) {
	if (N) {
		emptyrec(N->nxt);
		delnode(N);
	}
}

sll* empty(sll* L) {
	emptyrec(L->head);
	L->head = NULL;
	L->tail = NULL;
	L->size = 0;
	#if DEBUG
		printf("emptied list at %p\n", L);
	#endif
	return L;
}

void del(sll* L) {
	free(empty(L));
	#if DEBUG
		printf("freed list at %p\n", L);
	#endif
}

void delhead(sll* L) {
	if (L->head) {
		slln* N = L->head;
		L->head = L->head->nxt;
		if(L->head == NULL) {
			L->tail = NULL;
		}
		delnode(N);
		L->size --;
	}
}

void print(sll* L) {
	if (L) {
		slln* N;
		printf("[");
		if (L->head){
			for(N = L->head; N != L->tail; N = N->nxt) {
				N->print(N->data);
				printf(", ");
			}
			N->print(N->data);
		}
		printf("]\n");
	}
	#if DEBUG
		printf("printed list at %p\n", L);
	#endif
}

const struct sll SLL = {
    .new = new,
	.append = append,
	.prepend = prepend,
	.empty = empty,
	.del = del,
	.delhead = delhead,
	.print = print
};

const struct slln SLLN = {
	.new = newn
};
#endif
