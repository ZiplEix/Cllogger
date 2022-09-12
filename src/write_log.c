/*
** CLlogger project
** Clogger [WSL : Ubuntu]
** File description:
** write_log
*/
#include "cllogger.h"

char *get_actual_time(void)
{
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char *s = malloc(sizeof(char) * 100);

    strftime(s, 100, "%d/%m/%Y %H:%M:%S", tm);
    return s;
}

char *define_type(log_type type)
{
    switch (type) {
        case INFO:
            return "INFO";
        case WARNING:
            return "WARNING";
        case ERROR:
            return "ERROR";
        case DEBUG:
            return "DEBUG";
        case LOG:
            return "LOG";
        default:
            return "INFO";
    }
}

int display_log(char *now, char *type, char *log)
{
    printf("\e[2m");
    printf("%s : ", now);
    printf("\e[0m");
    if (strcmp(type, "INFO") == 0) {
        printf("\e[37m");
    } else if (strcmp(type, "WARNING") == 0) {
        printf("\e[33m");
    } else if (strcmp(type, "ERROR") == 0) {
        printf("\e[31m");
    } else if (strcmp(type, "DEBUG") == 0) {
        printf("\e[32m");
    } else {
        printf("\e[35m");
    }
    printf("%s %s %s %s\n", "[", type, "]", log);
    printf("\e[0m");
}

int write_log(char *file_name, log_type log_type, char *log)
{
    char *now = get_actual_time();
    char *type = define_type(log_type);

    FILE *file = fopen(file_name, "a");
    if (file == NULL)
        return 84;
    fprintf(file, "%s : %s %s %s %s\n", now, "[", type, "]", log);
    fclose(file);

    // display in the generic log file
    file = fopen("log/log", "a");
    if (file == NULL)
        return 84;
    fprintf(file, "%s : %s %s %s %s\n", now, "[", type, "]", log);
    fclose(file);

    // display in the console
    display_log(now, type, log);
    free(now);
    return 0;
}
