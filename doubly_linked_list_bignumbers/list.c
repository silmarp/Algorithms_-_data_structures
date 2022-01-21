#include "list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Big_number *create_number(char num[CHARS]){
  Big_number *number = calloc(1, sizeof(Big_number));
  number->size = 0;
  Unity *tmp = number->head;
  
  for(int i = strlen(num) - 1;i>=0;i--){
    if(i == (int) strlen(num) - 1){
      number->size++;
      tmp = calloc(1, sizeof(Unity));
      number->tail = tmp;
      tmp->unit = num[i]-48;// 48 == 0 in UTF-8
      tmp->previous = NULL;
      tmp->next = NULL;

      if(num[i-1] == '-'){
        tmp->unit = tmp->unit * -1;
        number->head = tmp;
        break;
      }

      number->head = tmp;
      continue;
    }
    number->size++;
    tmp->next = calloc(1, sizeof(Unity));
    Unity *next = tmp->next; 
    next->unit = num[i] - 48; // 48 == 0 in UTF-8
    next->previous = tmp;
    next->next = NULL;
    
    if(num[i-1] == '-'){
      next->unit = next->unit * -1;
      number->head = next; 
      break;
    }
    
    tmp = next;
    number->head = next; 
  }
  return number;
}

void print_number(Big_number *number){
  Unity *tmp = number->head;
  printf("Resultado :: ");
  while(tmp != NULL){
    printf("%i", tmp->unit);
    tmp = tmp->previous;
  }
  printf("\n");
}

Big_number *sum_numbers(Big_number *num1, Big_number *num2){
  Unity *tmp1 = num1->tail;
  Unity *tmp2 = num2->tail;
  Big_number *result = calloc(1, sizeof(Big_number));
  Unity *tmp3 = result->head;
  tmp3 = calloc(1, sizeof(Unity));
  int carry = 0;

  int un_result = tmp1->unit + tmp2->unit + carry;

  if(un_result>=10){
      carry = 1;
      un_result = un_result - 10;
  }
  else{
      carry = 0;
  }
  
  tmp3->unit = un_result;
  tmp3->previous = NULL;
  tmp3->next = NULL;

  result->head = tmp3;
  result->tail = tmp3;
  result->size = 1;
  

  tmp1 = tmp1->next;
  tmp2 = tmp2->next;

  while(tmp1 != NULL && tmp2 != NULL){
    int un_result = tmp1->unit + tmp2->unit + carry;
    if(un_result>=10){
      carry = 1;
      un_result = un_result - 10;
    }
    else{
      carry = 0;
    }
    tmp3 = result->head;
    tmp3->next = calloc(1, sizeof(Unity));
    Unity *next = tmp3->next;
    next->previous = tmp3;
    next->next = NULL;
    next->unit = un_result;
  
    result->head = next;
    result->size++;

    tmp1 = tmp1->next;
    tmp2 = tmp2->next;
  }

  while(tmp1 != NULL){
    tmp3 = result->head;
    tmp3->next = calloc(1, sizeof(Unity));
    Unity *next = tmp3->next;
    
    next->previous = tmp3;
    next->next = NULL;
    next->unit = tmp1->unit + carry;
    carry = 0;
    
    result->head = next;
    result->size++;

    tmp1 = tmp1->next;
  }

  while(tmp2 != NULL){
    tmp3 = result->head;
    tmp3->next = calloc(1, sizeof(Unity));
    Unity *next = tmp3->next;
    
    next->previous = tmp3;
    next->next = NULL;
    next->unit = tmp2->unit + carry;
    carry = 0;
    
    result->head = next;
    result->size++;
    
    tmp2 = tmp2->next;
  }

  while(carry != 0){
    tmp3 = result->head;
    tmp3->next = calloc(1, sizeof(Unity));
    Unity *next = tmp3->next;
    
    next->previous = tmp3;
    next->next = NULL;
    next->unit = carry;
    carry = 0;
    
    result->head = next;
    result->size++;
  }

  return result;
}

// retorna 1 se num1 > num2, 0 se num1 == num2 e -1 se num1 < num2
int big_numbercmp(Big_number *num1, Big_number *num2){
  Unity *tmp1 = num1->head;
  Unity *tmp2 = num2->head;

  if (tmp1->unit >= 0 && tmp2->unit >= 0){ // ambos positivos
    if (num1->size > num2->size){
      return 1;
    }
    else if(num1->size < num2->size){
      return -1;
    }
    else{ //tamanhos iguais
      while(tmp1->unit == tmp2->unit && tmp1 != NULL){
        tmp1 = tmp1->previous;
        tmp2 = tmp2->previous;
        if(tmp1 == NULL){   // todas unidades iguais
          return 0;
        }
      }
      if(tmp1->unit > tmp2->unit){
        return 1;
      }
      else{
        return -1;
      }
    }
  }

  else if(tmp1->unit > tmp2->unit){
    return 1;
  }
  else if(tmp1->unit < tmp2->unit){
    return -1;
  }

  else{ // ambos negativos
    if (num1->size > num2->size){
      return -1;
    }
    else if(num1->size < num2->size){
      return 1;
    }
    else{ //tamanhos iguais
      while(tmp1->unit == tmp2->unit && tmp1 != NULL){
        tmp1 = tmp1->previous;
        tmp2 = tmp2->previous;
        if(tmp1 == NULL){ // todas unidades iguais
          return 0;
        }
      }
      if(tmp1->unit > tmp2->unit){
        return -1;
      }
      else{
        return 1;
      }
    }
  }
  return 404; 
}
