/*
** EPITECH PROJECT, 2024
** my_time
** File description:
** Returns a tm structure with the time in UTC
*/

#include "my_time.h"
#include "private.h"

// Only works for times after epoch
struct my_tm *my_gmtime(const my_time_t *timer)
{
    static struct my_tm gm = {0, 0, 0, 0, 0, 70, 0, 0, 0};
    long remaining = (long)*timer;
    long days = 0;

    days = remaining / SEC_IN_DAY;
    remaining -= days * SEC_IN_DAY;
    for (; days >= DAY_IN_YEAR; gm.tm_year++) {
        days -= DAY_IN_YEAR;
        if ((STD_YEAR(gm.tm_year)) % 4 == 0)
            days--;
        if (STD_YEAR(gm.tm_year) % 100 == 0 && STD_YEAR(gm.tm_year) % 400 != 0)
            days++;
    }
    gm.tm_yday = (int)days;
    gm.tm_hour = (int)remaining / 3600;
    gm.tm_min = (int)(remaining - gm.tm_hour * 3600) / 60;
    gm.tm_sec = (int)(remaining - gm.tm_min * 60 - gm.tm_hour * 3600) % 60;
    return &gm;
}
