#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include <unistd.h>
void fill_time(char *, int);
void fill_date(char *);
int input_format();
void clr_scr();
int main()
{
    char time[100], date[100];
    int format = input_format();

    while(1)
    {
    fill_time(time, format);
    fill_date(date);
    clr_scr();
    printf("\nCurrent Time: %s", time);
    printf("\nDate: %s", date);
    sleep(1);//sleep for 1 second
    }
    
    return 0;
}

int input_format()
{
    int format;
    printf("\nChoose the formate: ");
    printf("\n1. 24 Hour Formate");
    printf("\n2. 12 Hour Formate");
    printf("\nMake a choice(1/2): ");
    scanf("%d", &format);
    return format;
}
void fill_time(char *buffer, int format)
{
    time_t raw_time;
    struct tm *current_time;

    time(&raw_time);
    current_time = localtime(&raw_time);
    if (format == 1)
    {
        strftime(buffer, 100, "%H:%M:%S ", current_time);
    }
    else
    {
        strftime(buffer, 100, "%I:%M:%S %p", current_time);
    }
}
void fill_date(char *buffer)
{
    time_t raw_time;
    struct tm *current_time;

    time(&raw_time);
    current_time = localtime(&raw_time);
    strftime(buffer, 100, "%A %B %d %Y", current_time);
}
void clr_scr()
{  
    #ifdef _WIN32
     system("cls");
     #else
     system("clear");
     #endif
}