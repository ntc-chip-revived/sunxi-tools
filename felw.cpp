#include <stdio.h>
/* Notes on translation from c to cpp
 *
 * In felw.c:
 * 		replaced "exit(" with "throw_exit("
 * 		replaced "assert(" with "throw_assert("
 * 		renamed main() to fel_main_body()
 * In this file:
 * 		created fel_main() which is the entry point and calls fel_main_body
 * 		fel_main() redirects stdout to fel.out, and puts it back to console when done
 */

extern "C" {

void throw_exit(int val) {
	throw (val);
}
void throw_assert(int val) {
	throw ((bool)val);
}

int fel_main_body(int argc, char **argv);


int fel_main(int argc, char **argv)
{
	/* redirecting stdout to a file */
	freopen("fel.out","w",stdout);
	int result = 0;
	try
	{
		result = fel_main_body(argc,argv);
	} catch (bool assertValue) {
		result = -999;
	} catch (int exitValue) {
		result = exitValue;
	}
	/* Put back normal stdout to console. CON is a predefined value */
	freopen("CON","w",stdout);
	printf("Result is %d",result);
	return result;
}

}
