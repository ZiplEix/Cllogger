/*
** EPITECH PROJECT, 2022
** Clogger [WSL : Ubuntu]
** File description:
** logger_reset
*/
#include "clogger.h"

int logger_reset(log_type type)
{
    if (access("log/", F_OK) == -1) {
        mkdir("log/", 0777);
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
}