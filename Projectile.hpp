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
#include	"Common.hpp"
#include	"Entity.hpp"


class Projectile: public Entity
{
	public:
		Projectile(void);
		Projectile(const Projectile&);
		Projectile &operator=(const Projectile&);
		~Projectile();
	
	private:
		int		lifespan;
		std::string sprite;
};


#endif