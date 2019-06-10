/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 13:34:09 by jwolf             #+#    #+#             */
/*   Updated: 2019/06/08 13:46:54 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Entity.hpp"

Entity::Entity(){}
Entity::~Entity(){}

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
	this->life = l;
}