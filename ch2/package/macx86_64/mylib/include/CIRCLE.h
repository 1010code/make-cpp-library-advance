class CIRCLE
{
    // private variables
    double _radius;

    public:
        CIRCLE();
        CIRCLE(double radius);
        void GetArea();
        void SetRadius (double radius);

    private:
        void Display(double area);
};