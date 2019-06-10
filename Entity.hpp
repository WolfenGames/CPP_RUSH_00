/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <tramants@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 13:34:16 by jwolf             #+#    #+#             */
/*   Updated: 2019/06/10 17:26:35 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_HPP
# define ENTITY_HPP

#include <curses.h>
#include "Common.hpp"

class Entity {
	public:
		Entity(void);
		Entity(bool isBig);
		~Entity(void);
		void	renderLeft(WINDOW *, const char *sprite);
		void	renderRight(WINDOW *, const char *sprite);
		void	renderUp(WINDOW *, const char *sprite);
		void	renderDown(WINDOW *,const char *sprite);
		
		void	setPos(VEC);
		void	setPos(int, int);
		VEC		getPos(void);
		void	setLife(int);
		int		getLife(void);
		bool	IsAlive(void);
		bool	isBig;
	private:
		VEC		pos;
		int		life;
};

#endif