#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#define BLOCK 2


void list_init(record_list *plist){
	(*plist).data = 0;
	(*plist).nalloc = 0;
	(*plist).nused = 0;
}


void list_destroy(record_list *plist){
	free((*plist).data);
	(*plist).nalloc = 0;
	(*plist).nused = 0;

	
}

int list_insert(record_list *plist, const record *prec){
	if((*plist).nalloc == (*plist).nused){
		record *temp = realloc(plist->data, ((*plist).nalloc + BLOCK) * sizeof(record));
		if(temp == 0){
			fprintf(stderr,"unable to allocate memory");
			return 0;
		}
		
		(*plist).data = temp;
		(*plist).nalloc = ((*plist).nalloc) + BLOCK;
	}
	
	(*plist).data[(*plist).nused] = *prec;
	(*plist).nused++;
	
	return 1;
}