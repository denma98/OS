#include <stdio.h>
#include <time.h>
#include <string.h>
#include <errno.h>
// hello
// hello
void print_date()
{
    time_t t = time(NULL);
    if (t == -1)
    {
        perror(" Error ");
        return;
    }

    struct tm *pres;
    pres = localtime(&t);
    if (pres == NULL)
    {
        perror(" Error ");
        return;
    }

    char day[10], month[10], tm[20], zone[10];

    strftime(day, 10, "%A", pres);
    strftime(month, 10, "%B", pres);
    strftime(tm, 20, "%r", pres);
    strftime(zone, 10, "%Z", pres);
    //  %02d converts 5 -> 05 and 22 ->22 : just add 0 to numbers < 10

    printf("%s %02d %s %d %s %s \n", day, pres->tm_mday, month, pres->tm_year + 1900, tm, zone);

    return;
}

void print_date_u()
{
    time_t t = time(NULL);
    if (t == -1)
    {
        perror(" Error ");
        return;
    }

    struct tm *ptm;
    char buf1[4], buf2[4], buf3[6];
    ptm = gmtime(&t);
    if (ptm == NULL)
    {
        perror("Error is");
        return;
    }
    strftime(buf1, 4, "%a", ptm);
    strftime(buf2, 4, "%b", ptm);
    strftime(buf3, 6, "%z", ptm);
    printf("%s %s %02d %02d:%02d:%02d UTC %d\n", buf1, buf2, ptm->tm_mday, ptm->tm_hour, ptm->tm_min, ptm->tm_sec, ptm->tm_year + 1900);
}

void print_date_r()
{
    time_t t = time(NULL);
    if (t == -1)
    {
        perror(" Error ");
        return;
    }

    struct tm *pres;
    pres = localtime(&t);
    if (pres == NULL)
    {
        perror(" Error ");
        return;
    }

    char day[10], month[10], tm[20], zone[10];
    strftime(day, 10, "%a", pres);
    strftime(month, 10, "%b", pres);
    strftime(tm, 20, "%X", pres);
    strftime(zone, 10, "%z", pres);
    //  %02d converts 5 -> 05 and 22 ->22 : just add 0 to numbers < 10

    printf("%s, %02d %s %d %s %s \n", day, pres->tm_mday, month, pres->tm_year + 1900, tm, zone);

    return;
}

int main(int argc, char **argv)
{

    if (argc == 2)
    {
        print_date();
    }
    else if (argc == 3)
    {
        char *temp = argv[2];
        if (temp[0] == '-')
        {
            if (strcmp(temp, "-U") == 0)
            {
                print_date_u();
            }
            else if (strcmp(temp, "-R") == 0)
            {
                print_date_r();
            }
            else
            {
                printf("Invalid Input -- %s \n", temp);
            }
        }
        else
        {
            printf("Invalid Input -- %s \n", temp);
        }
    }
    else
    {
        printf("Invalid Input");
    }

    return 0;
}