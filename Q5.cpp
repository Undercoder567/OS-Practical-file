#include<unistd.h>
#include<fcntl.h>
#include<iostream>
#include<stdio.h>

int main( int argc, char *argv[] )
{
	char buf[128];
	int src, des, n;
	if (argc != 3)
	{
		std::cerr << "Error! Two files excepted";
		exit(1);
	}
	else
	{
		src = open(argv[1], O_RDONLY);
		if (src == -1)
		{
			perror("Error");
			exit(0);
		}
		else
		{
			des = open(argv[2], O_WRONLY | O_CREAT , 0640);
			if (des == -1)
			{
				perror("Error");
				close(src);
				exit(0);
			}
			else
			{
				while ((n = read(src, &buf, 128))> 0)
				{
					if (write( des, &buf, n)!=n)
					{
						perror("Error:");
						close(src);
						close(des);
						exit(0);
					}
				}
				write(STDOUT_FILENO, "Copying Sucessful", 18);
				close(src);
				close(des);
			}
		}
	}
	return 0;
}