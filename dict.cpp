/**
*       @file dict.cpp
*       @brief Contains Definitions of functions of class dict.
*
*       @author Anil Kumar Chilli, Praveen Srinivas
*
*/

#include <ctime>
#include <unistd.h>
#include <sys/time.h>
#include "dict.h"

/**
*	Populates the dictionary with values read from ipfile
*	@param ipfile : input file file name
*/
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

/**
*	Searches the dictionary for values read from the input file
*	@param ipfile: Filename from which search values are read.
*/
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
//		printf("%d %d\n",temp,retval);
	}
	fclose(fp);
}

/**
*       Populates the dictionary with values read from ipfile
*	and updates the time taken to insert all
*       @param ipfile : input file file name, timefileinsert: file to which time to be inserted
*/
void dict::PopulateDictionary(char *ipfile,char* timefileinsert)
{
	FILE *fp=NULL,*sp=NULL;
	int temp;
//	time_t timer=time(0);
//	tm *ltm=NULL;
	struct timeval start,end;
	int init_time,final_time;
	int total_time;
	int no_of_elements;

	if((fp=fopen(ipfile,"r"))==NULL)
	{
		printf("could not open file %s\nExiting\n",ipfile);
		exit(0);
	}

	if((sp=fopen(timefileinsert,"a"))==NULL)
	{
		printf("could not open file %s\nExiting\n",timefileinsert);
		exit(0);
	}

	no_of_elements = 0;
	total_time = 0;
	while(fscanf(fp,"%d",&temp)!=EOF)
	{
		no_of_elements++;
//		ltm=localtime(&timer);
//		init_time = ltm->tm_hour * 60 + ltm->tm_min * 60 + ltm->tm_sec;
		gettimeofday(&start,NULL);
		insert(temp);
		gettimeofday(&end,NULL);
//		ltm=localtime(&timer);
//		final_time = ltm->tm_hour * 60 + ltm->tm_min * 60 + ltm->tm_sec;
		total_time += ((end.tv_sec-start.tv_sec)*1000000) + (end.tv_usec - start.tv_usec);
//		fprintf(sp,"%d %d\n",no_of_elements,final_time-init_time);
	}
	fprintf(sp,"%d %d\n",no_of_elements,total_time);
	fclose(fp);
	fclose(sp);
}

/**
*       Searches the dictionary for values read from the input file
*	and updates the file timefile with time taken to perform the op
*       @param ipfile: Filename from which search values are read, timefile: file to which new time has to be appended
*/
void dict::LocateInDictionary(char *ipfile,char* timefileinsert)
{
	FILE *fp=NULL,*sp=NULL;
	int temp;
//	time_t timer=time(0);
//	tm *ltm=NULL;
//	int init_time,final_time;
	struct timeval start,end;
	int total_time;
	int retval;
	int no_of_elements;

	if((fp=fopen(ipfile,"r"))==NULL)
	{
		printf("could not open file %s\nExiting\n",ipfile);
		exit(0);
	}

	if((sp=fopen(timefileinsert,"a"))==NULL)
	{
		printf("could not open file %s\nExiting\n",ipfile);
		exit(0);
	}
	
	no_of_elements=0;
	total_time = 0;
	while(fscanf(fp,"%d",&temp)!=EOF)
	{
		no_of_elements++;
//		ltm=localtime(&timer);
//		init_time = ltm->tm_hour * 60 + ltm->tm_min * 60 + ltm->tm_sec;
		gettimeofday(&start,NULL);
		retval = search(temp);
		gettimeofday(&end,NULL);
//		final_time = ltm->tm_hour * 60 + ltm->tm_min * 60 + ltm->tm_sec;
//		total_time = final_time - init_time;
		total_time += ((end.tv_sec-start.tv_sec)*1000000) + (end.tv_usec - start.tv_usec);
//		fprintf(sp,"%d %d\n",no_of_elements,final_time-init_time);
//		printf("%d %d\n",temp,retval);
	}
	fprintf(sp,"%d %d\n",no_of_elements,total_time);
	fclose(fp);
	fclose(sp);
}
