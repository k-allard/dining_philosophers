#include "philo_one.h"

static int	ft_digits(int n)
{
	int dig;

	dig = 1;
	while ((n /= 10) > 0)
		dig++;
	return (dig);
}

/*
** Allocates and returns a string representing the int received as an argument.
*/

char		*ft_itoa(int n)
{
	char	*str;
	int		negative;
	int		len;

	negative = 0;
	if (n < 0)
	{
		negative = 1;
		n = -n;
	}
	len = ft_digits(n) + negative;
	if (!(str = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	if (negative)
		str[0] = '-';
	str[len--] = '\0';
	while (len >= negative)
	{
		str[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (str);
}

int			ft_atoi(char *str)
{
	unsigned long long	result;
	int					sign;
	int					i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = (str[i++] == '-') ? -1 : 1;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	return (sign * result);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr(int n)
{
	char ch;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n / 10 > 0)
		ft_putnbr(n / 10);
	ch = n % 10 + '0';
	write(1, &ch, 1);
}

size_t	ft_cpy(char *dest, const char *src)
{
	size_t i;

	i = 0;
	if (!dest || !src)
		return (0);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (i);
}