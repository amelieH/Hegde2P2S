#include <iostream>
#include "game.h"


static const string HOME = "/Users/heliou/Documents/these/theorie_jeux/Hedge2P2S/";


void fill_payoff(double** payoff1, double** payoff2){
  double test1 = payoff1[0][0] - payoff1[0][1] + payoff2[1][0];
  double test2 = payoff1[1][0] - payoff1[1][1] + payoff2[0][0] - payoff2[0][1];
  payoff2[1][1] = test1 - test2;
}

void random_payoff(double** payoff1, double** payoff2){
  for (int i=0;i<2;i++){
    for (int j =0;j<2;j++){
      payoff1[i][j] = (rand() % 10)/10.0;
      payoff2[i][j] = (rand() % 10)/10.0;
    }
  }
  fill_payoff(payoff1,payoff2);
}

void print_payoffs(double** payoff1, double** payoff2){
  std::cout<<"Payoff1 against 1 :"<<payoff1[0][0]<<" "<<payoff1[0][1]<<std::endl;
  std::cout<<"Payoff1 against 2 :"<<payoff1[1][0]<<" "<<payoff1[1][1]<<std::endl;
  std::cout<<"Payoff2 against 1 :"<<payoff2[0][0]<<" "<<payoff2[0][1]<<std::endl;
  std::cout<<"Payoff2 against 2 :"<<payoff2[1][0]<<" "<<payoff2[1][1]<<std::endl;
}

int main() {
  int seed=100;
  srand(seed);
  double** payoff1 = new double* [2];
  double** payoff2 = new double* [2];
  for( int i=0;i<2;i++){
    payoff1[i]=new double[2];
    payoff2[i]=new double[2];
  }
  random_payoff(payoff1,payoff2);
  seed=90;
  srand(seed);
  print_payoffs(payoff1,payoff2);
  Game* G=new Game(payoff1, payoff2, 100);
  G->play(HOME+"out_s"+to_string(seed)+".dat");
  return 0;
}
