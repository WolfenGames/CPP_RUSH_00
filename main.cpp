/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 08:57:10 by jwolf             #+#    #+#             */
/*   Updated: 2019/06/08 13:50:45 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <curses.h>
#include <unistd.h>
#include <random>

#include "player.hpp"

#define DELAY 30000

void	init()
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

}

int		main(void)
{
	Player player;
	int max_y, max_x;
	int x = 0, y = 0;
	int state = 0;
	int swap = 0;
	int	maxStars = 4, currStars = 0;
	init();
	getmaxyx(stdscr, max_y, max_x);
	WINDOW *main = newwin(max_y,max_x, 0, 0);
	keypad(main, TRUE);
	nodelay(main, TRUE);

	srand(time(NULL));
	x = rand() % max_x;
	y = rand() % max_y;
	if (x <= 0) x = 1;
	if (x >= max_x) x -=1;
	if (y <= 0) y = 1;
	if (y >= max_y) y -=1;

	while(1) 
	{
		werase(main);
		box(main, 0, 0);
		usleep(DELAY);
		for(int i = 1; i < max_y - 1; i++)
		{
			for (int j = 1; j < max_x - 1; j++)
			{
				if (currStars < maxStars)
				{
					int rnd = rand() % 100;
					if (rnd == 1 || rnd == 99)
					{
						currStars++;
						if (swap % 2)
						{
							//wattron(main, )
							if ((i * j + 1) % 2) mvwprintw(main, i, j, "+", COLOR_BLUE); else mvwprintw(main, i, j, "*", COLOR_GREEN);
						}
						else
						{

							if ((i * j + 1) % 2) mvwprintw(main, i, j, "*", COLOR_RED); else mvwprintw(main, i, j, "+", COLOR_MAGENTA);
						}
					}
				}
			}
			currStars = 0;
		}
		if (state == 0)
		{
			player.renderUp(main, x, y);
			//mvwprintw(main, y + 1, x, "|");
			//mvwprintw(main, y, x, "^");
		}
		if (state == 1)
		{
			player.renderDown(main, x, y);
			//mvwprintw(main, y - 1, x, "|");
			//mvwprintw(main, y, x, "v");
		}
		if (state == 2)
		{
			player.renderLeft(main, x, y);
			//mvwprintw(main, y, x, "<--");
		}
		if (state == 3)
		{
			player.renderDown(main, x, y);
			//mvwprintw(main, y, x, "-->");
		}
		wrefresh(main);
		
		//usleep(DELAY);

		int ch = wgetch(main);
		switch (ch)
		{
			case KEY_UP:
				y--;
				state = 0;
				break;
			case KEY_DOWN:
				y++;
				state = 1;
				break;
			case KEY_LEFT:
				x--;
				state = 2;
				break;
			case KEY_RIGHT:
				x++;
				state = 3;
				break;
			default:
				break;
		}
		if (x <= 0) x = 1;
		if (x >= max_x - 3) x = max_x - 4;
		if (y <= 0) y = 1;
		if (y >= max_y - 1) y = max_y - 2;
		VEC pos;
		pos.x = x;
		pos.y = y;
		player.setPos(pos);
		swap++;
		currStars = 0;
	}
	endwin();
	return (0);
}