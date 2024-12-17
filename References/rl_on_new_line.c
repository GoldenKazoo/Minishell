#include <readline/readline.h>

int main()
{
    rl_on_new_line();  // Indiquer qu'une nouvelle ligne commence
    char *input = readline("Entrez quelque chose : ");
    printf("Vous avez entré : %s\n", input);
    free(input);
    return 0;
}
