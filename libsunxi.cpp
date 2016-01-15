#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <fstream>
#include <sstream>

extern "C" {
#include "libsunxi.h"

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






void throw_exit(int val) {
	throw (val);
}
void throw_assert(int val) {
	if (!val)
		throw ((bool)val);
}

//http://stackoverflow.com/questions/18816126/c-read-the-whole-file-in-buffer
/** Read file into string. */
std::string slurp (const std::string& path)
{
  std::ostringstream buf;
  std::ifstream input (path.c_str());
  buf << input.rdbuf();
  return buf.str();
}

// Copy a file's contents into a c buffer
char * slurpFileIntoBuffer(const std::string& path)
{
	std::string data = slurp(path);
	char * result = (char*) malloc(data.size()+1);
	strcpy(result,data.c_str());
	return result;
}
//
//int call_main(char ** returnBuffer, ...) {
//	va_list ap;
//	va_start(ap,returnBuffer);
//
//}


// caller needs to free the returned returnBuffer!
int call_main(int argc, char **argv, MAIN_FUNC main_func, char ** returnBuffer)
{
	std::string tempFileName = std::tmpnam(nullptr); // get a temp file name

	/* redirecting stdout to a file */
	FILE * redirect = freopen(tempFileName.c_str(),"w",stdout);
	int result = 0;
	try
	{
		result = (*main_func)(argc,argv);
	} catch (bool assertValue) {
		result = -999;
	} catch (int exitValue) {
		result = exitValue;
	}
	fflush(redirect);
	fclose(redirect);
	if (result == 0)
		*returnBuffer = slurpFileIntoBuffer(tempFileName); // remember to free this later
	else
		*returnBuffer = (char*) calloc(1,1); // a null terminated array
	remove(tempFileName.c_str()); // get rid of temp files
	/* Put back normal stdout to console. CON is a predefined value */
	freopen("CON","w",stdout);
	return result;
}


int fel(int argc, char **argv, char ** returnBuffer)
{
	return call_main(argc, argv, fel_main, returnBuffer);
}

}
