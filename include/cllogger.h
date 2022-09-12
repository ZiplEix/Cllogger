/*
** CLlogger project
** Clogger [WSL : Ubuntu]
** File description:
** clogger
*/

#ifndef CLOGGER_H_
    #define CLOGGER_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <time.h>

    typedef enum {
        INFO,
        WARNING,
        ERROR,
        DEBUG,
        LOG,
        ALL
    } log_type;

    int write_log(char *file_name, log_type log_type, char *log);
    int logger(char *log);
    int logger_warning(char *log);
    int logger_error(char *log);
    int logger_debug(char *log);
    int logger_log(char *log, char *type);
    int logger_reset(log_type type);

#endif /* !CLOGGER_H_ */
