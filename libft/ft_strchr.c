/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:12:59 by vzashev           #+#    #+#             */
/*   Updated: 2023/10/24 17:33:13 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	if (ch == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char)ch)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}