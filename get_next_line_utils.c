#include "get_next_line.h"
#include <stdlib.h>
char	*ft_strchr(const char *s, int c)
{
	int	len;

	len = 0;
	while (s[len])
	{
		if (s[len] == (unsigned char)c)
			return ((char *)&s[len]);
		len++;
	}
	if (c == '\0')
		return ((char *)&s[len]);
	return (0);
}

void	*ft_memcpy(void *dst, const void *src, int n)
{
	unsigned char	*d;
	unsigned char	*s;
	int				i;

	i = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (n == 0 || dst == src)
		return (dst);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

int		ft_strlen(const char *c)
{
	int		i;

	i = 0;
	while (c[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;
	int		s1_len;
	int		s2_len;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	a = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!a)
		return (0);
	ft_memcpy(a, s1, s1_len);
	ft_memcpy(a + s1_len, s2, s2_len);
	a[s1_len + s2_len] = '\0';
	return (a);
}
