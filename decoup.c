#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#define SIZE 9
typedef struct{
  uint8_t size;
  uint8_t *message;
}CAN_Msg;
void SendCommande(CAN_Msg *msg){
  for(uint8_t i =0 ; i < msg->size ; i++){
  printf(" %d ",msg->message[i]);
}
printf(" - %d\n",msg->size );
}
void SendMCInterface(uint8_t code, uint8_t *bufr, uint8_t sizemone){
	if(sizemone){
    uint8_t i =0;
    uint8_t sz = ((sizemone < 8)? sizemone : 7);
    uint8_t *buf = (uint8_t*)calloc(sz,sizeof(uint8_t));
	CAN_Msg newmsg = {
    size : sz,
    message : buf,
  };
newmsg.message[i] = code;
sizemone++;
goto JUMPIN;
while(sizemone){
for(i=0; sizemone && i < 8 ; sizemone--){
  newmsg.message[i] = (*bufr++);
  JUMPIN:i++;
}
newmsg.size = i;
SendCommande(&newmsg);
}
}
}
uint8_t count(uint8_t *buf){
  uint8_t i=0;
  while(*buf){i++;(*buf++);}
  return i;
}
void remplir(uint_fast8_t *buf, uint_fast8_t s){
  for(uint_fast8_t i =0 ; i < s ; i++){
    buf[i] = i;
  }
}
int main(int argc, char const *argv[]) {
  uint8_t bufffer[17];
  remplir(bufffer,17u);
  for (uint8_t i =0 ; i <17 ; i++){
    printf("%d\n",bufffer[i] );
  }
  SendMCInterface(0xFF,bufffer,17u);
  return 0;
}
