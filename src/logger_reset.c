/*
** CLlogger project
** a lite logger for C project
** File description:
** logger_reset
*/
#include "cllogger.h"

int logger_reset(log_type type)
{
    if (access("log/", F_OK) == -1) {
        return 0;
    }
    switch (type) {
        case INFO:
            remove("log/info");
            break;
        case WARNING:
            remove("log/warning");
            break;
        case ERROR:
            remove("log/error");
            break;
        case DEBUG:
            remove("log/debug");
            break;
        case LOG:
            remove("log/log");
            break;
        case ALL:
            remove("log/info");
            remove("log/warning");
            remove("log/error");
            remove("log/debug");
            remove("log/log");
            remove("log/");
            break;
    }
    return 0;
}