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

    #infoPrefix = '[INFO] ';
    log(message, inConsole = false) {
        var date = setDate(new Date());
        const logMsg = date + " | " + this.#infoPrefix + message + '\n';
        this.#writeLog(logMsg, 'info');
        if (inConsole) {
            var displayMsg = '\x1b[2m' + date + " | " + '\x1b[0' + '\x1b[37m' + this.#infoPrefix + '\x1b[0m' + message;
            console.log(displayMsg);
        }
    }

    #errorPrefix = '[ERROR] ';
    error(message, inConsole = false) {
        var date = setDate(new Date());
        const logMsg = date + " | " + this.#errorPrefix + message + '\n';
        this.#writeLog(logMsg, 'error');
        if (inConsole) {
            var displayMsg = '\x1b[2m' + date + " | " + '\x1b[0' + '\x1b[91m' + this.#errorPrefix + '\x1b[0m' + message;
            console.log(displayMsg);
        }
    }

    #warnPrefix = '[WARNING] ';
    warning(message, inConsole = false) {
        var date = setDate(new Date());
        const logMsg = date + " | " + this.#warnPrefix + message + '\n';
        this.#writeLog(logMsg, 'warning');
        if (inConsole) {
            var displayMsg = '\x1b[2m' + date + " | " + '\x1b[0' + '\x1b[33m' + this.#warnPrefix + '\x1b[0m' + message;
            console.log(displayMsg);
        }
    }

    #debugPrefix = '[DEBUG] ';
    debug(message, inConsole = false) {
        var date = setDate(new Date());
        const logMsg = date + " | " + this.#debugPrefix + message + '\n';
        this.#writeLog(logMsg, 'debug');
        if (inConsole) {
            var displayMsg = '\x1b[2m' + date + " | " + '\x1b[0' + '\x1b[32m' + this.#debugPrefix + '\x1b[0m' + message;
            console.log(displayMsg);
        }
    }
}

module.exports = new ClassLogger();
