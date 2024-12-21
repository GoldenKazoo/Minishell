#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t ft_count_space(char *prompt)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (prompt[i] != '\0')
    {
        if (prompt[i+1] && prompt[i-1])
        {
            if (prompt[i] == '|' && prompt[i-1] != ' ' && prompt[i+1] != ' ')
            {
                count = count + 2;
            }
            if (prompt[i] == '<')
            {
                if (prompt[i-1] != ' ' && prompt[i+1] != ' ' && prompt[i+1] != '<')
                {
                    count = count + 2;
                }
                if (prompt[i+1] == '<')
                {
                    count = count + 2;
                    i++;
                }
            }
            if (prompt[i] == '>')
            {
                if (prompt[i-1] != ' ' && prompt[i+1] != ' ' && prompt[i+1] != '>')
                {
                    count = count + 2;
                }
                if (prompt[i+1] == '>')
                {
                    i++;
                }
            }
        }
        i++;
    }
    return (count);
}

char  *ft_insert_space(char *prompt)
{
    int i;
    int j;
    char *new_prompt;

    i = 0;
    j = 0;
    new_prompt = malloc(strlen(prompt) + ft_count_space(prompt));
    while(prompt[j]!='\0')
    {
        if (prompt[j + 1] == '|')
        {
            new_prompt[i] = prompt[j];
            i++;
            new_prompt[i] = ' ';
            i++;
            new_prompt[i] = '|';
            i++;
            new_prompt[i] = ' ';
            j++;
        }
        else if (prompt[j + 1] == '<')
        {
            new_prompt[i] = prompt[j];
            i++;
            new_prompt[i] = ' ';
            i++;
            new_prompt[i] = '<';
            j++;
            if (prompt[j] && prompt[j] == '<')
            {
                i++;
                new_prompt[i] = '<';
                i++;
                new_prompt[i] = ' ';
                j++;
            }
            else
            {
                i++;
                new_prompt[i] = ' ';
            }
        }
        else if (prompt[j + 1] == '>')
        {
            new_prompt[i] = prompt[j];
            i++;
            new_prompt[i] = ' ';
            i++;
            new_prompt[i] = '>';
            j++;
            if (prompt[j] && prompt[j + 1] == '>')
            {
                i++;
                new_prompt[i] = '>';
                i++;
                new_prompt[i] = ' ';
                j++;
            }
            else
            {
                i++;
                new_prompt[i] = ' ';
            }
        }
        else
        {
            new_prompt[i] = prompt[j];
        }
        i++;
        j++;
    }
    new_prompt[i] = '\0';
    return (new_prompt);
}

// int main()
// {
//     char *test = "echo '$aled'|cat grep l<<";
//     char *new_test = ft_insert_space(test);

//     printf("%s\n", test);
//     printf("%s", new_test);
// }