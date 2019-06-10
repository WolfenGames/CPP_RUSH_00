/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameManager.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-beer <rde-beer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 09:01:59 by jwolf             #+#    #+#             */
/*   Updated: 2019/06/10 10:46:15 by rde-beer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEMANAGER_HPP
# define GAMEMANAGER_HPP
#define DELAY 30000

#include <curses.h>
#include <unistd.h>
#include "player.hpp"
#include "Common.hpp"

class GameManager
{
	private:
		WINDOW	*main;
		WINDOW	*score;
		Player	player;
		t_list	*objects;
		int 	max_y;
		int		max_x;
		int 	state;
		int 	swap;
		int		maxStars;
		int		currStars;
		int		tick;
		void	pushOnObjects(Entity*);
		bool	entityExists(Entity*, t_list*);
		void	checkObjs(void);

	public:
		GameManager(void);
		~GameManager();
		// Menu	menu;
		void	timer(void);
		bool	canStart(void);
		void	Update(void);
		void	Draw(void);
		void	Init(void);
		void	Destroy(void);
		void	DrawBackground(void);
		void	DrawPlayer(void);
};

#endif