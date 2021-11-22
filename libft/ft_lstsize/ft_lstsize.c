#include <stdio.h>
#include <stdlib.h>
#include "test.h"

typedef struct s_list	t_list;

struct s_list {
	void			*content;
	struct s_list	*next;
};

size_t	ft_lstsize(t_list *lst);

void
	dump_list(t_list *lst)
{
	t_list	*tmp;

	printf("(");
	tmp = lst;
	while (tmp != NULL)
	{
		if (do_test_mem) {
			printf("%lu ", (unsigned long) malloc_size(tmp));
		}
		printf("%lu, ", (unsigned long) tmp->content);
		tmp = tmp->next;
	}
	printf(")\n");
}

t_list
	*str2list(const char *str)
{
	t_list	*tmp;

	if (!*str)
		return (NULL);
	tmp = malloc(sizeof(t_list));
	tmp->content = (void *)(unsigned long) *str;
	tmp->next = str2list(str + 1);
	return (tmp);
}

void
	test(const char *str)
{
	t_list	*lst;

	lst = str2list(str);
	printf("ft_lstsize() -> %lu\n", ft_lstsize(lst));
	printf("%lu unfreed mallocs\n", mallocs - frees);
}

void
	main_test(void)
{
	test("");
	test("a");
	test("ab");
	test("abc");
}
