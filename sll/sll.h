#ifndef _SLL_H_
#define	_SLL_H_
#include <stdlib.h>
#include <stdio.h>

typedef struct sllnode{
	size_t type;
	void* data;
	void (*delet)(void);
	void (*print)(void);
	struct sllnode *nxt;
}slln;

typedef struct {
	size_t size;
	slln *head;
	slln *tail;
}sll;

sll* sll_New();

slln* sll_NewNode(size_t type, void* data, void (*delet)(void*, void (*print)(void*);

#endif
