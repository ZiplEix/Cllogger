/*
** CLlogger project
** a lite logger for C project
** File description:
** main
*/
#include "cllogger.h"

int main(int argc, char const *argv[])
{
    logger("une info");
    logger_warning("un warning");
    logger_error("une erreur");
    logger_debug("un debug");
    return 0;
}
