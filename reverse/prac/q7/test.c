#include <stdio.h>


/*
	Search and Delete an node in the linked list.
*/



struct List {
	int value;
	struct List* next;
};



int sub_401060(List* Memory, int arg_4){
	if(Memory == 0) return 0;

	*prev = NULL;
	*curr = *Memory
	while(curr->value != arg_4){		//cmp [eax], ecx
		*prev = curr*;
		curr = curr->next;
		if(curr==NULL) return 0;	
	}

	if(prev==NULL){
		free(curr)
	}
	else{
		prev->next = curr->next;
		free(curr);
	}
}


