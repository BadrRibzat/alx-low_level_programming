#include "main.h"

/**
 * _strlen - return the length of a string
 * @s: the string whos length to check
 * Return: integer length of string
 */

int _strlen(char *s)
{
	int a = 0;

	if (!s)
		return (0);

	while (*s++)
		a++;
	return (a);
}
/**
 * create_file - create file
 * @filename: name of the file
 * @text_content: text to write
 *
 * Return: 1 on Success 0 on Failure
 */

int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t bytes = 0, len = _strlen(text_content);

	if (!filename)
		return (-1);
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, STRUSR | S_TWUSR);
	if (fd == -1)
		return (-1);
	if (len)
		bytes = write(fd, text_content, len);
	close (fd);
	return (bytes == len ? 1 : -1);
}
