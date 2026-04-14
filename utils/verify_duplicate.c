/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_duplicate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 20:48:48 by akhalfou          #+#    #+#             */
/*   Updated: 2026/03/15 21:17:38 by akhalfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	verify_duplicate(t_list *stack, int number)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->value == number)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
