#include <unistd.h>
#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv, char **envp) {
    // Récupérer la valeur de la variable PATH
    const char *path = getenv("PATH");

    if (*envp == NULL)
        printf("envp est null");
    // Vérifier si la variable a été trouvée
    if (path) {
        printf("Le PATH est :\n%s\n", path);
    } else {
        printf("La variable PATH n'est pas définie.\n");
    }

    return 0;
}

