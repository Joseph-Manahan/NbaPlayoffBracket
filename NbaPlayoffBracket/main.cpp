//
//  main.cpp
//  NbaPlayoffBracket
//
//  Created by Joseph Manahan on 5/1/23.
//

#include <iostream>

using namespace std;

class player {
public:
    int points_range;
    int playerNum;
    string playerName;
    string position;
    int age;
    int height;
};

class team {
public:
    string team_name;
    player pg;
    player sg;
    player sf;
    player pf;
    player c;
    int sum_scores;
    int rank;
    int addPoints() {
        int total_points;
        total_points = pg.points_range + sg.points_range + sf.points_range + pf.points_range + c.points_range;
        return total_points;
    }
};

class league {
public:
    team team1;
    team team2;
    team team3;
    team team4;
    team team5;
    team team6;
    team team7;
    team team8;
    void rankTeams() {
        team1.sum_scores = team1.addPoints();
        team2.sum_scores = team2.addPoints();
        team3.sum_scores = team3.addPoints();
        team4.sum_scores = team4.addPoints();
        team5.sum_scores = team5.addPoints();
        team6.sum_scores = team6.addPoints();
        team7.sum_scores = team7.addPoints();
        team8.sum_scores = team8.addPoints();
        
        team* teams[8] = { &team1, &team2, &team3, &team4, &team5, &team6, &team7, &team8 };
        
        sort(teams, teams + 8, [](team* a, team* b) { return a->sum_scores > b->sum_scores; });
        
        for (int i = 0; i < 8; i++) {
            teams[i]->rank = i + 1;
        }
    }
};

class playerList {
public:
    PlayerList() {
            head* = nullptr;
            tail* = nullptr;
        }
        
        ~PlayerList() {
            player* current = head;
            while (current != nullptr) {
                player* next = current->nextPlayer;
                current = next;
            }
        }
        
        void addPlayer(int points_range, int playerNum, string playerName, string position, int age, int height) {
            player* newPlayer = new player;
            newPlayer->points_range = points_range;
            newPlayer->playerNum = playerNum;
            newPlayer->playerName = playerName;
            newPlayer->position = position;
            newPlayer->age = age;
            newPlayer->height = height;
            newPlayer->nextPlayer = nullptr;
            
            if (head == nullptr) {
                head = newPlayer;
                tail = newPlayer;
            } else {
                tail->nextPlayer = newPlayer;
                tail = newPlayer;
            }
        }
        
        void printPlayers() {
            player* current = head;
            while (current != nullptr) {
                cout << "Player Name: " << current->playerName << endl;
                cout << "Points Range: " << current->points_range << endl;
                cout << "Player Number: " << current->playerNum << endl;
                cout << "Position: " << current->position << endl;
                cout << "Age: " << current->age << endl;
                cout << "Height: " << current->height << endl;
                cout << endl;
                current = current->nextPlayer;
            }
        }
        
    private:
        player* head;
        player* tail;
};

class teamList {
public:
    teamList() {
        head* = nullptr;
        tail* = nullptr;
    }
    void addTeam (string team_name, player player, int sum_scores, int rank, vector<string> roster) {
        team* newTeam = new team;
        newTeam -> team_name = team_name;
        newTeam -> sum_scores = sum_scores;
        newTeam -> rank = rank;
        newTeam -> roster = roster;
        newTeam -> nextTeam = nullptr;
        
        if (head == nullptr) {
            head = newTeam;
            tail = newTeam;
        } else {
            tail -> nextTeam = newTeam;
            tail = newTeam;
        }
        
    void rankTeams() {
        int rank = 1;
        team* currentTeam = head;
        
        while (currentTeam != nullptr) {
            int currentSumScores = currentTeam->sum_scores;
            int numTeamsAhead = 0;
            
            team* otherTeam = head;
            while (otherTeam != nullptr) {
                if (otherTeam != currentTeam && otherTeam->sum_scores > currentSumScores) {
                    numTeamsAhead++;
                }
                otherTeam = otherTeam->nextTeam;
            }
            
            currentTeam->rank = rank + numTeamsAhead;
            
            currentTeam = currentTeam->nextTeam;
            rank++;
            }
        }
        void createBracket() {
            int numTeams;
            team* currentTeam = head;
            while (currentTeam != nullptr) {
                numTeams++
                currentTeam = currentTeam -> nextTeam;
            }
            int numPlayoffTeams = 8;
            team* playOffTeam[numPlayoffTeams];
            currentTeam = head;
            for (int i=0; i<numPlayoffTeams;i++) {
                playoffTeams[i] = currentTeam;
                currentTeam= currentTeam -> nextTeam;
            }
            int matchUp[numPLayoffTeams/2][2];
            int j = 0;
            for (int i = 0; i < numPlayoffTeams/2; i++) {
                matchUp[i][0] = j;
                matchUp[i][1] = numPlayoffTeams - j - 1;
                j++;
            }
            for (int i=0; i < numPlayoffTeams/2; i++) {
                cout << playoffTeams[matchUp[i][0]]->team_name << "vs" << playoffTeams[matchUp[i][1]] << endl;
            }
        }
    }
}
