#include "shell.h"

/**
 *_eputs - print an input string
 * @str: the string to be printed
 * Return: Nil
 */
void _eputs(char *str)
{
	int a = 0;

	if (!str)
		return;
	while (str[a] != '\0')
	{
		_eputchar(str[a]);
		a++;
	}
}

/**
 * _eputchar - write a character c to stderr
 * @c: The character to print
 * Return: 1 on success.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - write character c to given fd
 * @c: The character to print
 * @fd: The filedescriptor to write to
 * Return: 1 On success.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char c, int fd)
{
	static int s;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || s >= WRITE_BUF_SIZE)
	{
		write(fd, buf, s);
		s = 0;
	}
	if (c != BUF_FLUSH)
		buf[s++] = c;
	return (1);
}

/**
 *_putsfd - print an input string
 * @str: string to be printed
 * @fd: the filedescriptor to write to
 * Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
