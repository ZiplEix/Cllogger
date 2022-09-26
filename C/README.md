
# SULogger for C

In C SULogger is presented as a static library
which includes several functions and a header file


## Installation

### Download

Before installing  and compiling the library you need to download it.

```bash
git clone git@github.com:ZiplEix/SULogger.git
```

### Compile the library

SULogger is in the form of a static library, it must be compiled. For it :

```bash
cd SULogger/C
sh install.sh
```

The ``install.sh`` script will compile the archive file
and create the ``SULogger`` folder which contains everything you need.
In the include folder you will find the header file
and in the src folder you will find the archive file.

### install the library

>For security reasons it is best to copy paste the archive file and the header file directly into your source code.
>But you can also install the library to facilitate the compilation

```bash
sudo cp SULogger/include/sulogger.h /usr/lib
sudo cp SULogger/src/libsulogger.a /lib64
```

## Usage

```c
#include "sulogger.h"

int main()
{
    logger("an info log");
    logger_warning("a warning log");
    logger_error("an error log");
    logger_debug("an debug log");

    return 0;
}
```

output :
[IMAGE OF THE OUTPUT AND OF THE TREE ARCHITECTURE]

### if you havan't install the lib

```bash
gcc main.c -o test_log -I path/to/the/header/file -Lpath/to/libsulogger.a -lsulogger
```

### if you have install the lib

```bash
gcc main.c -o test_log -lsulogger
```
## Features

- a log in the console
    - date (dd-mm-yyyy) time (hh:mm:ss) [TYPE] log message
- logger folder
    - log.log (all the logs are append here)
    - info.log (all the info log are append here)
    - warning.log (all the warning log are append here)
    - error.log (all the error log are append here)
    - debug.log (all the debug log are append here)


## Tech Stack

SULogger in C use all this libraries to work :
- stdio.h
- stdlib.h
- string.h
- unistd.h
- sys/stat.h
- sys/types.h
- time.h

