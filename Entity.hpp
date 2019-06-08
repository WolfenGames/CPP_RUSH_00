/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 13:34:16 by jwolf             #+#    #+#             */
/*   Updated: 2019/06/08 13:45:04 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_HPP
# define ENTITY_HPP

#include <curses.h>

struct VEC
{
	int x;
	int y;
};

class Entity {
	public:
		Entity(void);
		~Entity(void);
		void	renderLeft(WINDOW *, int, int);
		void	renderRight(WINDOW *, int, int);
		void	renderUp(WINDOW *, int, int);
		void	renderDown(WINDOW *, int, int);
		
		void	setPos(VEC);
		VEC		getPos(void);
	private:
		VEC		pos;
};

#endif