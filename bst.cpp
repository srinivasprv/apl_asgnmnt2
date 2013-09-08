#include "dict.h"

bst::bst()
{
	head = NULL;
	//head->parent = NULL;
}

bst_node* bst::search_tree(int value)
{
	bst_node *pres;

	pres = head;
	while((pres!=NULL)&&(!(pres->element==(value))))
	{
		if(pres->element>(value))
			pres = pres->left;
		else
			pres = pres->right;
	}
	return pres;
}

bst_node* bst::find_minimum(bst_node *node)
{
	bst_node *pres;
	pres = node;

	while((pres->left!=NULL))
		pres = pres->left;
	return pres;
}

bst_node* bst::find_maximum(bst_node *node)
{
	bst_node *pres;
	pres = node;

	while((pres->right!=NULL))
		pres = pres->right;
	return pres;
}

bst_node* bst::find_successor(bst_node *node)
{
	bst_node *pres,*parent;
	pres = node;

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

void bst::insert(int value)
{//if(head!=NULL)printf("insert %d\n",head->element);
	bst_node *pres,*prev,*new_leaf;
	
	new_leaf = new bst_node();
	new_leaf->element=value;
	new_leaf->left = NULL;
	new_leaf->right = NULL;//head->new_leaf

//	printf("insert2");
	prev = NULL;
	pres = head;
	while(pres != NULL)//if->while
	{
		prev = pres;//pres=prev
		if((pres->element)>(value))//paranthesis
			pres = pres->left;
		else
			pres = pres->right;
	}
	new_leaf->parent = prev;
	if(prev == NULL)
		head = new_leaf;
	else if((prev->element)>(value))//paranthesis)
		prev->left = new_leaf;
	else
		prev->right = new_leaf;
}

void bst::replace(bst_node *a,bst_node *b)
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

void bst::delete_element(int value)
{
	bst_node *pres,*prev,*child_node,*delete_node;
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

bool bst::search(int value)
{
	return (search_tree(value) != NULL);
}

void bst::display()
{
	pio(head);
	printf("\n");
}

void bst::pio( bst_node *ptr )//print inorder from a node
{
	if( ptr->left != NULL )
	pio( ptr->left );
	printf("%d ,",ptr->element);
	if( ptr->right != NULL )
	pio( ptr->right );
}

void bst::clear()
{
	
}
