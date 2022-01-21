#include <stdio.h>
#include "cartas.h"
#include "pilha.h"
#include <stdlib.h>

int main(){
  Pilha *baralho = criar_pilha();
  
  for(int i=0; i<52;i++){
    Carta input;
    scanf("%s %s", input.nipe, input.valor);
    pilha_push(baralho, input);
  }
  
  int blackjack=0;
  
  while(blackjack<21){
    Carta carta=pilha_pop(baralho);
    if(carta.valor[0]=='V' || carta.valor[0]=='D' || carta.valor[0]=='K' || carta.valor[0]=='R'){
      blackjack += 10;
    }
    else{
      blackjack += atoi(carta.valor);
    }
  }
  
  if(blackjack==21){
    printf("Ganhou ;)\n");
  }
  else{
    printf("Perdeu :(\nSoma :: %i\n", blackjack);
  }
  
  pilha_destroy(baralho);
}
