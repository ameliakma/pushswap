/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 22:08:35 by akhalfou          #+#    #+#             */
/*   Updated: 2026/04/02 19:50:29 by akhalfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	radix_big(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	j;
	int	size;
	int	bits;

	size = ft_lstsize(*stack_a);
	bits = count_max_bits(size);
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*stack_a)->index >> i) & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size <= 1)
		return ;
	if (size == 2 && (*stack_a)->index > (*stack_a)->next->index)
		sa(*stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 5)
		sort_five(stack_a, stack_b);
	else
		radix_big(stack_a, stack_b);
}

void	sort_three(t_list **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->index;
	second = (*stack_a)->next->index;
	third = (*stack_a)->next->next->index;
	if (first > second && second < third && first < third)
		sa(*stack_a);
	else if (first > second && second > third)
	{
		sa(*stack_a);
		rra(stack_a);
	}
	else if (first > second && second < third && first > third)
		ra(stack_a);
	else if (first < second && second > third && first < third)
	{
		sa(*stack_a);
		ra(stack_a);
	}
	else if (first < second && second > third && first > third)
		rra(stack_a);
}

int	min_pos(t_list *stack)
{
	int	min_indx;
	int	min_pos;
	int	i;

	if (!stack)
		return (0);
	min_pos = 0;
	i = 0;
	min_indx = stack->index;
	while (stack)
	{
		if (stack->index < min_indx)
		{
			min_indx = stack->index;
			min_pos = i;
		}
		i++;
		stack = stack->next;
	}
	return (min_pos);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	while (size > 3)
	{
		while (min_pos(*stack_a) != 0)
		{
			if (min_pos(*stack_a) <= size / 2)
				ra(stack_a);
			else
				rra(stack_a);
		}
		pb(stack_a, stack_b);
		size--;
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}
