#include <iostream>
#include <unistd.h>
#include <sys/types.h>

using namespace std;

int main()
{
	pid_t pid;

	pid=fork();

	cout<<"pid = "<<pid<<endl;

	return 0;
	
}
