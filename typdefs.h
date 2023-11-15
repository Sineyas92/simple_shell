#ifndef TYPEDEFS_H
#define TYPEDEFS_H

/**
 * @brief Enumeration representing boolean values.
 */
typedef enum _bool
{
    false = 0,
    true = 1
} Bool;

/**
 * @brief Enumeration representing different error types.
 */
typedef enum errors
{
    READLINE = 0
} Errors;

/**
 * @brief Struct defining a node in a linked list.
 * @var dir: Directory path stored in the node.
 * @var next: Pointer to the next node in the linked list.
 */
typedef struct list_s
{
    char *dir;
    struct list_s *next;
} list_t;

/**
 * @brief Struct defining a builtin command.
 * @var name: Name of the builtin command.
 * @var f: Function pointer to the implementation of the builtin command.
 */
typedef struct builtin_s
{
    char *name;
    int (*f)(char **argv, char **front);
} builtin_t;

/**
 * @brief Struct defining an alias.
 * @var name: Name of the alias.
 * @var value: Value associated with the alias.
 * @var next: Pointer to the next alias in the list.
 */
typedef struct alias_s
{
    char *name;
    char *value;
    struct alias_s *next;
} alias_t;

#endif /* TYPEDEFS_H */

