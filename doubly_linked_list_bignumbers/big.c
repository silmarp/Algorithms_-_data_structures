#include <stdio.h>
#include "list.h"
#include <string.h>


int main(){
  char sum[]="soma", higher[]="maior", lesser[]="menor";
  int n;
  scanf("%i", &n);

  for(int i=0; i<n;i++){
    char operation[10], num1[CHARS], num2[CHARS]; 
    scanf("%s %s %s", operation, num1, num2);
    Big_number *number1 = create_number(num1);
    Big_number *number2 = create_number(num2);

    getchar();
    if(strncmp(operation, sum, strlen(sum))==0){
      Big_number *result = sum_numbers(number1, number2);
      print_number(result);
    }
    else if(strncmp(operation, higher, strlen(higher))==0){
      int result = big_numbercmp(number1, number2);
      if(result == 1){
        printf("Resultado :: True\n");
      }
      else{
        printf("Resultado :: False\n");
      }
    }
    else if(strncmp(operation, lesser, strlen(lesser))==0){
      int result = big_numbercmp(number1, number2);
      if (result == -1){
        printf("Resultado :: True\n");
      }
      else{
        printf("Resultado :: False\n");
      }
    }
    else{
      int result = big_numbercmp(number1, number2);
      if (result == 0){
        printf("Resultado :: True\n");
      }
      else{
        printf("Resultado :: False\n");
      }
    }
  }
}
