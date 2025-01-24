# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

int main()
{
    char *input;
    while (1)
    {
        input = readline("Entrez un truc :");
        add_history(input);
    }
}