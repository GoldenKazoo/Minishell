#include <readline/readline.h>
#include <readline/history.h>

int main()
{
    char *input = readline("Entrez quelque chose : ");
    add_history(input);  // Ajoute à l'historique
    printf("Historique ajouté.\n");
    free(input);
    return 0;
}