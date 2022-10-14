const fs = require('fs');

function setDate(date) {
    day = date.getDate(); if (day < 10) { day = '0' + day; }
    month = date.getMonth() + 1; if (month < 10) { month = '0' + month; }
    year = date.getFullYear();
    hour = date.getHours(); if (hour < 10) { hour = '0' + hour; }
    minute = date.getMinutes(); if (minute < 10) { minute = '0' + minute; }
    second = date.getSeconds(); if (second < 10) { second = '0' + second; }
    return `${day}-${month}-${year} ${hour}:${minute}:${second}`;
}

class ClassLogger {

    #color = {
        black: '\x1b[30m',
        red: '\x1b[31m',
        green: '\x1b[32m',
        yellow: '\x1b[33m',
        blue: '\x1b[34m',
        magenta: '\x1b[35m',
        cyan: '\x1b[36m',
        white: '\x1b[37m',
        reset: '\x1b[0m'
    }

    #writeLog(logMsg, type = 'log') {
        if (fs.existsSync('log/log.log')) {
            fs.appendFile('log/log.log', logMsg, err => {
                if (err) {
                    console.error(err);
                    return;
                }
            });
        } else {
            fs.mkdir('log', { recursive: true }, (err) => {
                if (err) throw err;
                fs.writeFile('log/log.log', logMsg, err => {
                    if (err) {
                        console.error(err);
                        return;
                    }
                });
            });
        }
        if (fs.existsSync('log/' + type + '.log')) {
            fs.appendFile('log/' + type + '.log', logMsg, err => {
                if (err) {
                    console.error(err);
                    return;
                }
            });
        } else {
            fs.mkdir('log', { recursive: true }, (err) => {
                if (err) throw err;
                fs.writeFile('log/' + type + '.log', logMsg, err => {
                    if (err) {
                        console.error(err);
                        return;
                    }
                });
            });
        }
    }

    #doLog(message, inConsole, type, color, prefix) {
        var date = setDate(new Date());
        const logMsg = date + " | " + prefix + message + '\n';
        this.#writeLog(logMsg, type);
        if (inConsole) {
            var displayMsg = '\x1b[2m' + date + " | " + this.#color.reset + color + prefix + this.#color.reset + message;
            console.log(displayMsg);
        }
    }

    #infoPrefix = '[INFO] ';
    log(message, inConsole = false) {
        this.#doLog(message, inConsole, 'info', this.#color.white, this.#infoPrefix);
    }

    #errorPrefix = '[ERROR] ';
    error(message, inConsole = false) {
        this.#doLog(message, inConsole, 'error', this.#color.red, this.#errorPrefix);
    }

    #warnPrefix = '[WARNING] ';
    warning(message, inConsole = false) {
        this.#doLog(message, inConsole, 'warning', this.#color.yellow, this.#warnPrefix);
    }

    #debugPrefix = '[DEBUG] ';
    debug(message, inConsole = false) {
        this.#doLog(message, inConsole, 'debug', this.#color.green, this.#debugPrefix);
    }
}

module.exports = new ClassLogger();
