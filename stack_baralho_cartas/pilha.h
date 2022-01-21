#ifndef Pilha_included
#define Pilha_included
#define CAP 52

#include <stdlib.h>
#include "cartas.h"
#include <stdio.h>


typedef struct pilha{
  int topo;
  Carta *elementos[CAP];
} Pilha;
// -- metodos--

Pilha *criar_pilha();

void pilha_push(Pilha *stack, Carta carta);

Carta pilha_pop(Pilha *stack);

void pilha_destroy(Pilha *stack);

Carta pilha_topo(Pilha *stack);

#endif // Pilha_included
