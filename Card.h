#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <String>

using namespace std;
enum aspect{ SCAR, ARTI, EARTH, WIND, FIRE, WATER, BOLT, LEAF };

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

class Card
{
	private:
		Card() { };
		string title;
		aspect type;
		int stats[2][3];
		string abilityText;
		string flavorText;

	public:
		Card(string ti, aspect ty, int att, int def, int pts, string ab, string fl)
		{
			title = ti;
			type = ty;
			stats[0][0] = att; stats[1][0] = att;
			stats[0][1] = def; stats[1][1] = def;
			stats[0][2] = pts; stats[1][2] = pts;
			abilityText= ab;
			flavorText = fl;
		}

		// operators
		bool Card::operator== (Card oth)
		{
			if ( (getTitle() ) == ( (oth.getTitle()) ) ) return true;
			return false;
		}

		// getters
		string Card::getTitle()    { return title; }
		aspect Card::getType()     { return type; }
		int Card::getAttack()      { return stats[0][0]; }
		int Card::getBaseAttack()  { return stats[1][0]; }
		int Card::getDefense()     { return stats[0][1]; }
		int Card::getBaseDefense() { return stats[1][1]; }
		int Card::getValue()       { return stats[0][2]; }
		string Card::getAbility()  { return abilityText; }
		string Card::getFlavor()   { return flavorText; }

		// setters
		void Card::buffAttack( int b )   { stats[0][0] += b; }
		void Card::buffDefense( int b )  { stats[0][1] += b; }
		void Card::scaleAttack( int s )  { stats[0][0] *= s; }
		void Card::scaleDefense( int s ) { stats[0][1] *= s; }
		void Card::setAttack( int x )    { stats[0][0]  = x; }
		void Card::setDefense( int x )   { stats[0][1]  = x; }
		void Card::resetAD()
		{
			setAttack( getBaseAttack() );
			setDefense( getBaseDefense() );
		}

		// printers
		void Card::print()
		{
			cout  << title << " ["; printType(); cout 
				<< "] A:" << stats[0][0] 
				<< " / D:" << stats[0][1] 
				<< " / V:" << stats[0][2] << endl;
			cout << abilityText << endl;
			cout << flavorText << endl;
		}

		void Card::printStats()
		{
			cout << "A:" << stats[0][0] 
				<< " / D:" << stats[0][1] 
				<< " / V:" << stats[0][2];
		}

		void Card::printType()
		{
			switch( type )
			{
			case SCAR: cout << "Scar"; break;
			case ARTI: cout << "Artifact"; break;
			case EARTH: cout << "Earth"; break;
			case WIND: cout << "Wind"; break;
			case FIRE: cout << "Fire"; break;
			case WATER: cout << "Water"; break;
			case BOLT: cout << "Electric"; break;
			case LEAF: cout << "Leaf"; break;
			}
		}
		
};

#endif