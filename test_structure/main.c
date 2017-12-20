#include "struct.h"

void pass(test *s)
{
	test *ptr; // pointeur de structure
	ptr = s; // recuperer l adresse de la structure dans le ptr
	s->b = "salut"; // changement b via la strcture
	s->b = "OUI"; // ""
	ptr->a = 'Z'; // changement de a via ptr de struct
}

void passage_ptr(test *z)
{
	z->a = 'a';

	z->a++;
	z->a++;
	z->a++;
	z->a++;
	z->a++;
	//	return (z)
}

test renvoi_struct(void)
{
	test b;
	test *c;
	b.a = 'a';

//	c = &b;
//	return (c);
return(b);
}

test renvoi_ptr_struct(void)
{
	test v;

	v.a = 'l';
	return (v);
}
int main(void)
{
	test a; // declaration d une structure
	test b;
	test *c;

	a.a = 'b';
	a.b = "abc";
	ft_putchar(a.a);
	passage_ptr(&a);
	ft_putchar(a.a);
	ft_putstr(a.b);
	pass(&a);
	ft_putstr(a.b);
	ft_putchar(a.a);



	c = (test *)malloc(sizeof(test));
	*c = renvoi_ptr_struct();
	ft_putchar(c->a);

	
	b = renvoi_struct();
	ft_putchar(b.a);
}
