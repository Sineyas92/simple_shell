#ifndef MINISHELL_H
#define MINISHELL_H

#include <stddef.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include "typedefs.h"
#include "constants.h"

/* Global program name and aliases linked list */
extern char *name;
extern alias_t *aliases;

/* Global environment */
extern char **environ;

/* Signals and processes */
void signal_handler(int);

/* Helpers for user inputs */
char *get_user_input();

/* Helpers for error handling */
/* 0: readline_error */
void readline_error(void);

/* Array of error handling functions */
extern void (*handle_error[])(void);

#endif /* MINISHELL_H */

