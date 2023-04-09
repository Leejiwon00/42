/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_five.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:57:19 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/03/25 14:40:19 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a_stack)
{
	int	first;
	int	second;
	int	third;

	first = a_stack->top->data;
	second = a_stack->top->next->data;
	third = a_stack->top->next->next->data;
	if ((first < second) && (second > third) && (first < third))
	{
		rra(a_stack);
		sa(a_stack);
	}
	else if ((first > second) && (second < third) && (first < third))
		sa(a_stack);
	else if ((first < second) && (second > third) && (first > third))
		rra(a_stack);
	else if ((first > second) && (second < third) && (first > third))
		ra(a_stack);
	else if ((first > second) && (second > third) && (first > third))
	{
		ra(a_stack);
		sa(a_stack);
	}
}

void	sort_five(t_stack *a_stack, t_stack *b_stack)
{
	int	min;

	while (a_stack->cnt > 3)
	{
		min = min_max_idx(a_stack, 0) - 1;
		rotate_a(a_stack, min);
		pb(a_stack, b_stack);
	}
	sort_three(a_stack);
	while (b_stack->cnt)
		pa(a_stack, b_stack);
}

void	about_five(t_stack *a_stack, t_stack *b_stack)
{
	if (a_stack->cnt == 2)
		sa(a_stack);
	else if (a_stack->cnt == 3)
		sort_three(a_stack);
	else
		sort_five(a_stack, b_stack);
}
