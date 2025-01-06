/*
** EPITECH PROJECT, 2024
** my_time
** File description:
** difftime
*/

#include "my_time.h"

double my_difftime(my_time_t time1, my_time_t time2)
{
    return (double)(time1 - time2);
}
