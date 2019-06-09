/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameManager.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 09:01:59 by jwolf             #+#    #+#             */
/*   Updated: 2019/06/09 14:57:09 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEMANAGER_HPP
# define GAMEMANAGER_HPP
#define DELAY 10000

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
		char	***map;
		void	**objects;
		int 	max_y;
		int		max_x;
		int 	state;
		int 	swap;
		int		maxStars;
		int		currStars;
		int		tick;
	public:
		GameManager(void);
		~GameManager();
		void	Update(void);
		void	Draw(void);
		void	Init(void);
		void	Destroy(void);
		void	DrawBackground(void);
		void	DrawPlayer(void);
};

#endif