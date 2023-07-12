#ifndef MAIN_H
#define MAIN_H

//--------- <libraries>------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>

/**
 *struct list_path- linked list containing path directories
 *@dir - name of the directory
 *@node - pointer to the node 
 */
typedef struct list_path
{
	char *dir;
	struct list_path *next_node;
}list_path;

/**
 *struct built_in - struct to the built in commands and the corresponding function  
 *@name - built in command 
 *@func - corresponding function 
 */
typedef struct built_in
{
	char *name;
	void (*func)(char **);
}built_in;

/* -------------------<functions>--------------------- */

void _isatty();
void sig_handler(int sig);
ssize_t _getline(char **line_ptr, size_t *n, FILE *stream);
char **string_parse(char *str);
void execute(char **command);
int _puts(char *str);
void free_list(list_path *head);

/* -------------------< functions in directories_list.c >--------------------- */

extern char **environ;
list_path *add_node_end(list_path **head, const char *str);
char *_strdup(const char *str);
void free_list(list_path *head);
char *_getenv(const char *var_name);
#endif
