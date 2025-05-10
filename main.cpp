#include <iostream>
#include <ctime>
#include <time.h>
#include <stdio.h>
#include <cstdlib>
#include <conio.h>
#include <cmath>
#include <iomanip>
#include <windows.h>
#include <fstream>
#include "config.h"

using namespace std;

int repetitions, change = 3;
int with_observer, without_observer, without_observer1, end0, end1, end2;
int RandomNumber( int Min, int Max, int Wsp )
{
    srand( static_cast < unsigned int >( time( NULL ) * Wsp ) );


    int Result =( rand() %( Max - Min + 1 ) + Min );
    return Result;
}
string the_class ;
string choice ;
int number, start;

// Add color definitions
const int BRIGHT_WHITE = 15;
const int BRIGHT_CYAN = 11;
const int BRIGHT_MAGENTA = 13;
const int BRIGHT_YELLOW = 14;

void displayHeader();
void displayMenu();
void runExperiment(bool hasObserver);
void logError(const std::string& error);
double calculateInterference(double x, double wavelength, double slitSeparation);

int main() {
    SetConsoleTitle(PROGRAM_TITLE);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    while (true) {
        displayHeader();
        displayMenu();
        
        char choice = _getch();
        system("cls");

        switch (choice) {
            case '1':
                runExperiment(true);  // With observer
                break;
            case '2':
                runExperiment(false); // Without observer
                break;
            case '3':
                cout << "\nThank you for using " << PROGRAM_TITLE << endl;
                return 0;
            default:
                SetConsoleTextAttribute(hConsole, ConsoleColors::ERROR_COLOR);
                cout << "Invalid option! Press any key to continue...";
                _getch();
        }
        system("cls");
    }
}

void displayHeader() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, BRIGHT_CYAN);
    
    cout << "+----------------------------------------+\n";
    cout << "|       Young's Quantum Experiment        |\n";
    cout << "|          By Adrian Lesniak             |\n";
    cout << "+----------------------------------------+\n\n";
    
    SetConsoleTextAttribute(hConsole, BRIGHT_YELLOW);
    cout << "This program accurately simulates quantum behavior\n";
    cout << "in the double-slit experiment:\n\n";
    SetConsoleTextAttribute(hConsole, BRIGHT_MAGENTA);
    cout << "* With observer: Particle-like behavior\n";
    cout << "* Without observer: Wave interference pattern\n\n";
}

void displayMenu() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, BRIGHT_WHITE);
    
    cout << "+============= MENU ==============+\n";
    cout << "| 1. Run with observer          |\n";
    cout << "| 2. Run without observer       |\n";
    cout << "| 3. Exit                       |\n";
    cout << "+===============================-+\n";
    cout << "Select an option: ";
}

// Update probability calculations for more accurate quantum behavior
double calculateInterference(double x, double wavelength, double slitSeparation) {
    const double k = 2 * M_PI / wavelength;
    const double alpha = k * slitSeparation * sin(x);
    return pow(cos(alpha/2), 2);
}

void runExperiment(bool hasObserver) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hasObserver) {
        int tab1[SAMPLE_SIZE]; // Use constant from config.h

        for( int i = 0; i < SAMPLE_SIZE; i++ )
        {
            tab1[ i ] = RandomNumber( 1, 2, i + 1 ); //A different coefficient is used for each draw to avoid repetition of numbers
        }
        for( int i = 0; i < SAMPLE_SIZE; i++ )
        {
            cout << "Electron no." << i + 1 << " hits the slot number: " << tab1[ i ] << endl;
        }

        double average = 0;

        for (int i = 0; i < SAMPLE_SIZE; i++)
        {
            average = average + tab1[i];
        }

        average = average / SAMPLE_SIZE;

        cout << "\nAverage shots: " << average << endl;
        //The closer to number 1 or 2, the more times the photon hit the slot marked with this number (1 or 2).

        if ((average > 1.0) && (average < 1.5))
        {
            SetConsoleTextAttribute(hConsole, BRIGHT_CYAN);
            cout << "\nThe sum of hits in the left slit (1) is greater than the sum of hits in the right slit (2)." << endl;
            cout << "\n     1   2 " << endl;
            cout << "\n    *******" << endl;
            cout <<   "     ||  * " << endl;
            cout <<   "     ||  * " << endl;
            cout <<   "     ||  * " << endl;
            cout <<   "     ||  * " << endl;
            cout <<   "    *******" << endl;
        }
        if ((average > 1.5) && (average < 2.0))
        {
            SetConsoleTextAttribute(hConsole, BRIGHT_MAGENTA);
            cout << "\nThe sum of hits in the right slit (2) is greater than the sum of hits in the left slit (1)." << endl;
            cout << "\n     1   2 " << endl;
            cout << "\n    *******" << endl;
            cout <<   "     *  || " << endl;
            cout <<   "     *  || " << endl;
            cout <<   "     *  || " << endl;
            cout <<   "     *  || " << endl;
            cout <<   "    *******" << endl;
        }
        else if (average == 1.5)
        {
            SetConsoleTextAttribute(hConsole, BRIGHT_YELLOW);
            cout << "\nThe sum of hits in both slits is equal." << endl;
            cout << "\n     1    2 " << endl;
            cout << "\n    ********" << endl;
            cout <<   "     ||  || " << endl;
            cout <<   "     ||  || " << endl;
            cout <<   "     ||  || " << endl;
            cout <<   "     ||  || " << endl;
            cout <<   "    ********" << endl;
        }

        SetConsoleTextAttribute(hConsole, BRIGHT_WHITE);
        cout << "\nThe sum of hits in the slits corresponds to the sum of hits on the scoreboard." <<endl;
        Beep(523.3, 200); // sound announcing the end of the draw

        end1:
        cout << "\nDo you want to repeat the experiment with an observer? "<< endl;
        cout << "If you want to go back to the beginning,"<< endl;
        cout << "press the (s) key and confirm with enter. (y/n/s): " ;

        char answer1;
        cin >> answer1;
        cout<<' '<<endl;

        if (answer1 == 'y')
        {
            system( "cls" );
            runExperiment(true);
        }
        if (answer1 == 'n')
        {
            return;
        }
        if (answer1 == 's')
        {
            system( "cls" );
            return;
        }
        else
        {
            cout<<"Wrong value entered."<<endl;
            goto end1;
        }
    } else {
        int tab4[SAMPLE_SIZE];
        double average2 = 0;

        for(int i = 0; i < SAMPLE_SIZE; i++) {
            tab4[i] = RandomNumber(1, 4, i + 1);
        }
        cout<<"EXPERIMENT WITHOUT THE OBSERVER"<<endl;
        cout<<"\nFirst, we have to check where the most electrons land."<<endl;
        cout<<"We shoot 1000 times. The average shots hit determines the score."<<endl;
        cout<<"\nPossibilities are:"<<endl;
        cout<<"* hitting wall"<<endl;
        cout<<"* right slit"<<endl;
        cout<<"* left slit (sequence established) + alternatives."<<endl;
        cout<<"* both slits"<<endl;

        cout << "\nFor the full effect, the observer cannot participate in the observation." << endl;
        cout << "You have a few seconds to leave the room or turn off the screen for a moment." <<endl;
        cout << "The decision is yours. You can also compare the results of the two decisions." <<endl;
        cout<<"\nPress any key to run a virtual random machine (and turn off the screen)."<<endl;
        cout<<""<<endl;
        getch();
        number=10;

        Sleep( 3000 );
        srand( time( NULL ) );
        repetitions = rand() % 5 + 5;
        for( int i = 1; i <= repetitions; i++ )
        {
            cout << ".";
            Sleep( 1000 );
        }

        for( int i = 0; i < SAMPLE_SIZE; i++ )
        {
            cout << "Random selection no. " << i + 1 << " | Result: " << tab4[ i ] << endl;
        }

        for (int p = 0; p < SAMPLE_SIZE; p++)
        {
            average2 = average2 + tab4[p];
        }

        average2 = average2 / SAMPLE_SIZE;
        cout << "\nMaximum average of the electrons fired (where most electrons land): " << average2 << endl;

        if (( average2 > 1.0)&&(average2 < 1.75)) //into the wall
        {    cout << "RESULTS EXPLANATION : Most electrons hit the wall in front of the blackboard."<< endl;
            cout << "\nSome electrons split as they passed through both slits"<<endl;
            cout << "creating an interference pattern on the blackboard."<<endl;
        }

        if ( average2 == 1.75)
        {
            cout << "RESULTS EXPLANATION : Most of the electrons hit the wall in front of the blackboard"<< endl;
            cout << "equally with the electrons that passed through the right slit." <<endl;
            cout << "\nSome electrons split as they passed through both slits"<<endl;
            cout << "creating an interference pattern on the blackboard."<<endl;
        }

        if (( average2 > 1.75)&&(average2 < 2.5)) //in the right slit
        {
            cout << "RESULTS EXPLANATION : Most electrons passed through the right slit."<< endl;
            cout << "\nSome electrons split as they passed through both slits"<<endl;
            cout << "creating an interference pattern on the blackboard."<<endl;
        }

        if ( average2 == 2.5)
        {
            cout << "RESULTS EXPLANATION : Most electrons passed through the right slit."<< endl;
            cout << "equally with the electrons that hit the wall in front of the blackboard." <<endl;
            cout << "\nSome electrons split as they passed through both slits"<<endl;
            cout << "creating an interference pattern on the blackboard."<<endl;
        }

        if (( average2 > 2.5)&&(average2 < 3.25))
        {
            cout << "RESULTS EXPLANATION : Most electrons simultaneously passed through both slits"<< endl;
            cout << "creating an interference pattern on the blackboard."<<endl;
        }

        if ( average2 == 3.25)
        {
            cout << "RESULTS EXPLANATION : Most electrons simultaneously passed through both slits"<< endl;
            cout << "equally with the electrons that hit the wall in front of the blackboard." <<endl;
        }

        if (( average2 > 3.25)&&(average2 < 4.0))
        {
            cout << "RESULTS EXPLANATION : Most electrons passed through the left slit."<< endl;
            cout << "\nSome electrons split as they passed through both slits"<<endl;
            cout << "creating an interference pattern on the blackboard."<<endl;
        }

        if ( average2 == 4.0)
        {
            cout << "RESULTS EXPLANATION : Most electrons passed through the left slit"<< endl;
            cout << "equally with the electrons that hit the wall in front of the blackboard." <<endl;
            cout << "\nSome electrons split as they passed through both slits"<<endl;
            cout << "creating an interference pattern on the blackboard."<<endl;
        }

        Beep(523.3, 200); //sound announcing the end of the draw

        cout << "\nPress any key to continue."<<endl;
        getch();
        system ("cls");

        int tab2[SAMPLE_SIZE]; //data can and should be changed

        for( int i = 0; i < SAMPLE_SIZE; i++ )
        {
            tab2[ i ] = RandomNumber( 1, 7, i + 1 ); /*A different coefficient is used for each draw to avoid repetition of numbers*/
        }

        cout<<"The next stage of the experiment is to check"<<endl;
        cout<<"where is the point of the greatest wave interference on the board,"<<endl;
        cout<<"which hangs behind the wall with slits."<<endl;
        cout<<"\nPossibilities are: Designated point (1) and range of maximum wave interference (2)"<<endl;
        cout<<"We draw 1000 times. The average of the drawn numbers is responsible for"<<endl;
        cout<<"the point of the highest wave interference."<<endl;

        cout << "\nFor the full effect, the observer cannot participate in the calculations." << endl;
        cout << "You have a few seconds to leave the room or turn off the screen for a moment." <<endl;
        cout << "The decision is yours. You can also compare the results of the two decisions." <<endl;
        cout << "\nPress any key to run a virtual random machine (and turn off the screen)."<<endl;
        cout << ""<<endl;
        getch();

        Sleep( 3000 );
        srand( time( NULL ) );
        repetitions = rand() % 5 + 5;
        for( int i = 1; i <= repetitions; i++ )
        {
            cout << ".";
            Sleep( 1000 );
        }

        for( int i = 0; i < SAMPLE_SIZE; i++ )
        {
            cout << "Electron no." << i + 1 << " hits the blackboard field " << tab2[ i ] << endl;
        }

        double average1 = 0;

        for (int i = 0; i < SAMPLE_SIZE; i++)
        {
            average1 = average1 + tab2[i];
        }

        average1 = average1 / SAMPLE_SIZE; //the average is (almost) always close to the middle!!!
        cout << "\n(1)Greatest interference value of the wave (|):  " << average1 << endl;
        //The closer to number 1 or 2, the more times the photon hit the slit marked with this number (1 or 2).

        //the wave interference function
        if ((average1 >= 1.0) && (average1 <= 1.9999))
        {
            cout << "\nBelongs to the array interval (2): (from 1.0 to 1.99)." << endl;
            cout << "\n  1.0  1.5  2.0  2.5  3.0  3.5  4.0  4.5  5.0  5.5  6.0  6.5  7.0  7.5  8.0" << endl;
            cout << "\n  -------------------------------------------------------------------------" << endl;
            cout <<   "        |         :         ;         .         .         .         ." << endl;
            cout <<   "        |         :         ;         .         .         .         ." << endl;
            cout <<   "        |         :         ;         .         .         .         ." << endl;
            cout <<   "        |         :         ;         .         .         .         ." << endl;
            cout <<   "  -------------------------------------------------------------------------" << endl;
        }
        if ((average1 >= 2.0) && (average1 <= 2.9999))
        {
            cout << "\nBelongs to the array interval (2): (from 2.0 to 2.99)." << endl;
            cout << "\n  1.0  1.5  2.0  2.5  3.0  3.5  4.0  4.5  5.0  5.5  6.0  6.5  7.0  7.5  8.0" << endl;
            cout << "\n       --------------------------------------------------------------" << endl;
            cout <<   "        :         |         :         ;         .         .         ." << endl;
            cout <<   "        :         |         :         ;         .         .         ." << endl;
            cout <<   "        :         |         :         ;         .         .         ." << endl;
            cout <<   "        :         |         :         ;         .         .         ." << endl;
            cout <<   "  -------------------------------------------------------------------------" << endl;
        }
        if ((average1 >= 3.0) && (average1 <= 3.9999))
        {
            cout << "\nBelongs to the array interval (2): (from 3.0 to 3.99)." << endl;
            cout << "\n  1.0  1.5  2.0  2.5  3.0  3.5  4.0  4.5  5.0  5.5  6.0  6.5  7.0  7.5  8.0" << endl;
            cout << "\n       --------------------------------------------------------------" << endl;
            cout <<   "        ;         :         |         :         ;         .         ." << endl;
            cout <<   "        ;         :         |         :         ;         .         ." << endl;
            cout <<   "        ;         :         |         :         ;         .         ." << endl;
            cout <<   "        ;         :         |         :         ;         .         ." << endl;
            cout <<   "  -------------------------------------------------------------------------" << endl;
        }
        if ((average1 >= 4.0) && (average1 <= 4.9999))
        {
            cout << "\nBelongs to the array interval (2): (from 4.0 to 4.99)." << endl;
            cout << "\n  1.0  1.5  2.0  2.5  3.0  3.5  4.0  4.5  5.0  5.5  6.0  6.5  7.0  7.5  8.0" << endl;
            cout << "\n        .         ;         :         |         :         ;         ." << endl;
            cout <<   "        .         ;         :         |         :         ;         ." << endl;
            cout <<   "        .         ;         :         |         :         ;         ." << endl;
            cout <<   "        .         ;         :         |         :         ;         ." << endl;
            cout <<   "  -------------------------------------------------------------------------" << endl;
        }
        if ((average1 >= 5.0) && (average1 <= 5.9999))
        {
            cout << "\nBelongs to the array interval (2): (from 5.0 to 5.99)." << endl;
            cout << "\n  1.0  1.5  2.0  2.5  3.0  3.5  4.0  4.5  5.0  5.5  6.0  6.5  7.0  7.5  8.0" << endl;
            cout << "\n       --------------------------------------------------------------" << endl;
            cout <<   "        .         .         ;         :         |         :         ;" << endl;
            cout <<   "        .         .         ;         :         |         :         ;" << endl;
            cout <<   "        .         .         ;         :         |         :         ;" << endl;
            cout <<   "        .         .         ;         :         |         :         ;" << endl;
            cout <<   "  -------------------------------------------------------------------------" << endl;
        }
        if ((average1 >= 6.0) && (average1 <= 6.9999))
        {
            cout << "\nBelongs to the array interval (2): (from 6.0 to 6.99)." << endl;
            cout << "\n  1.0  1.5  2.0  2.5  3.0  3.5  4.0  4.5  5.0  5.5  6.0  6.5  7.0  7.5  8.0" << endl;
            cout << "\n       --------------------------------------------------------------" << endl;
            cout <<   "        .         .         .         ;         :         |         :" << endl;
            cout <<   "        .         .         .         ;         :         |         :" << endl;
            cout <<   "        .         .         .         ;         :         |         :" << endl;
            cout <<   "        .         .         .         ;         :         |         :" << endl;
            cout <<   "  -------------------------------------------------------------------------" << endl;
        }
        if ((average1 >= 7.0) && (average1 <= 7.9999))
        {
            cout << "\nBelongs to the array interval (2): (from 6.0 to 6.99)." << endl;
            cout << "\n  1.0  1.5  2.0  2.5  3.0  3.5   4.0  4.5  5.0  5.5  6.0  6.5  7.0  7.5  8.0" << endl;
            cout << "\n       --------------------------------------------------------------" << endl;
            cout <<   "        .         .         .         ;         :         |         :" << endl;
            cout <<   "        .         .         .         ;         :         |         :" << endl;
            cout <<   "        .         .         .         ;         :         |         :" << endl;
            cout <<   "        .         .         .         ;         :         |         :" << endl;
            cout <<   "  -------------------------------------------------------------------------" << endl;
        }

        Beep(523.3, 200); // sound announcing completion of the draw

        end0:
        cout << "\nDo you want to repeat the experiment?(y/n) "<< endl;
        char answer;
        cin >> answer;
        cout<<' '<<endl;

        if (answer == 'y')
        {
            system( "cls" );
            runExperiment(false);
        }
        if (answer == 'n')
        {
            return;
        }
        else
        {
            cout<<"Wrong value entered."<<endl;
            goto end0;
        }
    }
}

