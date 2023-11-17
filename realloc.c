#include "shell.h"

/**
 **_memset - fills memory with a constant byte
 *@memory: the pointer to the memory area
 *@byte: the byte to fill *memory with
 *@size: the amount of bytes to be filled
 *Return: (memory) a pointer to the memory area memory
 */
char *_memset(char *memory, char byte, unsigned int size)
{
	unsigned int index;

	for (index = 0; index < size; index++)
		memory[index] = byte;

	return memory;
}

/**
 * free_string_array - frees a string of strings
 * @string_array: string of strings
 */
void free_string_array(char **string_array)
{
	char **ptr = string_array;

	if (!string_array)
		return;

	while (*string_array)
		free(*string_array++);

	free(ptr);
}

/**
 * reallocate_memory - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of the previous block
 * @new_size: byte size of the new block
 *
 * Return: pointer to the old block, if reallocation fails, returns NULL
 */
void *reallocate_memory(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr;

	if (!ptr)
		return malloc(new_size);

	if (!new_size)
		return free(ptr), NULL;

	if (new_size == old_size)
		return ptr;

	new_ptr = malloc(new_size);
	if (!new_ptr)
		return NULL;

	old_size = old_size < new_size ? old_size : new_size;

	while (old_size--)
		new_ptr[old_size] = ((char *)ptr)[old_size];

	free(ptr);

	return new_ptr;
}

