#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*1*/
typedef struct record record;
struct record{
	char name[32];
	int score;
};

typedef struct node node;
struct node{
	record data;
	node *next;
};

/*1.a*/
void print(node *list){
	node *p;
	for(p=list;p!=0;p=p->next){
		printf("%s %d\n", p->data.name, p->data.score);
	}
}

/*1.b*/
node * find(node *list, const char *name){
	node *p;
	for(p=list;p!=0;p=p->next){
		if(strcmp(p->data.name,name)==0){
			return p;
		}
	}
	return 0;
}

/*1.c*/
void destroy(node *list){
	node *p, *q;
	for(p=list; p!=0; p=q){
		q=p->next;
		free(p);
	}
}

/*1.d*/
int insert(node **plist, const char *name, int score){
	node * newnode = malloc(sizeof(node));
	if(newnode == 0){
		return 0;
	}
	strcpy(newnode->data.name,name);
	newnode->data.score = score;
	newnode->next = *plist;
	*plist = newnode;
	return 1;
	
}

/*1.e*/
size_t delet_all(node **plst, const char *name){
	node **tracer;
	size_t count = 0;
	for(tracer=plst;*tracer!=0; ){
		if( strcmp( (*tracer)->data.name, name ) ==0){
			node * tmp = *tracer;
			*tracer = (*tracer)->next;
			free(tmp);
			count++;
		} else{
			tracer = &(*tracer)->next;
		}
	}
	return count;
}

/*
size_t delet_all(node **plst, const char *name){
	node **tracer;
	size_t count = 0;
	for(tracer=plst;*tracer!=0; ){
		if( strcmp( (*tracer)->data.name, name ) ==0){
			node * tmp = (*tracer)->next;
			free(*tracer);
			*tracer = tmp;
			count++;
		} else{
			tracer = &(*tracer)->next;
		}
	}
	return count;
}
*/



/*2*/
int cmp(const void *p, const void *q){
	const record *pp = p;
	const record *qq = q;
	int n;	
	if( (n = strcmp(pp->name, qq->name))!=0   ){
		return n;
	}
	return qq->score - pp->score;
}

/*3*/
typedef struct binary_node binary_node;
struct binary_node {
	int data;
	binary_node *left, *right;
};

size_t count(binary_node *tree){
	if(tree == 0){
		return 0;
	}
	return 1 + count(tree->left) + count(tree->right);
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

/*destroy*/
void destroy_binary_node(binary_node * tree){
	if(tree != 0){
		destroy_binary_node(tree->left);
		destroy_binary_node(tree->right);
		free(tree);
	}
}

/*4*/
int four_a(){
	char a [] = "hello";
	char *p = "world";
	p = a +2;
	printf("%s\n", p);	
	return 0;
}

int four_b(){
	char a [] = "hello";
	*a = *( a+ 1);
	printf("%s\n", a);	
	return 0;
}

int four_c(){
	char a [] = "hello";
	char *p = "world";
	*(p + 1) = a[0];
	printf("%s\n", p);	
	return 0;
}

/*
4a
valid, llo
4b
valid, eello
4c
invalid, can't change a const string

go right
and go left
5a
x is a pointer to an array of 2 ints
5b
x is a pointer to a function that takes a float and returns an int
5c
x is an array of two pointers to functions that take a float and return  int


*/




int main(void){
	node * list = 0;
	node * temp;
	
	
	binary_node * root = 0;
	
	insert(&list, "name1",50);
	insert(&list, "name2",65);
	insert(&list, "name3",45);
	insert(&list, "name4",23);
	print(list);
	
	temp = find(list, "name3");
	printf("name3: %d\n", temp->data.score);
	printf("delete name3:\n");
	delet_all(&list, "name3");
	print(list);

	destroy(list);
	
	insert_binary_node(&root, 14);
	insert_binary_node(&root, 27);
	insert_binary_node(&root, 10);
	insert_binary_node(&root, 13);
	insert_binary_node(&root, 16);
	insert_binary_node(&root, 28);
	insert_binary_node(&root, 9);
	printf("The number of binary tree: %d\n", (int) count(root));
	
	destroy_binary_node(root);
	
	four_a();

	four_b();

	/*
	four_c();
	*/
	return 0;
}