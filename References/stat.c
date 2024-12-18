#include <sys/stat.h>
#include <stdio.h>

int main()
{
    struct stat buf;
    if (stat("fichier.txt", &buf) == 0) {
        printf("Taille du fichier : %ld\n", buf.st_size);
    }
    return 0;
}