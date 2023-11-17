#include "shell.h"

/**
 * split_string - splits a string into words. Repeat delimiters are ignored
 * @input_str: the input string
 * @delimiter: the delimiter string
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **split_string(char *input_str, char *delimiter)
{
	int index, word_index, length, temp, num_words = 0;
	char **result;

	if (input_str == NULL || input_str[0] == 0)
		return NULL;

	if (!delimiter)
		delimiter = " ";

	for (index = 0; input_str[index] != '\0'; index++)
		if (!is_delim(input_str[index], delimiter) &&
		    (is_delim(input_str[index + 1], delimiter) || !input_str[index + 1]))
			num_words++;

	if (num_words == 0)
		return NULL;

	result = malloc((1 + num_words) * sizeof(char *));
	if (!result)
		return NULL;

	for (index = 0, word_index = 0; word_index < num_words; word_index++)
	{
		while (is_delim(input_str[index], delimiter))
			index++;

		length = 0;
		while (!is_delim(input_str[index + length], delimiter) && input_str[index + length])
			length++;

		result[word_index] = malloc((length + 1) * sizeof(char));
		if (!result[word_index])
		{
			for (temp = 0; temp < word_index; temp++)
				free(result[temp]);
			free(result);
			return NULL;
		}

		for (temp = 0; temp < length; temp++)
			result[word_index][temp] = input_str[index++];
		result[word_index][temp] = 0;
	}

	result[word_index] = NULL;
	return result;
}

/**
 * split_string2 - splits a string into words
 * @input_str: the input string
 * @delimiter: the delimiter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **split_string2(char *input_str, char delimiter)
{
	int index, word_index, length, temp, num_words = 0;
	char **result;

	if (input_str == NULL || input_str[0] == 0)
		return NULL;

	for (index = 0; input_str[index] != '\0'; index++)
		if ((input_str[index] != delimiter && input_str[index + 1] == delimiter) ||
		    (input_str[index] != delimiter && !input_str[index + 1]) || input_str[index + 1] == delimiter)
			num_words++;

	if (num_words == 0)
		return NULL;

	result = malloc((1 + num_words) * sizeof(char *));
	if (!result)
		return NULL;

	for (index = 0, word_index = 0; word_index < num_words; word_index++)
	{
		while (input_str[index] == delimiter && input_str[index] != delimiter)
			index++;

		length = 0;
		while (input_str[index + length] != delimiter && input_str[index + length] && input_str[index + length] != delimiter)
			length++;

		result[word_index] = malloc((length + 1) * sizeof(char));
		if (!result[word_index])
		{
			for (temp = 0; temp < word_index; temp++)
				free(result[temp]);
			free(result);
			return NULL;
		}

		for (temp = 0; temp < length; temp++)
			result[word_index][temp] = input_str[index++];
		result[word_index][temp] = 0;
	}

	result[word_index] = NULL;
	return result;
}

