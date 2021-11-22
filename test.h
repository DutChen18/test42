#ifndef TEST_H
# define TEST_H
# include <stddef.h>

extern long	mallocs;
extern long	frees;
extern long	fail_malloc;
extern int	do_test_mem;

size_t	malloc_size(void *ptr);
void	*libc_malloc(size_t size);
void	libc_free(void *ptr);
void	*malloc(size_t size);
void	free(void *ptr);

#endif
