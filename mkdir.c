#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void makeDir(char file[1000])
{

    int flag = mkdir(file, 0777);
    if (flag < 0)
    {
        perror(file);
        return;
    }
}

void mkdir_ver()
{
    printf("mkdir (GNU coreutils) 8.32 \nCopyright (C) 2020 Free Software Foundation, Inc. \nLicense GPLv3+: GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>. \nThis is free software: you are free to change and redistribute it. \nThere is NO WARRANTY, to the extent permitted by law. \nWritten by David MacKenzie.\n");
}

void makeDir_V(char file[1000])
{

    int flag = mkdir(file, 0777);
    if (flag < 0)
    {
        perror(file);
        return;
    }
    else
    {

        printf("mdkrir: created directory of address: '%s' ", file);
    }
}

void makeDir_M(char file[1000])
{

    int flag = mkdir(file, 0777);
    if (flag < 0)
    {
        perror(file);
        return;
    }
}
// ./mkdir mkdir command
//  agrc == number

int main(int argc, char *argv[])
{

    if (argc == 3)
    {
        if (strcmp(argv[2], "--version") == 0)
        {

            printf("\n");
            // call
            mkdir_ver();
        }
        else
        {
            mkdir(argv[2], 0777);
        }
    }

    else if (argc == 4)
    {
        char *val = argv[2];

        if (val[0] == '-')
        {

            if (strcmp(val, "-v") == 0)
            {
                makeDir_V(argv[3]);
            }
            else if (strcmp(val, "-m") == 0)
            {
                makeDir_M(argv[3]);
            }
            else
            {
                printf("Invalid input -- '%s'", val);
            }
        }
    }
    else
    {
        printf("invalid input ");
    }
    return 0;
}