//
// Created by Heliou on 29/06/2017.
//

#ifndef HEDGE_GAME_H
#define HEDGE_GAME_H
#include "player.h"

class Game {
 public:
  Game(double** payoff1, double** payoff2, int steps);

  ~Game();

  int steps;

  Player* P1;
  Player* P2;
  double** potential;

  void play(const string &outfile);

  double play_one_turn(int step,bool &recompute);

  Player* get_Player(int id);
  double** potential_func(double ** payoff1,double** payoff2);
  void print_potential();
};


#endif //HEDGE_GAME_H
