#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// Two integers, initialised to zero
struct BullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame
{
public:
	FBullCowGame(); //Constructor

	int32 GetMaxTries() const; //Gets the max number of tries allowed
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset();
	bool CheckGueesValidity(FString);

	// Counts bulls & cows and increases try count, assuming valid guess
	BullCowCount SubmitGuess(FString);

private:
	// See Constructor for Init
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};