#include "main.h"
/**
 * my_free - frees any allocated memory after use
 * @mem: pointer pointer to mem to be freed
 */
void my_free(char **mem)
{
	int i;

	if (mem != NULL)
	{
		for (i = 0; mem[i] != NULL; i++)
		{
			free(mem[i]);
		}
		free(mem);
	}
}
