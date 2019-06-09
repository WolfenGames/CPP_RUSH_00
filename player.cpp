/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 13:37:37 by jwolf             #+#    #+#             */
/*   Updated: 2019/06/08 13:51:58 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.hpp"
#include <curses.h>

Player::Player(void):Entity() {}
Player::~Player(void) {}

void Player::getPlayerInput(){
    int input = getch();
    VEC pos = this->getPos();
    if (input == KEY_UP){
        pos.y = pos.y++;
        pos.heading = 1;
        this->setPos(pos);
    } else if (input == KEY_DOWN){
        pos.y = pos.y--;
        pos.heading = 0;
        this->setPos(pos);
    }  else if (input == KEY_LEFT){
        pos.x = pos.x--;
        pos.heading = 2;
        this->setPos(pos);
    }  else if (input == KEY_RIGHT){
        pos.x = pos.x++;
        pos.heading = 3;
        this->setPos(pos);
    }
}
