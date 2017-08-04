#ifndef _SLL_H_
#define	_SLL_H_
#include <stdlib.h>
#include <stdio.h>

typedef struct slln_ {
	size_t type;
	void* data;
	void (*del)(void*);
	void (*print)(void*);
	struct slln_ *nxt;
}slln_;

typedef struct sll_{
	size_t size;
	slln_ *head;
	slln_ *tail;
	slln_ *curr;
}sll_;

struct sll {
    void (*func) (void);
};

extern const struct sll sll;
#endif
