#ifndef _LIBSUNXI_H
#define _LIBSUNXI_H

void throw_exit(int);
void throw_assert(int);


typedef int (*MAIN_FUNC)(int, char **);
int call_main(int argc, char **argv, MAIN_FUNC main_func, char ** returnBuffer);

/* The fel function */
int fel(int argc, char **argv, char ** returnBuffer);

/* From fel.c */
int fel_main(int argc, char **argv);

#endif
