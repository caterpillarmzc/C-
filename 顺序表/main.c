#include"SeqList.h"

int main(){
#if 0
	SeqList *p = SeqList();
#endif

	SeqList seqlist;
	
	SeqListInit(&seqlist,10);
	SeqListDestroy(&seqlist);
}