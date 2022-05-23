//Here we are importing all the modules.

#include <cstdio>
#include <stdlib.h>
#include <ctime>
#include <string.h>
#include <string>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <chrono>
#include <thread>

using namespace std;
#define max 24 // define the max string
string strings[max];

//Here are all the word array
//all of them are separated according to the number of letters.
static string user_name;
static string pass_word;

char letter3[99][4]={"Cab", "Dab", "Jab", "Lab", "Nab", "Tab", "Bat", "Cat", "Fat", "Hat", "Mat", "Pat", "Rat", "Sat", "Hop", "Gel", "Pal", "Gas", "Yak", "Wax", "Bid", "Did",
                     "Hid", "Kid", "Lid", "Bog", "Cog", "Dog", "Mob", "Rob", "But", "Cut", "Gut", "Hut", "Nut"};

char letter4[99][5]={"Area", "Army", "Baby", "Back", "Ball", "Band", "Bank", "Base", "Bill", "Gold", "Hair", "Half", "Hall", "Hand", "Head", "Help", "Hill", "Home", "Bear",
                     "Beat", "Blow", "Burn", "Call", "Care", "Cast", "Cost", "Come", "Cook", "Mine", "Cold"};

char letter5[99][6]={"Apple", "Squid", "Child", "Eager", "Abide", "Abode", "Cable", "Inbox", "Early", "After", "Earth", "Cabin", "Cache", "Gamma", "Gauge", "North", "Laugh",
                     "Giant", "Jewel", "Glass", "Indie", "Laser", "Layer", "Lease", "Mayor"};

char letter6[99][7]={"Abacus", "Abduct", "Cactus", "Campus", "Edible", "Editor", "Effect", "Effort", "Emerge", "Galaxy", "Gallon", "Garage", "Garden", "Garlic", "Gender",
                     "Danger", "Factor", "Hammer", "Farmer", "Marvel"};

char letter7[99][8]={"Ancient", "Android", "Anxiety", "Capital", "Captain", "Economy", "Edition", "Gallery", "General", "Illegal", "Install", "Leather", "Library",
                     "License", "Parking"};

char letter8[99][9]={"Absolute", "Civilian", "Database", "Daughter", "Explicit", "Moderate", "Nineteen", "Observer", "Progress", "Umbrella"};



//These are all the arrays for the hints for the game

char hintlet3[36][255]={"Taxi", " a gentle stroke or touch", "To pierce with a pointed object ", "Laboratory", "To catch or seize", "A small insert or addition",
                        "A solid stick used for hitting balls in games", "A carnivorous mammal ", "Plump ", "A head covering", "A piece of fabric used as a floor covering", "A light blow with hand",
                        "A rodent ", "Past tense of sit", "Jump or leap", "A colloid in which solid is more than sol", "Friend", "A state of matter", "A large ox", "A substance secreted by bees",
                        "To offer a price", "Past tense of do ", "To conceal", "Child", "A move-able cover for a container", "A wet spongy ground", "A tooth on rim of wheel",
                        "A domesticated animal related to gray wolf", "A large number of people", "To steal from", "Other than / except", "To penetrate with something sharp",
                        "Digestive tract", "A shack", "A hard-shelled dry fruit or seed"};

char hintlet4[31][255]={"A piece of ground", "A large number of armed personnel", "A young child ", "Rear part of a body", "A round body or mass", "A thin encircling strip",
                        "Rising ground bordering a lake ", "Bottom or lowest part of something", "An account of separate cost of goods", "A yellow metallic element",
                        "A slender outgrowth of epidermis of animal", "Either of two equal parts", "A chief living room in a structure", "A forelimb",
                        "A part of boy containing eyes , nose , mouth", "To do something that makes it easier for someone to do a job", "An elevation of land", "House",
                        "A heavy animal that has thick hair and sharp claws", "To hit", "To move with speed or force", "Combustion", "To announce in loud voice", "Effort to do something safely",
                        "To put forth", "Price", "To move towards something", "Prepare food", "My", "Low temperature"};

char hintlet5[26][255]={"An edible pome fruit", "An animal having 8 short arms & 2 longer tentacles", "A young person between infancy and puberty", "Excited or interested",
                        "To tolerate", "Home ", "A strong wire rope", "A computer folder containing incoming email", "Before expected time", "Behind or later", "The planet on which we live",
                        "A private room on ship or boat", "A secure place of storage", "Third letter of greek alphabet ", "Distance between rails of railroad", "Direction on top of compass",
                        "Chuckle/amusement", "A living being of great size", "Precious stone", "A translucent material made of a mixture of silicates", "Independant", "Beam of coherent radiation",
                        "One fold lying over another", "A contract of real estate for a specific term", "An elected nominal head of a city or town"};

char hintlet6[21][255]={"An instrument for performing calculations by sliding counters along rods ", "Seize or kidnap ",
                        "Plants that have succulent stems and branches with scales or spines instead of leaves", " the grounds and buildings of a university, college, or school",
                        "Everythin that can be eaten", " someone who edits", " a distinctive impression", " a serious attempt", "To become known or apparent", "Very large groups of stars",
                        "A unit of liquid capacity equal to 231 cubic inches", "A shelter or repair shop for vehicles", " a plot of ground where herbs, fruits, flowers, or vegetables are cultivated",
                        "A plant cultivated for its pungent bulbs used in cooking", " the range of characteristics pertaining to, and differentiating between femininity and masculinity",
                        "Possibility of harm or death", "A thing that causes an event to happen", " a tool containing a solid metal head on a handle ",
                        "A person who cultivates land or raises animals", "One that causes astonishment or wonder"};

char hintlet7[16][255]={"Old or having long existence", "Robot with human form", "Fear or nervousness", "Area having main government offices", "A commander of a unit of troops",
                        "Process of system by which goods and services are produced and sold in a country", "The form or version in which a text is published", "An outdoor balcony",
                        "Relating to main or major parts of something rather than details", "Unlawful", " To make something ready to be used like a machine",
                        "Animal skin used for clothing and footwear ", " A place where books and other literary materials are kept",
                        "A permission granted by an official authority  for business or a certain activity", " An area used for storing vehicles"};

char hintlet8[11][255]={"Perfect or pure", "Outsider or not on active duty in armed services or official forces", "A large collection of organized data", "A female child",
                        "Very clear or complete", "Calm or temperate", "A number that is one more than eighteen", "An analyst or commentator in a particular field",
                        "Process of improving or developing something over a period of time", "A shade for protection against rain and snow"};


//These are all the global variables used throughout the program for various pruposes

char out[9];
int rintering;
int no=0;
int countdoku=0;
char p[20];
char wrongansarr[3][9];
char chh[10];
int sabsezyadascore= 0;
string name;
int score=0;
int scoring[100];




int len(string str)
{
    int length = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        length++;
    }
    return length;
}

void split (string str, char seperator)
{
    int currIndex = 0, i = 0;
    int startIndex = 0, endIndex = 0;
    while (i <= len(str))
    {
        if (str[i] == seperator || i == len(str))
        {
            endIndex = i;
            string subStr = "";
            subStr.append(str, startIndex, endIndex - startIndex);
            strings[currIndex] = subStr;
            currIndex += 1;
            startIndex = endIndex + 1;
        }
        i++;
    }
}

int word_finder(string w){
    ifstream fin;
    string line;
    fin.open("score_database.csv");
    while(!fin.eof()){
        fin>>line;
        //cout<<"found"<<line<<endl;
        split(line,',');
        if(strings[0]==w){
            fin.close();
            return 1;}


    }
    fin.close();
    return 0;
}
class User{
public:
    int highscore=0;
    string username;
    string password;
    User(string username1,string password1){
        while(read(user_name,pass_word)){
            cout<<"Wrong login info, Try again"<<endl;
            cout<<"Enter username:\n";
            cin>>user_name;
            cout<<"Enter password(IN NUMERIC ONLY):\n";
            cin>>pass_word;
            read(user_name,pass_word);
        }
            cout<<"Login Successful"<<endl;

    }
    User(){

    }
    int highscore_check(string username)
    {
        ifstream fin;
        string line;
        int highscore=0;

        // Open an existing file
        fin.open("score_database.csv");
        while(!fin.eof()){
            fin>>line;
            if(!(line.find(username))){
                //cout<<"found"<<line<<endl;
                split(line,',');
                // cout<<strings[2];
                if(stoi(strings[2])>highscore){
                    highscore=stoi(strings[2]);
                }
                continue;}

        }
        //cout<<"\n"<<highscore;
        fin.close();
        return highscore;
    }


    int read(string username,string passwd)
    {
        ifstream fin;
        string line;
        int ver=0;
        string passwd2;
        // Open an existing file
        fin.open("score_database.csv");
        while(!fin.eof()){
            fin>>line;
            split(line,',');

            if(strings[0]==username&&(stoi(strings[1]))==stoi(passwd)){
                /* ver=0;
                 cout<<"login succesful";*/
                //fin.close();
                return 0;
            }
            /*
            else if(ver){
                fin.close();
                return 1;
            }
            if (strings[0]==username){
                ver=1;
                continue;
    ;        }*/
        }
        cout<<"\n";
        return 1;
    }

    void sign_up(string username,string passwd){
        string us2;
        if((word_finder(username))){
            cout<<"Username is already taken or not available.\nEnter another username:";
            cin>>us2;
            cout<<"Enter password(IN NUMERIC ONLY):\n";
            cin>>passwd;
            sign_up(us2,passwd);
            read(username,passwd);
        }
        else{
            fstream fout;

            // opens an existing csv file or creates a new file.
            fout.open("score_database.csv", ios::out | ios::app);

            int highscore =0;


            // Insert the data to file
            fout << username << ","
                 << passwd << ","
                 << highscore
                 << "\n";
            fout.close();
            read(username,passwd);
        }
    }
};
static User use;

void create()
{

    fstream fout;

    // opens an existing csv file or creates a new file.
    //remove("score_database.csv");
    fout.open("score_database.csv", ios::out | ios::app);

    // Insert the data to file
    fout << "username" << ", "
         << "password" << ", "
         << "highscore"
         << "\n";
    fout.close();
}

//This is function stringcat
//This is a function taking two parameters
//First is a string and second integer the string is printed as much times as the value of integer.


//This function is used for creating a random number.
int randomno(int range){
    int rintu;
    time_t t;
    srand((unsigned) time(&t));
    rintu=rand()%range;
    return rintu;
}

int stringcat(string st,int k){
    for (int i=0;i<k;i++){
        cout<<st;
    }
    return 0;
}


//This function is used for creating a word with random spaces.
int stringprinter(char st[]){
    if (strlen(st)<5){
        int a=randomno(strlen(st));
        for (int i=0;i<strlen(st);i++){
            if (!(i==a)){
                printf(" %c ",st[i]);
            }
            else{
                printf(" _ ");
            }
        }
    }
    else if(strlen(st)<7){
        int a=randomno(strlen(st)/2);
        int b;
        while(true){
            b=randomno(strlen(st));
            if (b==a)
                continue;

            break;
        }
        for (int i=0;i<strlen(st);i++){
            if ((!(i==a)) && (!(i==b))){
                printf(" %c ",st[i]);
            }
            else{
                printf(" _ ");
            }
        }
    }

    else{
        int a=randomno(strlen(st)/2);
        int b;
        int c;
        while(true){
            b=randomno(strlen(st));
            if (b==a)
                continue;

            break;
        }
        while(true){
            c=randomno(strlen(st));
            if ((c==a)||(c==b))
                continue;

            break;
        }
        for (int i=0;i<strlen(st);i++){
            if ((!(i==a)) && (!(i==b)) && (!(i==c))){
                printf(" %c ",st[i]);
            }
            else{
                printf(" _ ");
            }
        }

    }

    return 1;
}


//This uses the time module to delay the program form running.
void delay(int number_of_seconds)
{
    /*
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);*/
    using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono; // nanoseconds, system_clock, seconds

    sleep_for(nanoseconds(10));
    sleep_until(system_clock::now() + seconds(number_of_seconds));

}





/*This is an function which uses multiple ascii values to print welcome to hangedman in 
a nice and decorative manner to indulge the player more into the game and make it more fascinating.
This fucntion makes the user fell welcome to play the game while using delay function to take time and 
make the player anticipate about the game more.*/
void welcome(){
    stringcat("\n",10);
    stringcat(" ",20);
    printf(" **       ** ******** **         ******    *******   ****     **** ********\n");
    stringcat(" ",20);
    printf("/**      /**/**///// /**        **////**  **/////** /**/**   **/**/**///// \n");
    stringcat(" ",20);
    printf("/**   *  /**/**      /**       **    //  **     //**/**//** ** /**/**      \n");
    stringcat(" ",20);
    printf("/**  *** /**/******* /**      /**       /**      /**/** //***  /**/******* \n");
    stringcat(" ",20);
    printf("/** **/**/**/**////  /**      /**       /**      /**/**  //*   /**/**////  \n");
    stringcat(" ",20);
    printf("/**** //****/**      /**      //**    **//**     ** /**   /    /**/**      \n");
    stringcat(" ",20);
    printf("/**/   ///**/********/******** //******  //*******  /**        /**/********\n");
    stringcat(" ",20);
    printf("//       // //////// ////////   //////    ///////   //         // //////// \n");

    delay(2);
    system(" clear");
    stringcat("\n",10);
    stringcat(" ",45);
    printf(" **********   *******     \n");
    stringcat(" ",45);
    printf("/////**///   **/////**    \n");
    stringcat(" ",45);
    printf("    /**     **     //**   \n");
    stringcat(" ",45);
    printf("    /**    /**      /**   \n");
    stringcat(" ",45);
    printf("    /**    /**      /**   \n");
    stringcat(" ",45);
    printf("    /**    //**     **    \n");
    stringcat(" ",45);
    printf("    /**     //*******     \n");
    stringcat(" ",45);
    printf("    //       ///////      \n");
    delay(2);
    system(" clear");
    stringcat("\n",10);
    stringcat(" ",10);
    printf(" **      **     **     ****     **   ********  ******** *******   ****     ****     **     ****     **\n");
    stringcat(" ",10);
    printf("/**     /**    ****   /**/**   /**  **//////**/**///// /**////** /**/**   **/**    ****   /**/**   /**\n");
    stringcat(" ",10);
    printf("/**     /**   **//**  /**//**  /** **      // /**      /**    /**/**//** ** /**   **//**  /**//**  /**\n");
    stringcat(" ",10);
    printf("/**********  **  //** /** //** /**/**         /******* /**    /**/** //***  /**  **  //** /** //** /**\n");
    stringcat(" ",10);
    printf("/**//////** **********/**  //**/**/**    *****/**////  /**    /**/**  //*   /** **********/**  //**/**\n");
    stringcat(" ",10);
    printf("/**     /**/**//////**/**   //****//**  ////**/**      /**    ** /**   /    /**/**//////**/**   //****\n");
    stringcat(" ",10);
    printf("/**     /**/**     /**/**    //*** //******** /********/*******  /**        /**/**     /**/**    //***\n");
    stringcat(" ",10);
    printf("//      // //      // //      ///   ////////  //////// ///////   //         // //      // //      /// \n");
    cout<<"\n\n\n";

    delay(4);
    system(" clear");
}


/*This function is used whenever a user answers a wrong answer it checks the 
number of times the user had entered the wrong answer before on the respective round
and uses the information to check weather the game is over or not and then
uses file handling to save the score into a binary file. it also prints an aesthetic YOU DIED 
if the user has dies.*/
void wrongans(int n){
    system(" clear");
    if (n==1){
        printf(":( Please Help me You have only 2 chances remaining for this round.\n\n");
        printf("  +---+\n");
        printf("  |   |\n");
        printf("  O   |\n");
        printf(" /|%c  |\n",92);
        printf(" / %c  |\n",92);
        printf(" =====|\n");
        printf("========= \n");
        printf("\n1 out of 3 lives gone for the round.\n2 Lives remaining.");
    }
    else if (n==2){
        printf(":( Please Help me You have only 1 chance remaining for this round.\n\n");
        printf("  +---+\n");
        printf("  |   |\n");
        printf("  O   |\n");
        printf(" /|%c  |\n",92);
        printf(" / %c  |\n",92);
        printf(" =====|\n");
        printf("========= \n");
        printf("\n2 out of 3 lives gone for the round.\n1 Live remaining.");
    }
    else{

        fstream fout;

        // opens an existing csv file or creates a new file.
        fout.open("score_database.csv", ios::out | ios::app);
        // Insert the data to file
        fout << user_name << ","
             << pass_word << ","
             << score
             << "\n";
        fout.close();

        countdoku= use.highscore_check(user_name);



        printf(":(\n\nOH NO!\n");
        printf("  +---+\n");
        printf("  |   |\n");
        printf(" |O|  |\n");
        printf(" /|%c  |\n",92);
        printf(" / %c  |\n",92);
        printf("      |\n");
        printf("========= \n");
        printf("\n");


        printf("oooooo   oooo   .oooooo.   ooooo     ooo      oooooooooo.   ooooo oooooooooooo oooooooooo.   \n");
        printf(" `888.   .8'   d8P'  `Y8b  `888'     `8'      `888'   `Y8b  `888' `888'     `8 `888'   `Y8b  \n");
        printf("  `888. .8'   888      888  888       8        888      888  888   888          888      888 \n");
        printf("   `888.8'    888      888  888       8        888      888  888   888oooo8     888      888 \n");
        printf("    `888'     888      888  888       8        888      888  888   888    '     888      888 \n");
        printf("     888      `88b    d88'  `88.    .8'        888     d88'  888   888       o  888     d88' \n");
        printf("    o888o      `Y8bood8P'     `YbodP'         o888bood8P'   o888o o888ooooood8 o888bood8P'   \n");





        printf("\n\nThe words were: %s , %s and %s \n",wrongansarr[0],wrongansarr[1],wrongansarr[2]);
        delay(7);
    }
    delay(3);
}


//This is the funciton which runs when the user has won the game .
//It also displays an asii smiley and enters the score into the binary file.
void winround(int end){
    sabsezyadascore= use.highscore_check(user_name);
    if(end==0)
        printf("\n Congrats correct Answer now onto next level!!\n");
    delay(2);
    if (end==1){
        system(" clear");
        printf("\n Congratulations you have completed the game\n");
        printf("\n");
        printf(" 0 0 0\n");
        printf("0 . . 0\n");
        printf("0 %c_/ 0\n",92);
        printf(" 0 0 0\n");

        fstream fout;

        // opens an existing csv file or creates a new file.
        fout.open("score_database.csv", ios::out | ios::app);

        // Insert the data to file
        fout << user_name << ","
             << pass_word << ","
             << score
             << "\n";
        fout.close();

        delay(4);
    }
}




//Theses are all functions for the levels
/*Each function uses  clear to clear the screen and each 
level is run and gives the informaiton to other functions.*/

class level{

};

bool level1(){
    score=0;
    system(" clear");
    stringcat(" ",39);
    printf("Level 1\t\t\tYour Highest Score = %d\t\t Your current score = %d\n",use.highscore_check(user_name),score);
    stringcat("_",120);
    rintering=randomno(35);
    printf("\n\n Here is the incomplete word:\n");
    printf("\n ");
    stringprinter(letter3[rintering]);
    printf("\n");
    stringcat("_ ",60);
    printf("\n\n Here is the Hint:\n");
    printf("\n %s\n", hintlet3[rintering]);
    stringcat("_ ",60);
    printf("\n\n Enter your guess:\n\n ");
    scanf("%s",&out);
    if (strcmp((out), (letter3[rintering]))==0){
        score+=3-no;
        winround(0);
        return true;}
    else if(no==2){
        strcpy(wrongansarr[2],letter3[rintering]);
        wrongans(0);
        printf("You have failed Level 1 :(\n\n\n");
        return false;}
    else{
        wrongans(no+1);
        strcpy(wrongansarr[no],letter3[rintering]);
        no++;
        return level1();
    }
}

bool level2(){
    system(" clear");
    rintering=randomno(30);
    stringcat(" ",39);
    printf("Level 2\t\t\tYour Highest Score = %d\t\t Your current score = %d\n",use.highscore_check(user_name),score);
    stringcat("_",120);
    printf("\n\n Here is the word:\n");
    printf("\n ");
    stringprinter(letter4[rintering]);
    printf("\n");
    stringcat("_ ",60);
    printf("\n\n Here is the Hint:\n");
    printf("\n %s\n", hintlet4[rintering]);
    stringcat("_ ",60);
    printf("\n\n Enter the word:\n\n ");
    scanf("%s",&out);
    if (strcmp( (out), (letter4[rintering]))==0){
        score+=3-no;
        winround(0);
        return true;}
    else if(no==2){
        strcpy(wrongansarr[2],letter4[rintering]);
        printf("You have failed Level 2 :(\n\n\n");
        wrongans(0);
        return false;}
    else{
        wrongans(no+1);
        strcpy(wrongansarr[no],letter4[rintering]);
        no++;
        return level2();
    }
}

bool level3(){
    system(" clear");
    rintering=randomno(25);
    stringcat(" ",39);
    printf("Level 3\t\t\tYour Highest Score = %d\t\t Your current score = %d\n",use.highscore_check(user_name),score);
    stringcat("_",120);
    printf("\n\n Here is the word:\n");
    printf("\n ");
    stringprinter(letter5[rintering]);
    printf("\n");
    stringcat("_ ",60);
    printf("\n\n Here is the Hint:\n");
    printf("\n %s\n", hintlet5[rintering]);
    stringcat("_ ",60);
    printf("\n\n Enter the word:\n\n ");
    scanf("%s",&out);
    if (strcmp( (out), (letter5[rintering]))==0){
        score+=3-no;
        winround(0);
        return true;}
    else if(no==2){
        strcpy(wrongansarr[2],letter5[rintering]);
        printf("You have failed Level 3 :(\n\n\n");
        wrongans(0);
        return false;}
    else{
        wrongans(no+1);
        strcpy(wrongansarr[no],letter5[rintering]);
        no++;
        return level3();
    }
}

bool level4(){
    system(" clear");
    rintering=randomno(20);
    stringcat(" ",39);
    printf("Level 4\t\t\tYour Highest Score = %d\t\t Your current score = %d\n",use.highscore_check(user_name),score);
    stringcat("_",120);
    printf("\n\n Here is the word:\n");
    printf("\n ");
    stringprinter(letter6[rintering]);
    printf("\n");
    stringcat("_ ",60);
    printf("\n\n Here is the Hint:\n");
    printf("\n %s\n", hintlet6[rintering]);
    stringcat("_ ",60);
    printf("\n\n Enter the word:\n\n ");
    scanf("%s",&out);
    if (strcmp( (out), (letter6[rintering]))==0){
        score+=3-no;
        winround(0);
        return true;}
    else if(no==2){
        strcpy(wrongansarr[2],letter6[rintering]);
        printf("You have failed Level 4 :(\n\n\n");
        wrongans(0);
        return false;}
    else{
        wrongans(no+1);
        strcpy(wrongansarr[no],letter6[rintering]);
        no++;
        return level4();
    }
}

bool level5(){
    system(" clear");
    rintering=randomno(15);
    stringcat(" ",39);
    printf("Level 5\t\t\tYour Highest Score = %d\t\t Your current score = %d\n",use.highscore_check(user_name),score);
    stringcat("_",120);
    printf(" Here is the word:\n");
    printf("\n ");
    stringprinter(letter7[rintering]);
    printf("\n");
    stringcat("_ ",60);
    printf("\n\n Here is the Hint:\n");
    printf("\n %s\n", hintlet7[rintering]);
    stringcat("_ ",60);
    printf("\n Enter the word:\n\n ");
    scanf("%s",&out);
    if (strcmp( (out), (letter7[rintering]))==0){
        score+=3-no;
        winround(0);
        return true;}
    else if(no==2){
        strcpy(wrongansarr[2],letter7[rintering]);
        printf("You have failed Level 5 :(\n\n\n");
        wrongans(0);
        return false;}
    else{
        wrongans(no+1);
        strcpy(wrongansarr[no],letter7[rintering]);
        no++;
        return level5();
    }
}

bool level6(){
    system(" clear");
    rintering=randomno(10);
    stringcat(" ",39);
    printf("Level 6\t\t\tYour Highest Score = %d\t\t Your current score = %d\n",use.highscore_check(user_name),score);
    stringcat("_",120);
    printf(" Here is the word:\n");
    printf("\n ");
    stringprinter(letter8[rintering]);
    printf("\n");
    stringcat("_ ",60);
    printf("\n\n Here is the Hint:\n");
    printf("\n %s\n", hintlet8[rintering]);
    stringcat("_ ",60);
    printf("\n Enter the word:\n\n ");
    scanf("%s",&out);
    if (strcmp( (out), (letter8[rintering]))==0){
        score+=3-no;
        winround(1);
        return true;}
    else if(no==2){
        strcpy(wrongansarr[2],letter8[rintering]);
        printf("You have failed Level 6 :(\n\n\n");
        wrongans(0);
        return false;}
    else{
        wrongans(no+1);
        strcpy(wrongansarr[no],letter8[rintering]);
        no++;
        return level6();
    }
}

int read(string username,string passwd)
{
    ifstream fin;
    string line;
    int ver=0;
    string passwd2;
    // Open an existing file
    fin.open("score_database.csv");
    while(!fin.eof()){
        fin>>line;
        split(line,',');

        if(strings[0]==username&&(stoi(strings[1]))==stoi(passwd)){
            /* ver=0;
             cout<<"login succesful";*/
            //fin.close();
            return 0;
        }
        /*
        else if(ver){
            fin.close();
            return 1;
        }
        if (strings[0]==username){
            ver=1;
            continue;
;        }*/
    }
    cout<<"\n";
    return 1;
}



void intro();

//this is the function which is used for running the
//games until the player has lost the game.
int playgame()
{
    while(1) {
        no=0;
        if (!level1()){
            break;
        }
        system(" clear");
        no=0;
        if (!level2()){
            break;
        }
        system(" clear");
        no=0;
        if (!level3()){
            break;
        }
        system(" clear");
        no=0;
        if (!level4()){
            break;
        }
        system(" clear");
        no=0;
        if (!level5()){
            break;
        }
        system(" clear");
        no=0;
        if (!level6()){
            break;
        }
        system(" clear");
        break;
    }
    system(" clear");
    intro();
    return 0;
}

//This is the funciton to start the game or display the score using file handling.
//This functin runs everytime when a game is completed or lost.
void intro()
{
    cout<<" Press any character and enter to start the game \n Type Exit to exit \n or Type 'Score' to see the score list.\n ";
    scanf("%s",&chh);

    if ((strcmp(chh,"score"))==0){
        ifstream fin;
        string line;
        // Open an existing file
        fin.open("score_database.csv");
        while(!fin.eof()){
            fin>>line;
            split(line,',');
            if(strings[0]==user_name)
            cout<<strings[2]<<endl;
        }
        cout<<"\n";
        fin.close();
        delay(6);
        intro();
    }

    else if((strcmp(chh,"exit"))==0){
        printf(" visit again !!\n");
        delay(2);
        exit(0);}
    else {
        playgame();
    }

}

//this function is main function
int main(){
    welcome();
    system(" clear");

    //create();//uncomment to create the csv file when needed
    cout<<"Signup or login?:\n";

    string t;
    cin>>t;
    cout<<"Enter username:\n";
    cin>>user_name;
    cout<<"Enter password(IN NUMERIC ONLY):\n";
    cin>>pass_word;
    if(t=="login"){
        static User use(user_name,pass_word);
    }
    else {
        static User use;
        use.sign_up(user_name,pass_word);
        static int sabsezyadascore= use.highscore_check(user_name);
    }

    name=user_name;
    cout<<name;
    intro();
    system(" clear");

    return 0;
}
