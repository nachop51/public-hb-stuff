#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

/* global variables */
extern char **environ;

typedef unsigned long int ulint;
typedef const unsigned char ucchar;

/* useful macros */

#define HASH_ARRAY_LENGTH 1024

#define INTERACTIVE_MODE 1

#define HISTORY_READ_SIZE 1024

#define GETLINE_BUFFER 1024

#define PROMPT "Nashell$ "

/* For hash_table_print function*/
#define ENVIRONMENT 0
#define ALIASES 1

/* Hash table implementation structs */

/**
 * struct hash_node_s - hash table node
 * @key: key
 * @value: value
 * @next: next node
 * Description: hash table node
 */
typedef struct hash_node_s
{
	char *key;
	char *value;
	struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - hash table
 * @size: size of the array
 * @array: array of nodes
 * Description: hash table
 */
typedef struct hash_table_s
{
	ulint size;
	hash_node_t **array;
} hash_table_t;

/**
 * struct list_s - linked list
 * @s: string
 * @next: next node
 * Description: linked list
 */
typedef struct list_s
{
	char *s;
	struct list_s *next;
} list_t;

/**
 * struct cmd_s - Command struct
 * @list: linked list
 * @path: linked list
 * @env: hash table
 * @vector: array of strings
 * @buffer: buffer
 * @err: error
 * @fd: file descriptor
 * @tty: tty
 * Description: Command struct
 */
typedef struct cmd_s
{
	list_t *list, *path;
	hash_table_t *env;
	char **vector, *buffer;
	int err, fd, tty;
} cmd_t;

/**
 * struct builtin_s - Builtins
 * @name: name of builtin
 * @f: function pointer
 * Description: Builtins
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(cmd_t **);
} builtin_t;

/* Hash tables implementation */

hash_table_t *map_environ(void);
hash_table_t *hash_table_create(ulint);
ulint hash_djb2(ucchar *);
ulint key_index(ucchar *, ulint);
hash_node_t *add_to_list(hash_node_t **, const char *, const char *);
int check_key(hash_node_t **, char *);
int hash_table_set(hash_table_t *, const char *, const char *);
char *hash_table_get(const hash_table_t *, const char *);
void hash_table_print(const hash_table_t *, int);
void hash_table_delete(hash_table_t *);
int hash_table_delete_key(hash_table_t *, char *);
char **ht_to_array(hash_table_t *);
char *_getenv(hash_table_t *, const char *);

/* Linked list implementation */

list_t *add_node_end(list_t **, char *);
void free_list(list_t *);
list_t *map_path(char *);
list_t *update_path(list_t *, char *);
void print_list(list_t *h);
size_t list_len(list_t *h);

/* String functions */
int _strlen(const char *);
int _strcmp(const char *s1, const char *s2);
char *_strdup(const char *str);
void _strcpy(char *dest, const char *src);
char *_str_concat(const char *s1, const char *s2);

/* Command struct functions */
cmd_t *setup_cmd(char **av);
void free_cmd_items(cmd_t **cmd);
int evaluate_input(cmd_t **cmd);
char **list_to_vector(list_t *h);
int execute_cmd(cmd_t **cmd);

/* Getline related */
int solve_getline(cmd_t **cmd);
int solve_path(cmd_t **cmd);

/* Validators */
int is_exec(char *path);
int valid_file(char *path);

/* Vectors */
void print_vector(char **v);
void free_vector(char **v);

/* Builtins */
int is_builtin(cmd_t **cmd);
int b_exit(cmd_t **cmd);
int b_env(cmd_t **cmd);

/* Without category */
unsigned char before_exit(cmd_t **cmd, char free_items);

#endif /* SHELL_H */
