#include "dict.h"

template <class type1>
bst<type1>::bst()
{
	head = NULL;
	head->parent = NULL;
}

template <class type1>
typename bst<type1>::node* bst<type1>::search_tree(type1 value)
{
	node *pres;

	pres = head;
	while((pres!=NULL)&&(!(pres->operator==(value))))
	{
		if(pres->operator>(value))
			pres = pres->left;
		else
			pres = pres->right;
	}
	return pres;
}

template <class type1>
typename bst<type1>::node* bst<type1>::find_minimum(node *mynode)
{
	node *pres;
	pres = mynode;

	while((pres->left!=NULL))
		pres = pres->left;
	return pres;
}

template <class type1>
typename bst<type1>::node* bst<type1>::find_maximum(node *mynode)
{
	node *pres;
	pres = mynode;

	while((pres->right!=NULL))
		pres = pres->right;
	return pres;
}

template <class type1>
typename bst<type1>::node* bst<type1>::find_successor(node *mynode)
{
	node *pres,*parent;
	pres = mynode;

	if(pres->right !=NULL)
		return find_minimum(pres->right);

	parent = pres;
	while((pres!=NULL)&&(pres == parent->right))
	{
		pres = parent;
		parent = parent->parent;
	}
	return parent;
}

template <class type1>
void bst<type1>::insert(type1 value)
{
	node *pres,*prev,*new_leaf;
	
	new_leaf = new node();
	new_leaf->operator=(value);
	new_leaf->left = head->right = NULL;

	prev = NULL;
	pres = head;
	if(pres != NULL)
	{
		pres = prev;
		if(pres->operator>(value))
			pres = pres->left;
		else
			pres = pres->right;
	}
	new_leaf->parent = prev;
	if(prev == NULL)
		head = new_leaf;
	else if(prev->operator>(value))
		prev->left = new_leaf;
	else
		prev->right = new_leaf;
}

template <class type1>
void bst<type1>::replace(node *a,node *b)
{
	if(a->parent==NULL)
		head = b;
	else if(a == a->parent->left)
		a->parent->left = b;
	else
		a->parent->right = b;
	if(b!=NULL)
		b->parent = a->parent;
}

template <class type1>
void bst<type1>::delete_element(type1 value)
{
	node *pres,*prev,*child_node,*delete_node;
	bool flag;

	delete_node = search_tree(value);
	if(delete_node == NULL)
	{
		printf("element does not exist in tree\n");
		return;
	}

	if(delete_node->left==NULL)
		replace(delete_node,delete_node->right);
	else if(delete_node->right==NULL)
		replace(delete_node,delete_node->left);
	else
	{
		pres = find_minimum(delete_node->right);
		if(pres->parent == NULL)
		{
			replace(pres,pres->right);
			pres->right = delete_node->right;
			pres->right->parent = pres;
		}
		replace(delete_node,pres);
		pres->left = delete_node->left;
		pres->left->parent = pres;
	}
	delete delete_node;
}
