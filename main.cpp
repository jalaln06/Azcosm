#include <iostream>
#include <vector>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
unsigned int init_game(){
        while (true) {
            std::cout << "Choose the amount of players: 2-10 ";
            unsigned int players;
            std::cin >> players;

            if (players < 2 || players > 10) {
                std::cout << "Wrong amount of players! try again"<<'\n';
                continue;
            }
            return players;
        }
}

[[noreturn]] void launch_game(unsigned int players) {
    std::vector<int> vect(players, 0);
    bool win_cond = true;
    while (win_cond) {
        for (int i = 0; i < vect.size(); i++) {
            std::cout<<"Player "<<i+1<<" Rolls"<<std::endl;
            std::cin.get();
            srand (time(NULL));
            int roll =rand() % 12+1;
            if(roll==1){
                std::cout<<"You rolled zero"<<std::endl;
                vect[i]=0;
            }
            else {
                std::cout << "Your rolled: " << roll << " Total score " << vect[i] + roll << std::endl;
                vect[i] += roll;
            }
            if (vect[i] > 100) {
                std::cout << "PLayer " << i+1 << " Won!"<<std::endl;
                win_cond = false;
                break;
            }
        }
        if(!win_cond){
            std::cout<<"Exit"<<std::endl;
            break;
        }

    }
}

int main() {
    std::cout << "Hello, Player!" << std::endl;
    unsigned int players = init_game();
    launch_game(players);
    return 0;
}

