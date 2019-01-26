#include <stdio.h>

int main()
{
   int i = -10;
   char* even = "EVEN";
   char* odd = "ODD";
   for( i = -10; i <= 10; i++ ) {
      printf( "%i    %i    %s\n", i, i*i, i%2==0? even : odd);
   }
    return 0;
}
