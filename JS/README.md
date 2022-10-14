
# SULogger for JS

In JS we have a single file that contains all the code. This is because we don't have a way to import files in JS. The file is located at `JS/logger.js`.


## Installation

There is 2 ways to install the logger. You can either download the file and include it in your project or you can use npm (not ready yet).

### Download

To dowload the logger you just nedd to download it with :
```bash
git clone git@github.com:ZiplEix/SULogger.git
```
Then copy `SULogger/JS/logger.js` on your project

### Install

>Not implemented yet

```bash
npm install @ZiplEix/SULogger/js
```

## Usage

```js
const Logger = require('path/to/the/logger')

Logger.log('a log message', true);
Logger.debug('a debug message', true);
Logger.warning('a warning message', true);
Logger.error('an error message', true);
```

output :
[IMAGE OF THE OUTPUT AND OF THE TREE ARCHITECTURE]

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

SULogger in JS use all this libraries to work :
- fs (to manage)
