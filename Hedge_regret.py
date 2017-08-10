#! usr/bin/python

import sys
from math import *

def play(T):
    print "--------------Play our algo  "+str(T)+"-------------"
    w1=0 #log of the weight of strat1
    w2=0 #log of the weight of strat2
    T0=int(T/4.0)+1 #Before T0 strat1 wins 1, strat2 wins 0. After T0, strat1 wins 0 and strat2 wins 1.
    G1=0 #Gain of strat1
    G2=0 #Gain of strat2
    G_algo=0
    for t in range(1,T0+1):
        G1=G1+1
        w1=w1+1/sqrt(t)
        G_algo= G_algo+1/(1+exp(w2-w1))
    for t in range(T0+1,T+1):
        G2=G2+1
        w2=w2+1/sqrt(t)
        G_algo=G_algo+exp(w2-w1)/(1+exp(w2-w1))
    print "gain algo : "+str(G_algo)
    print "gain strat1 : "+str(G1)
    print "gain strat2 : "+str(G2)
    print "regret "+str(G2-G_algo)


def play_h(T):
    print "--------------Play regular hedge  "+str(T)+"-------------"
    w1=0
    w2=0
    T0=int(T/4.0)+1
    G1=0
    G2=0
    G_hedge=0
    for t in range(1,T0+1):
        G1=G1+1
        w1=w1+1
        G_hedge= G_hedge+1/(1+exp((w2-w1)/sqrt(t)))
    for t in range(T0+1,T+1):
        G2=G2+1
        w2=w2+1
        G_hedge=G_hedge+exp((w2-w1)/sqrt(t))/(1+exp((w2-w1)/sqrt(t)))
    print "gain hedge : "+str(G_hedge)
    print "gain strat1 : "+str(G1)
    print "gain strat2 : "+str(G2)
    print "regret "+str(G2-G_hedge)




def main():
    play(10)
    play(20)
    play(50)
    play(100)
    play(10000)


    play_h(10)
    play_h(20)
    play_h(50)
    play_h(100)
    play_h(10000)

if __name__=='__main__':
    main()
