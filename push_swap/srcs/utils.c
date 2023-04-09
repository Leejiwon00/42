/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:11:45 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/03/30 15:47:05 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	is_sorted(t_stack *a_stack)
{
	t_list	*tmp;

	tmp = a_stack->top;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	rrr(t_stack *a_stack, t_stack *b_stack)
{
	rra(a_stack);
	rra(b_stack);
	write(1, "rrr\n", 4);
}
