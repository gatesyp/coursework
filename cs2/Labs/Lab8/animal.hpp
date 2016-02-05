#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

struct Animal
{
  std::string virtual name() = 0;
  std::string virtual sound() = 0;  
};
struct Cow : Animal{
virtual std::string name(){
	std::string name = "cow";
	return name; 	
}
virtual std::string sound() {
	std::string sound = "moo";
	return sound;
}
};

struct Cat: Animal{
virtual std::string name(){
	std::string name = "cat";
	return name; 	
}
virtual std::string sound() {
	std::string sound = "mewo";
	return sound;
}
};struct Frog : Animal{
virtual std::string name(){
	std::string name = "frog";
	return name; 	
}
virtual std::string sound() {
	std::string sound = "ribbit";
	return sound;
}
};struct Horse : Animal{
virtual std::string name(){
	std::string name = "horse";
	return name; 	
}
virtual std::string sound() {
	std::string sound = "neigh";
	return sound;
}
};

struct Sheep : Animal{
virtual std::string name(){
	std::string name = "sheep";
	return name; 	
}
virtual std::string sound() {
	std::string sound = "baaaaa";
	return sound;
}
};


struct Dog : Animal{
virtual std::string name(){
	std::string name = "dog";
	return name; 	
}
virtual std::string sound() {
	std::string sound = "woof";
	return sound;
}
};

struct Duck : Animal{
virtual std::string name(){
	std::string name = "fuck";
	return name; 	
}
virtual std::string sound() {
	std::string sound = "qwak";
	return sound;
}
};
struct Pig : Animal{
virtual std::string name(){
	std::string name = "pig";
	return name; 	
}
virtual std::string sound() {
	std::string sound = "oink";
	return sound;
}
};
struct Fox : Animal{
virtual std::string name(){
	std::string name = "fox";
	return name; 	
}
virtual std::string sound() {
	std::string sound = "????????????????????????";
	return sound;
}
};

#endif
