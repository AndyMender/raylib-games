
#pragma once

#include <getopt.h>
#include <stdio.h>
#include <unistd.h>

#include "../common.hpp"

/* Set verbosity limits */
enum AppLogLevel VERBOSITY = APP_LOG_ERROR;
const enum AppLogLevel VERBOSITY_MIN = APP_LOG_ERROR;
const enum AppLogLevel VERBOSITY_MAX = APP_LOG_DEBUG;

/// Print a help text for app usage
void usage()
{
    printf("Usage: wallbreaker [option]\n");
    printf("-h - print this help text\n");
    printf("-v <value> - set verbosity level [0-3]. Default: 0\n");
}

enum CmdlineCode {
    CMDLINE_SUCCESS,
    CMDLINE_HELP,
    CMDLINE_ERROR
};

/// Use 'getopt' to process command-line arguments
enum CmdlineCode process_cmdline_args(const int argc, char *const *argv)
{
    char choice, *input_endptr;
    long input_value;
    /* default exit is SUCCESS - change only when needed */
    enum CmdlineCode exit_code = CMDLINE_SUCCESS;

    while ( (choice = getopt(argc, argv, "v:h")) != -1 )
    {
        switch(choice) {
            case 'v':
                input_value = strtol(optarg, &input_endptr, 10);

                /* No numeric input value found */
                if (input_endptr == optarg) {
                    log_message("Verbosity level value has to be an integer!", APP_LOG_ERROR);
                    exit_code = CMDLINE_ERROR;
                } 
                /* Allowed VERBOSITY range exceeded */
                else if ( (input_value > VERBOSITY_MAX) || (input_value < VERBOSITY_MIN) )
                {
                    log_message("Verbosity level value out of range! [0-4]", APP_LOG_ERROR);
                    exit_code = CMDLINE_ERROR;
                }
                VERBOSITY = (enum AppLogLevel) input_value;
                break;
            case 'h':
                usage();
                exit_code = CMDLINE_HELP;
                break;
            default:
                usage();
                exit_code = CMDLINE_ERROR;
        }
    }

    return exit_code;
}
