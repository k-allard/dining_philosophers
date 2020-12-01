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

/*
** Converts ASCII string to integer.
** Is intended to imitate the behaviour of original atoi,
** which has undef behavior if the value of the result cannot be represented.
*/

int			ft_atoi(char *str)
{
	unsigned long long	result;
	int					length_max;
	int					sign;
	int					i;

	result = 0;
	length_max = 19;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = (str[i++] == '-') ? -1 : 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i++] - '0';
		if (length_max-- < 0)
			return ((sign == 1) ? -1 : 0);
		if (result >= LLMAX && sign == 1)
			return (-1);
		if (result > LLMAX && sign == -1)
			return (0);
	}
	return (sign * result);
}