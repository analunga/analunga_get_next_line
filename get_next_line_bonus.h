/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analunga <analunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:38:05 by analunga          #+#    #+#             */
/*   Updated: 2024/05/20 22:47:05 by analunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef MAX_FD
#  define MAX_FD 10240
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h> 
# include <ctype.h>
# include <string.h>

typedef struct s_store {
	char	*new_remainder;
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	len;
}			t_store;

typedef struct s_conjoin {
	char	*buff;
	char	*temp;
	int		read_bytes;
}			t_conjoin;

char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
void	*ft_memmove(void *dest, const void *src, size_t len);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

#endif
