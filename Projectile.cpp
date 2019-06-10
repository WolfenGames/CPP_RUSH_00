/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 09:09:22 by jwolf             #+#    #+#             */
/*   Updated: 2019/06/09 14:32:38 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Projectile.hpp"
#include <curses.h>
#include <cstdlib>
#include <unistd.h>

Projectile::Projectile(void)
{
	this->lifespan = 10000;
}

Projectile::Projectile(const Projectile &cpy)
{
	*this = cpy;
}

Projectile::~Projectile(void)
{
	delete this;
}

Projectile	&Projectile::operator=(const Projectile &cpy)
{
	if (this != &cpy)
	{
		
	}
	return *this;
}