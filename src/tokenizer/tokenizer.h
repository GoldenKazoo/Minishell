/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:27:59 by zchagar           #+#    #+#             */
/*   Updated: 2024/12/21 18:30:19 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

char	**ft_split(char const *s, char c);
size_t	ft_count_space(char *prompt);
char	*ft_insert_space(char *prompt);

#endif