#ifndef MEM_H
# define MEM_H
# include <stddef.h>

extern long	mallocs;
extern long	frees;

size_t	malloc_size(void *ptr);
void	*libc_malloc(size_t size);
void	libc_free(void *ptr);
void	*malloc(size_t size);
void	free(void *ptr);

#endif
