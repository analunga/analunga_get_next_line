/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analunga <analunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 01:32:05 by analunga          #+#    #+#             */
/*   Updated: 2024/05/21 03:24:58 by analunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h> 
# include <ctype.h>
# include <string.h>

typedef struct s_conjoin {
	char	*buff;
	char	*temp;
	int		read_bytes;
	char	j;
}			t_conjoin;

typedef struct s_store {
	char	*new_remainder;
	size_t	i;
	size_t	j;
	size_t	len;
}			t_store;

char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
void	*ft_memmove(void *dest, const void *src, size_t len);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

#endif