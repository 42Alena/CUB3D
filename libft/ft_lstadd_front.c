/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:30:36 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/11/16 12:13:50 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
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
	ft_lstadd_front(&node1, new);
	while (node1)
	{
		printf("%s\n", (char *)node1->content);
		node1 = node1->next;
	}
}*/