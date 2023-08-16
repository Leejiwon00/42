/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 14:10:50 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/07/29 16:58:07 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

void	free_stack(t_stack *stack)
{
	while (stack->cnt)
	{
		free(stack->top);
		stack->top = stack->top->next;
		stack->cnt--;
	}
	free(stack);
}

void	init_stacks(t_stack *a_stack, t_stack *b_stack)
{
	a_stack->top = NULL;
	a_stack->bottom = NULL;
	b_stack->top = NULL;
	b_stack->bottom = NULL;
	a_stack->cnt = 0;
	b_stack->cnt = 0;
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
