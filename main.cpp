/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-beer <rde-beer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 08:57:10 by jwolf             #+#    #+#             */
/*   Updated: 2019/06/10 11:01:39 by rde-beer         ###   ########.fr       */
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

int		main(void)
{
	srand(time(NULL));
	GameManager manager;
	manager.Init();
	if(manager.canStart())
	{
		manager.showTimer();
		manager.createEnemies();
		manager.Update();
	}

	endwin();
	return (0);
}