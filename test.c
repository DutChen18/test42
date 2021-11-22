#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
#include "test.h"

long	mallocs = 0;
long	frees = 0;
long	fail_malloc = -1;
int		do_test_mem = 0;

size_t
	malloc_size(void *ptr)
{
	return (*((size_t *) ptr - 1));
}

void
	*libc_malloc(size_t size)
{
	void	*(*fn)(size_t);

	fn = (void *(*)(size_t)) dlsym(RTLD_NEXT, "malloc");
	return (fn(size));
}

void
	libc_free(void *ptr)
{
	void	(*fn)(void *);

	fn = (void (*)(void *)) dlsym(RTLD_NEXT, "free");
	fn(ptr);
}

void
	*malloc(size_t size)
{
	size_t	*ptr;

	if (fail_malloc == mallocs)
	{
		fail_malloc = -1;
		return (NULL);
	}
	ptr = libc_malloc(size + sizeof(size_t));
	if (ptr == NULL)
		return (NULL);
	*ptr = size;
	mallocs += 1;
	return (ptr + 1);
}

void
	free(void *ptr)
{
	if (ptr != NULL)
		frees += 1;
	libc_free((size_t *) ptr - 1);
}
