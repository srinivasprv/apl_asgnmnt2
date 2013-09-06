#include "dict.h"

template <class type1>
void dict<type1>::operator=(int a2)
{
	this.element = a2;
}
template <class type1>
void dict<type1>::operator=(float a2)
{
	this.element = a2;
}
template <class type1>
void dict<type1>::operator=(double a2)
{
	this.element = a2;
}
template <class type1>
void dict<type1>::operator=(char a2)
{
	this.element = a2;
}
template <class type1>
void dict<type1>::operator=(char* a2)
{
	strcpy(this.element,a2);
}

template <class type1>
bool dict<type1>::operator==(int a2)
{
	if(this.element == a2)
		return 1;
	else
		return 0;
}
template <class type1>
bool dict<type1>::operator==(float a2)
{
	if(this.element == a2)
		return 1;
	else
		return 0;
}
template <class type1>
bool dict<type1>::operator==(double a2)
{
	if(this.element == a2)
		return 1;
	else
		return 0;
}
template <class type1>
bool dict<type1>::operator==(char a2)
{
	if(this.element == a2)
		return 1;
	else
		return 0;
}
template <class type1>
bool dict<type1>::operator==(char *a2)
{
	if(!strcmp(this.element,a2))
		return 1;
	else
		return 0;
}
template <class type1>
bool dict<type1>::operator<(int a2)
{
	if(this.element < a2)
		return 1;
	else
		return 0;
}
template <class type1>
bool dict<type1>::operator<(float a2)
{
	if(this.element < a2)
		return 1;
	else
		return 0;
}
template <class type1>
bool dict<type1>::operator<(double a2)
{
	if(this.element < a2)
		return 1;
	else
		return 0;
}
template <class type1>
bool dict<type1>::operator<(char a2)
{
	if(this.element < a2)
		return 1;
	else
		return 0;
}
template <class type1>
bool dict<type1>::operator<(char *a2)
{
	if(strcmp(this.element,a2)<0)
		return 1;
	else
		return 0;
}
template <class type1>
bool dict<type1>::operator>(int a2)
{
	if(this.element > a2)
		return 1;
	else
		return 0;
}
template <class type1>
bool dict<type1>::operator>(float a2)
{
	if(this.element > a2)
		return 1;
	else
		return 0;
}
template <class type1>
bool dict<type1>::operator>(double a2)
{
	if(this.element > a2)
		return 1;
	else
		return 0;
}
template <class type1>
bool dict<type1>::operator>(char a2)
{
	if(this.element > a2)
		return 1;
	else
		return 0;
}
template <class type1>
bool dict<type1>::operator>(char *a2)
{
	if(strcmp(this.element,a2)>0)
		return 1;
	else
		return 0;
}
