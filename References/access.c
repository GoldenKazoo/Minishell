#include <unistd.h>
#include <stdio.h>

int main()
{
    if (access("fichier.txt", F_OK) == 0) {
        printf("Le fichier existe\n");
    } else {
        printf("Le fichier n'existe pas\n");
    }
    return 0;
}
