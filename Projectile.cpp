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

Projectile::Projectile(VEC pos, VEC dir, WINDOW *win)
{
	this->lifespan = 300;
	this->dir = dir;
	this->pos = pos;
	this->win = win;
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
		this->setLeft(cpy.left);
		this->setRight(cpy.right);
		std::string up[] = {
			cpy.up[0],
			cpy.up[1]
		};
		this->setUp(up);
		std::string down[] = {
			cpy.down[0],
			cpy.down[1]
		};
		this->setDown(down);
		this->lifespan = cpy.lifespan;
		this->dir = cpy.dir;
		this->pos = cpy.pos;
	}
	return *this;
}

void		Projectile::setLeft(std::string left)
{
	this->left = left;
}

void		Projectile::setRight(std::string right)
{
	this->right = right;
}

void		Projectile::setUp(std::string up[])
{
	this->up[0] = up[0];
	this->up[1] = up[1];
}

void		Projectile::setDown(std::string down[])
{
	this->down[0] = down[0];
	this->down[1] = down[1];
}

void		Projectile::move(void)
{
	if (lifespan == 0)
	{
		delete this;
		return;
	}
	int x = 0, y = 0;
	wattron(this->win, COLOR_PAIR(4));
	mvwprintw(this->win, this->pos.y + (y * this->dir.y), this->pos.x + (x * this->dir.x), this->right.c_str());
	wattroff(this->win, COLOR_PAIR(4));
	x++;
	y++;
	this->lifespan--;
}

void		Projectile::shoot(VEC pos, VEC dir)
{
	(void)pos;
	(void)dir;	
}