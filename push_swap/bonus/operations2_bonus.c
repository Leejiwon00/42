/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:46:30 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/03/26 14:21:20 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra(t_stack *a_stack)
{
	t_list	*tmp_node;

	if (a_stack->cnt <= 1)
		return ;
	tmp_node = a_stack->top;
	a_stack->top = a_stack->top->next;
	a_stack->top->prev = NULL;
	a_stack->bottom->next = tmp_node;
	tmp_node->prev = a_stack->bottom;
	a_stack->bottom = tmp_node;
	a_stack->bottom->next = NULL;
}

void	rb(t_stack *b_stack)
{
	t_list	*tmp_node;

	if (b_stack->cnt <= 1)
		return ;
	tmp_node = b_stack->top;
	b_stack->top = b_stack->top->next;
	b_stack->top->prev = NULL;
	b_stack->bottom->next = tmp_node;
	tmp_node->prev = b_stack->bottom;
	b_stack->bottom = tmp_node;
	b_stack->bottom->next = NULL;
}

void	rr(t_stack *a_stack, t_stack *b_stack)
{
	ra(a_stack);
	rb(b_stack);
}

void	rra(t_stack *stack)
{
	t_list	*tmp_node1;
	t_list	*tmp_node2;

	tmp_node1 = stack->bottom;
	stack->bottom = stack->bottom->prev;
	stack->bottom->next = NULL;
	tmp_node2 = stack->top;
	stack->top->prev = tmp_node1;
	stack->top = tmp_node1;
	stack->top->prev = NULL;
	stack->top->next = tmp_node2;
}

void	rrb(t_stack *stack)
{
	t_list	*tmp_node1;
	t_list	*tmp_node2;

	tmp_node1 = stack->bottom;
	stack->bottom = stack->bottom->prev;
	stack->bottom->next = NULL;
	tmp_node2 = stack->top;
	stack->top->prev = tmp_node1;
	stack->top = tmp_node1;
	stack->top->prev = NULL;
	stack->top->next = tmp_node2;
}
