#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "tokenizer.h"

void	ft_print_status(bool status)
{
	if (status)
		printf("Syntax OK\n");
	else
		printf("Syntax Error: Unmatched quote\n");
}

void	print_command_list(t_command *cmds)
{
	int i = 0;
	int cmd_num = 1;

	while (cmds)
	{
		printf("=== Skill Issue summon the Commande #%d ===\n", cmd_num);

		// affich argv
		printf("argv: ");
		if (cmds->argv)
		{
			while (cmds->argv[i])
			{
				printf("\"%s\" ", cmds->argv[i]);
				i++;
			}
		}
		else
		{
			printf("(null)");
		}
		printf("\n");

		// Redir
		if (cmds->infile)
			printf("infile: \"%s\"\n", cmds->infile);
		if (cmds->outfile)
			printf("outfile: \"%s\"\n", cmds->outfile);
		if (cmds->heredoc_delim)
			printf("heredoc_delim: \"%s\"\n", cmds->heredoc_delim);
		if (cmds->outfile)
			printf("append : %s\n", cmds->append ? "true" : "false");

		// next
		printf("\n");
		cmds = cmds->next;
		cmd_num++;
		i = 0;
	}
}