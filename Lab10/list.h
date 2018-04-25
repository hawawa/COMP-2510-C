#ifndef LIST_H
#define LIST_H
#include "record.h"

typedef struct record_list record_list;
struct record_list{
	record *data;
	size_t nalloc;
	size_t nused;
};

void list_init(record_list *plist);
int list_insert(record_list *plist, const record *prec);
void list_destroy(record_list *plist);

#endif