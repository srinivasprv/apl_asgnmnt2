#include <iostream>
#include <cstdlib>
#include <cstdio>

int main(int argc,char* argv[])
{
	int i = 0;
	for(int i = 0; i < atoi(argv[1]); i++)
		printf("%d ",i);
	return 0;
}
