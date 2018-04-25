#include <stdio.h>
#include "record.h"
#include "io.h"
#include "list.h"
#include "sort.h"

int main(void) {
	FILE *fp;
	int m;
	record_list list;
	record r;
	list_init(&list);
	while((m = read_record(fp, &r)) != 0) {
		if (m == 1) {
			if (!list_insert(&list, &r)) {
				break;
			}
		}
	}
	return 0;
}