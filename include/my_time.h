/*
** EPITECH PROJECT, 2024
** my_time
** File description:
** Main header for the time functions
*/

#ifndef MY_NULL_H_
    #define MY_NULL_H_

    #define MY_NULL ((void *)0)

#endif /* MY_NULL_H_ */

#ifndef MY_SIZE_T_H_
    #define MY_SIZE_T_H_

typedef unsigned long my_size_t;

#endif /* MY_SIZE_T_H_ */

#ifndef MY_TIME_T_H_
    #define MY_TIME_T_H_

typedef unsigned long my_time_t;

#endif /* MY_TIME_T_H_ */

#ifndef MY_CLOCK_T_H_
    #define MY_CLOCK_T_H_

typedef unsigned long my_clock_t;

#endif /* MY_CLOCK_T_H_ */

#ifndef MY_WCHAR_T_H_
    #define MY_WCHAR_T_H_

typedef unsigned int my_wchar_t;

#endif /* MY_WCHAR_T_H_ */

#ifndef MY_TIME_H_
    #define MY_TIME_H_

struct my_tm {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
};

char *my_asctime(const struct my_tm *timeptr);
my_clock_t my_clock(void);
char *my_ctime(const my_time_t *timer);
double my_difftime(my_time_t time1, my_time_t time2);
struct my_tm *my_gmtime(const my_time_t *timer);
struct my_tm *my_localtime(const my_time_t *timer);
my_time_t my_mktime(struct my_tm *timeptr);
my_size_t my_strftime(char *str, my_size_t maxsize, const char *format,
    const struct my_tm *timeptr);
my_time_t my_time(my_time_t *timer);
my_size_t my_wcsftime(my_wchar_t *s, my_size_t maxsize,
    const my_wchar_t *format, const struct my_tm *tp);

#endif /* MY_TIME_H_ */
