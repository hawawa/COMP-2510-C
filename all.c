/*all*/
#include <stdio.h>

/*check macro*/
#define CHECK(PRED) printf("%s...%s\n", (PRED) ? "passed" : "FAILED", #PRED)

/*type*//*toupper, tolower, isalpha, isdigit*/
#include <ctype.h>

/*String*/
#include <string.h>

/*Macro variable*/
#define LINESIZE 1024

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
	

int main(void) {	
	main22();

	return 0;
}
/*for main16*/
/*
int main(int argc, char*argv[]) {
	main16(argc, argv);
	
	return 0;
}
*/

/*feb5*/



/*feb5_2*/