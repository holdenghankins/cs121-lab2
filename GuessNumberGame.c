#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Asks for the user's name and greets them
 */
int greetPlayer() {
  //Asks for the user's name
  char userName[100];
  printf("Hi, what is your name? ");
  scanf("%s", userName);

  //Greets user
  printf("Nice to meet you %s.", userName);
  return 0;
}

/**
 * Generates a random number between 1 and 100
 * @returns number
 */
int getRandomNumber() {
  int randomNumber = (rand() % 100) + 1; //Random number 1-100

  //Ensures number is within bounds
  if (randomNumber < 1) {
    //Ensures number is always > 0
    randomNumber = 1;
  }
  else if (randomNumber > 100) {
    // Ensures number is always < 100
    randomNumber = 100;
  }

  return randomNumber;
}

/**
 * Runs the game, looping the user until they guess the correct number
 * @param number for user to guess
 * @returns number of turns user took to guess correctly
 */
int numberGame(int numberToGuess) {
  int turn = 0; //eventually returned
  bool hasGuessedCorrectly = false;
  int guess = 0;

  // Each turn, asks user for number, then says if it is higher, lower, or correct
  while(!hasGuessedCorrectly) {
    turn++;
    printf("\nTurn %i) Please guess a number: ", turn);
    scanf("%d", &guess);

    // Feedback on guess
    if (guess > numberToGuess) {
      printf("too high");
    }
    else if (guess < numberToGuess) {
      printf("too low");
    }
    else { // guess = numberToGuess
      printf("you got it!");
      hasGuessedCorrectly = true;
    }

    // If over 100 guesses have been made, breaks game to prevent inf loops
      if (turn > 100) {
      printf("\nYou didn't get it");
      return 101;
    }
  }

  return turn;
}

/**
 * Score reported back to them based on turns taken to guess number
 * <7 = good
 * 7 = average
 * >7 = bad
 * @param number of turns until correct guess
 */
int giveFeedback(int turnsTookToGuess) {
  if (turnsTookToGuess < 7) {
    printf("\nGreat job!\n");
  }
  else if (turnsTookToGuess > 7) {
    printf("\nPoor job.\n");
  }
  else { // Exactly 7
    printf("\nAverage job.\n");
  }
  return 0;
}

/**
 * greets a user, has them play a guess a number game, then gives them feedback on
 * the amount of turns they took
 */
int main() {
  srand(time(NULL)); //Seed for the random number
  greetPlayer();
  printf(" Let's play a game");
  int turnsToGuess;
  turnsToGuess = numberGame(getRandomNumber()); // Plays game
  giveFeedback(turnsToGuess);
  return 0;
}