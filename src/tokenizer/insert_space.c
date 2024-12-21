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
            if (prompt[i] == '<' && prompt[i-1] != ' ' && prompt[i+1] != ' ')
            {
                count = count + 2;
                if (prompt[i+1] == '<')
                    i++;
            }
            if (prompt[i] == '>' && prompt[i-1] != ' ' && prompt[i+1] != ' ')
            {
                count = count + 2;
                if (prompt[i+1] == '>')
                    i++;
            }
        }
        i++;
    }
    return (count);
}

int ft_pipe_case(char *prompt, char *new_prompt, int *i, int *j, int state)
{
    if (!prompt || !new_prompt || !i || !j)
        return (0);
    if (prompt[*j + 1] == '|')
    {
        state = 1;
        new_prompt[*i] = prompt[*j];
        (*i)++;
        new_prompt[*i] = ' ';
        (*i)++;
        new_prompt[*i] = '|';
        (*i)++;
        new_prompt[*i] = ' ';
        (*j)++;
    }
    return (state);
}

int   ft_right_redir_case(char *prompt, char *new_prompt, int *i, int *j, int state)
{
    if (!prompt || !new_prompt || !i || !j)
        return (0);
    if (prompt[*j + 1] == '<')
    {
        state = 1;
        new_prompt[*i] = prompt[*j];
        (*i)++;
        new_prompt[*i] = ' ';
        (*i)++;
        new_prompt[*i] = '<';
        (*j)++;
        if (prompt[*j+1] && prompt[*j+1] == '<')
        {
            (*i)++;
            new_prompt[*i] = '<';
            (*i)++;
            new_prompt[*i] = ' ';
            (*j)++;
        }
        else
        {
            (*i)++;
            new_prompt[*i] = ' ';
        }
    }
    return (state);
}

int    ft_left_redir_case(char *prompt, char *new_prompt, int *i, int *j, int state)
{
    if (!prompt || !new_prompt || !i || !j)
        return (0);
    if (prompt[*j + 1] == '>')
    {
        state = 1;
        new_prompt[*i] = prompt[*j];
        (*i)++;
        new_prompt[*i] = ' ';
        (*i)++;
        new_prompt[*i] = '>';
        (*j)++;
        if (prompt[*j+1] && prompt[*j+1] == '>')
        {
            (*i)++;
            new_prompt[*i] = '>';
            (*i)++;
            new_prompt[*i] = ' ';
            (*j)++;
        }
        else
        {
            (*i)++;
            new_prompt[*i] = ' ';
        }
    }
    return (state);
}
char  *ft_insert_space(char *prompt)
{
    int i;
    int j;
    int state;
    char check1;
    char check2;
    char check3;
    char *new_prompt;

    i = 0;
    j = 0;
    new_prompt = malloc(strlen(prompt) + ft_count_space(prompt) + 10);
    while(prompt[j]!='\0')
    {
        check1 = prompt[j];
        check3 = new_prompt[i];
        state = 0;
        state = ft_pipe_case(prompt, new_prompt, &i, &j, state);
        state = ft_right_redir_case(prompt, new_prompt, &i, &j, state);
        state = ft_left_redir_case(prompt, new_prompt, &i, &j, state);
        if (state == 0)
        {
            new_prompt[i] = prompt[j];
        }
        check3 = new_prompt[i];
        i++;
        j++;
    }
    new_prompt[i] = '\0';
    return (new_prompt);
}

// int main()
// {
//     char *test = "l<outgile";
//     printf("%zu\n", ft_count_space(test));
//     char *new_test = ft_insert_space(test);

//     printf("%s", new_test);
// }