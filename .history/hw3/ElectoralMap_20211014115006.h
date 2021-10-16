#ifndef __ELECTORALMAP__
#define __ELECTORALMAP__

class ElectoralMap{
    public:
        static ElectoralMap& getInstance(){
            static ElectoralMap instance;
            return instance;
        }

    private:
        ElectoralMap();
        
};

#endif