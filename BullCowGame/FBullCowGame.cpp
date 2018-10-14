#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return HiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

void FBullCowGame::Reset()
{
	constexpr int MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;
	const FString HIDDEN_WORD = "planet";
	HiddenWord = HIDDEN_WORD;
	bGameIsWon = false;
	return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false) //If guess not isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false) //If not lowercase
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (GetHiddenWordLength() != Guess.length()) // If length wrong
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
}

// Receives a valid guess, increments turn and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = HiddenWord.length();

	for (int32 HW_Cnt = 0; HW_Cnt < WordLength; HW_Cnt++)
	{
		for (int32 G_Cnt = 0; G_Cnt < WordLength; G_Cnt++)
		{
			if (Guess[G_Cnt] == HiddenWord[HW_Cnt])
			{
				if (HW_Cnt == G_Cnt)
				{
					BullCowCount.Bulls++;
				}
				else
				{
					BullCowCount.Cows++;
				}
			}
		}
	}
	if (BullCowCount.Bulls == WordLength)
	{
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}
	return BullCowCount;
}

