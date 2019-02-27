#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
  int i, n;
  time_t t;
  clock_t start, end;
  double cpu_time_used;
  int *virtualMem;

  n = atoi(argv[1]);

  virtualMem = (int *)malloc(sizeof(int) * n);

  srand((unsigned)time(&t));

  for (i = 0; i < n; i++)
  {
    virtualMem[i] = rand() % 100;
  }

  start = clock();

  for (i = 0; i < n; i++)
  {
    if (i > 0 && (i + 1) % 4096 == 0)
    {
      end = clock();
      cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
      printf("Element %d is %d and took %f seconds to look up\n", i + 1,
             virtualMem[i], cpu_time_used);
    }
  }

  free(virtualMem);

  return 0;
}
