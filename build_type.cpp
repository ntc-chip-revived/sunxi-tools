#include <stdio.h>
extern "C" {

#include "build_type.h"


void throw_exit(int val) {
	throw (val);
}
void throw_assert(int val) {
	if (!val)
		throw ((bool)val);
}
int call_main(int argc, char **argv, MAIN_FUNC main_func, char * redirect_stdout_file)
{
	/* redirecting stdout to a file */
	freopen(redirect_stdout_file,"w",stdout);
	int result = 0;
	try
	{
		result = (*main_func)(argc,argv);
	} catch (bool assertValue) {
		result = -999;
	} catch (int exitValue) {
		result = exitValue;
	}
	/* Put back normal stdout to console. CON is a predefined value */
	freopen("CON","w",stdout);
	return result;
}

}
