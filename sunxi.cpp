#include <stdio.h>

extern "C" {
#include "build_type.h"

/* Notes on translation from c to cpp
 *
 * In felw.c:
 * 		replaced "exit(" with "throw_exit("
 * 		replaced "assert(" with "throw_assert("
 * 		renamed main() to fel_main via ifdef
 * In this file:
 * 		created fel_main() which is the entry point and calls fel_main_body
 * 		fel_main() redirects stdout to fel.out, and puts it back to console when done
 */

int fel_main(int argc, char **argv);

int fel(int argc, char **argv, char ** returnBuffer)
{
	return call_main(argc, argv, fel_main, returnBuffer);
}

}
