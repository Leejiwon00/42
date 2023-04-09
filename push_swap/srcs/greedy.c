/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:25:24 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/03/25 14:36:22 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_b(t_stack *b_stack, int idx)
{
	if (idx > b_stack->cnt / 2)
	{
		while (idx < b_stack->cnt)
		{
			rrb(b_stack);
			idx++;
		}
	}
	else
	{
		while (idx > 0)
		{
			rb(b_stack);
			idx--;
		}
	}
}

void	rotate_a(t_stack *a_stack, int idx)
{
	if (idx > a_stack->cnt / 2)
	{
		while (idx < a_stack->cnt - 1)
		{
			rra(a_stack);
			idx++;
		}
	}
	else
	{
		while (idx >= 0)
		{
			ra(a_stack);
			idx--;
		}
	}
}

void	sorting(t_stack *a_stack, t_stack *b_stack, int b_idx)
{
	int	data;
	int	a_idx;

	rotate_b(b_stack, b_idx);
	data = b_stack->top->data;
	if (!a_stack->top)
	{
		pa(a_stack, b_stack);
		return ;
	}
	a_idx = get_index(a_stack, data);
	rotate_a(a_stack, a_idx);
	pa(a_stack, b_stack);
}

void	greedy(t_stack *a_stack, t_stack *b_stack)
{
	int		p1;
	int		p2;
	int		b_idx;
	int		idx;

	if (a_stack->cnt <= 5)
	{
		about_five(a_stack, b_stack);
		return ;
	}
	get_pivot(a_stack, &p1, &p2);
	partition(a_stack, b_stack, &p1, &p2);
	while (b_stack->cnt > 0)
	{
		b_idx = count_operations(a_stack, b_stack);
		sorting(a_stack, b_stack, b_idx);
	}
	idx = min_max_idx(a_stack, 0) - 1;
	rotate_a(a_stack, idx);
}
