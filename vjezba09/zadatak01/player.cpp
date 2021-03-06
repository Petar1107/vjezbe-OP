#include "player.h"

Player::Player() 
{
	this->currentPoints = 0;
	this->points = 0;
}

void Player::checkCurrentHand(int guess)
{
	if (this->currentPoints == guess) 
	{
		this->points++;
		cout << "Correct\n";
	}
	else 
	{
		cout << "Incorrect\n";
	}
}
void Player::setHand(int value)
{
	this->currentPoints += value;
}
int Player::getHand()
{
	return this->currentPoints;
}
int Player::getPoints() 
{
	return this->points;
}
void Player::resetHand() 
{
	this->currentPoints = 0;
}
void ComputerPlayer::chooseSumOfCoins()
{
	resetHand();
	int NumberOfCoins = rand() % 3;
	int value;
	for (int i = 0; i < NumberOfCoins; i++)
	{
		value = rand() % 3;
		if (value == 0)
		{
			setHand(1);
		}
		else if (value == 1)
		{
			setHand(2);
		}
		else
		{
			setHand(5);
		}
	}
}

void HumanPlayer::chooseSumOfCoins()
{
	resetHand();
	int NumberOfCoins;
	int value;

	cout << "Choose how many coins you will use. three coins is the maximum: " << endl;
	for(;;)
	{
		cin >> NumberOfCoins;

		if (NumberOfCoins == 0 || NumberOfCoins == 1 || NumberOfCoins == 2 || NumberOfCoins == 3)
		{
			break;
		}
		else if (NumberOfCoins < 0)
		{
			cout << "The number of coins cannot be a negative number" << endl;
		}
		else
			cout << "Three coins is the maximum" << endl;
	}

	for(int i=0; i<NumberOfCoins; i++)
	{
		cout << "Choose a coin between 1 2 and 5 " << endl;
		cin >> value;
		if (value == 1) 
		{
			setHand(1);
			i++;
		}
		else if (value == 2) 
		{
			setHand(2);
			i++;
		}
		else if (value == 5)
		{
			setHand(5);
			i++;
		}
	}
}
int HumanPlayer::guessSumOfCoins()
{
	cout << "guess the sum of the coins generated by the computer: ";
	int ComputerSum;
	cin >> ComputerSum;
	return ComputerSum;
}

int ComputerPlayer::guessSumOfCoins()
{
	return rand() % 15;
}
