#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;
// Rock Paper Scissor
char getUserChoice();
char getComputerChoice();
void showChoice(char choice);
void chooseWinner(char player, char computer);
// Tic Tac Toe
void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);
// Hangman
void hangman();
// Main Function
int main(){
	int choice;
	char playAgain;
	do {
		system("cls");
		cout<<" _____________________________________________________________________________________________________________________________________________ " << endl;
	    cout<<" ||_________________________________________________________________________________________________________________________________________|| " << endl;
	    cout<<" || __        _______ _     ____ ___  __  __ _____   _____ ___     ____    _    __  __ _____   ____ _____ _   _ ____ ___ ___                ||" << endl;
	    cout<<" || \\ \\      / / ____| |   / ___/ _ \\|  \\/  | ____| |_   _/ _ \\   / ___|  / \\  |  \\/  | ____| / ___|_   _| | | |  _ \\_ _/ _ \\               ||" << endl;
	    cout<<" ||  \\ \\ /\\ / /|  _| | |  | |  | | | | |\\/| |  _|     | || | | | | |  _  / _ \\ | |\\/| |  _|   \\___ \\ | | | | | | | | | | | | |              ||" << endl;
	    cout<<" ||   \\ V  V / | |___| |__| |__| |_| | |  | | |___    | || |_| | | |_| |/ ___ \\| |  | | |___   ___) || | | |_| | |_| | | |_| |              ||" << endl;
	    cout<<" ||   \\_ /\\_/  |_____|_____\\____\\___/|_|  |_|_____|   |_| \\___/   \\____/_/   \\_\\_|  |_|_____| |____/ |_|  \\___/|____/___\\___/               ||" << endl;
	    cout<<" ||_________________________________________________________________________________________________________________________________________|| " << endl;
	    cout<<" ||_________________________________________________________________________________________________________________________________________|| " << endl;
		do {
			cout<<"\nSelect Game To Play\n";
			cout<<"1) Hangman \n2) Tic Tac Toe \n3) Rock Paper Scissor \n4) Exit\nYour Choice: ";
			cin>>choice;
			bool valid=false;
    		do {
        		if(cin.fail()) {
            		cout<<"\nInvalid Input! Please Enter an Integer.\n";
            		cin.clear();
            		cin.ignore(1000,'\n');
            		cout<<"Select Game To Play\n";
					cout<<"1) Hangman \n2) Tic Tac Toe \n3) Rock Paper Scissor \n4) Exit\nYour Choice: ";
					cin>>choice;
        		} else {
            		valid = true;
        		}
    		} while (!valid);
		} while ( choice<1  || choice>4);
		if (choice==4) {
			cout<<"\nThanks for playing!\n";
			break;
		}
		cout<<"\n";
		if (choice==1){
			// Hangman
			do {
				system("cls");
				hangman();
				cout<<"\nPlay again? (y/n): ";
				cin>>playAgain;
				while(playAgain != 'y' && playAgain != 'Y' && playAgain != 'n' && playAgain != 'N') {
					cout<<"Invalid input! Please enter y or n: ";
					cin>>playAgain;
				}
			} while(playAgain == 'y' || playAgain == 'Y');
    	} else if (choice==2){
		// Tic Tac Toe
			do {
				system("cls");
				cout<<" ________________________________________________________________________________________________________ " << endl;
			    cout<<" ||____________________________________________________________________________________________________|| " << endl;
			    cout<<" ||          _____ ___ ____   _____  _    ____   _____ ___  _____                                      ||" << endl;
			    cout<<" ||         |_   _|_ _/ ___| |_   _|/ \\  / ___| |_   _/ _ \\| ____|                                     ||" << endl;
			    cout<<" ||           | |  | | |       | | / _ \\| |       | || | | |  _|                                       ||" << endl;
			    cout<<" ||           | |  | | |___    | |/ ___ \\ |___    | || |_| | |___                                      ||" << endl;
			    cout<<" ||           |_| |___\\____|   |_/_/   \\_\\____|   |_| \\___/|_____|                                     ||" << endl;
			    cout<<" ||____________________________________________________________________________________________________|| " << endl;
			    cout<<" ||____________________________________________________________________________________________________|| " << endl;
			    cout<<"\n\n";
				char spaces[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    			char player = 'X';
    			char computer = 'O';
    			bool running = true;
    			cout<<"You: X \nComputer:0 \n";
    			drawBoard(spaces);
    			while(running){
        			playerMove(spaces, player);
        			drawBoard(spaces);
        			if(checkWinner(spaces, player, computer)){
            			running = false;
            			break;
        			} else if(checkTie(spaces)){
            			running = false;
            			break;
        			}
        			computerMove(spaces, computer);
        			drawBoard(spaces);
        			if(checkWinner(spaces, player, computer)){
            			running = false;
            			break;
        			} else if(checkTie(spaces)){
            			running = false;
            			break;
        			}
    			}
    			cout<<"\nPlay again? (y/n): ";
				cin>>playAgain;
				while(playAgain != 'y' && playAgain != 'Y' && playAgain != 'n' && playAgain != 'N') {
					cout<<"Invalid input! Please enter y or n: ";
					cin>>playAgain;
				}
			} while(playAgain == 'y' || playAgain == 'Y');
		} else if (choice==3){
		// Rock Paper Scissor
			do {
				system("cls");
				char player,computer;
				player = getUserChoice();
				cout<<"Your choice: ";
				showChoice(player);
				computer = getComputerChoice();
				cout<<"Computer's choice: ";
				showChoice(computer);
				chooseWinner(player, computer);
				cout<<"\nPlay again? (y/n): ";
				cin>>playAgain;
				while(playAgain != 'y' && playAgain != 'Y' && playAgain != 'n' && playAgain != 'N') {
					cout<<"Invalid input! Please enter y or n: ";
					cin>>playAgain;
				}
			} while(playAgain == 'y' || playAgain == 'Y');
		}
	} while (true);
	return 0;
}
// Rock Paper Scissor
char getUserChoice(){
	char player;
	cout<<" _______________________________________________________________________________________________________________________________________________ " << endl;
    cout<<" ||___________________________________________________________________________________________________________________________________________|| " << endl;
    cout<<" ||       ____   ___   ____ _  __  ____   _    ____  _____ ____      ____   ____ ___ ____ ____   ___  ____                                    ||" << endl;
    cout<<" ||      |  _ \\ / _ \\ / ___| |/ / |  _ \\ / \\  |  _ \\| ____|  _ \\    / ___| / ___|_ _/ ___/ ___| / _ \\|  _ \\                                   ||" << endl;
    cout<<" ||      | |_) | | | | |   | ' /  | |_) / _ \\ | |_) |  _| | |_) |   \\___ \\| |    | |\\___ \\___ \\| | | | |_) |                                  ||" << endl;
    cout<<" ||      |  _ <| |_| | |___| . \\  |  __/ ___ \\|  __/| |___|  _ <     ___) | |___ | | ___) |__) | |_| |  _ <                                   ||" << endl;
    cout<<" ||      |_| \\_\\\\___/ \\____|_|\\_\\ |_| /_/   \\_\\_|   |_____|_| \\_\\   |____/ \\____|___|____/____/ \\___/|_| \\_\\                                  ||" << endl;
    cout<<" ||___________________________________________________________________________________________________________________________________________|| " << endl;
    cout<<" ||___________________________________________________________________________________________________________________________________________|| " << endl;
    cout<<"\n\n";
	do{
		cout<<"Choose one of the following\n";
		cout<<"'r' for rock\n";
		cout<<"'p' for paper\n";
		cout<<"'s' for scissors\n";
		cin>>player;
		cout<<"\n";
	} while(player != 'r' && player != 'p' && player != 's');
	return player;
}
char getComputerChoice(){
	srand(time(0));
	int num = rand() % 3 + 1;
	switch(num){
		case 1:
			return 'r';
		case 2:
			return 'p';
		case 3:
			return 's';
	}
	return 0;
}
void showChoice(char choice){
	switch(choice){
		case 'r':
			cout<<"Rock\n";
			break;
		case 'p':
			cout<<"Paper\n";
			break;
		case 's':
			cout<<"Scissors\n";
			break;
	}
}
void chooseWinner(char player, char computer){
	switch(player){
		case 'r':
			if(computer == 'r'){
				cout<<"It's a tie!\n";
			} else 
			if(computer == 'p'){
				cout<<"You lose!\n";
			} else {
				cout<<"You win!\n";
			}
			break;
		case 'p':
			if(computer == 'p'){
				cout<<"It's a tie!\n";
			} else 
			if(computer == 's'){
				cout<<"You lose!\n";
			} else {
				cout<<"You win!\n";
			}
			break;
		case 's':
			if(computer == 's'){
				cout<<"It's a tie!\n";
			} else 
			if(computer == 'r'){
				cout<<"You lose!\n";
			} else {
				cout<<"You win!\n";
			}
			break;
	}
}
// Tic Tac Toe
void drawBoard(char *spaces){
    cout<<"\n";
    cout<<"     |     |     "<<"\n";
    cout<<"  "<<spaces[0]<<"  |  "<<spaces[1]<<"  |  "<<spaces[2]<<"  "<<"\n";
    cout<<"_____|_____|_____"<<"\n";
    cout<<"     |     |     "<<"\n";
    cout<<"  "<<spaces[3]<<"  |  "<<spaces[4]<<"  |  "<<spaces[5]<<"  "<<"\n";
    cout<<"_____|_____|_____"<<"\n";
    cout<<"     |     |     "<<"\n";
    cout<<"  "<<spaces[6]<<"  |  "<<spaces[7]<<"  |  "<<spaces[8]<<"  "<<"\n";
    cout<<"     |     |     "<<"\n";
    cout<<"\n";
}
void playerMove(char *spaces, char player){
    int number;
    do{
        cout<<"Enter a spot to place a marker (1-9): ";
        cin>>number;
        bool valid=false;
    	do {
        	if(cin.fail()) {
            	cout<<"Invalid Input! Please Enter an Integer.\n";
            	cin.clear();
            	cin.ignore(1000,'\n');
        	} else {
            	valid = true;
        	}
    	} while (!valid);
        number--;
        if(spaces[number] == ' '){
           spaces[number] = player;
           break; 
        }
    } while(!number > 0 || !number < 8);
}
void computerMove(char *spaces, char computer){
    int number;
    srand(time(0));
    while(true){
        number = rand() % 9;
        if(spaces[number] == ' '){
            spaces[number] = computer;
            break;
        }
    }
}
bool checkWinner(char *spaces, char player, char computer){
    if((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2])){
        spaces[0] == player ? cout<<"YOU WIN!\n" : cout<<"YOU LOSE!\n";
    }
    else if((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5])){
        spaces[3] == player ? cout<<"YOU WIN!\n" : cout<<"YOU LOSE!\n";
    }
    else if((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8])){
        spaces[6] == player ? cout<<"YOU WIN!\n" : cout<<"YOU LOSE!\n";
    }
    else if((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6])){
        spaces[0] == player ? cout<<"YOU WIN!\n" : cout<<"YOU LOSE!\n";
    }
    else if((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7])){
        spaces[1] == player ? cout<<"YOU WIN!\n" : cout<<"YOU LOSE!\n";
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8])){
        spaces[2] == player ? cout<<"YOU WIN!\n" : cout<<"YOU LOSE!\n";
    }
    else if((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8])){
        spaces[0] == player ? cout<<"YOU WIN!\n" : cout<<"YOU LOSE!\n";
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6])){
        spaces[2] == player ? cout<<"YOU WIN!\n" : cout<<"YOU LOSE!\n";
    }
    else
        return false;
    return true;
}
bool checkTie(char *spaces){
    for(int i=0;i<9;i++){
        if(spaces[i] == ' '){
            return false;
        }
    }
    cout<<"IT'S A TIE!\n";
    return true;
}
// Hangman
void hangman(){
	string words[50] = {
    "apple", "bread", "chair", "dance", "eagle",
    "flame", "grape", "house", "input", "joker",
    "knife", "lemon", "music", "night", "ocean",
    "piano", "queen", "river", "stone", "tiger",
    "umbra", "voice", "water", "xenon", "yacht",
    "zebra", "angel", "brave", "cloud", "dream",
    "earth", "fruit", "glass", "heart", "image",
    "juice", "karma", "light", "money", "north",
    "orbit", "peace", "quiet", "radio", "smile",
    "table", "unity", "vivid", "world", "youth"
	};
    srand(time(0));
    string secretWord = words[rand() % 50];
	char guessedWord[5] = {'_', '_', '_', '_', '_'};
    int wrongGuesses = 0;
    bool found;
	cout<<" __________________________________________________________________________________________________________ " << endl;
    cout<<" ||______________________________________________________________________________________________________|| " << endl;
    cout<<" ||     _   _    _    _   _  ____ __  __    _    _   _    ____    _    __  __ _____                      ||" << endl;
    cout<<" ||    | | | |  / \\  | \\ | |/ ___|  \\/  |  / \\  | \\ | |  / ___|  / \\  |  \\/  | ____|                     ||" << endl;
    cout<<" ||    | |_| | / _ \\ |  \\| | |  _| |\\/| | / _ \\ |  \\| | | |  _  / _ \\ | |\\/| |  _|                       ||" << endl;
    cout<<" ||    |  _  |/ ___ \\| |\\  | |_| | |  | |/ ___ \\| |\\  | | |_| |/ ___ \\| |  | | |___                      ||" << endl;
    cout<<" ||    |_| |_/_/   \\_\\_| \\_|\\____|_|  |_/_/   \\_\\_| \\_|  \\____/_/   \\_\\_|  |_|_____|                     ||" << endl;
    cout<<" ||______________________________________________________________________________________________________|| " << endl;
    cout<<" ||______________________________________________________________________________________________________|| " << endl;
    while (wrongGuesses < 6){
        cout<<"\nWord: ";
        for(int i=0;i<5;i++)
            cout<<guessedWord[i]<<" ";
        cout<<"\nWrong guesses: "<<wrongGuesses<<"/6\n";
        char guess;
        cout<<"Enter a lowercase letter: ";
        cin>>guess;
        found = false;
        for(int i=0;i<5;i++){
            if (secretWord[i] == guess && guessedWord[i] == '_'){
                guessedWord[i] = guess;
                found = true;
            }
        }
        if (!found)
            wrongGuesses++;
        bool win = true;
        for(int i=0;i<5;i++){
            if (guessedWord[i] == '_'){
                win = false;
                break;
            }
        }
        if (win){
            cout<<"\nCongratulations! You guessed the word: "<<secretWord<<"\n";
            return;
        }
    }
    cout<<"\nYou lost! The correct word was: "<<secretWord<<"\n";
}