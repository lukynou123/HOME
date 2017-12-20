#include <stdlib.h>
#include "list.h"

int main(void)
{
	t_list *list;

	list = NULL;
	list = add_link(list, "salut\n");
	list = add_link(list, "tata\n");
	list = add_link(list, "tutu\n");

	print_list(list);
	return (0);
}
