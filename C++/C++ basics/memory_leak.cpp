#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

/*  Simple bet game to demonstrate memory leak.
 Jack, Queen, King - shuffle cards
 Guess the position of Queen.
 if guess correctly, takes 3 times of money bet, else lose bet amount
*/

int cash = 100;

void play(int bet){
    char *c = new char[3]; //This goes on HEAP memory
    c[0] = 'J', c[1] = 'Q', c[2] = 'K';
    /*
        if you do not free up heap memory then it stays there,
        application memory will keep on increasing, so 
        once you allocate c*, it is important to free up that 
        or heap will keep allocating separate memory each time shuffling.
    */
    //char c[3] = {'J','Q','K'};
    cout << "Shuffling..." << endl;
    srand(time(NULL));
    for (int i =0;i <5; i++){
        int x = rand() %3;
        int y = rand() % 3;
        int temp = c[x];
        c[x] = c[y];
        c[y] = temp;
    }    
    int playerGuess;
    cout << "What's the position of queen? 1, 2 or 3? " <<endl;
    cin >> playerGuess;
    if(c[playerGuess-1] == 'Q'){
        cash += 3*bet;
        cout << "You win! Result : " << c[0] << " " << c[1] << " " << c[2] << ", Total cash: " << cash << endl;
    }else{
        cash -= bet;
        cout << "You lose!  Result : " << c[0] << " "<< c[1] << " " << c[2] << ", Total cash: " << cash << endl;
    }
    free(c); 
    //check memory consmption with commenting this line to see how memory goes high 
    //when you run this in Task Manager/Activity manager.
}

int main(){

    int betAmt = 0;

    while(cash > 0){
        cout << "Enter bet amount : " <<endl;
        cin >> betAmt;
        if(betAmt == 0 || betAmt > cash) break;
        play(betAmt);
    }
    return 0;
}