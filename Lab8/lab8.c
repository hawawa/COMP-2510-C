#include <stdio.h>
#include <stdlib.h>

#define IDSIZE 10
#define NAMESIZE 20
#define BLOCK 2

typedef struct {
	char last[NAMESIZE];
	char first[NAMESIZE];
} name;

typedef struct {
	char id[IDSIZE];
	name name;
	int score;
} record;

typedef struct record_list record_list;
struct record_list{
	record *data;
	size_t nalloc;
	size_t nused;
};

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




int main(void){
	
	record_list myList;
	
	record myRecord =
		{"A12345678",{"a","B"},50};

	list_init(&myList);
	list_insert(&myList, &myRecord);
	list_insert(&myList, &myRecord);
	list_insert(&myList, &myRecord);
	list_insert(&myList, &myRecord);
	list_destroy(&myList);
	
	
	return 0;
}



