#ifndef EARTH_H
#define EARTH_H


class Earth {
public:
	
	static Earth& GetInstance() {
		// gets instantiated the first time
		static Earth instance; // guaranteed to be destroyed

		return instance;
	}

	inline static int animal = 0;

    int get_population() { return population_; };
	
    void IncreasePopulation() { population_ += 1; };

	// Delete the methods we don't want
	Earth(Earth const&) = delete; // copy constructor
	void operator=(Earth const&) = delete; // assignment operator

 private:
 	Earth();  // private constructor

    int population_;
  
};  // class Earth

#endif  // EARTH_H

