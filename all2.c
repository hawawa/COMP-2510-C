/*all*/
#include <stdio.h>

/*check macro*/
#define CHECK(PRED) printf("%s...%s\n", (PRED) ? "passed" : "FAILED", #PRED)

/*type*//*toupper, tolower, isalpha, isdigit*/
#include <ctype.h>

/*String*//*strcpy*/
#include <string.h>

/*data space*//*malloc, calloc, realloc, free*/
#include <stdlib.h>

/*Macro variable*/
#define LINESIZE 1024

#define IDSIZE 10
#define NAMESIZE 20
#define NLINES 1000
#define BLOCK 2

/*type lab1*/
int main1() {
	char c = 'a';
	short s = 100;
	int i = 100;
	long l = 100;
	float f = 100.0;
	double d = 100.0;
	long double ld = 100.0;
	short a[10]; /* array of 10 shorts */
	int b[10]; /* array of 10 ints */
	
	/* literals */
	printf("size of 'a' is %lu\n", (unsigned long) sizeof('a'));
	printf("size of 100 is %lu\n", (unsigned long) sizeof(100));
	printf("size of 100.0 is %lu\n\n", (unsigned long) sizeof(100.0));
	
	/* char */
	printf("size of char is %lu\n", (unsigned long) sizeof(char));
	printf("size of c is %lu\n", (unsigned long) sizeof(c));
	
	/* short */
	printf("size of short is %lu\n", (unsigned long) sizeof(short));
	printf("size of s is %lu\n", (unsigned long) sizeof(s));
	
	/* int */
	printf("size of int is %lu\n", (unsigned long) sizeof(int));
	printf("size of i is %lu\n", (unsigned long) sizeof(i));
	
	/* long */
	printf("size of long is %lu\n", (unsigned long) sizeof(long));
	printf("size of l is %lu\n", (unsigned long) sizeof(l));
	
	/* float */
	printf("size of float is %lu\n", (unsigned long) sizeof(float));
	printf("size of f is %lu\n", (unsigned long) sizeof(f));
	
	/* double */
	printf("size of double is %lu\n", (unsigned long) sizeof(double));
	printf("size of d is %lu\n", (unsigned long) sizeof(d));
	
	/* long double */
	printf("size of long double is %lu\n", (unsigned long) sizeof(long double));
	printf("size of ld is %lu\n", (unsigned long) sizeof(ld));
	
	/* arrays */
	printf("size of a is %lu\n", (unsigned long) sizeof(a));
	printf("size of b is %lu\n", (unsigned long) sizeof(b));
	
	/* test */
	/*printf("size of null is %lu\n", (unsigned long) sizeof());*/
	
	return 0;
}





/*array*/
int arr_sum( const int a[], size_t n){
	int sum=0;
	size_t i;
	for(i = 0; i<n ; i++)
		sum += a[i];
	return sum;
}

int arr_max(const int a[], size_t n){ /*precondition: n>0*/
	int max = a[0];
	size_t i;
	for (i = 0; i<n; i++)
		if(a[i]>max)
			max = a[i];
	return max;
}


size_t arr_find(const int a[], size_t n, int x){
	size_t i;
	for(i=0; i<n; i++)
		if (a[i]==x)
			return i;
	return -1;
}


void arr_triple(int a[], size_t n){
	size_t i;
	for(i = 0; i<n ; i++)
		a[i] *=3;
}


int main2(void){
	int a[]={3,2,7,6,8};
	printf("%d\n", arr_sum(a,5));

	/*int a[]={3,2,7,6,8};*/
	printf("%d\n", arr_sum(a,5)==26);

	/*int a[] = {3,2,7,6,8};*/
	CHECK(arr_sum(a,5)==26);

	return 0;
}





/*array2 lab2*/
int arr_min(const int a[], size_t n){
	int min = a[0];
	size_t i;
	for (i = 0; i < n; i++){
		if(a[i] < min){
			min = a[i];
		}
	}
	return min;
}

size_t arr_count(const int a[], size_t n, int x){
	size_t count = 0;
	size_t i;
	for (i = 0; i < n; i++){
		if(a[i] == x){
			count++;
		}
	}
	return count;
}

int arr_all_even(const int a[], size_t n){
	size_t i;
	for (i = 0; i < n; i++){
		if(a[i] % 2 == 1){
			return 0;
		}
	}
	return 1;
}

size_t arr_find_last(const int a[], size_t n, int x){
	size_t i;
	size_t index = -1;
	for(i = 0; i < n; i++){
		if (a[i]==x){
			index = i;
		}
	}
	return index;
}


int main3(){
	int a[] = {2, 5, 0, 4, -1, 7};
	int b[] = {-2, 5, 1, 5, -1, 10};
	int c[] = {-2, 2, 4, 4, 2, 4, -6, 10};
	
	CHECK(arr_min(a,6) == -1);
	CHECK(arr_count(a,6,7) == 1);
	CHECK(arr_all_even(a,6) == 0);
	CHECK(arr_find_last(a,6,5) == 1);
	
	CHECK(arr_min(b,6) == -2);
	CHECK(arr_count(b,6,5) == 2);
	CHECK(arr_all_even(b,6) == 0);
	CHECK(arr_find_last(b,6,-1) == 4);
	
	CHECK(arr_min(c,8) == -6);
	CHECK(arr_count(c,8,4) == 3);
	CHECK(arr_all_even(c,8) == 1);
	CHECK(arr_find_last(c,8,5) == (size_t) -1);
	printf("%d\n", (int) arr_find_last(c,8,5));
	
	return 0;
}





/*string*/
/*The length of 'hello' is 5, not include the null character*/
size_t str_length(const char s[]){
	size_t i;
	for (i = 0; s[i] != '\0'; i++){
		;
	}
	return i;
}

void str_lowercase(char s[]){
	size_t i;
	for (i = 0; s[i] != '\0'; i++){
		s[i]=tolower(s[i]);
	}
}

int str_has_digit(const char s[]){
	size_t i;
	for (i = 0; s[i] != '\0'; i++){
		if(isdigit(s[i])){
			return 1;
		}
	}
	return 0;
}

/*1:00000001  -1:11111111*/
size_t str_find(const char s[], int c){
	size_t i;
	for (i = 0; s[i] != '\0'; i++){
		if(s[i] == c){
			return i;
		}
	}
	return -1;
}

void str_copy(char dest[], const char src[]){
	size_t i;
	for (i = 0; dest[i] != '\0'; i++){
		dest[i] = src[i];
	}
	dest[i] = '\0';
}


int main4(){
	char s[] = "HELLO";
	str_lowercase(s);
	printf("%s", s);
	return 0;
}





/*echo*/
int main5(int argc, char * argv[]){
	char s1[] = "helloworld";
	char s2[] = "hello";
	size_t n = 10;
	char dest[10];
	int i;
	
	printf("%d\n",(int) strlen(s1));
	printf("%d\n",(int) sizeof(s1));
	printf("%d\n",(int) strcmp(s1,s2));
	strncpy(dest, s1, 10);
	dest[n - 1] = '\0';
	printf("%s\n",dest);
	
	for (i = 0; i < argc; i++){
		printf("%s\n", argv[i]);
	}
	
	return 0;
}





/*echo2*/
int main6(int args, char * argv[]){
	int i;
	for(i = 1; i < args; i ++){
		if( i == args -1){
			printf("%s\n", argv[i]);
		} else {
			printf("%s ", argv[i]);
		}
	}
	
	for(i = 1; i < args; i ++){
		printf(i == args -1 ? "%s\n" :"%s ", argv[i]);
	}

	for(i = 1; i < args; i ++){
		printf("%s%c", argv[i], i == args -1 ? '\n': ' ');
	}
	return 0;
}





/*printf fprintf sprintf*/
int main7(){
	int n = 1, m = 2;
	char s[64];
	long x = -123456;
	
	printf("The sum of %d and %d is %d\n", n, m, n + m);
	
	fprintf(stderr, "unable to allocate memory!\n");
	
	sprintf(s, "%ld", x);  /*-123456*/
	printf("%s\n", s);
	return 0;
}





/*echo3*/
int main8() {
    int c;

	printf("Enter a String:\n");
	while( (c = getchar()) != EOF ){
		putchar(c);
		if(c == '\n'){
			printf("\nEnter a String:\n");
		}

	}

   return(0);
}





/*line counter*/
int main9(){
	int c;
	size_t nlines = 0;
	while((c = getchar())!= EOF){
		if(c == '\n'){
			nlines++;
		}
	
	}
	printf("%d\n", (int)nlines);
	return 0;
}





/*string lab3*/
size_t str_replace_all(char s[], int oldc, int newc){
	size_t i;
	size_t counter = 0;
	for (i = 0; s[i] != '\0'; i++){
		if(s[i] == oldc){
			s[i] = newc;
			counter++;
		}
	}
	return counter;
}

int str_replace_last(char s[], int oldc, int newc){
	size_t i;
	size_t index = -1;
	for(i = 0; s[i] != '\0'; i++){
		if (s[i] == oldc){
			index = i;
		}
	}
	if(index != (size_t)-1){
		s[index] = newc;
		return 1;
	}		
	return 0;
}

int str_all_digits(const char s[]){
	size_t i;
	for(i = 0; s[i] != '\0'; i++){
		if(!isdigit(s[i])){
			return 0;
		}
	}
	return 1;
}

int str_equal(const char s[], const char t[]){
	size_t i;
	for(i = 0; s[i] != '\0'; i++){
		if(s[i] != t[i]){
			return 0;
		}
	}
	return t[i] == '\0';
}

int main10(){
	/*declare 1*/
	char s1_1[] = "hello world";
	char s1_2[] = "hello world";
	char s1_3[] = "hello world";
	char s1_4[] = "hello world";
	char t1[] = "hello world";

	/*declare 2*/
	char s2_1[] = "12345678";
	char s2_2[] = "12345678";
	char s2_3[] = "12345678";
	char s2_4[] = "12345678";
	char t2[] = "1234567890";
	
	/*declare 3*/
	char s3_1[] = "123hello world";
	char s3_2[] = "123hello world";
	char s3_3[] = "123hello world";
	char s3_4[] = "123hello world";
	char t3[] = "123hello ";
	
	/*check 1*/
	CHECK(str_replace_all(s1_1,'l','x') == 3);
	CHECK(strcmp(s1_1, "hexxo worxd") ==0);
	CHECK(str_replace_last(s1_2,'l','x') == 1);
	CHECK(strcmp(s1_2, "hello worxd") ==0);
	CHECK(str_all_digits(s1_3) == 0);
	CHECK(str_equal(s1_4, t1) == 1);
	
	/*check 2*/
	CHECK(str_replace_all(s2_1,'5','x') == 1);
	CHECK(strcmp(s2_1, "1234x678") ==0);
	CHECK(str_replace_last(s2_2,'5','x') == 1);
	CHECK(strcmp(s2_2, "1234x678") ==0);
	CHECK(str_all_digits(s2_3) == 1);
	CHECK(str_equal(s2_4, t2) == 0);
	
	/*check 3*/
	CHECK(str_replace_all(s3_1,'a','x') == 0);
	CHECK(strcmp(s3_1, "123hello world") ==0);
	CHECK(str_replace_last(s3_2,'a','x') == 0);
	CHECK(strcmp(s3_2, "123hello world") ==0);
	CHECK(str_all_digits(s3_3) == 0);
	CHECK(str_equal(s3_4, t3) == 0);
	
	
	return 0;
}





/*bit counter*/
int main11(){
	int c;
	size_t nbytes = 0;
	while((c = getchar())!= EOF){
		nbytes++;
	}
	printf("%d\n", (int)nbytes);
	return 0;
}





/*Enter from keyboard and change*/
void printline(char s[]){
	
	char header[] = "All uppercase:";
	size_t i;
	printf("%s\n", header);
	for(i=0; i <10;i++){
		if(s[i] == '\n'){
			putchar('$');
		} else {
			putchar(toupper(s[i]));
		}
		
	}
	printf("%s\n","");

}

int main12(void){
	char line[10];
	while(1){
		printf("Enter a line:");
		if(!fgets(line, 10, stdin)){
			break;
		}
		printline(line);
	}	
	return 0;
}





/*Sum*/
int main13(void){
	char line[LINESIZE];
	int n, sum = 0;
	while(1){
		printf("Enter an integer: ");
		if(!fgets(line, LINESIZE, stdin)){
			clearerr(stdin);
			break;
		}
		if(sscanf(line, "%d", &n) == 1){
			sum += n;
		}
		
	}
	printf("\nThe sum is: %d\n", sum);
	return 0;
	
}





/*String functions lab4*/
void squeeze_spaces(void){
	int c;
	int old = 'A';
	while((c = getchar())!= EOF){	
		if(old != ' ' || (c != '\t' && c != ' ')){
			if(c=='\t'){
				putchar(' ');
				old = ' ';
			} else {
				putchar(c);
				old = c;
			}
		}		
	}
}

void format_words(void){
	int c;
	int old = ' ';
	while((c = getchar())!= EOF){
		if(isspace(old) || old == '"'){
			putchar(toupper(c));
		} else {
			putchar(tolower(c));
		}
		old = c;
	}
	
}


int main14(void){
	printf("%s\n","squeeze_spaces function:");
	squeeze_spaces();
	
	printf("%s\n","format_words function:");
	format_words();
	
	return 0;
}





/*Read integers from a file and sum.*/
int main15(){
	FILE *fp;
	int n, sum = 0;
	
	if( (fp = fopen("data.txt", "r") ) == 0) {
		perror("fopen");
		return 1;	
	}
		
	/*read an int from file*/
	while (fscanf(fp, "%d", &n) ==1){
		sum += n;
	}
	
	printf("%d\n", sum);
	
	return 0;
}
	


	

/*copy from a file to another file */	
int main16(int argc, char*argv[]){
	FILE *ifp, *ofp; /*in and out, * is repeated*/
	int c;
	
	if(argc !=3){
		fprintf(stderr, "usage: %s {source file} {destination file}\n", argv[0]);
		return 1;
	}
	
	if((ifp = fopen(argv[1], "rb")) ==0 ) {
		perror("fopen");
		return 2;
	}
	
	if((ofp = fopen(argv[2], "wb")) ==0 ) {
		perror("fopen");
		return 3;
	}
	
	while( (c=fgetc(ifp))!=EOF ){
		fputc(c, ofp);
		
	}
	
	if( fclose(ifp)!=0) {
		perror("fclose");
		return 4;
	}
	
	if( fclose(ofp)!=0) {
		perror("fclose");
		return 5;
	}
	
	return 0;
}	
	

	
	

/*Check palindrome*/	
int is_palindrome(const char s[]){
	size_t i, j;
	for(i = 0, j = strlen(s); i < j ;i++,j--){/*j can't be strlen(s)-1 because it could be -1 if it is empty string*/
		if(s[i] != s[j-1]){ /*j-1 because the \n charater*/
			return 0;
		}
	}
	return 1;
	
}

int main17(void){
	char word[LINESIZE];
	size_t i;

	while(1) {
		printf("Enter a word:\n");
		if( !fgets(word, LINESIZE, stdin) ){
			clearerr(stdin);
			break;
		}
		
		for( i = 0 ; word[i] != '\0'; i++){
			if(word[i]=='\n'){
				word[i]='\0';
			}
		}
		
		if(is_palindrome(word)==1){
			printf("The word is palindrome.\n");
		} else {
			printf("The word is NOT palindrome.\n");
		}

		
	}
	
	return 0;
}
	

	
	
	
/*fgets lab5*/
int get_word(const char prompt[], char word[], size_t n){
	while(1){
		char line[LINESIZE];
		char w[LINESIZE];
		size_t i;
		
		printf("%s\n",prompt);

		if(!fgets(line, LINESIZE, stdin)){
			clearerr(stdin);
			return 0;
		}
		
		for(i = 0; line[i] != '\0'; i++){
			if(!isspace(line[i])){
				break;
			}
			return 0;
		}
		
		
		if(sscanf(line, "%s", w) ==1){
			if(strlen(w) < n){
				strcpy(word,w);
				return 1;
			}	
		}
		
	}

}


int main18(void){
	size_t n = 10;
	char word[10]="\n";
	char prompt[] = "Please enter a word less than 10 charcaters";

	if(get_word(prompt, word ,n)){
		printf("%s\n", word);
	}
	
	return 0;	
}

int get_int(const char prompt[], int min, int max){
	
	while(1){
		char line[LINESIZE];
		int n = 0;
		size_t i;
		
		printf("%s\n",prompt);

		if(!fgets(line, LINESIZE, stdin)){
			clearerr(stdin);
			return -1;
		}
		
		for(i = 0; line[i] != '\0'; i++){
			if(!isspace(line[i])){
				break;
			}
			return -1;
		}
			
		
		if(sscanf(line, "%d", &n) != EOF){
			if(n >= min && n <= max){
				return n;
			}	
		}
		
	}
	
}



int main19(void){
	char prompt[] = "Please enter a integer";
	int min = 1;
	int max = 10;
	
	printf("%d\n", get_int(prompt, min ,max));

	return 0;	
}





/*pointer test 1*/
int main20(void){
	int n = 123;
	int m = 321;
	int *p = &n;
	int **pp = &p;
	int ***ppp = &pp;
	
	char *pointer = "hello";
	char a [] ="world";
	
	printf("%d\n", n);
	printf("%d\n", *p);
	printf("%d\n", **pp);
	printf("%d\n", ***ppp);
	
	printf("%d\n", (int) sizeof(pointer));
	a[0] = pointer[0];
	printf("%s\n", a);
	
	*p = 456;
	printf("*p = 456;\n");
	printf("%d\n", n);
	printf("%d\n", *p);
	
	**pp = 789;
	printf("**pp = 789;\n");
	printf("%d\n", n);
	printf("%d\n", *p);
	printf("%d\n", **pp);
	
	p = &m;
	printf("p = &m;\n");
	printf("%d\n", n);
	printf("%d\n", *p);
	printf("%d\n", **pp);
	
	return 0;
	
}





/*Swap*/
void triple (int *n){
	*n *= 3;
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
	
}

void swappointer(int **a, int **b){
	int *temp = *a;
	*a = *b;
	*b = temp;
	
}

int main21(void){
	
	int number = 10;
	int a = 5;
	int b = 11;
	
	int *p1;
	int *p2;
	
	p1 = &a;
	p2 = &b;
	
	triple(&number);
	printf("%d\n", number);	
	
	swap(&a, &b);
	printf("%d\n", a);
	printf("%d\n", b);

	swappointer(&p1, &p2);
	printf("%d\n", *p1);
	printf("%d\n", *p2);

	
	return 0;
}





/*Pointer function Lab6*/
void min_max(const int a[], size_t n, int *pmin, int *pmax){
	size_t i;
	*pmin = a[0];
	*pmax = a[0];
	for(i = 0; i < n; i++){
		if(a[i] < *pmin){
			*pmin = a[i];
		}
		if(a[i] > *pmax){
			*pmax = a[i];
		}	
	}
	
}

size_t num_digits(unsigned long n){
	size_t i = 1;
	for(; n/10 != 0;i++){
		n /= 10;
	}
	
	return i;
}

int is_reversible(unsigned long n){
	unsigned long rn = 0;
	unsigned long temp_n = n;
	
	for(; temp_n != 0;){
		rn = rn * 10 + temp_n % 10;
		temp_n /= 10;	
	}
	
	return n == rn;
}


int main22(void){
	int array[] = {5,4,6,7,8,3};
	int array_max;
	int array_min;
	min_max(array, 6, &array_min, &array_max);
	
	printf("max:%d min:%d\n", array_max, array_min);
	
	printf("num_digits(0):%d\n", (int) num_digits(0));
	printf("num_digits(32768):%d\n", (int) num_digits(32768));
	
	printf("is_reversible(327686723):%d\n", is_reversible(327686723));
	printf("is_reversible(3):%d\n", is_reversible(3));
	printf("is_reversible(12):%d\n", is_reversible(12));
	
	
	return 0;
}





/*
*********************
Final
*********************
*/
/*structure*/
struct id_score{        /*define a new type*/
	char id[IDSIZE];      /*id and score are the members of structure*/
	int score;
};

void print_id_score(const struct id_score *p){
	printf("%s: %d\n", p->id, p->score);
	
}

int read_id_score(struct id_score *p){
	return scanf("%s%d", p->id, &p->score) == 2;
}


int main23(void){
	struct id_score x, a[121], *p;
	/*analogy: int x, a[10], *P;*/
	
	/*Accessing the members of a structure:*/
	x.score = 85;
	
	/*x.id = "a12345678";  wrong, because id is an array  */
	strcpy(x.id, "a12345678");
	
	a[0].score = 76;
	strcpy(a[10].id, "a66666666");
	
	a[1] = x;
	
	p = &x;
	
	printf("%d\n", (*p).score);   /*    *p.score is equivalent to *(p.score)   */
	
	/*abbreviation: a->b is the same as (*a).b */
	
	printf("%s: %d\n", p->id, p->score);
	
	return 0;
}





/*nested structures*/
struct name_old{
	char first[NAMESIZE];
	char last[NAMESIZE];
};

struct record_old{
	char id[IDSIZE];
	struct name_old name;
	int score;
};


int main24(void){
	struct record_old r;
	strcpy(r.id, "a1234567");
	strcpy(r.name.first, "homer");
	strcpy(r.name.last, "simpson");
	r.score = 35;
	printf("%s : %s %s : %d\n", r.id, r.name.first, r.name.last, r.score);
	return 0;
}





/*Structures read and print lab7*/
typedef struct {
	char last[NAMESIZE];
	char first[NAMESIZE];
} name;

typedef struct {
	char id[IDSIZE];
	name name;
	int score;
} record;

int read_record(record *prec){
	char line[LINESIZE];
	size_t i;
	char id[LINESIZE];
	char last[LINESIZE];
	char first[LINESIZE]; 
	int score;
	int id_counter = 0;

	printf("Enter here:(id first last score)\n");
	if( !fgets(line, LINESIZE, stdin) ){
		clearerr(stdin);
		return 0;
	}
	
	if(sscanf(line, "%s %s %s %d", id, first, last, &score) < 4){
		return -1;
	}
	
	/*id check*/
	if(id[0] != 'a'){
		return -1;
	}
	
	for(i = 0; id[i] != '\0'; i++){
		id_counter++;
	}
	if(id_counter != IDSIZE - 1){
		return -1;
	}
	
	/*save to prec*/
	strcpy((*prec).id, id);
		
	if(strlen(first) >= NAMESIZE){
		return -1;
	}
	
	if(strlen(last) >= NAMESIZE){
		return -1;
	}
		
	for(i = 0; first[i] != '\0'; i++){
		(*prec).name.first[i] = tolower(first[i]);
	}
	(*prec).name.first[i] = '\0';
	

	for(i = 0; last[i] != '\0'; i++){
		(*prec).name.last[i] = tolower(last[i]);
	}
	(*prec).name.last[i] = '\0';

	
	(*prec).score = score;

	return 1;
}

void print_record(const record *prec){
	printf("%s : %s, %s : %d\n",(*prec).id,(*prec).name.last,(*prec).name.first,(*prec).score);
}


int main25(void){
	record x;
	printf("%d\n",read_record(&x));
	print_record(&x);
	
	return 0;
}





/*Dynamic memory*/
int main26(void){
	int n = 123;
	int *p;
	void *q;


	p = &n;
	q = &n;
	p = q;
	q = p;
	
	/*
	*q = 234; invalid, cannot dereference a void * 
	*/
	*(int*)q = 234;
	*p = 345;
	printf("%d\n",n);
	printf("%d\n",*p);
	printf("%d\n",*(int*)q);
		
	return 0;
}

int main27(void){
	int *p;
	size_t i;
	
	p = malloc(100 * sizeof(int) ); 
	if(p==0){
		fprintf(stderr, "unable to allocate memory\n");
		exit(1);
	}
	for (i=0;i<100;i++){
		p[i]=5*i;
		printf("%d\n",p[i]);
	}
	free(p); /*deallocates the block of memory*/
	return 0;
}





/*storing lines of text*/
/*1. using a 2-dimentional array of chars*/
int main28(void){
	char line[NLINES][LINESIZE];
	size_t i, j;
	for(i = 0; i < NLINES; i++){
		if(!fgets(line[i],LINESIZE,stdin)){
			break;
		}
	}
	
	for(j=0; j<i; j++){
		printf("%s",line[j]);
	}
		
	return 0;
}


/*2. fixed number of lines but each line is malloc(strlen(buffer) +1)
an array of char array pointers
*/
int main29(void){
	char *lines[NLINES];
	char buffer[LINESIZE];
	size_t i, j;
	for(i = 0; i < NLINES; i++){
		if(!fgets(buffer,LINESIZE,stdin)){
			break;
		}
		lines[i] = malloc(strlen(buffer) +1);
		if(lines[i]==0){
			fprintf(stderr,"unable to allocate memory");
			break;
		}
		strcpy(lines[i],buffer);
	}
	
	for(j=0; j<i; j++){
		printf("%s",lines[j]);
	}
	
	for(j=0; j<i; j++){
		free(lines[j]);
	}
	
	
	return 0;
}


/*each line is dynamically allocated and being allocated when it's used*/
int main30(void){
	char **lines = 0;
	/*char **lines = malloc(0);*/
	char buffer[LINESIZE];
	size_t i, nalloc, nused;
	nalloc = 0;
	nused = 0;
	
	while(fgets(buffer,LINESIZE,stdin)){
		if(nalloc == nused){
			char **temp = realloc(lines, (nalloc + BLOCK)*sizeof(char *));
			if(temp ==0){
				fprintf(stderr,"unable to allocate memory");
				break;
			}
			lines = temp;
			nalloc += BLOCK;
		}
		lines[nused] = malloc(strlen(buffer) +1);
		if(lines[nused]==0){
			fprintf(stderr,"unable to allocate memory");
			break;
		}
		strcpy(lines[nused++],buffer);
	}
	
	for(i=0; i<nused; i++){
		printf("%s",lines[i]);
	}
	
	for(i=0; i<nused; i++){
		free(lines[i]);
	}
	free(lines);
	
	
	return 0;
}





/*list lab8*/
typedef struct record_list{
	record *data;
	size_t nalloc;
	size_t nused;
} record_list;

/*
typedef struct record_list record_list;
struct record_list{
	record *data;
	size_t nalloc;
	size_t nused;
};
*/

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
		record *temp = realloc((*plist).data, ((*plist).nalloc + BLOCK) * sizeof(record));
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


int main31(void){
	size_t i;
	record_list myList;
	
	record myRecord =
		{"A12345678",{"a","B"},50};

	list_init(&myList);
	list_insert(&myList, &myRecord);
	list_insert(&myList, &myRecord);
	list_insert(&myList, &myRecord);
	list_insert(&myList, &myRecord);
	
	for(i = 0;i<myList.nused;i++ ){
		print_record(myList.data+i);
	}	
	list_destroy(&myList);
	
	return 0;
}





/*qsort*/
typedef struct{
	char id[IDSIZE];
	int score;
} grade;

int cmp_int( const void *p, const void *q){
	const int *pp = p;
	const int *qq = q;
	return *pp - *qq;
}	

int cmp_grade(const void *p, const void *q){
	const grade *pp = p;
	const grade *qq = q;
	int n = qq->score - pp->score;
	if(n!=0){
		return n;
	}
	return strcmp(pp->id, qq->id);
	
}


int main32(void) {
	int n;
    int values[] = { 88, 56, 100, 2, 25 };
	
	printf("Before sorting the list is: \n");
	for( n = 0 ; n < 5; n++ ) {
		printf("%d ", values[n]);
	}

	qsort(values, 5, sizeof(int), cmp_int);

	printf("\nAfter sorting the list is: \n");
	for( n = 0 ; n < 5; n++ ) {   
		printf("%d ", values[n]);
	}
  
	return 0;
}





/*sort string*/
int cmp_string(const void *p, const void *q){
	char * const *pp = p;
	char * const *qq = q;
	return strcmp(*pp,*qq);
}


int main33(void){
	char *a[]={"hello","goodbye","world"};
	size_t i;
	qsort(a,sizeof(a)/sizeof(a[0]),sizeof(a[0]),cmp_string);
	for(i = 0; i < 3; i++){
		printf("%s\n",a[i]);
	}
	
	return 0;
}





/*Sorting lab9*/
int strcmp_name(const name p, const name q){
	const name *pp = &p;
	const name *qq = &q;
	int n = strcmp(pp->last, qq->last);
	if(n!=0){
		return n;
	}
	return strcmp(pp->first, qq->first);
}

int cmp_score_desc_id_asc(const void *p, const void *q){
	const record *pp = p;
	const record *qq = q;
	int n = qq->score - pp->score;
	if(n!=0){
		return n;
	}
	return strcmp(pp->id, qq->id);
}

int cmp_name_asc_id_desc(const void *p, const void *q){
	const record *pp = p;
	const record *qq = q;
	int n = strcmp_name(pp->name, qq->name);
	if(n!=0){
		return n;
	}
	return strcmp(qq->id, pp->id);
}

int cmp_score_desc_name_asc_id_asc(const void *p, const void *q){
	const record *pp = p;
	const record *qq = q;
	int n = qq->score - pp->score;
	int m;
	if(n!=0){
		return n;
	}
	m = strcmp_name(pp->name, qq->name);
	if(m!=0){
		return m;
	}
	return strcmp(pp->id, qq->id);
}


void sort_score_desc_id_asc(record a[], size_t n){
	qsort(a,n,sizeof(a[0]),cmp_score_desc_id_asc);
}

void sort_name_asc_id_desc(record a[], size_t n){
	qsort(a,n,sizeof(a[0]),cmp_name_asc_id_desc);
}
 
void sort_score_desc_name_asc_id_asc(record a[], size_t n){
	qsort(a,n,sizeof(a[0]),cmp_score_desc_name_asc_id_asc);
}


int main34(int argc, char *argv[]){
	record a[100];
	record x;
	size_t counter = 0;
	size_t i;
	if(argc == 1){
		return 0;
	}
	while(read_record(&x)==1 && counter < 100){
		a[counter]=x;
		counter++;
	}
	if(counter!=0){
		if(strcmp(argv[1],"s-i+")==0){
			sort_score_desc_id_asc(a, counter);
		} else if(strcmp(argv[1],"n+i-")==0){
			sort_name_asc_id_desc(a, counter);
		} else if(strcmp(argv[1],"s-n+i+")==0){
			sort_score_desc_name_asc_id_asc(a, counter);
		} else {
			return 0;
		}
		
		for(i = 0; i<counter; i++){
			print_record(&a[i]);
		}
	}
	
	return 0;
}





/*use pointer to go through a string array*/
size_t str_length_pointer(const char *s){
	const char *p;
	for(p=s;*p!='\0'; p++){
		;
	}
	return p-s;
}

void str_uppercase_pointer(char *s){
	char *p;
	for(p=s;*p!='\0'; p++){
		*p=toupper(*p);
	}
}

char * str_find_pointer(const char *s, int c){
	const char *p;
	for(p=s;*p!='\0'; p++){
		if(*p == c){
			return (char *)p;
		}
	}
	return 0;
}


int main35(void){
	char s[] = "hello";
	printf("The size of s: %d\n", (int) str_length_pointer(s));
	str_uppercase_pointer(s);
	printf("s: %s\n", s);
	printf("L: %s\n", str_find_pointer(s, 'L'));
	return 0;
}





/*use pointer to go through an integer array*/
/*maximum of an integer array*/
int arr_max_pointer(const int *a, size_t n){/*precondition n>0 */
	const int *p;
	int max = *a;
	for(p=a; p<a+n;p++){
		if(*p>max){
			max = *p;
		}
	}
	return max;
}
/*looking for an integer in an integer array*/
int * arr_find_pointer(const int *a, size_t n, int x){
	const int *p;
	for(p=a; p<a+n;p++){
		if(*p==x){
			return (int *) p;
		}
	}
	return 0;
}

/*doubling all the integer in an integer array */
void arr_double_pointer(int *a, size_t n){
	int *p;
	for(p=a; p<a+n;p++){
		*p *=2;
	}
}

/*sperating an each element of an integer array*/
void arr_map_pointer(  const int *a, size_t n, void(*f)(int)  ){
	const int *p;
	for(p=a;p<a+n;p++){
		f(*p);
	}
}
void print_pointer(int x){
	printf("%d\n",x);
}

void arr_apply_pointer(  int *a, size_t n, void(*f)(int *)  ){
	int *p;
	for(p=a;p<a+n;p++){
		f(p);
	}
}
void triple_pointer(int *p){
	*p *=3;
}


int main36(void){
	int a[]={3,2,7,6,8};
	printf("Max: %d\n",arr_max_pointer(a, 5));
	printf("Find 7: %d\n", *arr_find_pointer(a, 5, 7));
	
	printf("Before:\n");
	arr_map_pointer(a,5,print_pointer);
	
	printf("After double:\n");
	arr_double_pointer(a, 5);
	arr_map_pointer(a,5,print_pointer);
	
	printf("After triple:\n");
	arr_apply_pointer(a,5,triple_pointer);
	arr_map_pointer(a,5,print_pointer);

	return 0;
}





/*use pointer go through array lab11*/
int *arr_first_max(const int *a, size_t n){
	const int *p;
	const int *max = a;
	for(p=a; p<a+n;p++){
		if(*p>*max){
			max = p;
		}
	}
	return (int *)max;
}

int *arr_last_max(const int *a, size_t n){
	const int *p;
	const int *max = a;
	for(p=a; p<a+n;p++){
		if(*p>=*max){
			max = p;
		}
	}
	return (int *)max;
}

size_t str_replace_all_lab11(char *s, int oldc, int newc){
	char *p;
	size_t counter=0;
	for(p=s; *p!='\0';p++){
		if(*p==oldc){
			*p = newc;
			counter++;
		}
	}
	return counter;
}

char *str_find_last(const char *s, int c){
	const char *p;
	const char *find = 0;
	for(p=s; *p!='\0';p++){
		if(*p==c){
			find=p;
		}
	}
	return (char *)find;
}


int main37(void){
	int array[]={5,7,9,11,2,3,11};
	char string[]="Hello world";
	int *p = array;
	char *q;
	
	printf("%d\n",(int)(p-array));
	p=arr_first_max(array, 7);
	printf("%d\n",*p);
	printf("%d\n",(int)(p-array));
	p=arr_last_max(array, 7);
	printf("%d\n",*p);
	printf("%d\n",(int)(p-array));




	CHECK(str_replace_all_lab11(string, 'o', 'x') == 2);
	printf("%s\n",string);
	
	q=str_find_last(string, 'l');
	printf("%c\n",*q);
	printf("%d\n",(int)(q-string));
	
	return 0;
}





/*node*/
typedef struct node node;
struct node{
	int data;
	node *next;
};

void print_node(node * list){
	node * p;
	for(p=list;p!=0;p=p->next){
		printf("%d\n",p->data);
	}
}

node * find_node(node * list, int data){
	node * p;
	for(p=list;p!=0;p=p->next){
		if(p->data == data){
			return p;
		}
	}
	return 0;
}

/*after free(p), p->next is gone*/
void destroy_node(node * list){
	node * p;
	node * temp;
	for(p=list;p!=0;p=temp){
		temp=p->next;
		free(p);
	}
}

/*insert in the beginning*/
/*because in c everything pass value, we need to use a double pointer*/
int insert_head_node(node **phead, int data){
	node * newnode=malloc(sizeof(node));
	if(newnode==0){
		return 0;
	}
	newnode->data=data;
	newnode->next=*phead;
	*phead=newnode;
	return 1;
}

/*insert in order*/
/*
single pointer is not working here because it's too late to get the right pointer
we have to use a double pointer because we can get the next data
	node ** tracer;
	tracer = &(*tracer)->next;
	(*tracer)->data;
	(*tracer)->next;

*/
int insert_byorder_node(node **phead, int data){
	node ** tracer;
	node * newnode=malloc(sizeof(node));
	if(newnode==0){
		return 0;
	}
	for(tracer = phead;*tracer!=0;tracer = &(*tracer)->next){
		if(  (*tracer)->data < data  ){
			break;
		}
	}
	newnode->data=data;
	newnode->next=*tracer;
	*tracer=newnode;
	return 1;
}

int delete_node(node **phead, int data){
	node ** tracer;
	for(tracer = phead;*tracer!=0;tracer = &(*tracer)->next){
		if(  (*tracer)->data == data  ){
			node *p = *tracer;
			*tracer=p->next;
			free(p);
			return 1;	
		}
	}
	return 0;	
}
/*
int delete_node(node **phead, int data){
	node ** tracer;
	for(tracer = phead;*tracer!=0;tracer = &(*tracer)->next){
		if(  (*tracer)->data == data  ){
			break;
		}
	}
	if(*tracer!=0){
		node *p = *tracer;
		*tracer=p->next;
		free(p);
		return 1;	
	}	
	return 0;	
}
*/

void reverse_print_node(node * list){
	if(list !=0){
		reverse_print_node(list->next);
		printf("%d\n", list->data);
	}
}

void print_node2(node * list){
	if(list !=0){
		printf("%d\n", list->data);
		print_node2(list->next);
	}
}

int main38(void){
	node * head1 = 0;
	node * head2 = 0;
	
	printf("Insert head:\n");
	insert_head_node(&head1, 5);
	insert_head_node(&head1, 2);
	insert_head_node(&head1, 7);
	insert_head_node(&head1, 3);	
	insert_head_node(&head1, 10);
	print_node(head1);
	
	printf("data 7: %d\n", find_node(head1, 7) -> data);
	
	printf("Delete 5:\n");
	delete_node(&head1, 5);
	print_node(head1);
	
	printf("Delete 10:\n");
	delete_node(&head1, 10);
	print_node(head1);
	
	printf("Delete 2:\n");
	delete_node(&head1, 2);
	print_node(head1);	
	
	printf("Insert by order:\n");
	insert_byorder_node(&head2, 5);
	insert_byorder_node(&head2, 2);
	insert_byorder_node(&head2, 7);
	insert_byorder_node(&head2, 3);	
	insert_byorder_node(&head2, 10);
	print_node2(head2);
	
	printf("Print reverse:\n");
	reverse_print_node(head2);
	
	destroy_node(head1);
	destroy_node(head2);
	
	
	return 0;
}





/*binary tree*/
typedef struct binary_node binary_node;
struct binary_node{
	int data;
	binary_node *left, *right;
};

void preorder_print(binary_node * tree){
	if(tree != 0){
		printf("%d\n", tree->data);
		preorder_print(tree->left);
		preorder_print(tree->right);
	}
}

void inorder_print(binary_node * tree){
	if(tree != 0){
		inorder_print(tree->left);
		printf("%d\n", tree->data);
		inorder_print(tree->right);
	}
}

void postorder_print(binary_node * tree){
	if(tree != 0){
		postorder_print(tree->left);
		postorder_print(tree->right);
		printf("%d\n", tree->data);
	}
}

/*destroy*/
void destroy_binary_node(binary_node * tree){
	if(tree != 0){
		destroy_binary_node(tree->left);
		destroy_binary_node(tree->right);
		free(tree);
	}
}

/*find a node*/
binary_node * find_binary_node(binary_node *tree, int data){
	if(tree ==0 || tree->data == data){
		return tree;
	}
	
	return (data < tree->data) ? find_binary_node(tree->left, data) : find_binary_node(tree->left, data);
}

/*maximum value*/
int max_binary_node(binary_node *tree){ /*tree != 0*/
	while(tree->right != 0){
		tree = tree->right;
	}
	return tree -> data;
}

int rmax_binary_node(binary_node *tree){
	if(tree->right == 0){
		return tree -> data; 
	}
	return rmax_binary_node(tree->right);
}

/*insert*/
int insert_binary_node(binary_node **ptree, int data){
	binary_node * p;
	binary_node * newnode=malloc(sizeof(binary_node));
	if(newnode==0){
		return 0;
	}
	newnode->data = data;
	newnode->left = 0;
	newnode->right = 0;
	for(p = *ptree; p!=0;){
		if(p->data>data){
			if(p->left == 0){
				p->left = newnode;
			}
			p = p->left;
		} else if(p->data<data){
			if(p->right == 0){
				p->right = newnode;
			}
			p = p->right;
		} else{
			return 1;
		}
	}
	*ptree = newnode;
	return 1;
}


int main39(void){
	binary_node * root = 0;
	/*
	binary_node * find;
	*/
	insert_binary_node(&root, 12);
	insert_binary_node(&root, 5);
	insert_binary_node(&root, 7);
	insert_binary_node(&root, 6);
	insert_binary_node(&root, 15);
	insert_binary_node(&root, 13);
	insert_binary_node(&root, 7);
	
	printf("preorder_print:\n");
	preorder_print(root);
	printf("inorder_print:\n");
	inorder_print(root);
	printf("postorder_print:\n");
	postorder_print(root);
	
	/*
	find = find_binary_node(root, 7);
	printf("7: %d\n", find->data);
	*/
	printf("max: %d\n", max_binary_node(root));
	printf("rmax: %d\n", rmax_binary_node(root));
	
	destroy_binary_node(root);
	
	return 0;
}





/*record list*/
typedef struct node_recode node_recode;
struct node_recode {
	record data;
	node_recode *next;
};

typedef node_recode *record_list_new;

void list_init_new(record_list_new *plist){
	*plist = 0;
}

void list_destroy_new(record_list_new *plist){
	node_recode *p;
	node_recode *q;
	for(p=*plist;p!=0;p=q){
		q=p->next;
		free(p);
	}
	*plist = 0;
}

int list_insert_new(record_list_new *plist, const record *prec){
	node_recode *newnode = malloc(sizeof(node_recode));
	if(newnode == 0){
		return 0;
	}
	newnode->data = *prec;
	newnode->next = *plist;
	*plist = newnode;
	return 1;
}

int read_record_new(FILE *fp, record *prec){
	char line[LINESIZE];
	size_t i;
	char id[LINESIZE];
	char last[LINESIZE];
	char first[LINESIZE]; 
	int score;
	int id_counter = 0;
	
	if( !fgets(line, LINESIZE, fp) ){
		clearerr(stdin);
		return 0;
	}
	
	if(sscanf(line, "%s %s %s %d", id, first, last, &score) < 4){
		return -1;
	}

	/*id check*/
	if(id[0] != 'a'){
		return -1;
	}
	
	for(i = 0; id[i] != '\0'; i++){
		id_counter++;
	}
	if(id_counter != IDSIZE - 1){
		return -1;
	}
	
	/*save to prec*/
	strcpy((*prec).id, id);
		
	if(strlen(first) >= NAMESIZE){
		return -1;
	}
	
	if(strlen(last) >= NAMESIZE){
		return -1;
	}
		
	for(i = 0; first[i] != '\0'; i++){
		(*prec).name.first[i] = tolower(first[i]);
	}
	(*prec).name.first[i] = '\0';
	

	for(i = 0; last[i] != '\0'; i++){
		(*prec).name.last[i] = tolower(last[i]);
	}
	(*prec).name.last[i] = '\0';

	
	(*prec).score = score;

	return 1;
}





int main40(int argc, char*argv[]){
	FILE *fp;
	int m;
	record_list_new list;
	record r;
	
	list_init_new(&list);
	
	if(argc != 2){
		fprintf(stderr, "usage: %s {source file}\n", argv[0]);
		return 1;
	}
	
	if((fp = fopen(argv[1], "rb")) ==0 ) {
		perror("fopen");
		return 2;
	}
	
	while((m = read_record_new(fp, &r)) != 0) {
		if (m == 1) {
			if (!list_insert_new(&list, &r)) {
				break;
			}
		}
	}

	/*print*/
	if(list !=0){
		node_recode *p = list;
		while(p!=0){
			printf("%s : %s, %s : %d\n", (*p).data.id, (*p).data.name.last,(*p).data.name.first,(*p).data.score);
			p = p->next;
		}
	}

	
	
	if( fclose(fp)!=0) {
		perror("fclose");
		return 4;
	}
	
	return 0;
}



/*
int main(void) {	
	main39();

	return 0;
}
*/
/*for main16*/
/*
int main(int argc, char *argv[]) {
	main16(argc, argv);
	
	return 0;
}
*/
/*for main34*/
/*
int main(int argc, char *argv[]) {
	main34(argc, argv);
	
	return 0;
}
*/
/*for main40*/
int main(int argc, char *argv[]) {
	main40(argc, argv);
	
	return 0;
}
