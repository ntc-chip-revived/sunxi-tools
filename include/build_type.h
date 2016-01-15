#ifndef _BUILD_TYPE_H
#define _BUILD_TYPE_H

void throw_exit(int);
void throw_assert(int);

#ifdef BUILD_AS_OBJECT

typedef int (*MAIN_FUNC)(int, char **);
int call_main(int argc, char **argv, MAIN_FUNC main_func, char ** returnBuffer);
#endif

#endif
