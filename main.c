#include "test.h"
#include <dlfcn.h>
#include <stdlib.h>

int
	main(int argc, char **argv)
{
	void	*dl;

	if (argc > 3)
		fail_malloc = atoi(argv[3]);
	if (argc > 4)
		do_test_mem = atoi(argv[4]);
	dl = dlopen(argv[1], RTLD_LAZY);
	((void (*)(void)) dlsym(dl, argv[2]))();
	return (EXIT_SUCCESS);
}
