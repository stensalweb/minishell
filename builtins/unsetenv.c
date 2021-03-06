/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrankul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:28:19 by vgrankul          #+#    #+#             */
/*   Updated: 2019/10/31 13:49:20 by vgrankul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**remove_env(const char *name, char **env)
{
	int		i;
	int		j;
	char	**new;
	int		count;

	i = 0;
	j = 0;
	count = count_arr(env) - 1;
	if ((new = (char**)malloc((count * sizeof(char*) + 1))))
	{
		while (j < count)
		{
			if (ft_strncmp(name, env[i], ft_strlen(name)) == 0)
				i++;
			if (!(new[j] = ft_strdup(env[i])))
				return (NULL);
			i++;
			j++;
		}
	}
	new[j] = NULL;
	return (new);
}

int		ft_unsetenv(int argc, char **argv, char ***env)
{
	char **tmp;

	if (argc != 2)
	{
		ft_printf("Incorrect number of arguments\n");
		return (2);
	}
	if (argv[1] == NULL || ft_strlen(argv[1]) == 0 ||
		str_chr(argv[1], '=') == 1)
		return (EXIT_FAILURE);
	if (find_env(argv[1], *env) == 0)
	{
		if (!(tmp = remove_env(argv[1], *env)))
			return (EXIT_FAILURE);
		destroy_arr(*env);
		*env = tmp;
	}
	return (0);
}
