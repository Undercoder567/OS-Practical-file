#include <iostream>
using namespace std;

int main()
{
	cout<<"KERNAL INFO: "<<endl;

	cout<<"CPU Type:"<<flush;
	system("cat /proc/cpuinfo | awk 'NR==3 {print $4}'");
	cout<<"CPU Model:"<<flush;
	system("cat /proc/cpuinfo | awk 'NR==4 {print $3}'");
	cout<<"Kernal version: "<<flush;
	system("cat /proc/version");
	return 0;
}
