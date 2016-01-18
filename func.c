#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "func.h"

extern node *nil;
extern node *root;

node * initialization(node *parent,int key)
{
	node *leaf;

	leaf = malloc(sizeof(node));
	leaf->colour = RED;
	leaf->key = key;
	leaf->p = parent;
	leaf->left = nil;
	leaf->rigth = nil;

	return leaf;
}

node * add_to_tree(node *z, int key)
{
	node *parent = nil, *buffer = nil;
	if (!z)
	{
		z = initialization(nil, key);
		z->colour = BLACK;
		return z;
	}
	buffer = z;
	while(buffer != nil)
	{
		parent = buffer;
		if((parent->key) < key)
			buffer = parent->rigth;
		else if((parent->key) > key)
			buffer = parent->left;
		else
			return root;
	}
	if(parent->key < key)
	{
		parent->rigth = initialization(parent, key);
		return fixing(root, parent->rigth);
	}
	else
	{
		parent->left = initialization(parent, key);
		return fixing(root, parent->left);
	}
}
void rigth_rotate(node *z)
{
	node *leaf = z->left;

	z->left = leaf->rigth;
	if(leaf->rigth != nil)
		leaf->rigth->p = z;

	leaf->p = z->p;

	if(z->p == nil)
		root = leaf;
	else if(z->p->left == z)
			z->p->left = leaf;
		else
			z->p->rigth = leaf;
	z->p = leaf;
	leaf->rigth = z;
}
void left_rotate(node *z)
{
	node *leaf = z->rigth;

	z->rigth = leaf->left;
	if(leaf->left != nil)
		leaf->left->p = z;

	leaf->p = z->p;

	if(z->p == nil)
		root = leaf;
	else if(z->p->left == z)
			z->p->left = leaf;
		else
			z->p->rigth = leaf;
	z->p = leaf;
	leaf->left = z;
}
node * fixing(node *z, node *leaf)
{
	node *uncle = NULL;
	while((leaf != root) && (leaf->p->colour == RED))
	{
		if((leaf->p->p->left) == leaf->p)
		{
			uncle = (leaf->p->p->rigth);
			if(uncle->colour == RED)
			{
				uncle->colour = BLACK;
				uncle->p->colour = RED;
				leaf->p->colour = BLACK;
				leaf = leaf->p->p;
			}
			else
			{
				if(leaf == leaf->p->rigth)
					left_rotate(leaf->p);
				leaf->p->colour = BLACK;
				leaf->p->p->colour = RED;
				rigth_rotate(leaf->p->p);
			}
		}
		else if((leaf->p->p->rigth) == leaf->p)
		{
			uncle = (leaf->p->p->left);
			if(uncle->colour == RED)
			{
				uncle->colour = BLACK;
				uncle->p->colour = RED;
				leaf->p->colour = BLACK;
				leaf = leaf->p->p;

			}
			else
			{ 
				if(leaf == leaf->p->left)
					rigth_rotate(leaf->p);
				leaf->p->colour = BLACK;
				leaf->p->p->colour = RED;
				left_rotate(leaf->p->p);
			}
		}
	}
	root->colour = BLACK;
	return root;
}
void print_all(node *p)
{
	if((p->left) != nil) 
		print_all(p->left);
	if (p->colour == RED)
		printf("%d RED\n",p->key);
	else
		printf("%d BLACK\n", p->key);
	if((p->rigth) != nil)
		print_all(p->rigth);
}
void interface(void)
{
	printf("\n");
	printf("1 - Insert new element to AVL-tree\n");
	printf("2 - Print all elements\n");
	printf("3 - Exit from programm\n");
	printf("4 - Find element\n");
	printf("5 - Delete element\n");
}
void delete_all(node *p)
{
	if((p->left) != nil ) 
		delete_all(p->left);
	if((p->rigth) != nil )
		delete_all(p->rigth);
	free(p);
}
node * find_element(node *p, int data)
{
	extern int key_position;
	if(!p) return NULL;
	if(p->key == data)
		return p;
	if(p->key > data)
		find_element(p->left, data);
	else
		find_element(p->rigth, data);
}