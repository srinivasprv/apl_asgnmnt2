#include "dict.h"

void print_usage()
{
	printf("Usage: <exe> [-bst] <i/p file> <o/p file>\nor\n");
	printf("Usage: <exe> [-bst] <i/p file> <o/p file> [-t <time_input_file> <time_output_file>]\n");
}
int main(int argc,char *argv[])
{
	FILE *fp=NULL;
	int r;
	char input_file[2000],output_file[2000];
	char time_input_file[2000],time_output_file[2000];
	bool bst_flag;
	int read_element;
	dict<int> *obj;

	//usage
	if((argc!=3)||(argc!=4)||(argc !=6)||(argc!=7))
	{
		print_usage();
		exit(0);
	}

	if(argc == 3)
	{
		bst_flag = 0;
		strcpy(input_file,argv[1]);
		strcpy(output_file,argv[2]);
	}
	else if(argc == 4)
	{
		if(strcpy(argv[1],"-bst"))
		{
			print_usage();
			exit(0);
		}
		bst_flag = 1;
		strcpy(input_file,argv[2]);
		strcpy(output_file,argv[3]);
	}
	if(argc == 6)
	{
		if(strcpy(argv[1],"-t"))
		{
			print_usage();
			exit(0);
		}
		bst_flag = 0;
		strcpy(input_file,argv[1]);
		strcpy(output_file,argv[2]);
		strcpy(time_input_file,argv[4]);
		strcpy(time_output_file,argv[5]);
	}
	if(argc == 7)
	{
		if(strcpy(argv[1],"-bst"))
		{
			print_usage();
			exit(0);
		}
		if(strcpy(argv[4],"-t"))
		{
			print_usage();
			exit(0);
		}
		bst_flag = 1;
		strcpy(input_file,argv[2]);
		strcpy(output_file,argv[3]);
		strcpy(time_input_file,argv[5]);
		strcpy(time_output_file,argv[6]);
	}

	if(bst_flag)
		obj = new bst<int>();
//		obj = new bst();
	else
		obj = new rbt<int>();
	//open input file if file exists
	if((fp= fopen(input_file,"r"))==NULL)
	{
		printf("cannot open file %s\nExiting..\n",input_file);
		exit(0);
	}

	// if read is successful read the elements and insert in tree
	while((r=fscanf(fp,"%d ",&read_element))!=EOF)
		obj->insert(read_element);
	fclose(fp);

	return 0;
}
