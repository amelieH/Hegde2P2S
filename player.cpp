//
// Created by Heliou on 28/06/2017.
//

#include "player.h"


Player::Player(int id, double** payoff):
_id(id){
  _payoff = new double*[2];
  for (int i=0;i<2;i++){
    _payoff[i]= new double[2];
    for (int j=0;j<2;j++){
      _payoff[i][j]=payoff[i][j];
    }
  }
  _strat=0;
  proba_strat = new double[2];
  y_strat = new long double[2];
  draw_ini_pba();
  //set_weight(0.5,0.5);
}

Player::~Player() {
  for (int i=0;i<2;i++){
    delete[] _payoff[i];
  }
}

int Player::getId() const{
  return _id;
}

int Player::getStrat() const{
  return _strat;
}

double Player::getUt() const{
  return ut;
}

void Player::setStrat(int s){
  _strat=s;
}

bool Player::update_proba(){
  long double max=-100000;
  for (int i=0;i<2;i++){
    if (y_strat[i]>max)
      max=y_strat[i];
  }
  long double sum=0;
  for (int i=0;i<2;i++){
    sum+=exp(y_strat[i]-max);
  }
  for (int i=0;i<2;i++){
    proba_strat[i]=(double)(exp(y_strat[i]-max)/sum);
    if (proba_strat[i] > 0.99) {
      _converged = true;
    }/*
    if(proba_strat[i] < 0.0000000001){
      proba_strat[i]=0;
    }*/
  }

  return _converged;
}

void Player::draw_ini_weight() {
  double r;
  for(int i=0;i<2;i++) {
  r = ((double) rand() / (RAND_MAX));
  y_strat[i]=r;
  }
  update_proba();
}

void Player::draw_ini_pba() {
    double r;
    r=rand();
    proba_strat[0]=((double) r / (RAND_MAX));
    cout<<"Player "<<_id<<" ini proba "<<proba_strat[0]<<endl;
    proba_strat[1]=1-y_strat[0];
    y_strat[0]=log(proba_strat[0]);
    y_strat[1]=log(proba_strat[1]);
}

void Player::set_weight(double w1, double w2) {

  y_strat[0]=w1;
  y_strat[1]=w2;
  update_proba();
}

int Player::draw_proba() {
  double r = ((double) rand() / (RAND_MAX));
  double sum = proba_strat[0];
  int i = 0;
  while (sum < r) {
    i++;
    sum += proba_strat[i];
  }
  return i;
}


bool Player::isConverged() const {
  return _converged;
}

double* Player::utility(int strat_other){
  double* res=new double[2];
  res[0]=_payoff[strat_other][0];
  res[1]=_payoff[strat_other][1];
  ut=_payoff[strat_other][_strat];
  return res;
}

void Player::print_Payoff(){
  cout<<_payoff[0][0]<<" "<<_payoff[0][1]<<" "<<_payoff[1][0]<<" "<<_payoff[1][1]<<" "<<endl;
}

ostream &operator<<(ostream &flux, Player &P) {
  flux << "Player " << P.getId()<< " pure " << P.getStrat()<<" mixed "<<P.proba_strat[0]<<" utility "<<P.getUt()<<" ";
  return flux;
}
