/*
** SULogger project
** a lite logger for C project
** File description:
** clogger
*/
#include "sulogger.h"

int logger(char *log)
{
    if (access("log/", F_OK) == -1) {
        mkdir("log/", 0777);
    }
    write_log("log/info.log", INFO, log);
    return 0;
}

int logger_warning(char *log)
{
    if (access("log/", F_OK) == -1) {
        mkdir("log/", 0777);
    }
    write_log("log/warning.log", WARNING, log);
    return 0;
}

int logger_error(char *log)
{
    if (access("log/", F_OK) == -1) {
        mkdir("log/", 0777);
    }
    write_log("log/error.log", ERROR, log);
    return 0;
}

int logger_debug(char *log)
{
    if (access("log/", F_OK) == -1) {
        mkdir("log/", 0777);
    }
    write_log("log/debug.log", DEBUG, log);
    return 0;
}
