#include <stdio.h>
#include <stdlib.h>
void testf(int **visit)
{
	(*visit)[1] = 3;
	printf("%d ", (*visit)[1]);
}

int main()
{
	int *arr = malloc(sizeof(int) * 10);

	for (int i=0;i<10;i++)
		arr[i] = 0;
	testf(&arr);
}