#include<iostream>
#include<ctime> // for the randomization
#include<string> // for string functions
#include<fstream> // for creating and writing on text files
#include<cstdlib> // for some functions 
#include <sstream> // for the convertion of int to string
#include <Windows.h> // for the type function to work 

using namespace std;

// utility
void delay(float seconds){ //delay function per cout
    clock_t startClock = clock();
    float secondsAhead = seconds * CLOCKS_PER_SEC;
    // pause until time
    while(clock() < startClock+secondsAhead);
    return;
}

void Type(const char * p, float Speed, float Wait){ //typing Effect
	if(NULL == p){
		return;
	}
	
	while (*p){
		printf("%c\xDB", *p++);
		Sleep(Speed/2);
		printf("\b \b");
		Sleep(Speed/2);
	}
	Sleep(100*Wait);
}

void createSave(){ // creates save file for highscore
	ifstream saveFile("highscore.txt");
	if(!saveFile.is_open()){
		ofstream saveFile;
		saveFile.open ("highscore.txt");
		saveFile <<"none\n0 0";
		saveFile.close();
		
		if(!saveFile){ // Checks if the file has been created and comments ERROR if it doesn't
			system("cls");
			cout << "\n\n\n\n\t\t\t\t ERROR CREATING THE FILE!";
		}
	}
	saveFile.close();
}

createProfile(string& name, string& password){ // creates a profile save
	string fileName = name + ".txt";
	ifstream streamPoints(fileName.c_str());
		if(!streamPoints.is_open()){
			ofstream streamPoints;
			streamPoints.open (fileName.c_str());
			streamPoints << name <<endl;
			streamPoints << password<<endl;
			streamPoints << "10" << endl;
			streamPoints << "0" << endl;
			
			if(!streamPoints){
				system("cls");
				cout << "\n\n\n\n\t\t\t\t ERROR CREATING THE FILE!";
		}
	}
	streamPoints.close();
}



void getSave(string& name, string& highscoreName, int& highScore, int& highestRoll){ // loads the highscore save
	ifstream saveFile("highscore.txt");
	if(saveFile.is_open()){
		getline(saveFile, name);
		while(saveFile >> highScore >> highestRoll){
			highscoreName = name;
			highScore = highScore;
			highestRoll = highestRoll;
		}
		saveFile.close();
	}
	
}


void terminate(int& game){ // terminates the game
	system("cls");
		Type("\n\n\n\t\t\tThank You For Playing!!......", 60, 0.5);
		Type("\n\t\t\tWe are now Terminating the game......", 60, 0.5);
		Type("\n\t\t\tIf you are out of luck......", 60, 0.5);
		Type("\n\t\t\tJust create a new profile......", 60, 0.5);
		Type("\n\t\t\tBYE BYE......", 60, 0.5);
		cout<<"\n\n\n\n\n\n\n";
		game = 1;
		
}

void load(float time){ // Fake Loading
	system("cls");
	cout<< "\n\n\t\t\t________________________________________________________";
	cout<<"\n\n\t\t\t\t\t Game of the Dying Luck!!";
	cout<< "\n\n\t\t\t________________________________________________________";
		    		
	delay(time/2);		    		

	system("cls");
		    		
	cout<< "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t________________________________________________________";
	cout<<"\n\n\t\t\t\t\t Game of the Dying Luck!!";
	cout<< "\n\n\t\t\t________________________________________________________";
	
	Type("\n\n\t\t\t\t\t\tLOADING........", 30, 0);
	delay(time/2);
		    		
	system("cls");
	cout<< "\n\n\t\t\t________________________________________________________";
	cout<<"\n\n\t\t\t\t\t Game of the Dying Luck!!";
	cout<< "\n\n\t\t\t________________________________________________________";
}

//FUNCTIONS

void tutorial(){ // brings out the rules/tutorial
	system("cls");
   	cout<< "\n\n\t\t\t________________________________________________________";
	cout<<"\n\n\t\t\t\t\t\t[Basic Rules]";
	cout<< "\n\n\t\t\t________________________________________________________";
		
	cout<<"\n\n\t\t\t [Black = -10 points]";
	cout<<"\n\n\t\t\t [Red = +2 points]";
	cout<<"\n\n\t\t\t [Blue = +3 points]";
	cout<<"\n\n\t\t\t [Green = +4 points]";
	cout<<"\n\n\t\t\t [Yellow = +5 points]";
	cout<< "\n\n\t\t\t________________________________________________________";
	cout<<"\n\n\t\t\t";
	system("pause");
		
	system("cls");
	cout<< "\n\n\t\t\t________________________________________________________";
	cout<<"\n\n\t\t\t\t\t [Basic Rules Doubles]";
	cout<< "\n\n\t\t\t________________________________________________________";
		
	cout<<"\n\n\t\t\t [Black = DEATH ]";
	cout<<"\n\n\t\t\t [Red = -1 Roll ]";
	cout<<"\n\n\t\t\t [Blue = Skip Roll ]";
	cout<<"\n\n\t\t\t [Green = +REVIVE ]";
	cout<<"\n\n\t\t\t [Yellow = Jackpot Double Rolls ]";
	cout<< "\n\n\t\t\t________________________________________________________";
	cout<<"\n\n\n\t\t\t";
	system("pause");
}

void setHighScores(string& name, string& highscoreName, int& numberOfRolls, int& points, int& highscore, int& highestRoll){ // saves the highscore
	if(points > highscore && numberOfRolls > highestRoll){
		highscoreName = name;
		highscore = points;
		highestRoll = numberOfRolls;
		
		ofstream saveFile;
		saveFile.open ("highscore.txt");
		saveFile << name << endl;
		saveFile << points << " " << numberOfRolls;
		saveFile.close();
	}
}

void loadPoints(string& name, string& password, int& points, int& firstPlay){ //load points
	string fileName = name + ".txt";
	ifstream streamPoints(fileName.c_str());
	if(streamPoints.is_open()){
		getline(streamPoints, name);
		
		getline(streamPoints, password);
		
		string tempPoints;
		stringstream pp;
		getline(streamPoints, tempPoints);
		pp << tempPoints;
		pp >> points;
		
		string tempFF;
		stringstream ff;
		getline(streamPoints, tempFF);
		ff << tempFF;
		ff >> firstPlay;
		
		streamPoints.close();
	}
}

void savePoints(string& name, string& password, int& points){ // saves the points
	string fileName = name + ".txt";
	ofstream streamPoints;
	streamPoints.open(fileName.c_str());
	streamPoints << name <<endl;
	streamPoints << password<<endl;
	streamPoints << points << endl;
	streamPoints << "1" << endl;
	
}

//Handles double effects
static void handleDoubleEffects(int& points, int color1, int color2, int& numberOfRolls, int& jackpotRolls, bool& revive, bool& dead, bool& skipRoll, string& doubleEffect){ 
	
    int effectNum;
    if(color1 == 1 && color2 == 1) { // deterimines the color of the double effect
    	effectNum = 1;
	}else if(color1 == 2 && color2 == 2){
    	effectNum = 2;
	}else if(color1 == 3 && color2 == 3){
		effectNum = 3;
	}else if(color1 == 4 && color2 == 4){
		effectNum = 4;
	}else if(color1 == 5 && color2 == 5){
		effectNum = 5;
	}else {
		effectNum = 0;
	}
    
    switch(effectNum){ // determines the effect of the color
        case 1: //double black
            if(!revive){ 
            	delay(2);
            	system("color 8");
            	dead = true;
            	doubleEffect = "\n\n\t\t\t\t\t  DEAD!";
			}else{
				revive = false;
				doubleEffect = "\n\n\t\t\t\t\t  REVIVED!";
			}
            break;
        case 2: //double blue
        		system("color 1");
            	skipRoll = true;
            	doubleEffect = "\n\n\t\t\t\t\t  ROLL SKIP!";
            break;
        case 3://double yellow
        		system("color 6");
            	jackpotRolls = 3;
            	doubleEffect = "\n\n\t\t\t JACKPOT!! POINTS DOUBLED ROLLS x3!";
            break;
        case 4://double green
        		system("color 2");
            	revive = true;
            	doubleEffect = "\n\n\t\t\t\t\t YOU GOT A REVIVE!";
            break;
        case 5://double red
        		system("color 4");
        		numberOfRolls--;
            	doubleEffect = "\n\n\t\t\t\t\t ROLLS DECREASED!";
            break;
        default:
        		doubleEffect = "";
        	break;
    }
}

void roll(int& dice, string& color, int& addPoints, bool& skipRoll, bool& revive){ // Rolls the dice
    dice = rand() % 5 + 1; // randomize the number of the dice from 1 to 5
    if(skipRoll){ // checks if you have a skipp roll and then returns the dice to default if you do
    	dice = 0;
	}
    switch(dice){ // deterimines the color of the dice
        case 1:
        	if(revive){
        		color = "Black [ +1 ]";
            	addPoints = 1;
			}else{
				color = "Black [ -10 ]";
            	addPoints = -10;
			}
            
            break;
        case 2:
            color = "Blue [ +3 ]";
            addPoints = 3;
            break;
        case 3:
            color = "Yellow [ +5 ]";
            addPoints = 5;
            break;
        case 4:
            color = "Green [ +4 ]";
            addPoints = 4;
            break;
        case 5:
            color = "Red [ +2 ]";
            addPoints = 2;
            break;
        default:
        	color = "blank";
        	skipRoll = false;
        	break;
    }
    return;
}


//MAIN
int main()
{
	srand(time(0));
	createSave();
	system("color d"); // change font color
	
	// VARIABLES
    int points = 10, pointsUsed = 5, dice1 = 1, dice2 = 1, numberOfRolls = 0, highestRoll = 0, highscore = 0;
    int game = 0, addPoints1 = 0, addPoints2 = 0, result = 0, firstPlay = 0, jackpotRolls = 0;
    
    bool revive = false, dead = false, skipRoll = false;
    string color1, color2, doubleEffect, name, password, tempPassword = "null", highscoreName;
    char response;
    
    
    getSave(name, highscoreName, highscore, highestRoll);
    cout<<highscore;
    
    load(1);
	
	system("cls");
	cout<< "\n\n\n\n\n\n\n\n\n\t\t\t________________________________________________________";
	Type("\n\n\t\t\t\t\t Welcome to Dying Luck", 60, 0);
	Type("\n\n\t\t\t\t Where You Try Your Luck Until You Die", 60, 0);
	cout<< "\n\n\t\t\t________________________________________________________";
	delay(2);
	
	cin.clear(); cin.sync(); 
	
	while(tempPassword != password){ // checks if the password is correct for the profile
		system("cls");
	    cout<< "\n\n\n\n\n\n\n\n\n\t\t\t________________________________________________________";
		cout<<"\n\n\t\t\t\t\t     The Dying Luck";
		cout<< "\n\n\t\t\t________________________________________________________";
		
		
		
		if(tempPassword != password && tempPassword != "null"){
			cout<<"\n\n\n\t\t\t\t [ Incorrect Username or Password ]";
		}
		cout << "\n\n\t\t\t      [Enter a New name to create a new profile]";
		
		Type("\n\n\t\t\t\t Please Enter Your Name: ",30,0);
		getline(cin, name);
		
		Type("\n\t\t\t\t Please Enter Your Password: ",30,0);
		getline(cin, tempPassword);
		
		createProfile(name, tempPassword);
		loadPoints(name, password, points, firstPlay);
	}
    
    load(1);
    
    if(firstPlay == 0 ){ // checks if it's your first time playing and forces you to see the tutorial if yes
    	tutorial();
		
	}
    
    system("cls");
    cout<< "\n\n\t\t\t________________________________________________________";
	cout<<"\n\n\t\t\t\t\t Welcome to Dying Luck \n\n\t\t\t\t\t\t " << name;
	cout<< "\n\n\t\t\t________________________________________________________";
	
	if(highscoreName != "none"){ // checks if there's a highscore if none the Top player won't show
		cout<<"\n\n\n\n\n\n\n\t\t\t\t\t     TOP PLAYER: "<< highscoreName << " \n" ;
		cout<<"\n\t\t\t\t   Highest Points: " << highscore << " Highest Rolls: " << highestRoll;
		cout<< "\n\n\t\t\t________________________________________________________";	
	}
	
    delay(1);
    if(firstPlay != 0){
    	Type("\n\n\n\t\t\t View Rules? [Y][N] ", 30, 0);
    	cin>> response;	
	}
    if(response == 'y' || response == 'Y'){
    	load(1);
    	tutorial();
	}
    
    cin.clear(); cin.sync(); // clears the CIN
    Type("\n\n\n\t\t\t Are you ready to play? [Y][N] ", 30, 0);
    cin >> response;
    
    if(response == 'y' || response == 'Y'){
    	system ("cls");
    	load(1);
    	delay(0.5);
	    
	    
	    while(points > 0){ // checks if you have points to play
	    	delay(0.5);
	    	system("cls");
	    	load(1);
	    	system("color d"); 
	    	cout << "\n\n\t\t\t You have " << points << " points";
	    	delay(1);
	    	Type("\n\n\t\t\t Insert points: ",30,0);
	    	cin>> pointsUsed;
	    	
	    	while(pointsUsed > points){ // Checks if you entered a sufficient points
	    		system("cls");
	    		load(1);
	    		delay(0.5);
	    		cout << "\n\n\t\t\t You have " << points << " remaining points";
	    		delay(0.5);
	    		cout << "\n\n\t\t\t You don't have enough points!. \n\t\t\t Please enter sufficient points: ";
	    		cin.clear(); cin.sync();
	    		cin >> pointsUsed;
			}
	    	if(!cin){ // checks if you entered a real number
	    		system("cls");
	    		load(1);
	    		delay(0.5);
	    		cout << "\n\n\t\t\t You have " << points << " remaining points";
	    		delay(0.5);
	    		cout << "\n\n\t\t\t Error!! please Insert a number: ";
	    		cin.clear(); cin.sync();
	    		cin >> pointsUsed;
			}
	    	
	    	points -= pointsUsed; // subtracts the game points from your points
	    	
	    	system("cls");
	    	load(1);
	    	while(!dead){
		    	cin.clear(); cin.sync();
		    	delay(0.5); 
		    	if(numberOfRolls != 0){
		    		Type("\n\n\t\t\t Test your luck? [Y] ",30, 0);
		    		Type("\n\t\t\t Or Save and Quit? [N] ",30, 0);	
				}else{
					Type("\n\n\t\t\t Test your luck? [Y][N] ",30, 0);
				}
		    	
		    	cin >> response;
		    	
		    	if(response == 'y' || response =='Y'){
		    		system("cls");
		  			srand(time(0));
		  			if(!skipRoll){  // IMPLEMENTS THE ROLL FUNCTION
		  				roll(dice1, color1, addPoints1, skipRoll, revive);
			    		roll(dice2, color2, addPoints2, skipRoll, revive);
						result = addPoints1 + addPoints2;
						if(jackpotRolls != 0){
							result *= 2;
						}
			    		handleDoubleEffects(result, dice1, dice2, numberOfRolls, jackpotRolls, revive, dead, skipRoll, doubleEffect);
			    		delay(1);
					}else{
						color1 = "Skipped";
						color2 = "Skipped";
						skipRoll = false;
					}
		    		
		    		load(1);
		    		
		    		delay(.5);
		    		Type("\n\n\t\t\t First Die = ",30,0);
					cout << color1;
					
					delay(.5);
					Type("\n\t\t\t Second Die = ",30,0);
					cout<< color2 << endl;
					if(revive){
			    		cout << "\n\n\n\t\t\t\t\t\t [ You have a revive! ]";	
					}
					if(jackpotRolls != 0 ){
			    		cout << "\n\n\n\t\t\t\t\t\t [ Jackpot Rolls =  "<< jackpotRolls << " ]";	
					}
					delay(0.2);
			    	cout << "\n\n\n\t\t\t\t\t\t Remaining Points: " << pointsUsed ;
			    	if(result >= 0) cout << " [ +" << result << " ] points";
			    	else cout << " [ " << result << " ] points";
			    	int tempResult = pointsUsed + result;
			    	
			    	if(numberOfRolls == 0 && tempResult <= 0) cout << "\n\n\t\t\t\t\t\t\t\t = 1" << " points";
			    	else cout << "\n\n\t\t\t\t\t\t\t\t = " << tempResult << " points";
			    	
			    	pointsUsed = tempResult;
			    	jackpotRolls--;
			    	numberOfRolls++;
			    	
			    	if(numberOfRolls <= 0 )	numberOfRolls = 0; // makes sure that the number of rolls are positive numbers
					if(jackpotRolls <= 0 )	jackpotRolls = 0; // makes sure that the number of doublerolls are positive numbers
			    	
			    	delay(0.2);
			    	cout <<"\n\n\n\t\t\t\t\t\t Rolls = " << numberOfRolls;
			    	
			    	cout<< "\n\n\t\t\t________________________________________________________";
			    	cout<<"\n\n\n\t\t\t\t\t";
			    	system("pause");
			    	 
			    	if(pointsUsed == 0){
			    		dead = true;
			        	doubleEffect = "\n\tDEAD!";
					}
					
					delay(0.2);
					if(doubleEffect != ""){
						system("cls");
						cout<< "\n\n\n\n\n\n\n\n\n\t\t\t________________________________________________________";
						cout<< doubleEffect;	
						cout<< "\n\n\t\t\t________________________________________________________";
					}else{
						system("cls");
						cout<< "\n\n\n\n\n\n\n\n\n\t\t\t________________________________________________________";
						cout<<"\n\n\t\t\t\t\t Remaining Poins = "<< pointsUsed;	
						cout<< "\n\n\t\t\t________________________________________________________";
						
						if(highscoreName != "none"){
			    			cout<<"\n\n\n\t\t\t TOP PLAYER: ";
							cout<<"\n\n\t\t\t Name: " <<highscoreName<< " \n\n\t\t\t Highest Point: " << highscore << "\n\t\t\t Highest Roll: " << highestRoll;	
							cout<< "\n\n\t\t\t________________________________________________________";
						}
					}
					
				}else{
					//setHighScores(name, highscoreName, numberOfRolls, pointsUsed, highscore, highestRoll);
					points += pointsUsed;
					savePoints(name, password, points);
					dead = true;
				}
			}
			
			if(dead){ // DEATH FUNCTION
				setHighScores(name, highscoreName, numberOfRolls, pointsUsed, highscore, highestRoll);
				system("cls");
				system("color 8");
				load(1);
		    	delay(1);
		    		
		    	system("cls");
		    	if(pointsUsed == highscore && numberOfRolls == highestRoll){
		    		system("color 6");
		    		cout<< "\n\n\t\t\t________________________________________________________";
		    		cout<<"\n\n\t\t\t\t\t Game of the Dying Luck!!";
		    		cout<<"\n\n\t\t\t\t      !!!!!!![ NEW HIGHSCORE ]!!!!!!!";
		    		cout<< "\n\n\t\t\t________________________________________________________";
				}else{
					cout<< "\n\n\t\t\t________________________________________________________";
		    		cout<<"\n\n\t\t\t\t\t !!! [ GAME OVER ] !!!";
		    		cout<< "\n\n\t\t\t________________________________________________________";
				}
				
				delay(0.5);
				cout<< "\n\n\n\t\t\t Your Rolls: " << numberOfRolls << " rolls";
				cout<< "\n\t\t\t Your Points: " << pointsUsed << " points";
				cout<< "\n\t\t\t Remaining Game Points: " << points << " points";
				
				if(highscoreName != "none"){
					cout<<"\n\n\n\t\t\t Top Player: ";
					cout<<"\n\n\t\t\t Name: " <<highscoreName<< " \n\t\t\t Highest Point: " << highscore << "\n\t\t\t Highest Roll: " << highestRoll; 
				}
				
				cout<< "\n\n\t\t\t________________________________________________________";
				Type("\n\n\n\t\t\t Play again? [Y][N] ",30,0);
				cin >> response;
				
				
				if(response == 'y' || response == 'Y'){
					numberOfRolls = 0;
					pointsUsed = 0;
					dead = false;
				}else{
					system("cls");
					load(1);
					terminate(game);
					return game;
				}
			}
		}
		
		// IF YOU ARE OUT OF POINTS YOU WILL GET THIS MESSAGE
		system("cls");
			cout<< "\n\n\n\n\n\n\n\n\n\t\t\t________________________________________________________";
			cout<<"\n\n\t\t\t\t\t You Are Out Of Luck!!";	
			cout<< "\n\n\t\t\t________________________________________________________";
		cout<<"\n\n\t\t\t";
		system("pause");
		load(1);
		terminate(game);
		return game;
	}else{
		
		// exits the game if you are not ready to play
		system("cls");
		load(1);
		terminate(game);
		return game;
	}
    
    
    return 0;
}

