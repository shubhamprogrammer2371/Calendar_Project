#include <stdio.h>
#include <stdlib.h>

int geyFirstWeekDay(int year)
{
    int d = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + (year / 400) + 1) % 7;
    return d;
}

int main()
{
    // system("color 3F");
    int year, month, day, daysInMonth, weekDay = 0, startingDay;
    printf("Enter any year : ");
    scanf("%d", &year);

    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int monthDay[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
    {
        monthDay[1] = 29;
    }

    system("cls");

    startingDay = geyFirstWeekDay(year);

    for (month = 0; month < 12; month++)
    {
        daysInMonth = monthDay[month];
        printf("\n\n----------------- %s ----------------", months[month]);
        printf("\n  SUN   MON  TUE  WED  THUR  FRI  SAT\n");

        for (weekDay = 0; weekDay < startingDay; weekDay++)
        {
            printf("     ");
        }
        for (day = 1; day <= daysInMonth; day++)
        {
            printf("%5d", day);

            if (++weekDay > 6)
            {
                printf("\n");
                weekDay = 0;
            }
            startingDay = weekDay;
        }
    }

    return 0;
}