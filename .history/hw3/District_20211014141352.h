#ifndef __DISTRICT__
#define __DISTRICT__

const enum party{one, two, three};

class Candidate{
    public:
    Candidate();
    int get_ids();
    private:
    int id;  
};

class Election{
    public:
        Election();
        void clear();
        void report();
        
    private:
        
};

class District{
    public:

    private:

};

#endif