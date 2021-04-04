#include "libft.h"

static int			cntw(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			count++;
			i++;
		}
		else if (s[i] == c)
			i++;
		else if (s[i] != c)
			i++;
	}
	return (count);
}

static unsigned int	fnd_w(char const *s, char c)
{
	unsigned int	w;

	w = 0;
	while (s[w] != '\0')
	{
		if (s[w] == c)
			w++;
		else if (s[w] != c)
			return (w);
	}
	return (w);
}

static size_t		lngth_w(char const *s, char c, unsigned int i)
{
	size_t	j;

	j = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

static void			*ft_free(char **str, unsigned int cnt)
{
	unsigned int	i;

	i = 0;
	while (i <= cnt)
	{
		free(str[cnt]);
		i++;
	}
	free(str);
	return (NULL);
}

char				**ft_split(char const *s, char c)
{
	size_t			i;
	unsigned int	w;
	int				cnt;
	char			**str;
	int				numw;

	if (s == NULL)
		return (NULL);
	numw = cntw(s, c);
	if (!(str = (char**)malloc(sizeof(char*) * (numw + 1))))
		return (NULL);
	cnt = 0;
	while (cnt != numw)
	{
		w = fnd_w(s, c);
		i = lngth_w(s, c, w);
		str[cnt] = ft_substr(s, w, i);
		if (str[cnt] == NULL)
			return (ft_free(str, cnt));
		cnt++;
		s = s + w + i;
	}
	str[cnt] = NULL;
	return (str);
}
