/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameManager.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 09:01:55 by jwolf             #+#    #+#             */
/*   Updated: 2019/06/09 15:06:13 by jwolf            ###   ########.fr       */
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
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_BLACK);
	init_pair(5, COLOR_BLUE, COLOR_BLACK);
}

void	GameManager::DrawBackground(void)
{
	if (((this->tick % 10)/3) == 0)
	{
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
						{
							if ((i * j + 1) % 2) 
							{
								wattron(this->main, COLOR_PAIR(3));
								mvwprintw(main, i, j, "+");
								wattroff(this->main, COLOR_PAIR(3));
							}
							else 
							{
								wattron(this->main, COLOR_PAIR(4));
								mvwprintw(main, i, j, "*");
								wattroff(this->main, COLOR_PAIR(4));
							}
						}
						else
						{
							if ((i * j + 1) % 2)
							{
								wattron(this->main, COLOR_PAIR(1));
								mvwprintw(main, i, j, "*");
								wattroff(this->main, COLOR_PAIR(1));
							}
							else
							{
								wattron(this->main, COLOR_PAIR(2));
								mvwprintw(main, i, j, "+");
								wattroff(this->main, COLOR_PAIR(2));	
							}
						}
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

void		GameManager::Draw(void)
{
	char bordTop = '=';
	char bordBot = '=';
	char bordLeft = '|';
	char bordRight = '|';
	char bordTopLcor = '.';
	char bordTopRcor = '.';
	char bordBotLcor = '`';
	char bordBotRcor = '`';

	werase(this->main);
	wclear(this->main);
	wattron(this->main, A_BOLD);
	wborder(this->main, (int)bordLeft, (int)bordRight, 
						(int)bordTop, (int)bordBot, 
						(int)bordTopLcor, (int)bordTopRcor, 
						(int)bordBotLcor, (int)bordBotRcor);
	this->DrawBackground();
	wrefresh(this->main);
}

GameManager::~GameManager(void)
{}

void		GameManager::Update(void){
	this->currStars = 0;
	this->maxStars = 40;
	
	while(1) 
	{
		this->Draw();
		this->tick++;
		this->swap++;
		this->currStars = 0;
		usleep(DELAY);
	}
}