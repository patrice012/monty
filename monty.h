#ifndef _MONTY_H_
#define _MONTY_H_


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

#endif

