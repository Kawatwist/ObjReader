/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ObjError.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <lomasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 21:06:21 by lomasse           #+#    #+#             */
/*   Updated: 2020/08/08 21:33:55 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJERROR_H
# define OBJERROR_H

# define ERR_MAX                6

# define ERR_OBJ_VALID          "Not a valid Error\n\0"
# define ERR_OBJ_MALLOC         "Error memory allocation\n\0"
# define ERR_OBJ_NOT_INIT       "Error obj not initialized\n\0"
# define ERR_OBJ_OPEN           "Error open failed\n\0"
# define ERR_OBJ_PARSING        "Error parsing invalid\n\0"
# define ERR_OBJ_INVALID        "Error not defined\n\0"

#endif