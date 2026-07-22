#pragma once

typedef long long time_t;

struct tm {
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

static __inline time_t time(time_t *t) { if (t) *t = 0; return 0; }
static __inline struct tm *localtime(const time_t *t) { (void)t; return (struct tm *)0; }
static __inline struct tm *gmtime(const time_t *t) { (void)t; return (struct tm *)0; }
