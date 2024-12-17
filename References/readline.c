#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

int main()
{
    char *input = readline("Entrez quelque chose: ");
    if (input != NULL) {
        printf("Vous avez entré : %s\n", input);
        free(input);
    }
    return 0;
}
