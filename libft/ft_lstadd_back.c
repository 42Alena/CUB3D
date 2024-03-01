/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:49:32 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/11/16 12:10:05 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
}
/*
#include <stdio.h>
int main() 
{
    t_list *node1 = ft_lstnew("One");
    t_list *node2 = ft_lstnew("Two");
    t_list *node3 = ft_lstnew("Three");
	t_list	*new = ft_lstnew("Four");

    node1->next = node2;
    node2->next = node3;
	ft_lstadd_back(&node1, new);
	while (node1)
	{
		printf("%s\n", (char *)node1->content);
		node1 = node1->next;
	}
}*/