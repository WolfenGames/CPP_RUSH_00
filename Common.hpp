/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Common.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 11:29:37 by jwolf             #+#    #+#             */
/*   Updated: 2019/06/09 11:30:40 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_HPP
# define COMMON_HPP

typedef struct	s_list
{
	void		*content;
	s_list		*next;
	s_list		*previous;
}				t_list;

struct VEC
{
	int x;
	int y;
	int heading;
};

#endif