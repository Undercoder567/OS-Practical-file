#include<iostream>
using namespace std;
int main()
{
	cout<<"MEMORY INFO:"<<endl;

	cout<<"Total memory: "<<flush;
	system("cat /proc/meminfo| awk 'NR==1 {print $2}'");
	cout<<"Free memory: "<<flush;
	system("cat /proc/meminfo| awk 'NR==2 {print $2}'");
	cout<<"Used memory: "<<flush;
	system("cat /proc/meminfo| awk '{if(NR==1) a=$2; if(NR==2)b=$2;}END {print a-b}'");
return 0;
}
