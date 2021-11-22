#include <dlfcn.h>
#include <stdlib.h>

int
	main(int argc, char **argv)
{
	void	*dl;
	long	*fail_malloc;
	int		*do_test_mem;

	dl = dlopen(argv[1], RTLD_LAZY);
	fail_malloc = dlsym(dl, "fail_malloc");
	do_test_mem = dlsym(dl, "do_test_mem");
	if (argc > 3)
		*fail_malloc = atoi(argv[3]);
	if (argc > 4)
		*do_test_mem = atoi(argv[4]);
	((void (*)(void)) dlsym(dl, argv[2]))();
	return (EXIT_SUCCESS);
}
