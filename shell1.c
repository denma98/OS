#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
// #include <pwd.h>
#include <errno.h>
#include <sys/wait.h>
// hello mai hu insaan
char **many_tokens;
char **arg;
int line_next = 0;
int counter = 0;

char all_commands[10][10] = {"cd", "pwd", "exit", "ls", "cat", "date", "rm", "mkdir"}; //  0 1 2 3 4 5 6 7

void breakToSmaller(char *input)
{

    char *token = strtok(input, " \n");
    many_tokens[0] = token;
    int i = 0;
    while (token != NULL)
    {
        token = strtok(NULL, " \n");
        // printf("%s", token);
        many_tokens[i + 1] = token;
        i++;
    }
}

// void cd_L(char **input)
// {

//     char temp[1000];

//     if (input[2] != NULL)
//     {
//         strcpy(temp, input[2]);
//     }
// }

void cd(char **input)
{
    int a1 = 69;
    int a2 = 69;
    int a3 = 69; // check

    char cwd_arr[1000];

    if (input[1] != NULL)
    {

        strcpy(cwd_arr, input[1]);

        a1 = strcmp(cwd_arr, "-L");
        a2 = strcmp(cwd_arr, "-P");
        a3 = strcmp(cwd_arr, "..");
    }

    if (a1 == 0)
    {
        if (input[2] != NULL)
        {
            strcpy(cwd_arr, input[2]);
            char *tok = strtok(cwd_arr, " \n");
            int id = chdir(tok);

            if (id != 0)
            {
                perror("Error in -L ");
            }
            else
            {
                char cwd[200];
                char *cwd1 = getcwd(cwd, sizeof(cwd));
                printf("%s", cwd1);
            }
        }
        else
        {
            int val = chdir(getenv("HOME"));

            if (val != 0)
            {
                perror("Error in command -");
            }
            else
            {
                char cwd[200];
                char *cwd1 = getcwd(cwd, sizeof(cwd));
                printf("%s", cwd1);
            }
        }
    }

    else if (a2 == 0)
    {

        if (input[2] != NULL)
        {
            char cwd_new[1000];
            strcpy(cwd_new, input[2]);
            char *tok = strtok(cwd_new, " \n");

            char buf[1000];
            char *res = realpath(tok, buf);

            if (!res)
            {
                perror("realpath Error ");
            }
            else
            {
                int val2 = chdir(buf);
                printf("source directory : %s\n", buf);

                if (val2 != 0)
                {
                    perror("Error in command - ");
                }
                else
                {
                    char cwd5[200];
                    char *cwd6 = getcwd(cwd5, sizeof(cwd5));
                }
            }
        }

        else
        {
            int val = chdir(getenv("HOME"));

            if (val != 0)
            {
                perror("Error in command - ");
            }
            else
            {
                char cwd4[200];
                char *cwd6 = getcwd(cwd4, sizeof(cwd4));
                printf("%s", cwd6);
            }
        }
    }
    else if (a3 == 0)
    {

        int flag3 = chdir("..");
        if (flag3 != 0)
        {
            perror("Error in command - ");
        }
        else
        {
            char cwd9[200];
            char *cwd32 = getcwd(cwd9, sizeof(cwd9));
            printf("%s", cwd32);
        }
    }

    else
    {

        char *tk = strtok(cwd_arr, "\n");
        int val3 = chdir(tk);

        if (val3 != 0)
        {
            printf("Error in command -");
        }
        else
        {
            char cwd7[100];
            char *cwd8 = getcwd(cwd7, sizeof(cwd7));
            printf("%s", cwd8);
        }
    }
}

void echo(char **input)
{
    char temp[10];
    int f1 = 69;
    int f2 = 69;
    // int f3 = 69;
    char *p = input[1];
    if (p != NULL)
    {

        strcpy(temp, p);

        f1 = strcmp(p, "-e");
        f2 = strcmp(p, "-n");
        // f3 = strcmp(p, "--help");
    }
    else
    {
        printf("\n");
        return;
    }

    if (f1 == 0)
    {

        int i = 2;

        while (i < sizeof(input))
        {
            // int pp = 0;
            if (input[i] != NULL)
            {
                for (int j = 0; j < strlen(input[i]); j++)
                {

                    if (input[i][j] == '/')
                    {

                        continue;
                    }
                    else
                    {
                        printf("%c", input[i][j]);
                    }
                }
                printf(" ");
                // printf("%s", input[i]);
            }
            i++;
        }
        printf("\n");
    }

    else if (f2 == 0)
    {

        int i = 2;

        while (i < sizeof(input))
        {
            if (input[i] != NULL)
            {
                printf("%s", input[i]);
            }
            i++;
        }
    }
    else
    {
        int i = 1;
        while (i < sizeof(input))
        {
            if (input[i] != NULL)
            {
                printf("%s", input[i]);
            }
            i++;
        }
        printf("\n");
    }
}

void pwd(char **input)
{
    int check = 0;
    char temp[10];
    int f1 = 69;
    int f2 = 69;

    char arr[1000];
    // int f3 = 69;
    char *p = input[1];

    if (p != NULL)
    {
        strcpy(temp, p);
        check = 1;
    }
    // char *add1 = getc
    char *add = getcwd(arr, sizeof(arr));

    if (add == NULL)
    {

        perror("Error");
    }
    else
    {
        if (check == 1)
        {
            f1 = strcmp(p, "-p");
            f2 = strcmp(p, "-l");

            if (f1 == 0)
            {
                char *cnew = getcwd(arr, sizeof(arr));
                printf("%s", cnew);
            }

            else if (f2 == 0)
            {
                char *result = realpath(arr, arr);
                char *cnew = getcwd(arr, sizeof(arr));
                printf("%s", cnew);
            }
        }
        else
        {
            printf("%s", add);
        }
    }
}
//
void make_fork(char *name)
{

    arg[0] = name;
    for (int i = 0; i < sizeof(many_tokens); i++)
    {
        // printf("hello\n");
        arg[i + 1] = many_tokens[i];
    }
    pid_t pid = fork();
    if (pid == 0)
    {
        int v = execv(name, arg);
        if (v == -1)
        {
            perror("Error");
        }
    }
    else
    {
        wait(NULL);
    }
    return;
}

int main()
{
    char *line = NULL; 
    size_t s = 0;

    many_tokens = (char **)(malloc(sizeof(char *) * 1000));
    arg = (char **)(malloc(sizeof(char *) * 1000));

    while (2)
    {

        printf("##");
        getline(&line, &s, stdin);

        breakToSmaller(line);
        // printf("%s", many_tokens[0]);
        // printf("%s", many_tokens[1]);
        // printf("%s", line);

        if (strcmp(many_tokens[0], "echo") == 0)
        {
            echo(many_tokens);
        }

        if (strcmp(many_tokens[0], "pwd") == 0)
        {
            pwd(many_tokens);
        }

        if (strcmp(many_tokens[0], "cd") == 0)
        {
            cd(many_tokens);
        }

        if (strcmp(many_tokens[0], "mkdir") == 0)
        {
            make_fork("./mkdir");
        }
        if (strcmp(many_tokens[0], "date") == 0)
        {
            make_fork("./date");
        }

        if (strcmp(many_tokens[0], "rm") == 0)
        {
            make_fork("./rm");
        }
    }

    return 0;
}
