/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameManager.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 09:01:55 by jwolf             #+#    #+#             */
/*   Updated: 2019/06/09 12:23:50 by jwolf            ###   ########.fr       */
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

void	GameManager::Draw(void)
{
	this->currStars = 0;
	this->maxStars = 40;
	while(1) 
	{
		wclear(this->main);
		werase(this->main);
		box(this->main, 0, 0);
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
							{
								//wattron(main, )
								if ((i * j + 1) % 2) mvwprintw(main, i, j, "+"); else mvwprintw(main, i, j, "*");
							}
							else
							{

								if ((i * j + 1) % 2) mvwprintw(main, i, j, "*"); else mvwprintw(main, i, j, "+");
							}
						}
					}
				}
				this->currStars = 0;
			}
			// maxStars = 0;
			// if (state == 0)
			// {
			// 	//player.renderUp(main, x, y);
			// 	// mvwprintw(main, y + 1, x, "|");
			// 	// mvwprintw(main, y, x, "^");
			// }
			// if (state == 1)
			// {
			// 	// player.renderDown(main, x, y);
			// 	// mvwprintw(main, y - 1, x, "|");
			// 	// mvwprintw(main, y, x, "v");
			// }
			// if (state == 2)
			// {
			// 	// player.renderLeft(main, x, y);
			// 	// mvwprintw(main, y, x, "<--");
			// }
			// if (state == 3)
			// {
			// 	// player.renderDown(main, x, y);
			// 	// mvwprintw(main, y, x, "-->");
			// }

			// int ch = wgetch(main);
			// switch (ch)
			// {
			// 	case KEY_UP:
			// 		// y--;
			// 		state = 0;
			// 		break;
			// 	case KEY_DOWN:
			// 		// y++;
			// 		state = 1;
			// 		break;
			// 	case KEY_LEFT:
			// 		// x--;
			// 		state = 2;
			// 		break;
			// 	case KEY_RIGHT:
			// 		// x++;
			// 		state = 3;
			// 		break;
			// 	default:
			// 		break;
			// }
			// if (x <= 0) x = 1;
			// if (x >= max_x - 3) x = max_x - 4;
			// if (y <= 0) y = 1;
			// if (y >= max_y - 1) y = max_y - 2;
			// VEC pos;
			// pos.x = x;
			// pos.y = y;
			// player.setPos(pos);
			wrefresh(this->main);
		}
		this->tick++;
		this->swap++;
		this->currStars = 0;
	}
}

GameManager::~GameManager(void)
{
	
}

void		GameManager::Update(void){
	this->Draw();
}