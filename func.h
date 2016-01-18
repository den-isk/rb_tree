#ifndef FUNC_H
#define FUNC_H
#define RED 1
#define BLACK 0

struct node {
		int key;
		int colour;

		struct node *p;
		struct node *left;
		struct node *rigth;
};
typedef struct node node;


node * initialization(node *, int);
node * add_to_tree(node *, int);
void rigth_rotate(node *);
void left_rotate(node *);
node * fixing(node *, node *);
void interface(void);
node * find_element(node *, int);
void delete_all(node *);
void print_all(node *);
#endif