/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-beer <rde-beer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 13:37:37 by jwolf             #+#    #+#             */
/*   Updated: 2019/06/10 16:57:35 by rde-beer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.hpp"
#include <curses.h>

Player::Player(void):Entity() {
	this->setLife(3);
    this->bullets = NULL;
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
    this->addBullet(pos);
}

void Player::addBullet(VEC pos){
    t_list *runner;
    Projectile *bullet = new Projectile;
    bullet->setPos(pos);
    (void)pos;

    runner = this->bullets;
    if (!this->bullets){
        this->bullets = new t_list;
        this->bullets->content = bullet;
        this->bullets->next = NULL;
        this->bullets->previous = NULL;
    } else {
        while(runner->next)
            runner = runner->next;
        runner->next = new t_list;
        runner->next->content = bullet;
        runner->next->previous = runner;
        runner->next->next = NULL;
    }
}

void Player::killBullet(VEC pos){
    t_list *runner = this->bullets;
    while (runner){
        Projectile *tmp = (Projectile *)runner->content;
        VEC current = tmp->getPos();
        if (pos.x == current.x && pos.y == current.y && pos.heading == current.heading){
            if (runner->next)
                runner->next->previous = runner->previous;
            if (runner->previous)
                runner->previous->next = runner->next;
            delete (Projectile *)runner->content;
            delete runner;
            break;
        }
        runner = runner->next;
    }
}

t_list *Player::getProjectiles(){
    return (this->bullets);
}

int     Player::getLifes(void)
{
    return this->getLife();
}