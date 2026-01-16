# cs121-lab2
Guess a number game

Algo:
// intro
Ask user's name
  Store name
print "Nice to meet you [name]. Lets play a game\

// setup
int turn = 0
int guess = -1 // placeholder value 
boolean hasGuessedCorrectNumber = false
int numberToGuess = random number between 0 and 100 inclusive

// game
while (!hasGuessedCorrectNumber) {
  turn++
  print "turn [turn]) Please guess a number: "
    Store response in guess
  if (guess < numberToGuess) {
    print "\ntoo low\n"
  }
  else if (guess > numberToGuess) {
    print "\ntoo high\n"
  }
  else {
    print "\nyou got it\n"
    hasGuessedCorrectly = true
  }

// post game
if turn < 7 {
  print "Great job!"
}
else if turn > 7 {
  print "Poor job"
}
else {
  print "Average job"
}
