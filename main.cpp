#include <iostream>
#include <cmath>
#include <map>
#include "Player.h"
using namespace std;

int developmentCoefficient = 20; //determines for Elo Adjustment how strongly a result affects changes

double getScorePercent(int scoreDifference) {   //accepts a number between -14 and 14 and converts it into a range
                                                //between 0 and 1 (-14 -> 0, 0 -> 0.5, 14 -> 1)
    return ((double)scoreDifference+14)/28;
}

int getEloAdjustment(int elo, int opponentsElo, int score, int opponentsScore) { //performs elo calculation by using
    double scoreDifference = getScorePercent(score-opponentsScore);   //rank difference between two
                                                                                    //players to create an expected
                                                                                    //score (point difference between
                                                                                    //two players) and then adjusts
                                                                                    //players ranks based on actual
                                                                                    //point difference after a game
                                                                                    //returning the adjustment value
    double expectedScore = 1/(1+pow(10,(double)(opponentsElo-elo)/400));
    return round(developmentCoefficient*(scoreDifference-expectedScore));
}

int getEloAdjustment(Player playerA, Player playerB) { //gets rank adjustment, add to player A and subtract player B
    return getEloAdjustment(playerA.getRank(), playerB.getRank(), playerA.getScore(), playerB.getScore());
}

int main() {
    cout << "Enter Player Count: ";
    int playerCount;
    cin >> playerCount;

    map<Player*, int>players; //stores each player and their total rank adjustment
    for(int i = 0; i < playerCount;) {
        cout << "Player " << ++i << endl;
        cout << "Enter Player Name: ";
        string name;
        cin >> name;

        cout << "Enter Player Race: ";
        string race;
        cin >> race;

        cout << "Enter Player Rank: ";
        int rank;
        cin >> rank;

        cout << "Enter Race Rank: ";
        int raceRank;
        cin >> raceRank;

        cout << "Enter Player Score: ";
        int score;
        cin >> score;

        players[new Player(name, race, rank, raceRank, score)] = 0;
    }

    //TODO: Turn these loops into recursive functions I DESPISE NESTED LOOPS
    for(auto it1=players.begin();it1!=players.end();it1++) {
        for(auto it2=next(it1);it2!=players.end();it2++) {
            cout << "Comparing: " << it1->first->getName() << ":" << it1->first->getRank() << " <--> " << it2->first->getName() << ":" << it2->first->getRank() << endl;
        }
    }

}