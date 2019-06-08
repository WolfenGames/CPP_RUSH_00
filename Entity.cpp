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
}

VEC		Entity::getPos(void)
{
	return this->pos;
}


void	Entity::renderLeft(WINDOW *, int, int)
{

}

void	Entity::renderRight(WINDOW *, int, int)
{

}

void	Entity::renderUp(WINDOW *, int, int)
{

}

void	Entity::renderDown(WINDOW *, int, int)
{

}