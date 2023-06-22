#ifndef _ERROR_H_
#define _ERROR_H_

int error_instruction(char *opcode);
void swap_fail(unsigned int line_number);
void error_pint(unsigned int line_number);
void error_push(unsigned int line_number);
void error_pop(unsigned int line_number);

void malloc_fail(void);
void error_sub_fail(unsigned int line_number);
void error_div_fail(unsigned int line_number);
void error_zero_division(unsigned int line_number);
void error_mul_fail(unsigned int line_number);
void error_mod_fail(unsigned int line_number);

void call_function_error(void);
void code_error(unsigned int line_number);
#endif
