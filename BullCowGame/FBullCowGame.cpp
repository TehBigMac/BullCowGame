#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
bool FBullCowGame::IsGameWon() const { return false; }

void FBullCowGame::Reset()
{
	constexpr int MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;
	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	return;
}

bool FBullCowGame::CheckGueesValidity(FString)
{
	return false;
}

// Receives a valid guess, increments turn and returns count
BullCowCount FBullCowGame::SubmitGuess(FString)
{
	MyCurrentTry++;

	// setup a return variable
	BullCowCount BullCowCount;

	return BullCowCount;
}

