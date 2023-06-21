#ifndef _ERROR_H_
#define _ERROR_H_


void error_file(char *file);
int error_instruction(char *opcode);
void error_pint(void);
void error_push_value(void);
void error_pop(void);
void error_malloc(void);
int error_short_stack(char *opcode);
int error_div_zero(void);
int error_pchar(void);
void call_function_error(char *line);

#endif
