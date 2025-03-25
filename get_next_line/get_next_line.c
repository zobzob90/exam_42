/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:50:02 by eric              #+#    #+#             */
/*   Updated: 2025/03/25 13:16:20 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 30
#endif

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t i = 0;

	while (str[i])
		i++;
	return (i);
}

void	ft_strcpy(char *s1, const char *s2)
{
	while (*s2)
		*s1++ = *s2++;
	*s1 = '\0';
}

char	*ft_strdup(const char *src)
{
	size_t len = ft_strlen(src) + 1;
	char *dest = malloc(sizeof(char *) * (len));
	if (!dest)
		return (NULL);
	ft_strcpy(dest, src);
	return (dest);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (NULL);
	size_t s1_len = ft_strlen(s1);
	size_t s2_len = ft_strlen(s2);
	char	*join = malloc(sizeof(char *) * (s1_len + s2_len) + 1);
	if (!join)
		return (NULL);
	ft_strcpy(join, s1);
	ft_strcpy((join + s1_len), s2);
	free(s1);
	return (join);
}

char	*get_next_line(int fd)
{
	static char buf[BUFFER_SIZE + 1];  // Buffer statique pour garder le reste entre les appels
	char	*line;       // Ligne qu'on est en train de construire
	char	*newline;    // Pointeur vers le caractère '\n' dans la ligne
	int		countread;   // Nombre de caractères lus avec read()
	int		to_copy;     // Nombre de caractères à garder (jusqu’au '\n' ou fin)
	// On commence par dupliquer le contenu actuel du buffer
	line = ft_strdup(buf);
	if (!line)
		return (NULL);
	// Tant qu'on n'a pas trouvé de \n et qu'on peut lire, on continue
	while (!(newline = ft_strchr(line, '\n')) && (countread = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[countread] = '\0';          // On termine le buffer en chaîne de caractères
		line = ft_strjoin(line, buf);   // On ajoute ce qu'on vient de lire à la ligne
		if (!line)
			return (NULL);              // En cas d’erreur malloc
	}
	// Si read a échoué ou si la ligne est vide (EOF sans rien à renvoyer)
	if (countread < 0 || ft_strlen(line) == 0)
		return (free(line), NULL);
	// Si on a trouvé un '\n' dans la ligne
	if (newline != NULL)
	{
		to_copy = newline - line + 1;      // On garde jusqu’au \n inclus
		ft_strcpy(buf, newline + 1);       // Et on garde le reste dans buf
	}
	else
	{
		to_copy = ft_strlen(line);         // Sinon, on garde toute la ligne
		buf[0] = '\0';                     // Et on vide le buffer
	}
	line[to_copy] = '\0';  // On coupe la chaîne juste après le \n (ou à la fin)
	return (line);         // Et on retourne la ligne
}

int main(void)
{
	int fd = open("test", O_RDONLY);
	char *line;
	int nb = 1;

	while ((line = get_next_line(fd)))
	{
		printf("Ligne %d : %s", nb, line);
		nb++;
		free(line);
	}
	close(fd);
	return (0);
}
