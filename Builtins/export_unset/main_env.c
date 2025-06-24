/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsougoum <vsougoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:53:19 by vsougoum          #+#    #+#             */
/*   Updated: 2025/06/02 10:24:58 by vsougoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	main(__attribute__ ((unused)) int argc, __attribute__ ((unused)) char **argv, __attribute__ ((unused)) char **env)
{
	//int		i;
	t_env *env_copy;

	env_copy = NULL;
//	start_test = NULL;
//	ft_lstadd_back(&start_test, ft_lstnew("re guys"));
	env_copy = ft_copy_env(env);
	ft_print_env(env_copy);
	printf("--------------------------------------------------------------------------------------------------------------------------\n");
	printf("--------------------------------------------------------------------------------------------------------------------------\n");
//	if (ft_export(&env_copy, "asdasdasasdasdasd=") == 1)
//		return (1);
	//ft_print_env(env_copy);
//	if (ft_export(&env_copy, "LOGNAME=AAAA") == 1)
//		return (1);
//	ft_print_env(env_copy);
	printf("--------------------------------------------------------------------------------------------------------------------------\n");
	printf("--------------------------------------------------------------------------------------------------------------------------\n");
//	printf("blasdkasdaskdjkasdjasd\n");
//	printf("%s\n", ft_find_var_env(&env_copy, "USE=")->row);
	ft_unset(&env_copy, "COLORTERM");
//	if (ft_export(&env_copy, "asdasdasasdasdasd={}{}{}{}") == 1)
//		return (1);
	ft_print_env(env_copy);
	ft_free_env(env_copy);
	return (0);
}
