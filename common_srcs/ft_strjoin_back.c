/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 18:44:39 by julnolle          #+#    #+#             */
/*   Updated: 2020/10/06 17:38:58 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (dst == NULL && src == NULL)
		return (NULL);
	while (n-- > 0)
		((unsigned char *)dst)[n] = ((const unsigned char *)src)[n];
	return (dst);
}

static char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	len;

	dest = NULL;
	len = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest != NULL)
		ft_memcpy(dest, src, len + 1);
	return (dest);
}

static char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		dst = ft_strdup(s2);
	else if (!s2)
		dst = ft_strdup(s1);
	else
	{
		len_s1 = ft_strlen(s1);
		len_s2 = ft_strlen(s2);
		if (!(dst = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
			return (NULL);
		ft_memcpy(dst, s1, len_s1);
		ft_memcpy(dst + len_s1, s2, len_s2 + 1);
	}
	return (dst);
}

void		ft_strjoin_back(char *back, char **src)
{
	char *tmp;

	if (back == NULL || src == NULL)
		return ;
	if (*src)
	{
		tmp = ft_strdup(*src);
		free(*src);
		*src = NULL;
		*src = ft_strjoin(tmp, back);
		free(tmp);
		tmp = NULL;
	}
	else
		*src = ft_strdup(back);
}
