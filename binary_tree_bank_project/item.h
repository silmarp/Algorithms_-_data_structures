
typedef struct Bank_account Bank_account;



Bank_account *create_bank_account(char csv[500]);
void destroy_bank_account(Bank_account *account);
unsigned long int return_cpf(Bank_account *account);
unsigned long int convert_cpf_str_to_cpf_int(char cpf_str[20]);
void print_info(Bank_account *account);
void print_cpf(Bank_account *account);
