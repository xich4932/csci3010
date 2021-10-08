#ifndef header_h
#define header_h

class Point{
    public:
        Point();
        Point(int ,int);
        void setter_x(int);
        int getter_x(void);
        void setter_y(int );
        int getter_y(void);
        double Distance(Point*);
        void Translate(int d);
    private:
        int x;
        int y;
};

#endif
