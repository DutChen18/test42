#include <stdio.h>
#include <stdlib.h>
#include "test.h"

typedef struct s_list	t_list;

struct s_list {
	void			*content;
	struct s_list	*next;
};

t_list	*ft_lstnew(void *content);

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
	test()
{
	t_list	*lst;

	lst = ft_lstnew((void *) 1);
	printf("ft_lstnew(1) -> ");
	dump_list(lst);
	printf("%lu unfreed mallocs\n", mallocs - frees);
}

void
	main_test(void)
{
	test();
}
