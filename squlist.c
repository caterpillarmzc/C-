#include "Seqlist.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
void SeqListInit(SeqList*ps,int capacity){
	//ps期望是变量的地址,则不为空
	assert(ps != NULL);
	if (ps != NULL);
	
	ps->array = malloc(sizeof(int)*capacity);
	assert(ps->array != NULL);
	ps->size = 0;
	ps->capacity = capacity;
}

void SeqListDestroy(SeqList *ps){
	//释放array的空间
	free(ps->array);
}