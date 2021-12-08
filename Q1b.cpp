#include <iostream>
#include <unistd.h>
#include <sys/types.h>
using namespace std;

int n=10;
int main()
{
	cout<<"original value of n= "<<n<<endl;
	pid_t pid;
	pid=fork();

	if(pid==0)      //child process
	{
		cout<<"child process:"<<endl;
		n= n-5;
		cout<<"n = "<<n<<endl;
		return 0;
	}

	else if(pid>0)		//parent process
	{
		cout<<"parent process:"<<endl;
		n=n+5;
		cout<<"n = "<<n<<endl;
		return 0;
	}

}

