#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

int main()
{
    // Lire une ligne et l'ajouter à l'historique
    char *input = readline("Entrez une commande : ");
    add_history(input);
    
    // Effacer l'historique
    rl_clear_history();
    
    free(input);
    return 0;
}
