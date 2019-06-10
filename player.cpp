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

Player::Player(void):Entity() {
	this->setLife(3);
    // this->Projectile = NULL;
}
Player::~Player(void) {}

void Player::getPlayerInput(WINDOW *main){
    int input = wgetch(main);
    VEC pos = this->getPos();

    int xSpeed = 1;
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
    } else if (input == ' '){
        this->shoot();
    }
	this->setPos(pos);
}


void Player::shoot(){
    VEC pos = this->getPos();

    if (pos.heading == 1){
        pos.y--;
    } else if (pos.heading == 0){
        pos.y++;
    } else if (pos.heading == 2){
        pos.x--;
    } else if (pos.heading == 3){
        pos.x++;
    }
    //add bullets to player array
}