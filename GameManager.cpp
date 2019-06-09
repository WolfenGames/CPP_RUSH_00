/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameManager.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 09:01:55 by jwolf             #+#    #+#             */
/*   Updated: 2019/06/09 13:29:07 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameManager.hpp"

#include <iostream>

GameManager::GameManager(void)
{}

void		GameManager::Init(void)
{
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	clear();
	refresh();
 	if (!has_colors())
	{
		endwin();
		std::cerr << "ERROR: Terminal does not support color." << std::endl;
		exit(1);
	}
	start_color();

	getmaxyx(stdscr, this->max_y, this->max_x);
	this->main = newwin(this->max_y, this->max_x, 0, 0);
	keypad(this->main, TRUE);
	nodelay(this->main, TRUE);
	halfdelay(TRUE);
}

void	GameManager::DrawBackground(void)
{
	if (((this->tick % 10) / 3) == 0)
	{
		usleep(DELAY);
		for(int i = 1; i < this->max_y - 1; i++)
		{
			for (int j = 1; j < this->max_x - 1; j++)
			{
				if (this->currStars < this->maxStars)
				{
					int rnd = rand() % 100;
					if (rnd == 1 || rnd == 99)
					{
						this->currStars++;
						if (this->swap % 2)
							if ((i * j + 1) % 2) mvwprintw(main, i, j, "+"); else mvwprintw(main, i, j, "*");
						else
							if ((i * j + 1) % 2) mvwprintw(main, i, j, "*"); else mvwprintw(main, i, j, "+");
					}
				}
			}
			this->currStars = 0;
		}
	}
}

void	GameManager::DrawPlayer(void){
	VEC pos = this->player.getPos();
	if (pos.heading == 0){
		this->player.renderDown(this->main, "v");
	} else if (pos.heading == 1){
		this->player.renderUp(this->main, "^");
	}  else if (pos.heading == 2){
		this->player.renderLeft(this->main, "<");		
	} else if (pos.heading == 3){
		this->player.renderRight(this->main, ">");
	}
}

void	GameManager::Draw(void)
{
	this->currStars = 0;
	this->maxStars = 40;
	while(1) 
	{
		wclear(this->main);
		werase(this->main);
		box(this->main, 0, 0);
		this->DrawBackground();
		wrefresh(this->main);
		this->tick++;
		this->swap++;
		this->currStars = 0;
	}
}

GameManager::~GameManager(void)
{
	
}

void		GameManager::Update(void){
}