/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:46:33 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/03/26 13:53:38 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_stack *a_stack)
{
	int	tmp_data;

	if (a_stack->cnt <= 1)
		return ;
	tmp_data = a_stack->top->data;
	a_stack->top->data = a_stack->top->next->data;
	a_stack->top->next->data = tmp_data;
}

void	sb(t_stack *b_stack)
{
	int	tmp_data;

	if (b_stack->cnt <= 1)
		return ;
	tmp_data = b_stack->top->data;
	b_stack->top->data = b_stack->top->next->data;
	b_stack->top->next->data = tmp_data;
}

void	ss(t_stack *a_stack, t_stack *b_stack)
{
	sa(a_stack);
	sb(b_stack);
}

void	pa(t_stack *a_stack, t_stack *b_stack)
{
	t_list	*tmp_node;

	tmp_node = b_stack->top;
	if (b_stack->cnt == 0)
		return ;
	b_stack->top = b_stack->top->next;
	if (b_stack->cnt != 1)
		b_stack->top->prev = NULL;
	else
		b_stack->bottom = NULL;
	if (a_stack->cnt == 0)
	{
		a_stack->top = tmp_node;
		a_stack->top->next = NULL;
		a_stack->bottom = tmp_node;
	}
	else
	{
		tmp_node->next = a_stack->top;
		a_stack->top->prev = tmp_node;
		a_stack->top = tmp_node;
	}
	(a_stack->cnt)++;
	(b_stack->cnt)--;
}

void	pb(t_stack *a_stack, t_stack *b_stack)
{
	t_list	*tmp_node;

	tmp_node = a_stack->top;
	if (a_stack->cnt == 0)
		return ;
	a_stack->top = a_stack->top->next;
	if (a_stack->cnt != 1)
		a_stack->top->prev = NULL;
	else
		a_stack->bottom = NULL;
	if (b_stack->cnt == 0)
	{
		b_stack->top = tmp_node;
		b_stack->top->next = NULL;
		b_stack->bottom = tmp_node;
	}
	else
	{
		tmp_node->next = b_stack->top;
		b_stack->top->prev = tmp_node;
		b_stack->top = tmp_node;
	}
	(b_stack->cnt)++;
	(a_stack->cnt)--;
}
