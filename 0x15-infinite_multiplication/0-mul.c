#include "holberton.h"

/**
 * _strlen - calculat a string length
 * @s: pointer to a string
 * Return: string length
 */
int _strlen(char *s)
{
	int i, ln = 0;

	if (s)
	{
		for (i = 0; s[i]; i++)
		{
			ln++;
		}
	}
	return (ln);
}

/**
 * printAns - print the array
 * @ans: pointer to array to print
 * @i: counter
 */
void printAns(int *ans, int i)
{
	for (; i >= 0; i--)
	{
		_putchar(ans[i] + '0');
	}
	_putchar('\n');
}

/**
 * _isDigit - check if parametre of type digit
 * @num: variable to check
 * Return: 0 if true, 1 otherwise
 */
int _isDigit(int num)
{
	if (num >= 48 || num <= 57)
	{
		return (0);
	}
	return (1);
}

/**
 * checkArguments - check arguments size and type
 * @argc: number of arguments
 * @argv: pointer to the arguments
 * Return: 0 if valid
 */
int checkArguments(int argc, char *argv[])
{
	int i, arg;

	if (argc != 3)
	{
		_putchar('E');
        _putchar('r');
		_putchar('r');
        _putchar('o');
        _putchar('r');
        _putchar('\n');
		exit(98);
	}
	for (i = 0; i < argc; i++)
	{
		for (arg = 0; argv[i][arg]; arg++)
		{
			if (!_isDigit(argv[i][arg]))
			{
				_putchar('E');
        		_putchar('r');
				_putchar('r');
        		_putchar('o');
        		_putchar('r');
        		_putchar('\n');
				exit(98);
			}
		}        
	}
	return (0);
}

/**
 * main - main function to multiplie 2 elements
 * @argc: number of arguments
 * @argv: pointer to the arguments
 * Return: 0 if no error occures
 */
int main(int argc, char *argv[])
{
	int a[10000], b[10000], ans[10000] = {0};
	int i, j, tmp, l1, l2;
	char *s1, *s2;

	checkArguments(argc, argv);

	if (argv[1][0] == 0 || argv[2][0] == 0)
	{
		_putchar('0');
		_putchar('\n');
		return (0);
	}
	s1 = argv[1];
	s2 = argv[2];
	l1 = _strlen(s1);
	l2 = _strlen(s2);
	for (i = (l1 - 1), j = 0; i >= 0; i--, j++)
	{
		a[j] = s1[i] - '0';
	}
	for (i = (l2 - 1),j = 0; i >= 0; i--, j++)
	{
		b[j] = s2[i] - '0';
	}
	for (i = 0; i < l2; i++)
	{
		for (j = 0; j < l1; j++)
		{
			ans[i + j] += b[i] * a[j];
		}
	}
	for (i = 0; i < (l1 + l2); i++)
	{
		tmp = ans[i] / 10;
		ans[i] = ans[i] % 10;
		ans[i + 1] = ans[i + 1] + tmp;
	}
	for (i = (l1 + l2); i >= 0; i--)
	{
		if (ans[i] > 0)
			break;
	}
	printAns(ans, i);
	return (0);
}
