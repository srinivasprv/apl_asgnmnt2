#include <stdio.h>
#include <ctime>
//#include <iostream>

using namespace std;
int main()
{
	time_t timer=time(0);
//	struct tm y2k;
//	double seconds;

	char *dt = ctime(&timer);
//	printf("time = %s\n",dt);
//	time(&timer);
	tm *gmtm=gmtime(&timer);
	dt = asctime(gmtm);
//	printf("time = %s\n",dt);
	tm *ltm = localtime(&timer);
//	cout <<"year:" <<ltm->tm_mday<<endl;
	printf("%d\n",ltm->tm_hour);
	printf("%d\n",ltm->tm_min);
	printf("%d\n",ltm->tm_sec);
}
