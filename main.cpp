#include "FEHLCD.h" 
#include "FEHUtility.h" 
#include <string>
#include <iostream>
#include <time.h>
#include <FEHImages.h>

using namespace std;
/***********************************************/ 
/* Name: Yuri Batan & Griffin Gappa                       */ 
/* Date: 11/18/23                              */ 
/* Assignment: SDP 2          */ 
/* Seat: 1 Instructor: Toney     Time: 10:20   */ 
/***********************************************/ 


class Player {
    public: //Functions that will be called
        Player(); /*Constructor*/
        void gameMenu(); 
        void credits();
        void gameInstructions();
        void game();
        void stats();
        /*Getter Methods*/
        int getHappinessLevel();
        int getAlcConsumed();
        int getWaterConsumed();
        int getEnergyLevel();
        int getmostDrinksAlive();
        /*Setter Methods*/
        void sethappinessLevel(int level);
        void setalcConsumed(int numberOfAlc);
        void setwaterConsumed(int numberOfWater);
        void setenergyLevel(int energy);
        void setmostDrinksAlive(int number);
        /*Levels*/
        void LoadingScreen(); //Walking Animation
        void timeLimit();
        void resetStats();
        /*Pre-Game*/
        void introScreen();
        void unidentifiedDrink();
        void choiceOfDrink();
        void leavingDorm();
        /*For levels played*/
        int pregame = 0;
        int nextLevelPlayed = 0;
        /*To Choose Next Level*/
        void nextLevel();
        /*For level sequence*/
        int orderOfEvents[6] = {1,2,3,4,5,6};
        void shuffleEvents(int array[], int length);
        int nextEvent();
        /*Frat House*/
        void fratParty();
        /*House Party*/
        void houseParty();
        /*Possible Levels*/
        void buddySystem(); //2nd to last event
        void transportationBack(); //Last Event
        void socialMedia();
        void approached();
        void intervene();
        void getFood();
        void unidentifiedDrink2();
        void choiceOfDrink2();

        //
        void gameOver();
        void backToDorm();
        void gameOverLaw();
    private: //Stats that will be tracked
        int happinessLevel;
        int alcConsumed;
        int waterConsumed;
        int energyLevel;
        int mostDrinksAlive = 0;

        int levelsPlayed = 0; //For Array Indexing

};
//Setting Initial Values
Player::Player() { 
    happinessLevel = 50;
    alcConsumed = 0;
    waterConsumed = 0;
    energyLevel = 100;
}
/*Getter Methods*/
int Player::getHappinessLevel() {
    return happinessLevel; 
    //allows access to private variable happiness level and returns its value
}
int Player::getAlcConsumed() {
    return alcConsumed;
    //allows access to private variable alcConsumed and returns its value
}
int Player::getWaterConsumed() {
    return waterConsumed;
    //allows access to private variable waterConsumed and returns its value
}
int Player::getEnergyLevel() {
    return energyLevel;
    //allows access to private variable energyLevel level and returns its value
}
int Player::getmostDrinksAlive() {
    return mostDrinksAlive;
}

/*Setter Methods*/
void Player::sethappinessLevel(int level) {
    happinessLevel += level;
    /*Adds or subtracts the current player's happiness level by input level*/
}
void Player::setalcConsumed(int numberOfAlc) {
    alcConsumed += numberOfAlc;
     /*Adds the current player's number of alcohols consumed by input */
}
void Player::setwaterConsumed(int numberOfWater) {
    waterConsumed += numberOfWater;
    /*Adds the current player's number of water consumed by input */
}
void Player::setenergyLevel(int energy) {
    energyLevel += energy;
    /*Adds or subtracts the current player's energy level by input energy*/
}
void Player::setmostDrinksAlive(int number) {
    mostDrinksAlive = number;
}
void Player ::LoadingScreen(){

    int i;
    for(i=0;i<6;++i){
    //uses a for loop to repeat the cycle across the screen, incrimenting the x variable for each element
   
    //creates variables for the phase 1 leg x coordinates, sets them to incriment by 40 for each change in i
    //draws the legs for phase 1 of the walk cycle
    int p1_leg1 = (i*40) + 20, p1_leg2 = (i*40) + 40, p1_leg3 = (i*40) + 60;
    LCD.DrawLine(p1_leg1,230,p1_leg2,200);
    LCD.DrawLine(p1_leg2,200,p1_leg3,230);
    //creates a variable for the phase 1 torso x coordinate, sets it to incriment by 40 for each change in i
    //draws the torso for phase 1 of the walk cycle
    int p1_torso = (i*40) + 40;
    LCD.DrawLine(p1_torso,200,p1_torso,125);
    //creates variables for the phase 1 arm x coordinates, sets them to incriment by 40 for each change in i
    //draws the arms for phase 1 of the walk cycle
    int p1_arm1 = (i*40) + 20, p1_arm2 = (i*40) + 40, p1_arm3 = (i*40) + 60;
    LCD.DrawLine(p1_arm2,150,p1_arm1,185);
    LCD.DrawLine(p1_arm2,150,p1_arm3,185);
    //creates a variable for the phase 1 head x coordinate, sets it to incriment by 40 for each change in i
    //draws the head for phase 1 of the walk cycle
    int p1_head = (i*40) + 40;
    LCD.DrawCircle(p1_head,105,20);
    //writes a message for the loading screen
    LCD.WriteAt("Next Stage Loading.",30,50);
    //sleeps so that this phase of the cycle stays on the screen for a short moment
    Sleep(100);

    LCD.Clear();
    //clears the screen to draw phase 2 of the walk cycle

    //creates variables for the phase 2 leg x coordinates, sets them to incriment by 40 for each change in i
    //draws the legs for phase 2 of the walk cycle
    int p2_leg1 = (i*40) + 30, p2_leg2 = (i*40) + 45, p2_leg3 = (i*40) + 50, p2_leg4 = (i*40) + 60;
    LCD.DrawLine(p2_leg2,215,p2_leg3,200);
    LCD.DrawLine(p2_leg2,215,p2_leg1,230);
    LCD.DrawLine(p2_leg3,200,p2_leg4,230);
    //creates a variable for the phase 2 torso x coordinate, sets it to incriment by 40 for each change in i
    //draws the torso for phase 2 of the walk cycle
    int p2_torso = (i*40) + 50;
    LCD.DrawLine(p2_torso,200,p2_torso,125);
    //creates variables for the phase 2 arm x coordinates, sets them to incriment by 40 for each change in i
    //draws the arms for phase 2 of the walk cycle
    int p2_arm1 = (i*40) + 40, p2_arm2 = (i*40) + 50, p2_arm3 = (i*40) + 60;
    LCD.DrawLine(p2_arm2,150,p2_arm1,185);
    LCD.DrawLine(p2_arm2,150,p2_arm3,185);
    //creates a variable for the phase 2 head x coordinate, sets it to incriment by 40 for each change in i
    //draws the head for phase 2 of the walk cycle
    int p2_head = (i*40) + 50;
    LCD.DrawCircle(p2_head,105,20);
    //writes a message for the loading screen
    LCD.WriteAt("Next Stage Loading..",30,50);
    //sleeps so that this phase of the cycle stays on the screen for a short moment
    Sleep(100);

    LCD.Clear();
    //clears the screen to draw phase 2 of the walk cycle

    //creates variables for the phase 3 leg x coordinates, sets them to incriment by 40 for each change in i
    //draws the legs for phase 3 of the walk cycle
    int p3_leg1 = (i*40) + 50, p3_leg2 = (i*40) + 60, p3_leg3 = (i*40) + 70;
    LCD.DrawLine(p3_leg2,200,p3_leg2,230);
    LCD.DrawLine(p3_leg2,200,p3_leg3,210);
    LCD.DrawLine(p3_leg3,210,p3_leg1,230);
    //creates a variable for the phase 3 torso x coordinate, sets it to incriment by 40 for each change in i
    //draws the torso for phase 3 of the walk cycle
    int p3_torso = (i*40) + 60;
    LCD.DrawLine(p3_torso,200,p3_torso,125);
    //creates variables for the phase 3 arm x coordinates, sets them to incriment by 40 for each change in i
    //draws the arms for phase 3 of the walk cycle
    int p3_arm1 = (i*40) + 40, p3_arm2 = (i*40) + 60, p3_arm3 = (i*40) + 80;
    LCD.DrawLine(p3_arm2,150,p3_arm3,185);
    LCD.DrawLine(p3_arm2,150,p3_arm1,185);
    //creates a variable for the phase 3 head x coordinate, sets it to incriment by 40 for each change in i
    //draws the head for phase 3 of the walk cycle
    int p3_head = (i*40) + 60;
    LCD.DrawCircle(p3_head,105,20);
    //writes a message for the loading screen
    LCD.WriteAt("Next Stage Loading...",30,50);
    //sleeps so that this phase of the cycle stays on the screen for a short moment
    Sleep(100);

    LCD.Clear();
    //clears the screen to draw phase 2 of the walk cycle

    //creates variables for the phase 4 leg x coordinates, sets them to incriment by 40 for each change in i
    //draws the legs for phase 4 of the walk cycle
    int p4_leg1 = (i*40) + 65, p4_leg2 = (i*40) + 70, p4_leg3 = (i*40) + 85;
    LCD.DrawLine(p4_leg2,200,p4_leg1,230);
    LCD.DrawLine(p4_leg2,200,p4_leg3,220);
    LCD.DrawLine(p4_leg3,220,p4_leg3,230);
    //creates a variable for the phase 4 torso x coordinate, sets it to incriment by 40 for each change in i
    //draws the torso for phase 4 of the walk cycle
    int p4_torso = (i*40) + 70;
    LCD.DrawLine(p4_torso,200,p4_torso,125);
    //creates variables for the phase 4 arm x coordinates, sets them to incriment by 40 for each change in i
    //draws the arms for phase 4 of the walk cycle
    int p4_arm1 = (i*40) + 60, p4_arm2 = (i*40) + 70, p4_arm3 = (i*40) + 80;
    LCD.DrawLine(p4_arm2,150,p4_arm3,185);
    LCD.DrawLine(p4_arm2,150,p4_arm1,185);
    //creates a variable for the phase 4 head x coordinate, sets it to incriment by 40 for each change in i
    //draws the head for phase 4 of the walk cycle
    int p4_head = (i*40) + 70;
    LCD.DrawCircle(p4_head,105,20);
    //writes a message for the loading screen
    LCD.WriteAt("Next Stage Loading....",30,50);
    //sleeps so that this phase of the cycle stays on the screen for a short moment
    Sleep(100);

    LCD.Clear();
    //clears the screen to draw phase 2 of the walk cycle

    }
}

/*Playing Functions*/
void Player::credits () {
    /*For Coordinate Tracking*/
    float x_position, y_position;
    float x_trash, y_trash;

    /*Clearing Screen*/
    LCD.SetBackgroundColor(BLACK); 
    LCD.Clear(); 

    /*Top Stats Display Button*/
    LCD.WriteAt("Credits", 110, 10);
    LCD.DrawHorizontalLine(30, 0, 500);

    /*Back to Main Menu Button*/
    LCD.WriteAt ("Menu", 130, 220);
    LCD.DrawHorizontalLine(210, 0, 500);

    /*Creators*/
    LCD.WriteAt("Creators", 0,35);
    LCD.WriteAt("Griffin Gappa '27", 10 , 55);
    LCD.WriteAt("Yuri Batan '27", 10 , 75);

    int secondsElapsed;
    while(!LCD.Touch(&x_position, &y_position)) { //Wait for User to Touch Screen
    }; 

    while(LCD.Touch(&x_trash, &y_trash)) {
    }; //Wait for Touch Release

    if (y_position > 210 && y_position < 240) { //If Menu Button is Hit
        gameMenu();
    }
}

void Player::gameInstructions() {
    /*For Coordinate Tracking*/
    float x_position, y_position;
    float x_trash, y_trash;

    /*Clearing Screen*/
    LCD.SetBackgroundColor(BLACK); 
    LCD.Clear(); 

    /*Top Stats Display Button*/
    LCD.WriteAt("Instructions", 110, 10);
    LCD.DrawHorizontalLine(30, 0, 500);

    /*FIND A WAY TO MAKE TEXT SMALLER*/
    /*Instructions*/
    LCD.WriteAt("1.You Will Go Out as an ", 0, 35);
    LCD.WriteAt("Ohio State Student", 10, 55);
    LCD.WriteAt("2.Make Smart Decisions", 0, 75);
    LCD.WriteAt("when Out in 5 sec", 10, 95);
    LCD.WriteAt("3. Have Fun and Make it", 0, 115);
    LCD.WriteAt ("back to your dorm ",10,135);
    LCD.WriteAt ("(KEEP ALC LEVELS OPTMIZED)",10,155);

    /*Back to Main Menu Button*/
    LCD.WriteAt ("Menu", 130, 220);
    LCD.DrawHorizontalLine(210, 0, 500);

    /*Menu Button Functionality*/
    while(1) {
        while(!LCD.Touch(&x_position, &y_position)) {}; //Wait for User to Touch Screen

        while(LCD.Touch(&x_trash, &y_trash)) {}; //Wait for Touch Release

        if (y_position > 210 && y_position < 240) { //If Menu Button is Hit
            gameMenu();
            break;
        }

    }

}
void Player::stats () {
    /*String Holders*/
    string happinessLevelDisplay = "Happiness Level - "+to_string(getHappinessLevel()) + "%";
    string energyLevelDisplay = "Energy Level - " + to_string(getEnergyLevel()) + "%";
    string alcConsumedDisplay = "Drinks Consumed - " + to_string(getAlcConsumed());
    string waterConsumedDisplay = "Waters Consumed - " + to_string(getWaterConsumed());
    string highScore = "Most Drinks Consumed - "+ to_string(getmostDrinksAlive());
    /*For Coordinate Tracking*/
    float x_position, y_position;
    float x_trash, y_trash;

    /*Clearing Screen*/
    LCD.SetBackgroundColor(BLACK); 
    LCD.Clear(); 

    /*Top Stats Display Button*/
    LCD.WriteAt("Stats", 105, 10);
    LCD.DrawHorizontalLine(30, 0, 500);

    /*Back to Main Menu Button*/
    LCD.WriteAt ("Menu", 130, 220);
    LCD.DrawHorizontalLine(210, 0, 500);

    /*Creators*/
    LCD.WriteAt(happinessLevelDisplay, 0,35);
    LCD.WriteAt(energyLevelDisplay, 0 , 55);
    LCD.WriteAt(alcConsumedDisplay, 0 , 75);
    LCD.WriteAt(waterConsumedDisplay, 0 , 95);
    LCD.WriteAt(highScore, 0 , 115);

    while (1) {
        while(!LCD.Touch(&x_position, &y_position)) {}; //Wait for User to Touch Screen

        while(LCD.Touch(&x_trash, &y_trash)) {}; //Wait for Touch Release

        if (y_position > 210 && y_position < 240) { //If Menu Button is Hit
            gameMenu();
            break;
        }
    }
}
void Player::gameMenu() { 
    /*For Coordinate Tracking*/
    float x_position, y_position;
    float x_trash, y_trash;

    /*Clearing Screen*/
    LCD.SetBackgroundColor(BLACK); 
    LCD.Clear();

    LCD.SetFontColor(WHITE); 
    LCD.DrawVerticalLine(150, 0, 300); //Vertical Line
    LCD.DrawHorizontalLine(113,0,500); //Horizontal Line
    /*Text*/
    LCD.WriteAt("Play Game ", 15, 50); //Play Game
    LCD.WriteAt("Stats",200,50); //Stats
    LCD.WriteAt("Instructions", 0, 165); //Instructions
    LCD.WriteAt("Credits", 190, 165); //Credits

    while (1) {
        while(!LCD.Touch(&x_position, &y_position)) {}; //Wait for User to Touch Screen

        while(LCD.Touch(&x_trash, &y_trash)) {}; //Wait for Touch Release

        //Where did the User Hit?
        if (x_position > 150 && y_position > 113) { //If Credits is hit
            credits();
            break;
        } else if (x_position <  150 && y_position > 113) { //Instructions
            gameInstructions();
            break;
        }else if (x_position > 150 && y_position < 113) { //Stats
            stats();
            break;
        } else if (x_position < 150 && y_position < 113) { //Game
            game();
            break;
        }
    }
} 

void Player::game () {
    /*For Coordinate Tracking*/
    float x_position, y_position;
    float x_trash, y_trash;

    /*Clearing Screen*/
    LCD.SetBackgroundColor(BLACK); 
    LCD.Clear(); 

    /*Back to Main Menu Button*/
    LCD.WriteAt ("Menu", 130, 220);
    LCD.DrawHorizontalLine(210, 0, 500);

    /*Game Function*/
    introScreen();
    /*Generate Random Number*/
    /*Logic Gate*/
    while (1) {
        while(!LCD.Touch(&x_position, &y_position)) {}; //Wait for User to Touch Screen

        while(LCD.Touch(&x_trash, &y_trash)) {}; //Wait for Touch Release

        if (y_position > 210 && y_position < 240) { //If Menu Button is Hit
            gameMenu();
            break;
    }  

    }


}

void Player::resetStats() {
    happinessLevel = 50;
    alcConsumed = 0;
    waterConsumed = 0;
    energyLevel = 100;
    levelsPlayed = 0;
}
void Player::gameOver() {
    /*Clearing Screen*/
    LCD.SetBackgroundColor(BLACK); 
    LCD.Clear(); 

    FEHImage blackedOut;
    blackedOut.Open("pxArt-9FEH.pic");
    blackedOut.Draw(0,0);
    blackedOut.Close();

    LCD.SetFontColor(RED);

    LCD.WriteAt("GAME OVER", 40, 35);
    LCD.WriteAt("You Lost", 40, 55);
    LCD.WriteAt("You Drank Too Much", 40, 75);

    LCD.SetFontColor(WHITE);

    Sleep(10.0);
    resetStats();
    gameMenu();
}

void Player::gameOverLaw() {
    /*Clearing Screen*/
    LCD.SetBackgroundColor(BLACK); 
    LCD.Clear(); 

    LCD.WriteAt("GAME OVER", 40, 35);
    LCD.WriteAt("You Lost", 40, 55);
    LCD.WriteAt("You Broke The Law", 40, 75);
    FEHImage siren;
    siren.Open("policesirenFEH.pic");
    siren.Draw(145,95);
    siren.Close();
    Sleep(10.0);
    resetStats();
    gameMenu();
}

void Player::backToDorm() {
    LCD.SetBackgroundColor(BLACK); 
    LCD.Clear(); 

    
    int score = getAlcConsumed();

    if (score > getmostDrinksAlive()) {
        setmostDrinksAlive(score);
    }

    LCD.WriteAt("Great Job", 40, 35);
    LCD.WriteAt("You Made It Back Alive", 40, 55);
    LCD.WriteAt("Num of Drinks Consumed", 45,75);
    LCD.WriteAt(score,45,95);

    FEHImage thumbsUp;
    thumbsUp.Open("pxArt-8FEH.pic");
    thumbsUp.Draw(145,95);
    thumbsUp.Close();
    
    Sleep(5.0);

    resetStats();

    gameMenu();

    
}
/*---------------LEVELS----------------*/
/*---------------Pre-Game----------------*/
void Player::introScreen () {
    /*For Coordinate Tracking*/
    float x_position, y_position;
    float x_trash, y_trash;

    /*Clearing Screen*/
    LCD.SetBackgroundColor(BLACK); 
    LCD.Clear(); 


    /*Game Function*/
    LCD.WriteAt("Buckeye Blackout", 50, 35);
    LCD.WriteAt("Make Decisions in 5 sec", 25, 110);
    LCD.WriteAt("While Underage Drinking ",25,155);
    LCD.WriteAt("Is Illegal, it is", 25,175);
    LCD.WriteAt("Dangerous to Pretend",25,195);
    LCD.WriteAt("it won't happen",25,215);


    Sleep(4.0); //Pause for One Second

    /*Clearing Screen*/
    LCD.SetBackgroundColor(BLACK); 
    LCD.Clear(); 

    LCD.WriteAt("Before Going Out", 50, 35);
    LCD.WriteAt("You Decide to Meet with", 30, 110);
    LCD.WriteAt("your friends at a dorm", 30, 130);

    /*Clearing Screen*/
    LCD.SetBackgroundColor(BLACK); 
    LCD.Clear(); 

    LCD.WriteAt("Do you eat or", 85, 35);
    LCD.WriteAt("drink water", 95, 55);
    LCD.WriteAt("before going out", 75, 75);

    FEHImage water;
    water.Open("waterFEH.pic");
    water.Draw(25,140);
    water.Close();

    LCD.SetFontColor(WHITE);

    LCD.DrawRectangle(60, 130, 100, 50);
    LCD.WriteAt("Yes",65, 155 );
    LCD.WriteAt("No",165, 155 );
    LCD.DrawRectangle(160, 130, 100, 50);

    /*Back to Main Menu Button*/
    LCD.WriteAt ("Menu", 130, 220);
    LCD.DrawHorizontalLine(210, 0, 500);

    while (1) {
        int start;
        start = time(NULL);

        while ((time(NULL) - start) <6 && !LCD.Touch(&x_position, &y_position)) {
            if ((time(NULL) - start)  >= 4.9 ) {
                x_position = 80;
                y_position = 140;
                break;
            }
        }

        while((time(NULL) - start) < 6 && LCD.Touch(&x_trash, &y_trash)) {
            if ((time(NULL) - start) >= 4.9) {
                break;
            }
         }; //Wait for Touch Release
      




        if (y_position > 210 && y_position < 240) { //If Menu Button is Hit
            gameMenu();
           // break;
        }else if ((x_position > 60 && x_position < 160) && (y_position > 130 && y_position < 180)) { //Yes
            LCD.WriteAt("+10% Energy, +1 Water", 160, 100);
            setenergyLevel(10);
            setwaterConsumed(1);

            Sleep(1.5);

            LoadingScreen();

            int random = 1 + (rand() % 2); //Random number to determine next Scenartio

            if (random == 1) {
                pregame += 1; /*Level has been played*/
                choiceOfDrink();
                
            } else if (random == 2) {
                pregame += 1; /*Level has been played*/
                unidentifiedDrink();

            }

            //break;
        } else if ((x_position > 160 && x_position < 260) && (y_position > 130 && y_position < 180)) {

            LoadingScreen();

            int random = 1 + (rand() % 2); //Random number to determine next Scenartio

            if (random == 1) {
                pregame += 1; /*Level has been played*/
                choiceOfDrink();

            } else if (random == 2) {
                pregame += 1; /*Level has been played*/
                unidentifiedDrink();
            }
            //break;

        }
    }
}

void Player::unidentifiedDrink() {
     /*For Coordinate Tracking*/
    float x_position, y_position;
    float x_trash, y_trash;

    /*Clearing Screen*/
    LCD.SetBackgroundColor(BLACK); 
    LCD.Clear(); 

    LCD.WriteAt("Your friends", 65, 35);
    LCD.WriteAt("offer you an", 65, 55);
    LCD.WriteAt("unidentified drink", 50, 75);

    LCD.DrawRectangle(60, 130, 100, 50);
    LCD.WriteAt("Drink",65, 155);
    LCD.WriteAt("Decline",165, 155 );
    LCD.DrawRectangle(160, 130, 100, 50);

    /*Drawing Image*/
    FEHImage redCup;
    redCup.Open("pxArt-4FEH.pic");
    redCup.Draw(145,95);
    redCup.Close();

    LCD.SetFontColor(WHITE);

    /*Back to Main Menu Button*/
    LCD.WriteAt ("Menu", 130, 220);
    LCD.DrawHorizontalLine(210, 0, 500);




    while (1) {
        int start;
        start = time(NULL);

        while ((time(NULL) - start) <6 && !LCD.Touch(&x_position, &y_position)) {
            if ((time(NULL) - start)  >= 4.9 ) {
                x_position = 80;
                y_position = 140;
                break;
            }
        }

        while((time(NULL) - start) < 6 && LCD.Touch(&x_trash, &y_trash)) {
            if ((time(NULL) - start) >= 4.9) {
                break;
            }
         }; //Wait for Touch Release

        if (y_position > 210 && y_position < 240) { //If Menu Button is Hit
            gameMenu();
            break;
        }else if ((x_position > 60 && x_position < 160) && (y_position > 130 && y_position < 180)) { //If Drink is Hit
            /*Clearing Screen*/
            LCD.SetBackgroundColor(BLACK); 
            LCD.Clear(); 
            /*Lesson Screen*/
            LCD.WriteAt("Drinking an ", 50, 35);
            LCD.WriteAt("Unidentified Drink", 50, 55);
            LCD.WriteAt("is a ", 50, 75);
            LCD.WriteAt("Dangerous Idea", 50, 95);    
            LCD.WriteAt("+1 Drink Consumed",50, 115);
            LCD.WriteAt("-5% Energy ",50, 135);
            LCD.WriteAt("+5% Happiness",50, 155);

            Sleep(3.0);

            setalcConsumed(1); //Adds one alc to drink
            setenergyLevel(-5); /*-5% energy*/
            sethappinessLevel(5); /*5 Happiness*/

            switch (pregame)
             {
             case 1: //if the pregame variable is equal to 1 or only one leveled has been played
                pregame +=1;
                choiceOfDrink(); //play other random scenario
                break;
             
             default:
                pregame +=1;
                leavingDorm(); //if the other random scenario has been played, play transition
                break;
             }
            break;

            gameMenu();        
            break;
        } else if ((x_position > 160 && x_position < 260) && (y_position > 130 && y_position < 180)) { //If Decline
            /*Next Level*/
             LCD.WriteAt("-5% Energy +1 Water", 160, 100);
             Sleep(1.5);

             setenergyLevel(-5); //-5% energy boost

             switch (pregame)
             {
             case 1: //if the pregame variable is equal to 1 or only one leveled has been played
                if (nextLevelPlayed > 0) {
                    nextEvent();
                    break;
                } else {
                    pregame +=1;
                    choiceOfDrink(); //play other random scenario
                    break;
                }

             
             default:
                if (nextLevelPlayed > 0) {
                    nextEvent();
                    break;
                } else {
                    pregame +=1;
                    leavingDorm(); //if the other random scenario has been played, play transition
                    break;
                }
                
             }
            break;
        }
    }
}

void Player::choiceOfDrink() {
    /*For Coordinate Tracking*/
    float x_position, y_position;
    float x_trash, y_trash;

    /*Clearing Screen*/
    LCD.SetBackgroundColor(BLACK); 
    LCD.Clear(); 

    LCD.WriteAt("At the dorm, ", 65, 5);
    LCD.WriteAt("do you drink..", 65, 25);
    LCD.WriteAt("#1- Labeled Beer", 65, 45);
    LCD.WriteAt("#2- Self-Made Drink", 65, 65);

    FEHImage beer;
    beer.Open("pxArt-5FEH.pic");
    beer.Draw(30,140);
    beer.Close();


    LCD.DrawRectangle(60, 130, 100, 50);
    LCD.WriteAt("#1",65, 155);
    LCD.WriteAt("#2",165, 155 );
    LCD.DrawRectangle(160, 130, 100, 50);

    /*Back to Main Menu Button*/
    LCD.WriteAt ("Menu", 130, 220);
    LCD.DrawHorizontalLine(210, 0, 500);

    while (1) {
        int start;
        start = time(NULL);

        while ((time(NULL) - start) <6 && !LCD.Touch(&x_position, &y_position)) {
            if ((time(NULL) - start)  >= 4.9 ) {
                x_position = 80;
                y_position = 140;
                break;
            }
        }

        while((time(NULL) - start) < 6 && LCD.Touch(&x_trash, &y_trash)) {
            if ((time(NULL) - start) >= 4.9) {
                break;
            }
         }; //Wait for Touch Release

        if (y_position > 210 && y_position < 240) { //If Menu Button is Hit
            gameMenu();
            break;
        }else if ((x_position > 60 && x_position < 160) && (y_position > 130 && y_position < 180)) { //If #1 is Hit
            setalcConsumed(1); /*Add one to drinks consumed*/
            LCD.WriteAt("+1 Drinks Consumed", 60, 100);

            Sleep (2.0);

            switch (pregame)
             {
             case 1: //if the pregame variable is equal to 1 or only one leveled has been played
                if (nextLevelPlayed > 0) {
                    nextEvent();
                    break;
                } else {
                    pregame +=1;
                    unidentifiedDrink(); //play other random scenario
                    break;
                }
                
                break;
             
             default:
                if (nextLevelPlayed > 0) {
                    nextEvent();
                    break;
                } else {
                    pregame +=1;
                    leavingDorm(); //if the other random scenario has been played, play transition
                    break;
                }

             }

            break;

            break;
        } else if ((x_position > 160 && x_position < 260) && (y_position > 130 && y_position < 180)) { //If #2 is Hit
            setalcConsumed(2); /*Add two to drinks consumed*/
            LCD.WriteAt("+2 Drinks Consumed", 60, 100);
        
            Sleep(2.0);

            switch (pregame)
             {
             case 1: //if the pregame variable is equal to 1 or only one leveled has been played
                pregame +=1;
                unidentifiedDrink(); //play other random scenario
                break;
             
             default:
                pregame +=1;
                leavingDorm(); //if the other random scenario has been played, play transition
                break;
             }
            break;
        }
    }

}

void Player::leavingDorm() {
     /*For Coordinate Tracking*/
    float x_position, y_position;
    float x_trash, y_trash;

    /*Clearing Screen*/
    LCD.SetBackgroundColor(BLACK); 
    LCD.Clear(); 

    LCD.WriteAt("Before going out,", 65, 5);
    LCD.WriteAt("do you eat or", 65, 25);
    LCD.WriteAt("drink water", 65, 45);

    FEHImage water;
    water.Open("waterFEH.pic");
    water.Draw(25,140);
    water.Close();

    LCD.SetFontColor(WHITE);

    LCD.DrawRectangle(60, 130, 100, 50);
    LCD.WriteAt("Yes",65, 155);
    LCD.WriteAt("No",165, 155 );
    LCD.DrawRectangle(160, 130, 100, 50);

    /*Back to Main Menu Button*/
    LCD.WriteAt ("Menu", 130, 220);
    LCD.DrawHorizontalLine(210, 0, 500);

    while (1) {
        int start;
        start = time(NULL);

        while ((time(NULL) - start) <6 && !LCD.Touch(&x_position, &y_position)) {
            if ((time(NULL) - start)  >= 4.9 ) {
                x_position = 80;
                y_position = 140;
                break;
            }
        }

        while((time(NULL) - start) < 6 && LCD.Touch(&x_trash, &y_trash)) {
            if ((time(NULL) - start) >= 4.9) {
                break;
            }
         }; //Wait for Touch Release

        if (y_position > 210 && y_position < 240) { //If Menu Button is Hit
            gameMenu();
            break;
        }else if ((x_position > 60 && x_position < 160) && (y_position > 130 && y_position < 180)) { //Yes
            setwaterConsumed(1); //+1 Water
            setenergyLevel(10); //+10 Energy
            LCD.WriteAt("+1 Water Consumed", 60, 80);
            LCD.WriteAt("+10 Energy", 60, 100);

            Sleep(3.0);

            LoadingScreen();

            nextLevel();



            break;
        } else if ((x_position > 160 && x_position < 260) && (y_position > 130 && y_position < 180)) { //Else
            LoadingScreen();

            nextLevel();

            break;
        }
    }
    
}

void Player::nextLevel() {
    int randomLevel = 1 + (rand() % 2); //Random number to determine next Scenartio

    //shuffles orders of events 
    shuffleEvents(orderOfEvents, 6);

    for (int i = 0; i < 6; i++) {
        cout << orderOfEvents[i]<< " ";
    }

    if (randomLevel == 1) {
        fratParty();
        nextLevelPlayed += 1;
                
    } else if (randomLevel == 2) {
        houseParty();
        nextLevelPlayed += 1;

    }

}
void Player::shuffleEvents(int array[], int length) {
    /*https://www.youtube.com/watch?v=7OIZ_W75lAM&t=265s (Reference)*/
    srand((time(NULL)));

    for (int i = 0; i < length; i++) {
        int swap_index = rand() % length;
        int temp = array[i];
        array[i] = array[swap_index];
        array[swap_index] = temp;
    }
}

int Player::nextEvent() {
    /*Get Alc Levels and Water Levels and if ratio is 4:1, game is over*/
    double safeDrinking = (getAlcConsumed() * 1.0) / (getWaterConsumed() *1.0 );
    if (safeDrinking < 4.0) {
        if (levelsPlayed < 6) { //While Player is still at aprty
            int currentEvent = orderOfEvents[levelsPlayed];
            switch (currentEvent)
            {
            case 1:
                levelsPlayed+=1;
                socialMedia();

                break;
            case 2:
                 levelsPlayed+=1;               
                approached();
                levelsPlayed+=1;
                break;
            case 3:
                levelsPlayed+=1;
                intervene();

                break;            
            case 4:
                levelsPlayed+=1;
                getFood();

                break;            
            case 5:
                levelsPlayed+=1;
                unidentifiedDrink2();

                break;            
            case 6:
                levelsPlayed+=1;
                choiceOfDrink2();

                break;            
            default:
                break;
             } 
    } else {
        switch (levelsPlayed)
        {
        case 6:
            levelsPlayed += 1;
            buddySystem();

            break;
        case 7:
            levelsPlayed +=1;
            transportationBack();
            break;
        default:
            backToDorm(); //Good Game Over
            break;
        }
    }
    } else {
        //GAME OVER BAD
        gameOver();
    }
    

}
void Player::fratParty() {
    /*For Coordinate Tracking*/
    float x_position, y_position;
    float x_trash, y_trash;

    /*Clearing Screen*/
    LCD.Clear(); 

    FEHImage frat;
    frat.Open("pxArt-2FEH.pic");
    frat.Draw(0,0);
    frat.Close();

    LCD.SetFontColor(WHITE);

    LCD.WriteAt("You Are ", 65, 95);
    LCD.WriteAt("Going to a", 65, 115);
    LCD.WriteAt("Frat Party", 65, 135);

    Sleep(4.0);

    nextEvent();
}

void Player::houseParty() {
    /*For Coordinate Tracking*/
    float x_position, y_position;
    float x_trash, y_trash;

    /*Clearing Screen*/
    LCD.Clear(); 

    FEHImage house;
    house.Open("pxArt-3FEH.pic");
    house.Draw(0,0);
    house.Close();

    LCD.SetFontColor(WHITE);

    LCD.WriteAt("You Are ", 65, 95);
    LCD.WriteAt("Going to a", 65, 115);
    LCD.WriteAt("House Party", 65, 135);


    Sleep(4.0);

    nextEvent();
}
void Player::socialMedia(){
     /*For Coordinate Tracking*/
    float x_position, y_position;
    float x_trash, y_trash;

    /*Clearing Screen*/
    LCD.SetBackgroundColor(BLACK); 
    LCD.Clear(); 

    LCD.WriteAt("Some people want", 50, 5);
    LCD.WriteAt("to take a picture", 50, 25);
    LCD.WriteAt("with you ", 50, 45);
    LCD.WriteAt("for social media ", 50, 65);
    LCD.WriteAt("Do you join?", 50, 85);


    LCD.DrawRectangle(60, 130, 100, 50);
    LCD.WriteAt("Yes",65, 155);
    LCD.WriteAt("No",165, 155 );
    LCD.DrawRectangle(160, 130, 100, 50);

    /*Back to Main Menu Button*/
    LCD.WriteAt ("Menu", 130, 220);
    LCD.DrawHorizontalLine(210, 0, 500);

    FEHImage social;
    social.Open("pxArt-7FEH.pic");
    social.Draw(25,140);
    social.Close();

    LCD.SetFontColor(WHITE);

    while (1) {
        int start;
        start = time(NULL);

        while ((time(NULL) - start) <6 && !LCD.Touch(&x_position, &y_position)) {
            if ((time(NULL) - start)  >= 4.9 ) {
                x_position = 80;
                y_position = 140;
                break;
            }
        }

        while((time(NULL) - start) < 6 && LCD.Touch(&x_trash, &y_trash)) {
            if ((time(NULL) - start) >= 4.9) {
                break;
            }
         }; //Wait for Touch Release

        if (y_position > 210 && y_position < 240) { //If Menu Button is Hit
            gameMenu();
            break;
        }else if ((x_position > 60 && x_position < 160) && (y_position > 130 && y_position < 180)) { //Yes
            /*Clearing Screen*/
            LCD.SetBackgroundColor(BLACK); 
            LCD.Clear(); 
            /*Lesson Screen*/   
            LCD.WriteAt("When getting in a  ", 40, 35);
            LCD.WriteAt("picture for social", 40, 55);
            LCD.WriteAt("media. Remember that", 40, 75);
            LCD.WriteAt("the picture will affect", 40, 95);    
            LCD.WriteAt("your digital footprint.",40, 115);
            LCD.WriteAt("(Don't show anything",40, 135);
            LCD.WriteAt("that you wouldn't",40, 155);
            LCD.WriteAt("show an employer)",40, 175);

            Sleep(3.0);

            nextEvent();

            break;
        } else if ((x_position > 160 && x_position < 260) && (y_position > 130 && y_position < 180)) { //No
            /*Next*/
            LCD.SetBackgroundColor(BLACK); 
            LCD.Clear(); 
            /*Lesson Screen*/

            nextEvent();

            break;
        }
    }
}
void Player::approached(){
 /*For Coordinate Tracking*/
    float x_position, y_position;
    float x_trash, y_trash;

    /*Clearing Screen*/
    LCD.SetBackgroundColor(BLACK); 
    LCD.Clear(); 

    LCD.WriteAt("Someone intoxicated", 65, 5);
    LCD.WriteAt("asks you to leave", 65, 25);
    LCD.WriteAt("with them? ", 65, 45);
    LCD.WriteAt("Do you accept?", 65, 65);


    LCD.DrawRectangle(60, 130, 100, 50);
    LCD.WriteAt("Yes",65, 155);
    LCD.WriteAt("No",165, 155 );
    LCD.DrawRectangle(160, 130, 100, 50);

    /*Back to Main Menu Button*/
    LCD.WriteAt ("Menu", 130, 220);
    LCD.DrawHorizontalLine(210, 0, 500);

    while (1) {
        int start;
        start = time(NULL);

        while ((time(NULL) - start) <6 && !LCD.Touch(&x_position, &y_position)) {
            if ((time(NULL) - start)  >= 4.9 ) {
                x_position = 80;
                y_position = 140;
                break;
            }
        }

        while((time(NULL) - start) < 6 && LCD.Touch(&x_trash, &y_trash)) {
            if ((time(NULL) - start) >= 4.9) {
                break;
            }
         }; //Wait for Touch Release

        if (y_position > 210 && y_position < 240) { //If Menu Button is Hit
            gameMenu();
            break;
        }else if ((x_position > 60 && x_position < 160) && (y_position > 130 && y_position < 180)) { //Yes
            /*Clearing Screen*/
            LCD.SetBackgroundColor(BLACK); 
            LCD.Clear(); 
            /*Lesson Screen*/
            LCD.WriteAt("Game Over ", 40, 35);
            LCD.WriteAt("That is Sexual Assualt", 40, 105);
            LCD.WriteAt("They couldn't  ",40, 125);
            LCD.WriteAt("properly Consent", 40, 145);

            Sleep(3.0);

            gameOverLaw();
            break;
        } else if ((x_position > 160 && x_position < 260) && (y_position > 130 && y_position < 180)) { //No
            /*Clearing Screen*/
            LCD.SetBackgroundColor(BLACK); 
            LCD.Clear(); 

            LCD.WriteAt("Great Job! ", 40, 35);
            LCD.WriteAt("They weren't in ", 40, 55);
            LCD.WriteAt("a state where they", 40, 75);
            LCD.WriteAt("could consent", 40, 95); 

            Sleep(3.0);

            nextEvent();

            break;
        }
    }
}
void Player::intervene(){
     /*For Coordinate Tracking*/
    float x_position, y_position;
    float x_trash, y_trash;

    /*Clearing Screen*/
    LCD.SetBackgroundColor(BLACK); 
    LCD.Clear(); 

    LCD.WriteAt("Someone is leaving", 65, 5);
    LCD.WriteAt("with someone of the", 65, 25);
    LCD.WriteAt("opposite sex, who is ", 65, 45);
    LCD.WriteAt("clearly intoxicated  ", 65, 65);
    LCD.WriteAt("Do you intervene?", 65, 85);


    LCD.DrawRectangle(60, 130, 100, 50);
    LCD.WriteAt("Yes",65, 155);
    LCD.WriteAt("No",165, 155 );
    LCD.DrawRectangle(160, 130, 100, 50);

    /*Back to Main Menu Button*/
    LCD.WriteAt ("Menu", 130, 220);
    LCD.DrawHorizontalLine(210, 0, 500);

    while (1) {
        int start;
        start = time(NULL);

        while ((time(NULL) - start) <6 && !LCD.Touch(&x_position, &y_position)) {
            if ((time(NULL) - start)  >= 4.9 ) {
                x_position = 80;
                y_position = 140;
                break;
            }
        }

        while((time(NULL) - start) < 6 && LCD.Touch(&x_trash, &y_trash)) {
            if ((time(NULL) - start) >= 4.9) {
                break;
            }
         }; //Wait for Touch Release

        if (y_position > 210 && y_position < 240) { //If Menu Button is Hit
            gameMenu();
            break;
        }else if ((x_position > 60 && x_position < 160) && (y_position > 130 && y_position < 180)) { //Yes
            /*Clearing Screen*/
            LCD.SetBackgroundColor(BLACK); 
            LCD.Clear(); 
            /*Lesson Screen*/
            LCD.WriteAt("Great Job! ", 40, 35);
            LCD.WriteAt("You may have saved ", 40, 55);
            LCD.WriteAt("someone from being", 40, 75);
            LCD.WriteAt("sexually assaulted", 40, 95); 

            Sleep(3.0);

            nextEvent();

            break;
        } else if ((x_position > 160 && x_position < 260) && (y_position > 130 && y_position < 180)) { //No
            /*Clearing Screen*/
            LCD.SetBackgroundColor(BLACK); 
            LCD.Clear(); 

            LCD.WriteAt("You are also ", 40, 35);
            LCD.WriteAt("at fault for doing", 40, 55);
            LCD.WriteAt("nothing. Your ", 40, 75);
            LCD.WriteAt("help can potentially", 40, 95);    
            LCD.WriteAt("save a life.",40, 115);

            Sleep(4.0);

            nextEvent();

            break;
        }
    }
}
void Player::getFood(){
     /*For Coordinate Tracking*/
    float x_position, y_position;
    float x_trash, y_trash;
    /*Clearing Screen*/
    LCD.SetBackgroundColor(BLACK);
    LCD.Clear();

    LCD.WriteAt("You are hungry,", 65, 5);
    LCD.WriteAt("but if you leave", 65, 25);
    LCD.WriteAt("then you won't get", 65, 45);
    LCD.WriteAt("any more drinks.", 65, 65);
    LCD.WriteAt("Do you go get food?", 65, 85);

    LCD.DrawRectangle(60, 130, 100, 50);
    LCD.WriteAt("Yes",65, 155);
    LCD.WriteAt("No",165, 155 );
    LCD.DrawRectangle(160, 130, 100, 50);

    FEHImage food;
    food.Open("fastfoodFEH.pic");
    food.Draw(25,140);
    food.Close();

    LCD.SetFontColor(WHITE);
   
    /*Back to Main Menu Button*/
    LCD.WriteAt ("Menu", 130, 220);
    LCD.DrawHorizontalLine(210, 0, 500);

   while (1) {
        int start;
        start = time(NULL);
        while ((time(NULL) - start) <6 && !LCD.Touch(&x_position, &y_position)) {
            if ((time(NULL) - start)  >= 4.9 ) {
                x_position = 80;
                y_position = 140;
                break;
            }
        }
        while((time(NULL) - start) < 6 && LCD.Touch(&x_trash, &y_trash)) {
            if ((time(NULL) - start) >= 4.9) {
                break;
            }
         }; //Wait for Touch Release
        if (y_position > 210 && y_position < 240) { //If Menu Button is Hit
            gameMenu();
            break;
        }else if ((x_position > 60 && x_position < 160) && (y_position > 130 && y_position < 180)) { //Yes
            /*Clearing Screen*/
            LCD.SetBackgroundColor(BLACK);
            LCD.Clear();
            /*Lesson Screen*/
            LCD.WriteAt("Good call.", 40, 35);
            LCD.WriteAt("Eating when  ", 40, 55);
            LCD.WriteAt("intoxicated helps", 40, 75);
            LCD.WriteAt("you sober up, and can", 40, 95);
            LCD.WriteAt("reduce the effects", 40, 115);
            LCD.WriteAt("of hangovers. You feel", 40, 135);
            LCD.WriteAt("better after eating.", 40, 155);
            setenergyLevel(5);
            sethappinessLevel(10);
            //increase happiness by 10
            Sleep(5.0);

            nextEvent();
            break;
        } else if ((x_position > 160 && x_position < 260) && (y_position > 130 && y_position < 180)) { //Else
            /*Next*/
            LCD.WriteAt("You stay put and get", 40, 35);
            LCD.WriteAt("more to drink.", 40, 55);
            LCD.WriteAt("Your stomach begins to ache.", 40, 75);
            LCD.WriteAt("Good luck tomorrow morning.", 40, 95);  
            setalcConsumed(1);
            setenergyLevel(-5);
            nextEvent();
            break;
        }
    }
}
void Player::buddySystem() {
     /*For Coordinate Tracking*/
    float x_position, y_position;
    float x_trash, y_trash;

    /*Clearing Screen*/
    LCD.SetBackgroundColor(BLACK);
    LCD.Clear();
 
    LCD.WriteAt("You are headed out.", 45, 5);
    LCD.WriteAt("You can go alone,", 45, 25);
    LCD.WriteAt("or you can leave", 45, 45);
    LCD.WriteAt("with a friend.", 45, 65);
    LCD.WriteAt("Do you go ...", 45, 85);

    LCD.DrawRectangle(60, 130, 100, 50);
    LCD.WriteAt("Alone",65, 155);
    LCD.WriteAt("Friend",165, 155 );
    LCD.DrawRectangle(160, 130, 100, 50);

    /*Back to Main Menu Button*/
    LCD.WriteAt ("Menu", 130, 220);
    LCD.DrawHorizontalLine(210, 0, 500);
   while (1) {
        int start;
        start = time(NULL);
        while ((time(NULL) - start) <6 && !LCD.Touch(&x_position, &y_position)) {
            if ((time(NULL) - start)  >= 4.9 ) {
                x_position = 80;
                y_position = 140;
                break;
            }
        }
        while((time(NULL) - start) < 6 && LCD.Touch(&x_trash, &y_trash)) {
            if ((time(NULL) - start) >= 4.9) {
                break;
            }
         }; //Wait for Touch Release
        if (y_position > 210 && y_position < 240) { //If Menu Button is Hit
            gameMenu();
            break;
        }else if ((x_position > 60 && x_position < 160) && (y_position > 130 && y_position < 180)) { //Alone
                    /*Next*/
            /*Clearing Screen*/
            LCD.SetBackgroundColor(BLACK);
            LCD.Clear();


            LCD.WriteAt("Walking alone is", 40, 35);
            LCD.WriteAt("very dangerous.", 40, 55);
            LCD.WriteAt("Since you go alone,", 40, 75);
            LCD.WriteAt("you get lost.", 40, 95);  
            setenergyLevel(-5);
            sethappinessLevel(-5);
            //happiness decrease by 5
            Sleep(4.0);
            nextEvent();
            break;


        } else if ((x_position > 160 && x_position < 260) && (y_position > 130 && y_position < 180)) { //Else

         /*Clearing Screen*/
            LCD.SetBackgroundColor(BLACK);
            LCD.Clear();

            /*Lesson Screen*/
            LCD.WriteAt("Smart choice.", 40, 35);
            LCD.WriteAt("Walking alone ", 40, 55);
            LCD.WriteAt("is very dangerous, ", 40, 75);
            LCD.WriteAt("especially while ", 40, 95);
            LCD.WriteAt("intoxicated. Walking ", 40, 115);
            LCD.WriteAt("with a friend ",40,135);
            LCD.WriteAt("is much safer.", 40, 155);
            Sleep(4.0);
            nextEvent();
            break;
        }
    }
} //2nd to last event
void Player::transportationBack(){
     /*For Coordinate Tracking*/
    float x_position, y_position;
    float x_trash, y_trash;

    /*Clearing Screen*/
    LCD.SetBackgroundColor(BLACK);
    LCD.Clear();

    LCD.WriteAt("It is getting very late,", 45, 5);
    LCD.WriteAt("and you want to head", 45, 25);
    LCD.WriteAt("back to your dorm.", 45, 45);
    LCD.WriteAt("Do you walk back ", 45, 65);
    LCD.WriteAt("or call a ride?", 45, 85);

    LCD.DrawRectangle(60, 130, 100, 50);
    LCD.WriteAt("Walk",65, 155);
    LCD.WriteAt("Ride",165, 155 );
    LCD.DrawRectangle(160, 130, 100, 50);

    /*Back to Main Menu Button*/
    LCD.WriteAt ("Menu", 130, 220);
    LCD.DrawHorizontalLine(210, 0, 500);

    FEHImage lyft;
    lyft.Open("pxArt-6FEH.pic");
    lyft.Draw(25,140);
    lyft.Close();

    LCD.SetFontColor(WHITE);
   while (1) {
        int start;
        start = time(NULL);
        while ((time(NULL) - start) <6 && !LCD.Touch(&x_position, &y_position)) {
            if ((time(NULL) - start)  >= 4.9 ) {
                x_position = 80;
                y_position = 140;
                break;
            }
        }
        while((time(NULL) - start) < 6 && LCD.Touch(&x_trash, &y_trash)) {
            if ((time(NULL) - start) >= 4.9) {
                break;
            }
         }; //Wait for Touch Release
        if (y_position > 210 && y_position < 240) { //If Menu Button is Hit
            gameMenu();
            break;
        }else if ((x_position > 60 && x_position < 160) && (y_position > 130 && y_position < 180)) { //Ride
                        /*Clearing Screen*/
            LCD.SetBackgroundColor(BLACK);
            LCD.Clear();

            /*Next*/
            LCD.WriteAt("Walking around  is", 20, 35);
            LCD.WriteAt("very dangerous and tiring.", 20, 55);
            LCD.WriteAt("You can get easily lost.", 20, 75);
            Sleep(4.0);

            nextEvent();

            break;
            
        } else if ((x_position > 160 && x_position < 260) && (y_position > 130 && y_position < 180)) { //Else
            /*Clearing Screen*/
            LCD.SetBackgroundColor(BLACK);
            LCD.Clear();

            /*Lesson Screen*/
            LCD.WriteAt("Great Job! ", 40, 35);
            LCD.WriteAt("Getting a ride is ", 40, 55);
            LCD.WriteAt("is always the safer", 40, 75);
            LCD.WriteAt("option.With OSU's", 40, 95);
            LCD.WriteAt("Lyft Ride Smart,", 40, 115);
            LCD.WriteAt("rides at night around ", 40, 135);
            LCD.WriteAt("campus are discounted.", 40, 155);
            sethappinessLevel(5);
            Sleep(4.0);
            nextEvent();
            break;
        }
    }
} //Last Event

void Player::unidentifiedDrink2() {
     /*For Coordinate Tracking*/
    float x_position, y_position;
    float x_trash, y_trash;

    /*Clearing Screen*/
    LCD.SetBackgroundColor(BLACK); 
    LCD.Clear(); 

    LCD.WriteAt("Your friends", 65, 35);
    LCD.WriteAt("offer you an", 65, 55);
    LCD.WriteAt("unidentified drink", 50, 75);

    LCD.DrawRectangle(60, 130, 100, 50);
    LCD.WriteAt("Drink",65, 155);
    LCD.WriteAt("Decline",165, 155 );
    LCD.DrawRectangle(160, 130, 100, 50);

    FEHImage redCup;
    redCup.Open("pxArt-4FEH.pic");
    redCup.Draw(145,95);
    redCup.Close();

    LCD.SetFontColor(WHITE);

    /*Back to Main Menu Button*/
    LCD.WriteAt ("Menu", 130, 220);
    LCD.DrawHorizontalLine(210, 0, 500);



    while (1) {
        int start;
        start = time(NULL);

        while ((time(NULL) - start) <6 && !LCD.Touch(&x_position, &y_position)) {
            if ((time(NULL) - start)  >= 4.9 ) {
                x_position = 80;
                y_position = 140;
                break;
            }
        }

        while((time(NULL) - start) < 6 && LCD.Touch(&x_trash, &y_trash)) {
            if ((time(NULL) - start) >= 4.9) {
                break;
            }
         }; //Wait for Touch Release

        if (y_position > 210 && y_position < 240) { //If Menu Button is Hit
            gameMenu();
            break;
        }else if ((x_position > 60 && x_position < 160) && (y_position > 130 && y_position < 180)) { //If Drink is Hit
            /*Clearing Screen*/
            LCD.SetBackgroundColor(BLACK); 
            LCD.Clear(); 
            /*Lesson Screen*/
            LCD.WriteAt("Drinking an ", 50, 35);
            LCD.WriteAt("Unidentified Drink", 50, 55);
            LCD.WriteAt("is a ", 50, 75);
            LCD.WriteAt("Dangerous Idea", 50, 95);    
            LCD.WriteAt("+1 Drink Consumed",50, 115);
            LCD.WriteAt("-5% Energy ",50, 135);
            LCD.WriteAt("+5% Happiness",50, 155);

            Sleep(3.0);

            setalcConsumed(1); //Adds one alc to drink
            setenergyLevel(-5); /*-5% energy*/
            sethappinessLevel(5); /*5 Happiness*/

            nextEvent();
        } else if ((x_position > 160 && x_position < 260) && (y_position > 130 && y_position < 180)) {
            Sleep(1.0);
            nextEvent();
        }
}
}
void Player::choiceOfDrink2() {
    /*For Coordinate Tracking*/
    float x_position, y_position;
    float x_trash, y_trash;

    /*Clearing Screen*/
    LCD.SetBackgroundColor(BLACK); 
    LCD.Clear(); 

    LCD.WriteAt("At the party, ", 65, 5);
    LCD.WriteAt("do you drink..", 65, 25);
    LCD.WriteAt("#1- Labeled Beer", 65, 45);
    LCD.WriteAt("#2- Self-Made Drink", 65, 65);


    FEHImage beer;
    beer.Open("pxArt-5FEH.pic");
    beer.Draw(30,140);
    beer.Close();


    LCD.DrawRectangle(60, 130, 100, 50);
    LCD.WriteAt("#1",65, 155);
    LCD.WriteAt("#2",165, 155 );
    LCD.DrawRectangle(160, 130, 100, 50);

    /*Back to Main Menu Button*/
    LCD.WriteAt ("Menu", 130, 220);
    LCD.DrawHorizontalLine(210, 0, 500);

    FEHImage redCup;
    redCup.Open("pxArt-4FEH.pic");
    redCup.Draw(145,95);
    redCup.Close();

    LCD.SetFontColor(WHITE);


    while (1) {
        int start;
        start = time(NULL);

        while ((time(NULL) - start) <6 && !LCD.Touch(&x_position, &y_position)) {
            if ((time(NULL) - start)  >= 4.9 ) {
                x_position = 80;
                y_position = 140;
                break;
            }
        }

        while((time(NULL) - start) < 6 && LCD.Touch(&x_trash, &y_trash)) {
            if ((time(NULL) - start) >= 4.9) {
                break;
            }
         }; //Wait for Touch Release

        if (y_position > 210 && y_position < 240) { //If Menu Button is Hit
            gameMenu();
            break;
        }else if ((x_position > 60 && x_position < 160) && (y_position > 130 && y_position < 180)) { //If #1 is Hit
            setalcConsumed(1); /*Add one to drinks consumed*/
            LCD.WriteAt("+1 Drinks Consumed", 60, 100);

            Sleep (2.0);

            nextEvent();

            break;
        } else if ((x_position > 160 && x_position < 260) && (y_position > 130 && y_position < 180)) { //If #2 is Hit
            setalcConsumed(2); /*Add two to drinks consumed*/
            LCD.WriteAt("+2 Drinks Consumed", 60, 100);
        
            Sleep(2.0);

            nextEvent();

            break;
        }
    }

}



int main() { 
    // Clear background 
    LCD.SetBackgroundColor(BLACK); 
    LCD.Clear(); 
    Player currentPlayer;
    currentPlayer.gameMenu(); 
 
    while (1) { 
        LCD.Update(); 
        // Never end 
    } 
    return 0; 
} 
