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