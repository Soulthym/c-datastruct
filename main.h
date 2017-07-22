#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include "libs.h"

typedef struct cpx {
	double re;
	double im;
	struct cpx* (*Set)  (struct cpx*, double, double);
	struct cpx* (*SetRe)(struct cpx*, double);
	struct cpx* (*SetIm)(struct cpx*, double);
	void (*Del)  (void*);
	void (*Print)(void*);
}cpx;

#endif
