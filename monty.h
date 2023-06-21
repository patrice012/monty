#ifndef _MONTY_H_
#define _MONTY_H_

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

/* define macros */
#define UNUSED __attribute__((unused))
#define BUFFER_SIZE 1024

#define STACK 0
#define QUEUE 1



/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
  * global_var - global variable struct
  * @data_type: LIFO or FIFO data type. stack or queue
  * @cont: positive intger count the number of lines
  * @arg: program arg
  * @head: pointer to double linked list
  * @fd: file descriptor
  * @buffer: text temporary container
  */

typedef struct global_var
{
	int data_type;
	unsigned int cont;
	char  *arg;
	stack_t *head;
	FILE *fd;
	char *buffer;
} global_v;

extern global_v glob_var;

/*======= main functions ==========*/
void push(stack_t **stack, unsigned int line_number);



/*============== helper functions =========*/
void (*get_func(char *code))(stack_t **stack, unsigned int line_number);
/*int _getline(char **lineptr, size_t *n, int stream);*/
int process_file(char *file);
void parse_instruction(char *line, char **opcode, char **value);




/*=========== str helper =======*/
char *_itoa(int num);
int is_digit(char c);
int is_numeric(char *s);



/*=======  doubly linked list functions ===========*/

/* stack and queue functions */
int empty(void);
void push_back(int data);
void push_front(int data);
void pop_back(void);
void pop_front(void);
int front(void);
int back(void);
void free_list(void);


stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
size_t print_dlistint(const stack_t *h);
void free_dlistint(stack_t *head);


/* =========== */
void free_vglo(void);



/* error handlers */
void error_file(char *file);
int error_instruction(char *opcode);
void error_malloc(void);
void error_push_value(void);
void error_pint(void);

void error_pop(void);
int error_short_stack(char *opcode);
int error_div_zero(void);
int error_pchar(void);


/* print functions */
void print_str(char *s);
void print_err(char *s);

/* memory functions */
void _memcpy(void *dest, void *src, size_t n);
void *_realloc(void *ptr, unsigned int old_size,
    unsigned int new_size);
void *_memchr(char *s, char c, int n);
void *_calloc(size_t count, size_t size);
void *_recalloc(void *ptr, unsigned int old_size,
    unsigned int new_size);


#endif

