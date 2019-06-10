/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <tramants@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 08:57:10 by jwolf             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/06/10 14:15:43 by tramants         ###   ########.fr       */
=======
/*   Updated: 2019/06/10 14:27:02 by rde-beer         ###   ########.fr       */
>>>>>>> b747704ca74f0930085dc8dd70aac719318bfd6d
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <curses.h>
#include <unistd.h>
#include <random>
#include "Projectile.hpp"
#include "player.hpp"
#include "GameManager.hpp"
#include "Common.hpp"
#include "enemy.hpp"

int		main(void)
{
	srand(time(NULL));
	GameManager manager;
	manager.GameOver = false;
	manager.Init();
	if(manager.canStart())
	{
		manager.showTimer();
		manager.createEnemies();
		manager.Update();
	}
	manager.gameOver();
	endwin();
	return (0);
}