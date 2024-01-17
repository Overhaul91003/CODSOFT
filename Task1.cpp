// Task 1 : Number Guessing Game  


// Create a program that generates a random number and asks the user to guess it. Provide feedback on whether the guess is too high or too low until the user guesses the 
// correct number.

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std ;

int main()
{
    cout << "NUMBER GUESSING GAME" << endl ;

    int sv = time(0);

    srand(sv);

    int ran_num = 1+ rand() % 100 ;

    cout << "A Random Number has been Generated ! (Within 100)\n" ;

    int num_guess ;

    cout << "Guess the Generated Number : \n";

    cin >> num_guess ;

    if(num_guess == ran_num)
    {
        cout << "Great ! You guessed the Number on the First Try ." << endl ;
        cout << "GAME OVER !" ;
    }
    else
    {
        while(num_guess != ran_num)
        {
            if(num_guess > ran_num)
            {
                cout << "Guessed Higher ! Reduce value . \n";
                int lownum ;
                cin >> lownum ;
                num_guess = lownum ;
            }
            if(num_guess < ran_num)
            {
                cout << "Guessed Lower ! Increase Value . \n" ;
                int highnum;
                cin >> highnum ;
                num_guess = highnum ;
            }
        }

        cout << "You guessed the Number ! Congratulations ! \n";
        cout << "GAME OVER !" ;
    }






    return 0 ;
}