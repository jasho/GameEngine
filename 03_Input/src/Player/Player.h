#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include "../Misc/Vectors/Vector3.h"
#include <vector>
using namespace std;

class Item;
class Weapon;
class Armor;

class Player
{
public:
	Vector3 GetPosition();
protected:
private:
	Vector3 _position;
	float _velocity;
	float _health;
	float _energy;
	vector<Weapon *> _weapons;
	vector<Item *> _items;
	vector<Armor *> _armor;
	int _killings;
	//Model * _model;
	//Ammo

};
#endif
