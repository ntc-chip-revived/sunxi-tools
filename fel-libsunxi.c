#include <stdio.h>
#include <stdlib.h>
int fel(int argc, char **argv, char ** returnBuffer);
int main(int argc, char **argv) {
	char * returnBuffer;
	fel(argc,argv,&returnBuffer);
	printf("%s",returnBuffer);
	free(returnBuffer);
}
