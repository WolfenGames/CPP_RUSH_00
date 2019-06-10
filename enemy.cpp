/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <tramants@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 10:44:21 by tramants          #+#    #+#             */
/*   Updated: 2019/06/10 15:09:28 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemy.hpp"
#include <curses.h>
#include <cstdlib>

Enemy::Enemy(void):Entity() {}
Enemy::~Enemy(void) {}

void	Enemy::renderEnemy(WINDOW *main, const char *sprite)
{
	VEC pos = this->getPos();
	mvwprintw(main, pos.y, pos.x, sprite);
}

void    Enemy::updateMovement(int max_y, int max_x)
{
    VEC enemyPos = this->getPos();
    if (enemyPos.x < max_x && enemyPos.x + 2 != max_x && enemyPos.x) {
        if (enemyPos.x == 0) {
            enemyPos.x = enemyPos.x + 2;
        } else {
            enemyPos.x = enemyPos.x + 1;
        }
    }
	if ((enemyPos.x + 2) == max_x)
	{
		int randX = rand() % 30;
        int randY = rand() % 30;

		if (randY <= 1) randY += 3;
		if (randY >= max_x - 1) randY -= 3;
		(void)max_y;
        enemyPos.x = randX - 15;
        enemyPos.y = randY;
    }
    // enemyPos.y = enemyPos.y + 1;
    // enemyPos.x = enemyPos.x + 1;

    this->setPos(enemyPos);
}
