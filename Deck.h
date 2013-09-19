#ifndef DECK_H
#define DECK_H

#include <algorithm>
#include <ctime>
#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "Card.h"

using namespace std;

const int DECK_SIZE = 48;
const int ENEMY_DECK_SIZE = 6;
const int STARTING_DECK_SIZE = 10;

class Deck
{
	private:
		list<Card> cardStack;
	public:
		Deck() { };
		list<Card> getStack() { return cardStack; };

	void loadMainDeck()
	{
		list<Card> temp = readFile( "cards.txt", DECK_SIZE );
		temp = shuffle( temp );
		cardStack = temp;
	}

	void loadVillainDeck()
	{
		list<Card> temp = readFile( "villains.txt", ENEMY_DECK_SIZE );
		temp = shuffle( temp );
		cardStack = temp;
	}

	void loadPlayerDeck()
	{
		list<Card> temp = readFile( "start.txt", STARTING_DECK_SIZE );
		temp = shuffle( temp );
		cardStack = temp;
	}

	void print()
	{
		for (list<Card>::iterator it = cardStack.begin(); 
			it != cardStack.end(); it++)
		{
			it->print(); cout << endl;
			cout << "````````````````````````````````" << endl;
		}
	}

	list<Card> readFile( string s, int n )
	{
		// initate the file stream
		ifstream read;
		read.open( s );
		list<Card> out;

		// read cards from cards.txt into a vector of Cards
		if ( read.is_open() )
		{
			for (int i = 0; i < n; i++)
			{
				string title; getline(read, title);

				string ty; getline(read, ty);
				aspect type = aspectFromString( ty );

				string stringAttack; getline(read, stringAttack);
				int attack = atoi( stringAttack.c_str() );
				string stringDefense; getline(read, stringDefense);
				int defense = atoi( stringDefense.c_str() );
				string stringValue; getline(read, stringValue);
				int value = atoi( stringValue.c_str() );

				string ability; getline(read, ability);
				string flavor; getline(read, flavor);

				Card newCard(title, type, attack, defense, value, ability, flavor);
				out.push_back( newCard );

				getline(read, title);
			}
		}
		read.close();
		return out;
	}

	list<Card> shuffle( list<Card> d )
	{
		vector<Card> temp;
		for (list<Card>::iterator it = d.begin(); it != d.end(); it++)
			temp.push_back( *it );

		srand ( unsigned ( std::time(0) ) );
		random_shuffle(temp.begin(), temp.end());

		d.empty();
		for (int i = 0; i < (signed)temp.size(); i++) d.push_back( temp[i] );

		return d;
	}

	aspect aspectFromString( string s )
	{
		aspect a = ARTI;
		if( s.compare("SCAR") == 0 ) a = SCAR;
		else if ( s.compare("ARTI") == 0 ) a = ARTI;
		else if ( s.compare("EARTH") == 0 ) a = EARTH;
		else if ( s.compare("WIND") == 0 ) a = WIND;
		else if ( s.compare("FIRE") == 0 ) a = FIRE;
		else if ( s.compare("WATER") == 0 ) a = WATER;
		else if ( s.compare("BOLT") == 0 ) a = BOLT;
		else if ( s.compare("BOLT") == 0 ) a = LEAF;

		return a;
	}

};

#endif