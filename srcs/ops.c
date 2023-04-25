/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:38:10 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/03/14 19:06:29 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	add_operation(t_ops **head, char *name)
{
	t_ops	*new_node;
	t_ops	*last_node;

	new_node = (t_ops *)malloc(sizeof(t_ops));
	if (!new_node)
		return ;
	new_node->name = name;
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	last_node = *head;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->next = new_node;
}

void	print_operations(t_ops *ops)
{
	while (ops)
	{
		ft_putstr_fd(ops->name, 1);
		ft_putchar_fd('\n', 1);
		ops = ops->next;
	}
}
