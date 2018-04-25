#include <stdio.h>
#include <stdlib.h>

void one_a(){
	int a = 0, b = 0, c = -1;
	c = a++ || ++b;
	printf("%d %d %d", a, b, c);
}

void one_b(){
	int a = 1, b = 1, c = -1;
	c = --a && b++;
	printf("%d %d %d", a, b, c);
}

void one_c(){
	int n = 3;
	int *p = &n;
	while (++*p < 8)
		printf("%d ", *p);
}

void one_d(){
	int a[] = { 5, 3, 1};
	int *p = &a[1];
	printf("%d ", *p--);
	printf("%d", *p);
}

void one_e(){
	int a[] = { 5, 3, 1};
	int *p = &a[1];
	printf("%d ", --*p);
	printf("%d", *p);
}

void one_f(){
	int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int *p = a + 1;
	while (*p++ >5)
		printf("%d ", *p);
}

void one_g(){
	int a[] = { 12, 10, 8, 6, 4, 2};
	int *p = a + 1;
	while (--*p >5)
		printf("%d ", *p);
}

void one_h(){
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *p;
	for (p = a+1; p < a + 8; p +=2){
		printf("%d ", *p);
	}
}

void one_i(){
	int m = 12, n = 34;
	int *p = &m;
	int *q = &n;
	*q = --*p;
	*p = (*q)--;
	printf("%d %d", *p, *q);
}

void one_j(){
	int a[] = { 11, 22};
	int *p = a;
	int *q = a + 1;
	p++; q--;
	printf("%d %d", *p, *q);
}

void one_k(){
	char a[] = "goodbye!";
	char *p;
	for (p = a; *p !=0; p +=2)
		putchar(*p);
}

void one_l(){
	int a[]={11, 22, 33};
	int *b[3];
	int **p, **q, **r;
	b[0] = a, b[1] = a+1, b[2] = a+2;
	p = b, q = b+1, r =b+2;
	*p = *r--;
	--*q;
	printf("%d %d %d", **p, **q, **r);
}

void one_m(){
	int a[]={11, 22, 33};
	int *p = a, *q = a + 1, *r = a + 2;
	*p++ = *r--;
	*++q = *r--;
	--*p; ++*q; --*r;
	printf("%d %d %d", a[0], a[1], a[2]);
}

void one_n(){
	char a[32] = "0123456789";
	sscanf("hi", "%s", a + 4);
	printf("%s", a + 2);
}

void one_o(){
	char *argv[] = { "hello", "beautiful", "world" };
	printf( "%s", *(argv + 1) );
}

void one_p(){
	char *argv[] = { "hello", "beautiful", "world" };
	printf( "%s", *argv + 1 );
}

/*two*/
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

void destroy_binary_node(binary_node * tree){
	if(tree != 0){
		destroy_binary_node(tree->left);
		destroy_binary_node(tree->right);
		free(tree);
	}
}

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

int main(void){
	binary_node * root = 0;
	
	
	printf("\none_a\n");
	one_a();
	printf("\none_b\n");
	one_b();
	printf("\none_c\n");
	one_c();
	printf("\none_d\n");
	one_d();
	printf("\none_e\n");
	one_e();
	printf("\none_f\n");
	one_f();
	printf("\none_g\n");
	one_g();
	printf("\none_h\n");
	one_h();
	printf("\none_i\n");
	one_i();
	printf("\none_j\n");
	one_j();
	printf("\none_k\n");
	one_k();
	printf("\none_l\n");
	one_l();
	printf("\none_m\n");
	one_m();
	printf("\none_n\n");
	one_n();
	printf("\none_o\n");
	one_o();
	printf("\none_p\n");
	one_p();
	printf("\n");
	insert_binary_node(&root, 14);
	insert_binary_node(&root, 27);
	insert_binary_node(&root, 10);
	insert_binary_node(&root, 13);
	insert_binary_node(&root, 16);
	insert_binary_node(&root, 28);
	insert_binary_node(&root, 9);
	
	printf("preorder_print:\n");
	preorder_print(root);
	printf("inorder_print:\n");
	inorder_print(root);
	printf("postorder_print:\n");
	postorder_print(root);
	
	destroy_binary_node(root);

	return 0;
}