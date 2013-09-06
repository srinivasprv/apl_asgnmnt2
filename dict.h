#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
template <class type1>
class dict
{
	public:
		virtual bool search(type1 value)=0;
		virtual void insert(type1 value)=0;
		virtual void delete_element(type1 value)=0;
		virtual void clear()=0;
		void operator=(int a2);
		void operator=(float a2);
		void operator=(double a2);
		void operator=(char a2);
		void operator=(char* a2);
		bool operator==(int a2);
		bool operator==(float a2);
		bool operator==(double a2);
		bool operator==(char a2);
		bool operator==(char *a2);
		bool operator<(int a2);
		bool operator<(float a2);
		bool operator<(double a2);
		bool operator<(char a2);
		bool operator<(char *a2);
		bool operator>(int a2);
		bool operator>(float a2);
		bool operator>(double a2);
		bool operator>(char a2);
		bool operator>(char *a2);
};
template <class type1>
class bst :public dict<type1>
{
	private:
		struct node
		{
			type1 element;
			node *parent,*left,*right;
		};
	public:
		bst();
		node *head;
		node* search_tree(type1 value);
		node* find_minimum(node *value);
		node* find_maximum(node *value);
		node* find_successor(node *value);
		void replace(node *a,node *b);
		bool search(type1 value);
		void insert(type1 value);
		void delete_element(type1 value);
		void clear();
};
template <class type1>
class rbt :public dict<type1>
{
	private:
		struct node
		{
			type1 element;
			bool color,orig_color;
			node *parent,*left,*right;
		};
	public:
		rbt();
		node *head;
		node *tail;
		node* search_tree(type1 value);
		node* find_minimum(node *value);
		node* find_maximum(node *value);
		node* find_successor(node *value);
		node* left_rotation(node *mynode);
		node* right_rotation(node *mynode);
		void insert_adjust(node *mynode);
		void delete_adjust(node *mynode);
		void replace(node *a,node *b);
		bool search(type1 value);
		void insert(type1 value);
		void delete_element(type1 value);
		void clear();
};
#endif
