#include <readline/readline.h>

int main()
{
    char *input = readline("Entrez quelque chose : ");
    rl_replace_line("Texte remplacé", 0);  // Remplacer la ligne sans ajouter à l'historique
    printf("Ligne remplacée\n%s", input);
    free(input);
    return 0;
}
