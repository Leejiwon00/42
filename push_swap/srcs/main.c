/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:01:59 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/03/31 15:27:54 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(t_stack *a_stack, t_stack *b_stack)
{
	a_stack->top = NULL;
	a_stack->bottom = NULL;
	b_stack->top = NULL;
	b_stack->bottom = NULL;
	a_stack->cnt = 0;
	b_stack->cnt = 0;
}

void	init_list(t_stack *stack, t_list *lst)
{
	if (stack->top == NULL)
	{
		stack->bottom = lst;
		stack->top = lst;
		lst->next = NULL;
	}
	else
	{
		lst->next = stack->top;
		lst->next->prev = lst;
		stack->top = lst;
	}
}

void	parse_stack(t_stack *stack, char *av)
{
	t_list		*lst;
	char		**str;
	int			size;
	long long	data;

	str = ft_split(av, &size);
	while (--size > 0)
	{
		lst = malloc(sizeof(t_list));
		if (!lst)
			exit(1);
		data = ft_atoll(str[size - 1]);
		free(str[size - 1]);
		if (data >= -2147483648 && data <= 2147483647)
			lst->data = data;
		else
			error(1);
		init_list(stack, lst);
	}
	free(str);
}

int	main(int ac, char **av)
{
	t_stack	*a_stack;
	t_stack	*b_stack;

	a_stack = malloc(sizeof(t_stack));
	b_stack = malloc(sizeof(t_stack));
	if (!a_stack || !b_stack)
		return (0);
	if (ac >= 2)
	{
		init_stacks(a_stack, b_stack);
		while (ac > 1)
		{
			parse_stack(a_stack, av[ac - 1]);
			ac--;
		}
		check_dup(a_stack);
		if (is_sorted(a_stack))
			error(0);
		greedy(a_stack, b_stack);
	}
	free_stack(a_stack);
	free_stack(b_stack);
	return (0);
}
