#ifndef IO_H
#define IO_H
#include "record.h"
#include <stdio.h>
#define LINESIZE 1024
int read_record(FILE *fp, record *prec);
void print_record(FILE *fp, const record *prec);
#endif