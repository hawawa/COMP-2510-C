#include <stdio.h>
void one_a(){
	int i;
	for (i = 2; i< 10; i++){
		putchar('*');
		if(i > 7 ){
			break;
		}
	}
}

void one_b(){
	int i;
	for(i = 1; i <10; i++){
		if(i % 3 != 1){
		 continue;
		}
		putchar('*');
	}
}

void one_c(){
	int i, j;
	for(i = 1; i < 8; i += 2){
		for(j = 0; j <= i; j++){
			putchar('*');
		}
	}
}

void two_a(){
	int n = 7;
	while(n > 2){
		printf("%d ", n--);
	}
}

void two_b(){
	int n = 7;
	while(n-- > 2){
		printf("%d ", n);
	}
}

void two_c(){
	int n = 7;
	while(--n > 2){
		printf("%d ", n);
	}
}

void two_d(){
	int a = 1, b = 1, c = -1;
	c = --a && b++;
	printf("%d %d %d", a, b, c);
}

void two_e(){
	int a = 0, b = 0, c = -1;
	c = a++ || ++b;
	printf("%d %d %d", a, b, c);
}

void two_f(){
	int m = 11, n = 22;
	int *p = &m;
	int *q = &n;
	q = p;
	m++; n--;
	printf("%d %d", *p, *q);
}

void two_g(){
	int m = 11, n = 22;
	int *p = &m;
	int *q = &n;
	*q = *p;
	m++; n--;
	printf("%d %d", *p, *q);
}

void two_h(){
	int m = 11, n = 22;
	int *p = &m;
	int *q = &n;
	*q = *p + 1;
	*p = *q + 1;
	printf("%d %d", m, n);
}

void two_i(){
	int m = 11, n = 22;
	int *p = &m, *q = &n;
	int **pp = &p, **qq = &q;
	int *r = *pp;
	*pp = *qq;
	*qq = r;
	printf("%d %d", *p, *q);
}

void two_j(){
	int a = 11, b = 22, c = 33;
	int *p = &a, *q = &b, *r = &c;
	int **pp = &p, **qq = &q, **rr = &r;
	**pp = **qq;
	*pp = *qq;
	**pp = **rr;
	printf("%d %d %d", a, b, c);
}

void two_k(){
	char a[32] = "0123456789";
	sscanf("hi", "%s", &a[4]);
	printf("%s", &a[2]);
}

void two_l(){
	int m = 4, n = 5, p = 6;
	m = sscanf("  12hello  34", "%d %d", &n, &p);
	printf("%d/%d/%d", m, n, p);
}

void two_m(){
	int m = 4, n = 5, p = 6;
	m = sscanf("12-34.50", "%d %d", &n, &p);
	printf("%d/%d/%d", m, n, p);
}

void two_n(){
	int m = 4, n = 5;
	float f = 1.0;
	m = sscanf("34.50", "%f %d", &f, &n);
	printf("%d/%.2f/%d", m, f, n);
}

void three(){
	unsigned short m = 0x89ab, n = 0xef67;
	unsigned short a = ~m | n;
	printf("m & n\n");
	printf("%x\n", m & n);
	printf("~m | n\n");
	printf("%x\n", (~m | n));
	printf("m ^ n\n");
	printf("%x\n", m ^ n);
		printf("%x\n", a);
}



int main(void){
	printf("\none_a\n");
	one_a();
	printf("\none_b\n");
	one_b();
	printf("\none_c\n");
	one_c();
	printf("\ntwo_a\n");
	two_a();
	printf("\ntwo_b\n");
	two_b();
	printf("\ntwo_c\n");
	two_c();
	printf("\ntwo_d\n");
	two_d();
	printf("\ntwo_e\n");
	two_e();
	printf("\ntwo_f\n");
	two_f();
	printf("\ntwo_g\n");
	two_g();
	printf("\ntwo_h\n");
	two_h();
	printf("\ntwo_i\n");
	two_i();
	printf("\ntwo_j\n");
	two_j();
	printf("\ntwo_k\n");
	two_k();
	printf("\ntwo_l\n");
	two_l();
	printf("\ntwo_m\n");
	two_m();
	printf("\ntwo_n\n");
	two_n();
	printf("\nthree\n");
	three();
	
	return 0;
}