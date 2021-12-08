#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int result=0;
int choice;
void *sum(void *param)
{
	int *n= (int*)param;
	result=n[0]+n[1];
	
	printf("sum of %d and %d =%d\n",n[0],n[1],result);
	pthread_exit(0);
}

void *sub(void *param)
{
	int *n= (int*)param;
	result=n[0]-n[1];
	
	printf("subtraction of %d and %d =%d\n",n[0],n[1],result);
	pthread_exit(0);
}

void *prdt(void *param)
{
	int *n= (int*)param;
	result=n[0]*n[1];
	
	printf("product of %d and %d =%d\n",n[0],n[1],result);
	pthread_exit(0);
}

void *divd(void *param)
{
	int *n= (int*)param;
	result=n[0]/n[1];
	
	printf("division of %d and %d =%d\n",n[0],n[1],result);
	pthread_exit(0);
}

void input()
{
	

	printf("Which operation you want to perform:\n\n");
	printf("1) Addition(+)\n");
	printf("2) Subtraction(-)\n");
	printf("3) Multiplication(*)\n");
	printf("4) Division(/)\n\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);
}

int main(int argc, char *argv[])
{
	int arr[2];
	char ch;
	pthread_t tid;
	pthread_attr_t attr;

	input();
	
	abc:
	if(argc!=3)
	{
		printf("no argument is provided, enter an integer argument\n");
		return -1;
	}
	if(atoi(argv[1])<0)
	{
		printf("negative number\n");
		return -1;
	}

	arr[0]= atoi(argv[1]);
	arr[1]=atoi(argv[2]);
	
	if(choice==1)
	{
	pthread_attr_init(&attr);
	pthread_create(&tid,&attr,sum,arr);
	pthread_join(tid,NULL);
	}

	if(choice==2)
	{
	pthread_attr_init(&attr);
	pthread_create(&tid,&attr,sub,arr);
	pthread_join(tid,NULL);
	}
	
	if(choice==3)
	{
	pthread_attr_init(&attr);
	pthread_create(&tid,&attr,prdt,arr);
	pthread_join(tid,NULL);
	}

	if(choice==4)
	{
	pthread_attr_init(&attr);
	pthread_create(&tid,&attr,divd,arr);
	pthread_join(tid,NULL);
	}
	fflush(stdin);
	printf("Do you want to perform more operations?(Y/N): \n");
	scanf("%c", &ch);
	scanf("%c",&ch);
	printf("%c",ch);

	if(ch=='y'||ch=='Y')
	{
		input();
		goto abc;
	}
	else
		exit(0);

}	
