/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:12:15 by vzashev           #+#    #+#             */
/*   Updated: 2023/10/31 05:08:58 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *res, char *temp)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!res)
	{
		res = (char *)malloc(1 * sizeof(char));
		res[0] = '\0';
	}
	if (!res || !temp)
		return (NULL);
	j = 0;
	i = -1;
	str = malloc((ft_strlen(res) + ft_strlen(temp) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (res[++i])
		str[i] = res[i];
	while (temp[j])
		str[i++] = temp[j++];
	str[i] = '\0';
	free(res);
	return (str);
}
