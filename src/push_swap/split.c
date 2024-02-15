/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaillot <ebaillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:11:57 by edouard           #+#    #+#             */
/*   Updated: 2024/02/15 15:01:13 by ebaillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"


/**
 * Counts the number of words in a string separated by a given delimiter.
 * @param s The string to be examined.
 * @param c The delimiter character.
 * @return The count of words in the string.
 */
static int count_words(char *s, char c)
{
	int count;
	bool inside_word;

	count = 0;
	while (*s)
	{
		inside_word = false;
		while (*s == c)
			++s;
		while (*s != c && *s)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++s;
		}
	}
	return (count);
}

/**
 * Extracts the next word from a string starting at a specified cursor position.
 * @param s The string from which to extract the word.
 * @param c The delimiter character.
 * @return A pointer to the extracted word.
 */
static char *get_next_word(char *s, char c)
{
	static int cursor;
	char *next_word;
	int len;
	int i;

	cursor = 0;
	len = 0;
	i = 0;
	while (s[cursor] == c)
		++cursor;
	while ((s[cursor + len] != c) && s[cursor + len])
		++len;
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while ((s[cursor] != c) && s[cursor])
		next_word[i++] = s[cursor++];
	next_word[i] = '\0';
	return (next_word);
}

/**
 * Splits a string into an array of substrings using a specified delimiter.
 * @param s The string to be split.
 * @param c The delimiter character.
 * @return An array of substrings.
 */

char **ft_split(char *s, char c)
{
	int words_count;
	char **result_array;
	int i;

	i = 0;
	words_count = count_words(s, c);
	if (!words_count)
		exit(1);
	result_array = malloc(sizeof(char *) * (size_t)(words_count + 2));
	if (!result_array)
		return (NULL);
	while (words_count-- >= 0)
	{
		if (i == 0)
		{
			result_array[i] = malloc(sizeof(char));
			if (!result_array[i])
				return (NULL);
			result_array[i++][0] = '\0';
			continue ;
		}
		result_array[i++] = get_next_word(s, c);
	}
	result_array[i] = NULL;
	return (result_array);
}
