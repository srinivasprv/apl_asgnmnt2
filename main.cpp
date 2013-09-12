/**
*	@file main.cpp
*	@brief main function using ADT.
*
*	@author Anil Kumar Chilli, Praveen Srinivas
*
*/
#include "dict.h"

/**
*	Prints error message if input format is incorrect
*/
void print_usage()
{
	printf("Usage: <exe> [-bst] <populatefile> <searchfile>\nor\n");
	printf("Usage: <exe> [-bst] <populatefile> <searchfile> [-t <time_input_file> <time_output_file>]\n");
}

/**
*	Main function
*/
int main(int argc,char *argv[])
{
	FILE *fp=NULL;
	int r;
	char populate_file[2000],searchfile[2000];///< stores file names
	char time_input_file[2000],time_output_file[2000];///< stores time file names
	bool bst_flag;///< distinguishes rbt, bst
//	int read_element;
	int switchoption,element;
	dict *obj;///< pointer to dictionary object

	/*TO DO: check for '-' to distinguish file names.
		duplicates should not be inserted.--done 
		time file insert modifications append mode etc. -- done
	*/
	///usage
	if((argc!=3)&&(argc!=4)&&(argc !=6)&&(argc!=7))
	{
		print_usage();
		exit(0);
	}

	if(argc == 3)
	{
		bst_flag = 0;
		strcpy(populate_file,argv[1]);
		strcpy(searchfile,argv[2]);
	}
	else if(argc == 4)
	{	
		if(strcmp(argv[1],"-bst") != 0)//strcpy->strcmp
		{
			print_usage();
			exit(0);
		}
		bst_flag = 1;
		strcpy(populate_file,argv[2]);
		strcpy(searchfile,argv[3]);
	}
	if(argc == 6)
	{
		if(strcmp(argv[1],"-t"))
		{
			print_usage();
			exit(0);
		}
		bst_flag = 0;
		strcpy(populate_file,argv[1]);
		strcpy(searchfile,argv[2]);
		strcpy(time_input_file,argv[4]);
		strcpy(time_output_file,argv[5]);
	}
	if(argc == 7)
	{
		if(strcmp(argv[1],"-bst"))
		{
			print_usage();
			exit(0);
		}
	
		if(strcmp(argv[4],"-t"))
		{
			print_usage();
			exit(0);
		}
		bst_flag = 1;
		strcpy(populate_file,argv[2]);
		strcpy(searchfile,argv[3]);
		strcpy(time_input_file,argv[5]);
		strcpy(time_output_file,argv[6]);
	}

	///if bst flag is set create BST object
	if(bst_flag)
		obj = new bst();
	///else create RBT object
	else
		obj = new rbt();

	obj->PopulateDictionary(populate_file,time_input_file);
	obj->LocateInDictionary(searchfile,time_output_file);
/*	if((fp= fopen(populate_file,"r"))==NULL)
	{
		printf("cannot open file %s\nExiting..\n",populate_file);
		exit(0);
	}

	// if read is successful read the elements and insert in tree
	while((r=fscanf(fp,"%d ",&read_element))!=EOF){
		obj->insert(read_element);//obj->display();printf("\n");
	}
	fclose(fp);
*/
//	obj->display();

//	if(obj->search(19)) printf("found\n");

	///infinite loop breaks when input is 0
	while(1)
	{
		///Print options
		printf("Following Operations can be done on dictionary\n");
		printf("press 1 Insert an element in to Dictionary\n");
		printf("press 2 Delete an element in to Dictionary\n");
		printf("press 3 Search an element in to Dictionary\n");
		printf("press 4 Display all elements in to Dictionary\n");
		printf("press 5 Clear the Dictionary\n");
		printf("press 0 for Exiting the menu \n");
		printf("please enter the corresponding option for that operation:");
		///read option 
		scanf("%d",&switchoption);
		///switch and do corresponding peration
		switch(switchoption)
		{
			case 0:	exit(0);
				break;
		
			case 1:	printf("please enter the element to insert:");
				scanf("%d",&element);
				obj->insert(element);
				break;
			case 2:	printf("please enter the element to delete:");
				scanf("%d",&element);
				obj->delete_element(element);
				break;
			case 3:	printf("please enter the element to search:");
				scanf("%d",&element);
				if(obj->search(element)) printf("Found element %d\n",element);
				else printf("Element %d does not exist\n",element);
				break;
			case 4:	printf("Elements in Dictionary are:\n");
				obj->display();
				break;
			case 5:	printf("Clearing all the elements in Dictionary\n");
				obj->clear();
				break;
			default:printf("Please Enter the right choice in menu:\n");
				break;
		}
		printf("\n");
	}
/*	int del = 0;
	scanf("%d",&del);
	obj->delete_element(del);
	obj->display();*/

	return 0;
}
