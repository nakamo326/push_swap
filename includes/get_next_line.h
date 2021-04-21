/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakamot <ynakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 11:32:00 by ynakamot          #+#    #+#             */
/*   Updated: 2021/04/21 12:40:44 by ynakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "./libft/libft.h"

# define SUCCESS 1
# define ERROR -1
# define CONTINUE 3
# define END 0
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2047
# endif

int		get_next_line(int fd, char **line);

#endif
