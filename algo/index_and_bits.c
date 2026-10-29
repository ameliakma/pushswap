/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_and_bits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 21:54:43 by akhalfou          #+#    #+#             */
/*   Updated: 2026/04/16 21:01:21 by akhalfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_max_bits(int size)
{
	int	bits;

	bits = 0;
// Tant que 2 à la puissance 'bits' est inférieur à la taille de la pile
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
