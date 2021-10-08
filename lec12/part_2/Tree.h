#ifndef TREE_H
#define TREE_H

class Tree {
    public:

        virtual void Seed() { number_seeds_ += 1; };
        inline static int number_trees_ = 1;
        int get_number_seeds() { return number_seeds_; }
       // static num_trees = 0;
    private:
        static int number_seeds_;
};

class sur : public Tree {
    public:
        void Seed() { 
            Tree temp;
            temp.Seed();
            temp.Seed();
        };
        
};

#endif // TREE_H
