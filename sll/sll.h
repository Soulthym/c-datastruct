#ifndef _SLL_H_
#define	_SLL_H_
#include <stdlib.h>
#include <stdio.h>

typedef struct sllnode{
	size_t type;
	void* data;
	void (*delet)(void*);
	void (*print)(void*);
	struct sllnode *nxt;
}slln;

typedef struct sll{
	size_t size;
	slln *head;
	slln *tail;
	slln* (*append)(struct sll* L, slln* node);
	slln* (*delet)(struct sll* L);
	void (*print)(struct sll*);
}sll;

sll* sll_New();

slln* sll_NewNode(size_t type, void* data, void (*delet)(void*), void (*print)(void*));

slln* sll_Append(sll* L, slln* node);

void sll_Print(sll* L);

#endif
