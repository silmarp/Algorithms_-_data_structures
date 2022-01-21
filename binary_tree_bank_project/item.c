#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"


struct Bank_account {
  char cpf_str[20];
  unsigned long int cpf_int;
  char name[300];
  unsigned int age;
  float account_balance;
};

Bank_account *create_bank_account(char csv[500]){
  Bank_account *new = calloc(1, sizeof(Bank_account));
  
  // operation => indicates what data field will be filled
  // 0 -> cpf_str | 1 -> name | 2 -> age | 3 -> account_balance
  int data_field=0; 
  char *token = strtok(csv, ";");
  while(token){
    switch(data_field){
      case 0: strcpy(new->cpf_str, token);
              //printf("%s\n", new->cpf_str);
              break;
      
      case 1: strcpy(new->name, token);
              //printf("%s\n", new->name);
              break;
      
      case 2: new->age = atoi(token);
              //printf("%i\n", new->age);
              break;

      case 3: new->account_balance = atof(token);
              //printf("%f\n", new->account_balance);
              break;
    } 
    token = strtok(NULL, ";");
    data_field++;
  }
  
  // getting the cpf_int
  char cpf_str[20];
  strcpy(cpf_str, new->cpf_str);
  new->cpf_int = convert_cpf_str_to_cpf_int(cpf_str);

  //printf("%li", new->cpf_int);
  return new;
}

void destroy_bank_account(Bank_account *account){
  free(account);
}

unsigned long int return_cpf(Bank_account *account){
  unsigned long int cpf = account->cpf_int;
  return cpf;
}

unsigned long int convert_cpf_str_to_cpf_int(char cpf_str[20]){
  char cpf_int[20];
  char *token_cpf = strtok(cpf_str, ".");
  strcpy(cpf_int, token_cpf);
  token_cpf = strtok(NULL, ".");
  strcat(cpf_int, token_cpf);
  token_cpf = strtok(NULL, "-");
  strcat(cpf_int, token_cpf);
  token_cpf = strtok(NULL, "-");
  strcat(cpf_int, token_cpf);
  return atol(cpf_int);
}

void print_info(Bank_account *account){
  printf("Conta :: %s\n", account->name);
  printf("CPF :: %s\n", account->cpf_str);
  printf("Idade :: %u\n", account->age);
  printf("Saldo atual :: R$ %.2f\n", account->account_balance);
}

void print_cpf(Bank_account *account){
  if(account->cpf_int/9999999999 < 1){printf("0%li\n", account->cpf_int);}
  else{printf("%li\n", account->cpf_int);}


}
