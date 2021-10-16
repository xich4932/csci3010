#ifndef __DISTRICT__
#define __DISTRICT__

const enum party{one, two, three};

class Candidate{
    public:
    Candidate();
    int get_ids();
    private:
    int id;
    party party_affiliation;

};

class Election{
    public:
        Election();
        void clear();
        void report();
        void report_winnder();
        int counting();
        
    private:
        
};

class District{
    public:

    private:

};

#endif