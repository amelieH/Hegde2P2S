//
// Created by Heliou on 28/06/2017.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <functional>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

class Player {
 public:

  long double* y_strat;
  double* proba_strat;

  Player(int id, double** payoff);

  ~Player();


  int getId() const;

  int getStrat() const;

  double getUt() const;

  void setStrat(int s);

  bool update_proba();

  void draw_ini_weight();

  void set_weight(double w1, double w2);

  int draw_proba();

  bool isConverged() const;

  double* utility(int strat_other);

  void print_Payoff();

 private:
  const int _id;
  int _strat;
  bool _converged;
  double ut;
  double** _payoff;
};

ostream &operator<<(ostream &flux, Player &P);


#endif //PLAYER_H
