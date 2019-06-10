/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <tramants@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 13:34:09 by jwolf             #+#    #+#             */
/*   Updated: 2019/06/10 17:26:17 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Entity.hpp"

Entity::Entity(){this->isBig = false;}
Entity::Entity(bool isBig){ this->isBig = isBig;}
Entity::~Entity(){};

void	Entity::setPos(VEC pos)
{
	this->pos.x = pos.x;
	this->pos.y = pos.y;
	this->pos.heading = pos.heading;
}

void	Entity::setPos(int x, int y)
{
	this->pos.x = x;
	this->pos.y = y;
	this->pos.heading = 0;
}

VEC		Entity::getPos(void)
{
	return this->pos;
}


void	Entity::renderLeft(WINDOW *main, const char *sprite)
{
	VEC pos = this->getPos();
	mvwprintw(main, pos.y, pos.x, sprite);
}

void	Entity::renderRight(WINDOW *main, const char *sprite)
{
	VEC pos = this->getPos();
	mvwprintw(main, pos.y, pos.x, sprite);
}

void	Entity::renderUp(WINDOW *main, const char *sprite)
{
	VEC pos = this->getPos();
	mvwprintw(main, pos.y, pos.x, sprite);
}

void	Entity::renderDown(WINDOW *main, const char *sprite)
{
	VEC pos = this->getPos();
	mvwprintw(main, pos.y, pos.x, sprite);
}

void	Entity::setLife(int l)
{
	this->life += l;
}

int		Entity::getLife(void)
{
	return (this->life);// > 0);
}

bool	Entity::IsAlive(void)
{
	return (this->life > 0);
}