#ifndef ANIMAL_H
#define ANIMAL_H

// Name(s): Xiang Chen
//

class Animal {
public:
	Animal(std::string sound):
	sound_(sound)
	{}

	std::string MakeSound() const {return sound_; }

	void Fight(Animal &opponent);

	virtual int GetPower() { return 0; };

private:
	std::string sound_;
};

class Reptile : public Animal {
public:
	Reptile(std::string sound):
	Animal(sound + " rawr!")
	{}


	virtual int GetPower() { return 2; };

};

// Define your animals here.
// Define one class that inherits from Animal and
// one class that inherits from a child class of Animal
class fish : public Animal{
	public:
	fish(std::string sound): Animal(sound + "_fish"){};
	virtual int GetPower() {return 3;};
};


class shark : public fish{
	public:
	shark(std::string sound) : fish(sound + "_shark"){};
	int GetPower() {return 5;};
};
#endif  // ANIMAL_H
