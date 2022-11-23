#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void rm_file(char filename[])
{

    if (unlink(filename) != 0)
    {
        perror(" Error ");
        return;
    }
}

void rm_directory(char filename[])
{

    if (rmdir(filename) != 0)
    {
        perror(" Error ");
        return;
    }
}

void rm_file_v(char filename[])
{

    if (unlink(filename) != 0)
    {
        perror(" Error ");
        return;
    }
    else
    {
        printf("removed '%s' \n", filename);
    }
}

int main(int argc, char **argv)
{

    if (argc == 3)
    {
        rm_file(argv[2]);
    }
    else if (argc == 4)
    {
        char *tok = argv[2];
        if (tok[0] == '-')
        {
            if (strcmp(tok, "-d") == 0)
            {
                rm_directory(argv[3]);
            }
            else if (strcmp(tok, "-v") == 0)
            {
                rm_file_v(argv[3]);
            }
            else
            {
                printf("Invalid input taken -- %s \n", tok);
            }
        }
        else
        {
            printf("Invalid input taken -- %s \n", tok);
        }
    }
    else
    {
        printf("Invalid input taken ");
    }
    return 0;
}