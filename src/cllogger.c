/*
** CLlogger project
** a lite logger for C project
** File description:
** clogger
*/
#include "cllogger.h"

int logger(char *log)
{
    if (access("log/", F_OK) == -1) {
        mkdir("log/", 0777);
    }
    write_log("log/info.log", INFO, log);
}

int logger_warning(char *log)
{
    if (access("log/", F_OK) == -1) {
        mkdir("log/", 0777);
    }
    write_log("log/warning.log", WARNING, log);
}

int logger_error(char *log)
{
    if (access("log/", F_OK) == -1) {
        mkdir("log/", 0777);
    }
    write_log("log/error.log", ERROR, log);
}

int logger_debug(char *log)
{
    if (access("log/", F_OK) == -1) {
        mkdir("log/", 0777);
    }
    write_log("log/debug.log", DEBUG, log);
}

// int logger_log(char *log, char *type)
// {
//     if (access("log/", F_OK) == -1) {
//         mkdir("log/", 0777);
//     }
//     char *path = malloc(sizeof(char) * (strlen("log/") + strlen(type) + 1));
//     strcpy(path, "log/");
//     strcat(path, type);
//     write_log(path, LOG, log);
//     free(path);
// }
