/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 08:57:10 by jwolf             #+#    #+#             */
/*   Updated: 2019/06/09 12:20:37 by jwolf            ###   ########.fr       */
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
	
	manager.Update();
	manager.Init();

	endwin();
	return (0);
}