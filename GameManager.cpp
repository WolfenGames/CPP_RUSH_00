/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameManager.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-beer <rde-beer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 09:01:55 by jwolf             #+#    #+#             */
/*   Updated: 2019/06/10 16:13:53 by rde-beer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameManager.hpp"

#include <iostream>

GameManager::GameManager(void)
{
	this->objects = NULL;
}

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
	this->restart = 1;
	this->secondsLeft = (120 * 60);
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
	//Check border
	if (pos.x >= this->max_x - 1){
		pos.x = this->max_x-2;
	} else if (pos.x <= 0){
		pos.x = 1;
	} else if (pos.y >= this->max_y - 1){
		pos.y = this->max_y -2;
	} else if (pos.y <= 0){
		pos.y = 1;
	}
	this->player.setPos(pos);
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
	char bordTopAndBot = '=';
	char bordLeftAndRight = '|';
	char bordTopLcor = '.';
	char bordTopRcor = '.';
	char bordBotLcor = '`';
	char bordBotRcor = '`';

	werase(this->main);
	wclear(this->main);
	wattron(this->main, A_BOLD);
	wborder(this->main, (int)bordLeftAndRight, (int)bordLeftAndRight, 
						(int)bordTopAndBot, (int)bordTopAndBot, 
						(int)bordTopLcor, (int)bordTopRcor, 
						(int)bordBotLcor, (int)bordBotRcor);
	this->DrawBackground();
	this->DrawEntities();
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
	if (obj)
	{
		tmp = this->objects;
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

void		GameManager::pushOnProjectiles(Projectile *obj)
{
	t_list *tmp;

	tmp = this->objects;
	if (obj)
	{
		tmp = this->objects;
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

void		GameManager::DrawEntities(void)
{
	t_list *tmp;

	tmp = this->objects;
	while (tmp)
	{
		Entity *x = (Entity*)tmp->content;
		wattron(this->main, COLOR_PAIR(4));
		mvwprintw(this->main, x->getPos().y, x->getPos().x, "#");
		wattroff(this->main, COLOR_PAIR(4));
		tmp = tmp->next;
	}
}

void		GameManager::DrawProjectiles(void)
{
	t_list *tmp;

	tmp = this->projectiles;
	while (tmp)
	{
		Projectile *x = (Projectile*)tmp->content;
		wattron(this->main, COLOR_PAIR(4));
		//Position based on heading
		mvwprintw(this->main, x->getPos().y, x->getPos().x, "#");
		wattroff(this->main, COLOR_PAIR(4));
		tmp = tmp->next;
	}
}

#include <sstream>
void		GameManager::checkObjs(void)
{
	t_list	*tmp;

	tmp = this->objects;
	while (tmp != NULL)
	{
		Entity *obj = (Entity *)tmp->content;
		if (this->player.getPos().x == obj->getPos().x 
			&& this->player.getPos().y == obj->getPos().y)
		{
			this->GameOver = true;
		}
		tmp = tmp->next;
	}
}

void		GameManager::createEnemies(void)
{
	for (int i = 0; i < 20; i++)
	{
		Entity *newE = new Entity();
		newE->setPos(rand() % this->max_x, rand() % this->max_y);
		this->pushOnObjects(newE);
	}
}

void		GameManager::Update(void){
	this->currStars = 0;
	this->maxStars = 40;
	while(this->secondsLeft >= 0 && !this->GameOver) 
	{
		this->player.getPlayerInput(this->main);
		wattroff(this->main, COLOR_PAIR(5));
		this->checkObjs();
		this->Draw();
		this->tick++;
		this->swap++;
		this->currStars = 0;
	}
}

void 		GameManager::showTimer(void) 
{
	wattron(this->main, COLOR_PAIR(2));
	mvwprintw(this->main, 0, 0, "%i", this->secondsLeft / 60);
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

    std::string choices[] = {"Play", "Exit"};
    size_t choice;
    size_t highlight = 0;

    while(1)
    {
        for(size_t i = 0; i < (sizeof(choices)/sizeof(choices[0])); i++)
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
                if((int)highlight == -1)
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
    if (choices[highlight] == choices[0])
	{
		delwin(menuwin);
		return true;
	}
	else
	{
		//this->restart = false;
		//delwin(this->main);
		return false;
	}
}

void	GameManager::gameOver(void)
{
	int yMax, xMax;
	delwin(this->main);
	getmaxyx(stdscr, yMax, xMax);
	this->main = newwin(6, xMax, yMax, 5);
	nodelay(this->main, true);
	keypad(this->main, true);
	while (1)
	{
		wclear(this->main);
		box(this->main, 0, 0);
		refresh();
		wrefresh(this->main);
		mvprintw(2, 5," ####    ##   #    # ######     ####  #    # ###### #####");
		mvprintw(3, 5,"#    #  #  #  ##  ## #         #    # #    # #      #    #");
		mvprintw(4, 5,"#      #    # # ## # #####     #    # #    # #####  #    #");
		mvprintw(5, 5,"#  ### ###### #    # #         #    # #    # #      #####");
		mvprintw(6, 5,"#    # #    # #    # #         #    #  #  #  #      #   #");
		mvprintw(7, 5," ####  #    # #    # ######     ####    ##   ###### #    #");
		mvprintw(15, 10, "Press up to continue");
		int x = wgetch(this->main);
		if (x >= 0)
			break;
	}
	sleep(2);
}