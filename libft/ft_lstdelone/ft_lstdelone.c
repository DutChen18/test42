#include <stdio.h>
#include <stdlib.h>
#include "test.h"

typedef struct s_list	t_list;

struct s_list {
	void			*content;
	struct s_list	*next;
};

void	ft_lstdelone(t_list *lst, void (*del)(void *));

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

void
	dump_content(void *content)
{
	printf(" <%lu> ", (unsigned long) content);
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
	printf("ft_lstdelone()");
	ft_lstdelone(lst, dump_content);
	printf("%lu unfreed mallocs\n", mallocs - frees);
}

void
	main_test(void)
{
	test("a");
	test("ab");
	test("abc");
}
