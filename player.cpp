/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 13:37:37 by jwolf             #+#    #+#             */
/*   Updated: 2019/06/09 15:57:45 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.hpp"
#include <curses.h>

Player::Player(void):Entity() {}
Player::~Player(void) {}

void Player::getPlayerInput(WINDOW *main){
    int input = wgetch(main);
    VEC pos = this->getPos();

    int xSpeed = 2;
    int ySpeed = 1;

    if (input == KEY_UP){
        pos.y -= ySpeed;
        pos.heading = 1;
    } else if (input == KEY_DOWN){
        pos.y += ySpeed;
        pos.heading = 0;
    }  else if (input == KEY_LEFT){
        pos.x -= xSpeed;
        pos.heading = 2;
    }  else if (input == KEY_RIGHT){
        pos.x += xSpeed;
        pos.heading = 3;
    }
	this->setPos(pos);
}
