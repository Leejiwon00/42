/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:05:20 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/03/25 14:56:05 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_stack *stack)
{
	int		min;
	t_list	*tmp;

	tmp = stack->top;
	min = tmp->data;
	while (tmp)
	{
		if (tmp->data < min)
			min = tmp->data;
		tmp = tmp->next;
	}
	return (min);
}

int	get_max(t_stack *stack)
{
	int		max;
	t_list	*tmp;

	tmp = stack->top;
	max = tmp->data;
	while (tmp)
	{
		if (tmp->data > max)
			max = tmp->data;
		tmp = tmp->next;
	}
	return (max);
}

int	min_max_idx(t_stack *stack, int flag)
{
	int		data;
	int		idx;
	t_list	*tmp;

	if (flag == 0)
		data = get_min(stack);
	else
		data = get_max(stack);
	idx = 0;
	tmp = stack->top;
	while (idx < stack->cnt)
	{
		if (data == tmp->data)
			break ;
		idx++;
		tmp = tmp->next;
	}
	return (idx);
}

int	other_idx(t_stack *stack, int data)
{
	int		idx;
	t_list	*tmp;

	idx = 1;
	tmp = stack->top->next;
	while (tmp)
	{
		if (tmp->prev->data < data && tmp->data > data)
			break ;
		idx++;
	tmp = tmp->next;
	}
	return (idx);
}

int	get_index(t_stack *stack, int data)
{
	int	idx;

	if (data < get_min(stack))
		idx = min_max_idx(stack, 0) - 1;
	else if (data > get_max(stack))
		idx = min_max_idx(stack, 1);
	else
		idx = other_idx(stack, data) - 1;
	return (idx);
}
