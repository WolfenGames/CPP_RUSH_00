/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameManager.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-beer <rde-beer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 09:01:55 by jwolf             #+#    #+#             */
/*   Updated: 2019/06/10 11:09:27 by rde-beer         ###   ########.fr       */
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

	VEC	startPos;
	startPos.x = 4;
	startPos.y = 5;
	startPos.heading = 1;
	this->player.setPos(startPos);
	this->secondsLeft = 120 * 60;
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
	wattron(this->main, COLOR_PAIR(5));
	if (pos.heading == 0){
		this->player.renderDown(this->main, "v");
	} else if (pos.heading == 1){
		this->player.renderUp(this->main, "^");
	}  else if (pos.heading == 2){
		this->player.renderLeft(this->main, "<");	
	} else if (pos.heading == 3){
		this->player.renderRight(this->main, ">");
	}
	wattroff(this->main, COLOR_PAIR(5));
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
	this->DrawPlayer();
	this->showTimer();
	wrefresh(this->main);
}

GameManager::~GameManager(void)
{}

void		GameManager::pushOnObjects(Entity *obj)
{
	t_list *tmp;

	tmp = this->objects;
	if (obj && !entityExists(obj, tmp))
	{
		if (!this->objects)
		{
			this->objects = new t_list;
			this->objects->content = obj;
			this->objects->next = NULL;
		}
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new t_list;
			tmp->next->content = obj;
			tmp->next->next = NULL;
		}
	}
}

bool		GameManager::entityExists(Entity *obj, t_list *lst)
{
	if (!this->objects)
		return false;
	if (this->objects->content == obj)
		return true;
	return this->entityExists(obj, lst->next);
}

void		GameManager::checkObjs(void)
{
	t_list	*tmp;

	tmp = this->objects;
}

void		GameManager::Update(void){
	this->currStars = 0;
	this->maxStars = 40;
	
	while(this->secondsLeft >= 0) 
	{
		this->player.getPlayerInput(this->main);
		wattroff(this->main, COLOR_PAIR(5));
		this->Draw();
		this->tick++;
		this->swap++;
		this->currStars = 0;
	}
}

void GameManager::showTimer(void) 
{
	wattron(this->main, COLOR_PAIR(2));
	mvwprintw(this->main, 0, 0, "%i", this->secondsLeft/60);
	wattroff(this->main, COLOR_PAIR(2));
	this->secondsLeft -= 5;
}

bool	GameManager::canStart(void)
{
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    WINDOW * menuwin = newwin(6, xMax-12, yMax-8, 5);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);

    keypad(menuwin, true);

    std::string choices[3] = {"Play", "Instructions", "Exit"};
    int choice;
    int highlight = 0;

    while(1)
    {
        for(int i = 0; i < 3; i++)
        {
            if(i == highlight)
                wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i+1, 1, choices[i].c_str());
            wattroff(menuwin, A_REVERSE);
        }
        choice = wgetch(menuwin);

        switch(choice)
        {
            case KEY_UP:
                highlight--;
                if(highlight == -1)
                    highlight = 0;
                break;
            case KEY_DOWN:
                highlight++;
                if(highlight == 3)
                    highlight = 2;
                break;
            default:
                break;
        }
        if(choice == 10)
            break;
    }
    if (choices[highlight] == "Play")
	{
		delwin(menuwin);
		return true;
	}
	else
	{
		delwin(menuwin);
		return false;
	}
}