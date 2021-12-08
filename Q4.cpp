#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

int main(int argc, char *argv[])
{
	if(argc!=2)
	{
		cout<<"wrong command line arrguments";
		exit(0);
	}
	
	else
	{
		cout<<"permissions for "<<argv[1];
		cout<<"user group others access time"<<flush;
	char st[100]="";

	strcat(st, "ls -l ");
	strcat(st, argv[1]);
	strcat(st, "| awk '{print $1,$6,$7,$8};'");
	system(st);
	}
return 0;
} 
