
#pragma once

#include <ctype.h>
#include <stdio.h>
#include <string.h>

enum AppLogLevel {
    APP_LOG_ERROR,
    APP_LOG_WARNING,
    APP_LOG_INFO,
    APP_LOG_DEBUG
};

const char * LogLevelStrings[] = {
    "ERROR: APP",
    "WARNING: APP",
    "INFO: APP",
    "DEBUG: APP"
};

const size_t APP_LOG_LEN = 255;

extern enum AppLogLevel VERBOSITY;

/// Print a logging message
void log_message(const char* message, const enum AppLogLevel level)
{
    /* Quick skip for messages not meeting VERBOSITY level */
    if (level > VERBOSITY) return;

    const size_t message_len = strnlen(message, APP_LOG_LEN);
    const size_t message_len_total = message_len + 25;
    const char* level_string = LogLevelStrings[level];
    char message_buffer[message_len_total];

    /* Generate full message */
    snprintf(message_buffer, message_len_total, "%s: %s\n", level_string, message);

    if (level == APP_LOG_ERROR) fprintf(stderr, message_buffer);
    else fprintf(stdout, message_buffer);
}
