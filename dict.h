#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
class dict
{
	public:
		virtual bool search(int value)=0;
		virtual void insert(int value)=0;
		virtual void delete_element(int value)=0;
		virtual void clear()=0;
		virtual void display()=0;
};
class bst_node
{
	public:
		int element;
		bst_node *parent,*left,*right;
};
class bst :public dict
{
	public:
		bst();
		bst_node *head;
		bst_node* search_tree(int value);
		void pio(bst_node *ptr);
		bst_node* find_minimum(bst_node *value);
		bst_node* find_maximum(bst_node *value);
		bst_node* find_successor(bst_node *value);
		void replace(bst_node *a,bst_node *b);
		bool search(int value);
		void insert(int value);
		void delete_element(int value);
		void clear();
		void display();
};
class node
{
	public:
		int element;
		bool color,orig_color;
		node *parent,*left,*right;
};
class rbt :public dict
{
	public:
		rbt();
		node *head;
		node *tail;
		node* search_tree(int value);
		node* find_minimum(node *value);
		void pio(node *ptr);
		node* find_maximum(node *value);
		node* find_successor(node *value);
		node* left_rotation(node *mynode);
		node* right_rotation(node *mynode);
		void insert_adjust(node *node);
		void delete_adjust(node *node);
		void replace(node *a,node *b);
		bool search(int value);
		void insert(int value);
		void delete_element(int value);
		void clear();
		void display();
};
#endif
