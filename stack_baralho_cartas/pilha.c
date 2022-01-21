#include "pilha.h"
#include <stdio.h>
#include <string.h>

Pilha *criar_pilha(){
  Pilha *stack = calloc(1, sizeof(Pilha));
  stack->topo=-1;
  return stack;
}

void pilha_push(Pilha *stack, Carta carta){
  if(stack->topo < CAP){
    stack->topo++;
    stack->elementos[stack->topo]=calloc(1, sizeof(Carta));
    Carta *aux=stack->elementos[stack->topo];
    strcpy(aux->nipe, carta.nipe);
    strcpy(aux->valor, carta.valor);
  }
  else{
    printf("Capacidade maxima atingida");
    return;
  }
}

Carta pilha_pop(Pilha *stack){
    Carta *aux=stack->elementos[stack->topo];
    Carta carta;
    strcpy(carta.nipe, aux->nipe);
    strcpy(carta.valor, aux->valor);
    free(aux);
    stack->topo--;
    return carta;
}


void pilha_destroy(Pilha *stack){
  while(stack->topo>=0){
    Carta *aux=stack->elementos[stack->topo];
    free(aux);
    stack->topo--;
  }
  free(stack);
}


//retorna o elemento do topo sem desaloca-lo
Carta pilha_topo(Pilha *stack){  
    Carta *aux=stack->elementos[stack->topo];
    Carta carta;
    strcpy(carta.nipe, aux->nipe);
    strcpy(carta.valor, aux->valor);
    return carta;
}


