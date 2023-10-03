/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:19:31 by knishiok          #+#    #+#             */
/*   Updated: 2023/10/01 18:22:43 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*ptr;
	unsigned char	*uptr;
	size_t			total_size;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (count > SIZE_MAX / size)
		return (malloc(SIZE_MAX));
	total_size = count * size;
	ptr = malloc(sizeof(void) * total_size);
	if (ptr == NULL)
		return (NULL);
	uptr = (unsigned char *)ptr;
	while (total_size--)
		*uptr++ = 0;
	return (ptr);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*new_str;

	new_str = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (new_str)
	{
		i = 0;
		while (*src)
			new_str[i++] = *src++;
		new_str[i] = '\0';
	}
	return (new_str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	char	*ptr;
	int		s1_len;
	int		s2_len;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (res == NULL)
		return (NULL);
	ptr = res;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}
