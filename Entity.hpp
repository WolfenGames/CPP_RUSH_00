/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 13:34:16 by jwolf             #+#    #+#             */
/*   Updated: 2019/06/09 11:31:12 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_HPP
# define ENTITY_HPP

#include <curses.h>
#include "Common.hpp"

class Entity {
	public:
		Entity(void);
		~Entity(void);
		void	renderLeft(WINDOW *, const char *sprite);
		void	renderRight(WINDOW *, const char *sprite);
		void	renderUp(WINDOW *, const char *sprite);
		void	renderDown(WINDOW *,const char *sprite);
		
		void	setPos(VEC);
		void	setPos(int, int);
		VEC		getPos(void);
		void	setLife(int);
		bool	getLife(void);
	private:
		VEC		pos;
		int		life;
};

#endif