#ifndef _WIKICTL_PARSING_H
#define _WIKICTL_PARSING_H

#include <wikictl.h>
#include <getopt.h>

void parsing_parameters(int argc, char *argv[], const char *optString, struct option *long_options, parameters_t *params);

#endif