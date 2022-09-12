/*
** CLlogger project
** Clogger [WSL : Ubuntu]
** File description:
** clogger
*/
#include "cllogger.h"

int logger(char *log)
{
    if (access("log/", F_OK) == -1) {
        mkdir("log/", 0777);
    }
    write_log("log/info", INFO, log);
}

int logger_warning(char *log)
{
    if (access("log/", F_OK) == -1) {
        mkdir("log/", 0777);
    }
    write_log("log/warning", WARNING, log);
}

int logger_error(char *log)
{
    if (access("log/", F_OK) == -1) {
        mkdir("log/", 0777);
    }
    write_log("log/error", ERROR, log);
}

int logger_debug(char *log)
{
    if (access("log/", F_OK) == -1) {
        mkdir("log/", 0777);
    }
    write_log("log/debug", DEBUG, log);
}

int logger_log(char *log, char *type)
{
    if (access("log/", F_OK) == -1) {
        mkdir("log/", 0777);
    }
    char *path = malloc(sizeof(char) * (strlen("log/") + strlen(type) + 1));
    strcpy(path, "log/");
    strcat(path, type);
    write_log(path, LOG, log);
    free(path);
}
