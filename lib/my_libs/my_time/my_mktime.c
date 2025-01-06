/*
** EPITECH PROJECT, 2024
** my_time
** File description:
** transform a tm structure into time_t
*/

#include "my_time.h"
#include "private.h"

// tm to epoch goes like this:
// [year corresponds to year - 1900]
//
// seconds + minutes + hours + days this year + [years - 70] +
// leap days these past years - not leap days in centuries
//
// A leap day in a century only happens if the year is multiple of 400
my_time_t my_mktime(struct my_tm *timeptr)
{
    my_time_t final_value = 0;

    final_value = (my_time_t)timeptr->tm_sec
        + (my_time_t)timeptr->tm_min * SEC_IN_MIN
        + (my_time_t)timeptr->tm_hour * SEC_IN_HOUR
        + (my_time_t)timeptr->tm_yday * SEC_IN_DAY
        + (my_time_t)(timeptr->tm_year - 70) * SEC_IN_DAY * DAY_IN_YEAR
        + (my_time_t)((timeptr->tm_year - 69) / 4) * SEC_IN_DAY
        - (my_time_t)((timeptr->tm_year - 1) / 100) * SEC_IN_DAY
        + (my_time_t)((timeptr->tm_year + 299) / 400) * SEC_IN_DAY;
    return final_value;
}
