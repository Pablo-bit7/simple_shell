#include "main.h"

/**
 * _myhistory - Displays the command history list
 * @info: A structure containing relevant arguments
 * Return: Always returns 0
 */

int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - Removes an alias associated with a string
 * @info: The parameter structure containing relevant information
 * @str: The string alias to be removed
 * Return: 0 on success, 1 on error
 */

int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - Creates an alias for a given string
 * @info: A parameter structure containing necessary information
 * @str: The string to be aliased
 * Return: 0 on success, 1 on error
 */

int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - Prints the contents of an alias node
 * @node: The alias node to be printed
 * Return: 0 on success, 1 on error
 */

int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - Manage and interact with alias commands
 *
 * @info: A pointer to the parameter structure containing alias information
 *
 * This function allows for the management and interaction with alias commands.
 * If no arguments are provided, prints all defined aliases. If arguments are
 * given in the format "alias_name=command," it sets a new alias. If arguments
 * are provided without the equal sign, it tries to find and print aliases that
 * start with the provided name.
 *
 * @info: A pointer to the parameter structure containing alias information
 *        containing the alias list, arguments, and other relevant data.
 *
 * Return: 0 on success, 1 on error
 */

int _myalias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
