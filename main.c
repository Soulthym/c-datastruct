#include "main.h"

cpx* cpx_Set(cpx* C,double re, double im){
	C->re = re;
	C->im = im;
	return C;
}

cpx* cpx_SetRe(cpx* C,double re){
	C->re = re;
	return C;
}

cpx* cpx_SetIm(cpx* C, double im){
	C->im = im;
	return C;
}

void cpx_Del(void* C){
	free(C);
}

void cpx_Print(void* C){
	printf("%g+i%g",((cpx*)C)->re,((cpx*)C)->im);
}

cpx* cpx_New(){
	cpx* C = NULL;
	C = malloc(sizeof(cpx));
	C->Set = cpx_Set;
	C->SetRe = cpx_SetRe;
	C->SetIm = cpx_SetIm;
	C->Del = cpx_Del;
	C->Print = cpx_Print;
	C->Set(C,0,0);
	return C;
}

int main(int argc, char *argv[]) {
	cpx* C = cpx_New();
	sll* L = sll_New();
	slln* N = NULL;
	N = sll_NewNode(0,C,C->Del,C->Print);
	((cpx*)L->prepend(L,N)->data)->Set(N->data,4,2);

	C = cpx_New();
	N = sll_NewNode(0,C,C->Del,C->Print);
	((cpx*)L->prepend(L,N)->data)->Set(N->data,3,1);

	C = cpx_New();
	N = sll_NewNode(0,C,C->Del,C->Print);
	((cpx*)L->prepend(L,N)->data)->Set(N->data,5,0);

	L->print(L);
	L->del(L);
	return 0;
}
