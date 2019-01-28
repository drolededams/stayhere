#include <string.h>
#include <stdio.h>
#include <stdint.h>

int main(int ac, char **av)
{
	unsigned int	len;
	unsigned int	i;
	unsigned int	crypt_1;
	unsigned int	crypt_2;
	uint64_t		crypt_3;
	unsigned int	key;

	if (ac == 2)
	{
		len = strlen(av[1]);
		if (len <= 5)
		{
			puts("Login must be > 5 char");
			return(1);
		}
		i = 0;
		key = ((unsigned int)av[1][3] ^ 0x1337) + 6221293;
		while (i < len)
		{
			if (av[1][i] > 31)
			{
				crypt_1  = av[1][i] ^ key;

				crypt_3 = crypt_1 * 2284010283;
				crypt_3 = crypt_3 >> 32;

				crypt_2 = crypt_1;
				crypt_2 -= (unsigned int)crypt_3;
				crypt_2 /= 2;
				crypt_2 += (unsigned int)crypt_3;
				crypt_2 /= 1024;
				crypt_2 *= 1337;

				crypt_1 -= crypt_2;

				key += crypt_1;
				i += 1;
			}
			else
				return (1);
		}
		printf("serial = %u", key);
	}
	return (0);
}
