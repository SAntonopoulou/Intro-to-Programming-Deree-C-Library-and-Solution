typedef struct Int_Node
{
	long long int integer;
	struct Int_Node* next_link;
} Int_Node;

typedef struct Double_Node
{
	double double_value;
	struct Double_Node* next_link;
} Double_Node;

double do_exponent(double, int);
short is_space(char);
short is_digit(char);
size_t str_len(char*);
short alpha_to_int(char);
double str_to_double(char*, char**);
unsigned long long int str_to_int(char*);
short verify_signed_double(char*, double*);
short verify_double(char*, double*);
short verify_signed_integer(char*, long long int*);
short verify_integer(char*, unsigned long long int*);
void str_copy(char*, char*);
char* safely_get_input();
double safely_get_signed_double(char*);
double safely_get_double(char*);
long long int safely_get_signed_int(char*);
int safely_get_int(char*);
void new_int_node(Int_Node**, long long int);
void print_int_list(Int_Node*);
void free_int_list(Int_Node*);
void new_double_node(Double_Node**, double);
void print_double_list(Double_Node*);
void free_double_list(Double_Node*);
