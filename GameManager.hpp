/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameManager.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <tramants@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 09:01:59 by jwolf             #+#    #+#             */
/*   Updated: 2019/06/10 15:10:35 by rde-beer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEMANAGER_HPP
# define GAMEMANAGER_HPP
#define DELAY 30000

#include <curses.h>
#include <unistd.h>
#include "player.hpp"
#include "Common.hpp"
#include "Projectile.hpp"
#include "enemy.hpp"

class GameManager
{
	private:
		WINDOW	*main;
		WINDOW	*score;
		Player	player;
		Enemy	enemy;
		t_list	*objects;
		t_list	*projectiles;
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
		// Menu	menu;
  		int 	secondsLeft;// = 120;
		bool	canStart(void);
		void	showTimer(void);
		bool	GameOver;
		bool	restart;
		void	Update(void);
		void	Draw(void);
		void	Init(void);
		void	Destroy(void);
		void	DrawBackground(void);
		void	DrawPlayer(void);
		void	DrawEntities(void);
		void	DrawProjectiles(void);
		void	createEnemies(void);
		void	gameOver(void);
		void	pushOnObjects(Entity*);
		void	pushOnProjectiles(Projectile*);
		bool	entityExists(Entity*, t_list*);
		void	checkObjs(void);
		void	checkProjectile(Projectile *);
		void	DrawEnemies(void);
		void	UpdateEnemies(void);
};

#endif