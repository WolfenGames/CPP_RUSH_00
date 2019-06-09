/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 09:09:18 by jwolf             #+#    #+#             */
/*   Updated: 2019/06/09 11:48:42 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTILE_HPP
# define PROJECTILE_HPP

#include	<string>
#include	<curses.h>
#include "Common.hpp"


class Projectile
{
	private:
		VEC				dir;
		VEC				pos;
		std::string		up[2];
		std::string		down[2];
		std::string		left;
		std::string		right;
		int				lifespan;
		WINDOW			*win;

	public:
		Projectile(void);
		Projectile(VEC, VEC, WINDOW *);
		Projectile(const Projectile&);
		Projectile &operator=(const Projectile&);
		~Projectile();
		void		setLeft(std::string);
		void		setRight(std::string);
		void		setUp(std::string[]);
		void		setDown(std::string[]);
		void		move(void);
		void		shoot(VEC, VEC);
};


#endif