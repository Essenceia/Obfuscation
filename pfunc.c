#include <stdio.h>

typedef void (*fun) (void*);
typedef struct{
  int i;
}studpid;
void printstupid(void*suus);
void printstupid(void * suus){
  printf("%d\n",((studpid*)suus)->i );
}
void grub(void* suus) __attribute__ ((weak, alias ("printstupid")));
fun  GetStudpid(void){
  return grub;
}
int main(int argc, char const *argv[]) {
  studpid o ={ i : 2};
  fun fn = GetStudpid();
  fn(&o);
  return 0;
}
