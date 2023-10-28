/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 04:54:34 by snourry           #+#    #+#             */
/*   Updated: 2022/05/25 04:54:34 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	ft_eprint(char *s)
{
	ft_putstr_fd("[\e[31mERROR\e[39m] ", 1);
	ft_putendl_fd(s, 1);
}
