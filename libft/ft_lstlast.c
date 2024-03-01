/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:47:01 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/11/16 12:43:46 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
#include <stdio.h>
int main() 
{
    t_list *node1 = ft_lstnew("One");
    t_list *node2 = ft_lstnew("Two");
    t_list *node3 = ft_lstnew("Three");

    node1->next = node2;
    node2->next = node3;
	printf("%s\n", (char *)ft_lstlast(node1)->content);

}*/