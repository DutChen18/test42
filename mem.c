#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
#include "mem.h"

long	mallocs = 0;
long	frees = 0;

size_t
	malloc_size(void *ptr)
{
	return (*((size_t *) ptr - 1));
}

void
	*malloc(size_t size)
{
	void	*(*libc_malloc)(size_t);
	size_t	*ptr;

	libc_malloc = (void *(*)(size_t)) dlsym(RTLD_NEXT, "malloc");
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
	void	(*libc_free)(void *);
	
	libc_free = (void (*)(void *)) dlsym(RTLD_NEXT, "free");
	if (ptr != NULL)
		frees += 1;
	libc_free((size_t *) ptr - 1);
}
