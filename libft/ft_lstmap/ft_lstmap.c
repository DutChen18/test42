#include <stdio.h>
#include <stdlib.h>
#include "mem.h"

typedef struct s_list	t_list;

struct s_list {
	void			*content;
	struct s_list	*next;
};

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

void
	dump_list(t_list *lst)
{
	t_list	*tmp;

	printf("(");
	tmp = lst;
	while (tmp != NULL)
	{
#ifdef TEST_MEM
		printf("%lu ", (unsigned long) malloc_size(tmp));
#endif
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

void
	*double_content(void *content)
{
	return (void *)((unsigned long) content * 2);
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
	t_list	*lst2;

	lst = str2list(str);
	printf("ft_lstmap() -> ");
	lst2 = ft_lstmap(lst, double_content, dump_content);
	dump_list(lst);
	dump_list(lst2);
	printf("%lu unfreed mallocs\n", mallocs - frees);
}

int
	main(void)
{
	test("");
	test("a");
	test("ab");
	test("abc");
	return (EXIT_SUCCESS);
}
