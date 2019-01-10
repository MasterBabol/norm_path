#include "norm_path.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	char buf[1024]; char* pos;
	#define test(x) printf("%s\n", (pos = norm_path(buf, x))?pos:"ERROR")
	test(argv[1]);

	return 0;
}
