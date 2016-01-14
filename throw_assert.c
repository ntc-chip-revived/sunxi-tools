#include <assert.h>
#include <stdlib.h>

void throw_exit(int v) {
	exit(v);
}
void throw_assert(int v) {
	if (!v)
		assert(v);
}
