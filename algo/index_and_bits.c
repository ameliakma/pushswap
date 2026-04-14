/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_and_bits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 21:54:43 by akhalfou          #+#    #+#             */
/*   Updated: 2026/03/28 21:13:15 by akhalfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_max_bits(int size)
{
	int	bits;

	bits = 0;
	while ((1 << bits) < size)
		bits++;
	return (bits);
}

void	index_of_stack(t_list *stack)
{
	t_list	*node;
	t_list	*compare;
	int		index;

	node = stack;
	compare = stack;
	index = 0;
	while (node)
	{
		index = 0;
		compare = stack;
		while (compare)
		{
			if (compare->value < node->value)
				index++;
			compare = compare->next;
		}
		node->index = index;
		node = node->next;
	}
}
