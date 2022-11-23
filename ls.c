#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
void main(int rc, char **b)
{

    struct dirent **list;
    int n;

    if (rc == 1)
    {

        n = scandir(".", &list, NULL, alphasort);
        while (n--)
        {
            if (strcmp(list[n]->d_name, ".") != 0)
            {
                if (strcmp(list[n]->d_name, "..") != 0)
                {
                    printf("%s ", list[n]->d_name);
                }
            }
        }
    }
    else if (strcmp(b[1], "-1") == 0 && b[2] == NULL)
    {
        n = scandir(".", &list, NULL, alphasort);
        while (n--)
        {
            if (strcmp(list[n]->d_name, ".") != 0)
            {
                if (strcmp(list[n]->d_name, "..") != 0)
                {
                    printf("%s\n ", list[n]->d_name);
                }
            }
        }
    }
    else if (strcmp(b[1], "-a") == 0 && b[2] == NULL)
    {
        n = scandir(".", &list, NULL, alphasort);
        while (n--)
        {
            printf("%s ", list[n]->d_name);
        }
    }

    else if (rc < 1)
    {
        exit(1);
    }
    else if (b[2] == NULL)
    {
        n = scandir(b[1], &list, NULL, alphasort);
        while (n--)
        {
            if (strcmp(list[n]->d_name, ".") != 0)
            {
                if (strcmp(list[n]->d_name, "..") != 0)
                {
                    printf("%s ", list[n]->d_name);
                }
            }
        }
    }
    else if (strcmp(b[1], "-1") == 0 && b[2] != NULL)
    {
        n = scandir(b[2], &list, NULL, alphasort);
        while (n--)
        {
            if (strcmp(list[n]->d_name, ".") != 0)
            {
                if (strcmp(list[n]->d_name, "..") != 0)
                {
                    printf("%s\n ", list[n]->d_name);
                }
            }
        }
    }
    else if (strcmp(b[1], "-a") == 0 && b[2] != NULL)
    {
        n = scandir(b[2], &list, NULL, alphasort);
        while (n--)
        {
            printf("%s ", list[n]->d_name);
        }
    }
}