#include <ctime>    // for std::time
#include <cstdlib>  // for std::srand, std::rand
#include "animal.hpp"
#include <iostream>
#include <string>
#include <vector>

struct The_farmer_says 
{

	void play(){
		// Seed the pseudo-random number generator.
		std::srand(std::time(0));
		// Create the "wheel"
		std::vector<Animal*> v = { 
			new Cow(),   new Cat(),   new Frog(),
			new Horse(), new Sheep(), new Dog(),
			new Duck(),  new Pig(),   new Fox() 
		};

		// Play the "game"
		for(int i=0;i<10;i++) {  
			Animal* a = v[rand() % (v.size())];
			std::cout << a->name() << " says " << a->sound() << '\n';
		}

		// Reclaim resources.
		for (Animal* a : v)
			delete a;
	}
};


int main()
{
	// Seed the pseudo-random number generator.
	std::srand(std::time(0));

	// Create the wheel.
	The_farmer_says game;

	// Play the game.
	game.play();
}

