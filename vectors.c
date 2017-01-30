
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#define SIZE ((uint8_t)32)
typedef  uint8_t __vec __attribute((vector_size(SIZE)));
int main( ) {
  __vec v;
  v[0] = 1;
  for(uint8_t i = 0 ; i < 31 ; i++)
  {
    v[i+1] = i+2;
    printf("%o\n",v[i] );
  }
  printf("Size of vector %o expected size %o \n",sizeof(v),SIZE );
  return 0;
}
