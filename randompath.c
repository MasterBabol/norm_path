#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
	char* tb = "abcdefghijklmnopqrstuvwxyz";
	struct timeval t;
	gettimeofday(&t,0);
	srand(t.tv_usec);
	char buf[2048] = {0};
	char buf2[8];
	int i;
	int r;
	for (i = 0; i < 64; i++)
	{
		r = rand() % 100;
		if (r < 30)
		{
			buf2[0] = '.';
			buf2[1] = '.';
			buf2[2] = '/';
			buf2[3] = 0;
		}
		else if (r < 60)
		{
			buf2[0] = '.';
			buf2[1] = '/';
			buf2[2] = 0;
		}
		else
		{
			buf2[0] = tb[rand () % 26];
			buf2[1] = 0;
		}
		strcat(buf, buf2);
	}
	printf("%s\n", buf);
	return 0;
}

