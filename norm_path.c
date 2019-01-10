#include <string.h>

char* norm_path(char* output, const char* input)
{
	struct {
		int start;
		int len;
	} pairs[256];
    
	int pairs_cnt = 0;
	int i = 0, pi = 0, j;
	int eolp;
	int skip;
	int isroot = (input[i] == '/');

	do
	{
		if (input[i] == '/' || input[i] == '\0')
		{
			if (!(i - pi <= 1 && (input[pi] == '.' || input[pi] == '/')))
			{
				pairs[pairs_cnt].start = pi;
				pairs[pairs_cnt].len = i - pi + 1;
				pairs_cnt++;
			}
			pi = i+1;
		}
		i++;
	}
	while (input[i-1] != '\0' && (input[i-1] != '/' || input[i] != '\0'));

	eolp = i - 1;
	output[eolp + 1] = 0;
	skip = 0;

	for (pairs_cnt--; pairs_cnt >= 0; pairs_cnt--)
	{
		if (pairs[pairs_cnt].len == 2 &&
				input[pairs[pairs_cnt].start] == '.' &&
				input[pairs[pairs_cnt].start + 1] == '/')
			continue;
		else if (pairs[pairs_cnt].len == 3 &&
				input[pairs[pairs_cnt].start] == '.' &&
				input[pairs[pairs_cnt].start + 1] == '.' &&
				input[pairs[pairs_cnt].start + 2] == '/')
		{
			skip++;
		}
		else
		{
			if (skip > 0 && !(pairs_cnt == 0 && pairs[pairs_cnt].len == 1 && input[pairs[pairs_cnt].start] == '/'))
				skip--;
			else
			{
				for(j = pairs[pairs_cnt].start + pairs[pairs_cnt].len - 1; j >= pairs[pairs_cnt].start; eolp--, j--)
					output[eolp] = input[j];
			}
		}
	}

	if (isroot && output[eolp] != '/')
		output[eolp--] = '/';
	/*
    else if (!isroot && skip > 0)
	{
		while (skip > 0)
		{
			output[eolp--] = '/';
			output[eolp--] = '.';
			output[eolp--] = '.';
			skip--;
		}
	}

    // ../../abc = ../../abc
    // OR
    // ../../abc = abc
    */

	return output + eolp + 1;
}
