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
};
class node
{
	public:
		int element;
		node *parent,*left,*right;
};
class bst :public dict
{
	public:
		bst();
		node *head;
		node* search_tree(int value);
		node* find_minimum(node *value);
		node* find_maximum(node *value);
		node* find_successor(node *value);
		void replace(node *a,node *b);
		bool search(int value);
		void insert(int value);
		void delete_element(int value);
		void clear();
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
};
#endif
