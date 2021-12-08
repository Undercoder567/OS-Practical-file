#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

int main()
{
	pid_t pid;
	pid = fork();

	if(pid==0)
	{
		cout<<"Child process"<<endl;
		cout<<"Child process terminated"<<endl;
	return 0;
	}

	else if(pid>0)
	{
		wait(NULL);
		cout<<"Parent process"<<endl;
		cout<<"parent process terminated"<<endl;
	return 0;
	}
}
