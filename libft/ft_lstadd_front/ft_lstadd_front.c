#include <stdio.h>
#include <stdlib.h>
#include "test.h"

typedef struct s_list	t_list;

struct s_list {
	void			*content;
	struct s_list	*next;
};

void	ft_lstadd_front(t_list **lst, t_list *new);

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
	test(const char *str1, const char *str2)
{
	t_list	*lst;

	lst = str2list(str1);
	ft_lstadd_front(&lst, str2list(str2));
	printf("ft_lstadd_front() -> ");
	dump_list(lst);
	printf("%lu unfreed mallocs\n", mallocs - frees);
}

void
	main_test(void)
{
	test("", "a");
	test("abc", "d");
}
