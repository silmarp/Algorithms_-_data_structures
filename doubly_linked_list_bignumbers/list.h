#ifndef bigN
#define bigN
#define CHARS 300
//structs

typedef struct number_unity{
int unit;
struct number_unity *next;
struct number_unity *previous;
}Unity;

typedef struct big_number{
Unity *head;
Unity *tail;
unsigned int size;
}Big_number;

// methods
Big_number *create_number(char num[CHARS]);
void print_number(Big_number *number);
Big_number *sum_numbers(Big_number *num1, Big_number *num2);
    // retorna 1 se num1 > num2, 0 se num1 == num2 e -1 se num1 < num2
int big_numbercmp(Big_number *num1, Big_number *num2);
#endif //bigN
