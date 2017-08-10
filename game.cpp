//
// Created by Heliou on 29/06/2017.
//

#include "game.h"

Game::Game(double** payoff1, double** payoff2, int steps) {
  this->steps = steps;
  P1 = new Player(0, payoff1);
  P2 = new Player(1, payoff2);
  potential = potential_func(payoff1,payoff2);
  print_potential();
}

Game::~Game() {
  delete P1;
  delete P2;
  for (int i=0;i<2;i++)
    delete[] potential[i];
}

void Game::play(const string &outfile) {
  ofstream output;
  output.open(outfile.c_str());
  if (!output.is_open()) {
    cerr << "Cannot write to " << outfile << endl;
    cerr << " If it doesn't exist don't forget to create the output repository" << endl;
    exit(-1);
  }
  double res;
  bool stop=false;
  for (int i = 0; i < steps; i++) {
    if (i % 1 == 0 || stop ) {
      cout << " STEP " << i;
      cout << " potential " << res<<" ";
      cout<<*P1<<" "<<*P2<<endl;
      output<<P1->proba_strat[0]<<" "<<P2->proba_strat[0]<<endl;
    }

    res = play_one_turn(i, stop);
    if (stop)
      break;
  }
  cout<<"END GAME"<<endl;
  output.close();
}

Player* Game::get_Player(int id){
  if (id==0)
    return P1;
  return P2;
}

double Game::play_one_turn(int step,bool &stop) {
  /*
   * Play one round of Hedge.
   * Input are the number of the current round (step)
   * The output is the potential value.
   */
  Player* P;
  double gamma = 1 /sqrt(step + 1); //step size for hedge algorithm. //gamma = 1 / sqrt(step + 1)
  double** utility= new double*[2]; // utility
  for (int i = 0; i < 2; i++) {
    utility[i] = new double[2];
  }
  int i, j;
  for (i = 0; i<2; i++) {
    P = get_Player(i);
    P->setStrat(P->draw_proba());
  }
  utility[0] = P1->utility(P2->getStrat());
  utility[1] = P2->utility(P1->getStrat());

  for (i = 0; i < 2; i++) {
    P = get_Player(i);
    if (!P->isConverged()) {
      for (j = 0; j < 2; j++) {
        P->y_strat[j] = P->y_strat[j] + gamma * utility[i][j];
      }
    }
    P->update_proba();
  }
  stop=true;
  for (i = 0; i < 2; i++) {
    P = get_Player(i);
    if (!P->isConverged()) {
        stop = false;
    }
  }
  for (i=0;i<2;i++)
  delete[] utility[i];
  return potential[0][0]*P1->proba_strat[0]*P2->proba_strat[0]+potential[1][0]*P1->proba_strat[1]*P2->proba_strat[0]+potential[0][1]*P1->proba_strat[0]*P2->proba_strat[1]+potential[1][1]*P1->proba_strat[1]*P2->proba_strat[1];;
}

double** Game::potential_func(double ** payoff1,double** payoff2){
  double test1 = payoff1[0][0]- payoff1[0][1]+ payoff2[1][0]- payoff2[1][1];
  double test2 = payoff1[1][0] - payoff1[1][1] +payoff2[0][0]- payoff2[0][1];
  if (test1 != test2)
    cerr<< " this is not a potential game "<<endl;
  double** res = new double* [2];
  for (int i=0;i<2;i++){
    res[i] = new double[2];
  }
  res[0][0] = 1;
  res[1][0] = res[0][0] - payoff1[0][0] + payoff1[0][1];
  res[0][1] = res[0][0] - payoff2[0][0] + payoff2[0][1];
  res[1][1] = res[0][1] - payoff1[1][0] + payoff1[1][1];
  return res;
}

void Game::print_potential(){
  cout<<potential[0][0]<<" "<<potential[1][0]<<" "<<potential[0][1]<<" "<<potential[1][1]<<" "<<endl;
};
