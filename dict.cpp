/**
*       @file dict.cpp
*       @brief Contains Definitions of functions of class dict.
*
*       @author Anil Kumar Chilli, Praveen Srinivas
*
*/

#include <ctime>
#include "dict.h"

void dict::PopulateDictionary(char *ipfile)
{
	FILE *fp=NULL;
	int temp;

	if((fp=fopen(ipfile,"r"))==NULL)
	{
		printf("could not open file %s\nExiting\n",ipfile);
		exit(0);
	}

	while(fscanf(fp,"%d",&temp)!=EOF)
		insert(temp);
	fclose(fp);
}

void dict::LocateInDictionary(char *ipfile)
{
	FILE *fp=NULL;
	int temp;
	int retval;

	if((fp=fopen(ipfile,"r"))==NULL)
	{
		printf("could not open file %s\nExiting\n",ipfile);
		exit(0);
	}

	while(fscanf(fp,"%d",&temp)!=EOF)
	{
		retval = search(temp);
		printf("%d %d\n",temp,retval);
	}
	fclose(fp);
}

void dict::PopulateDictionary(char *ipfile,char* timefileinsert)
{
	FILE *fp=NULL,*sp=NULL;
	int temp;
	time_t timer=time(0);
	tm *ltm=NULL;
	int init_time,final_time;
	int no_of_elements;

	if((fp=fopen(ipfile,"r"))==NULL)
	{
		printf("could not open file %s\nExiting\n",ipfile);
		exit(0);
	}

	if((sp=fopen(timefileinsert,"w"))==NULL)
	{
		printf("could not open file %s\nExiting\n",ipfile);
		exit(0);
	}

	no_of_elements = 0;	
	while(fscanf(fp,"%d",&temp)!=EOF)
	{
		no_of_elements++;
		ltm=localtime(&timer);
		init_time = ltm->tm_hour * 60 + ltm->tm_min * 60 + ltm->tm_sec;
		insert(temp);
		final_time = ltm->tm_hour * 60 + ltm->tm_min * 60 + ltm->tm_sec;
		fprintf(sp,"%d %d\n",no_of_elements,final_time-init_time);
	}
	fclose(fp);
	fclose(sp);
}

void dict::LocateInDictionary(char *ipfile,char* timefileinsert)
{
	FILE *fp=NULL,*sp=NULL;
	int temp;
	time_t timer=time(0);
	tm *ltm=NULL;
	int init_time,final_time;
	int retval;
	int no_of_elements;

	if((fp=fopen(ipfile,"r"))==NULL)
	{
		printf("could not open file %s\nExiting\n",ipfile);
		exit(0);
	}

	if((sp=fopen(timefileinsert,"w"))==NULL)
	{
		printf("could not open file %s\nExiting\n",ipfile);
		exit(0);
	}
	
	no_of_elements=0;
	while(fscanf(fp,"%d",&temp)!=EOF)
	{
		no_of_elements++;
		ltm=localtime(&timer);
		init_time = ltm->tm_hour * 60 + ltm->tm_min * 60 + ltm->tm_sec;
		retval = search(temp);
		final_time = ltm->tm_hour * 60 + ltm->tm_min * 60 + ltm->tm_sec;
		fprintf(sp,"%d %d\n",no_of_elements,final_time-init_time);
//		printf("%d %d\n",temp,retval);
	}
	fclose(fp);
	fclose(sp);
}
