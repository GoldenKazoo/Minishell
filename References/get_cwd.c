#include <unistd.h>
#include <stdio.h>

int main()
{
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Répertoire actuel : %s\n", cwd);
    }
    return 0;
}
