/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:41:18 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/08/05 10:50:50 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	write(1, "ra\n", 3);
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
	write(1, "rb\n", 3);
}

void	rr(t_stack *a_stack, t_stack *b_stack)
{
	ra(a_stack);
	rb(b_stack);
	write(1, "rr\n", 3);
}

void	rra(t_stack *stack)
{
	t_list	*tmp_node1;
	t_list	*tmp_node2;

	if (stack->cnt <= 1)
		return ;
	tmp_node1 = stack->bottom;
	stack->bottom = stack->bottom->prev;
	stack->bottom->next = NULL;
	tmp_node2 = stack->top;
	stack->top->prev = tmp_node1;
	stack->top = tmp_node1;
	stack->top->prev = NULL;
	stack->top->next = tmp_node2;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack)
{
	t_list	*tmp_node1;
	t_list	*tmp_node2;

	if (stack->cnt <= 1)
		return ;
	tmp_node1 = stack->bottom;
	stack->bottom = stack->bottom->prev;
	stack->bottom->next = NULL;
	tmp_node2 = stack->top;
	stack->top->prev = tmp_node1;
	stack->top = tmp_node1;
	stack->top->prev = NULL;
	stack->top->next = tmp_node2;
	write(1, "rrb\n", 4);
}
