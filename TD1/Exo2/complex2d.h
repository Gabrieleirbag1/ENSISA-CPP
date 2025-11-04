#ifndef COMPLEX2D_H

#define COMPLEX2D_H

class Complex2D
{
public:
    Complex2D() {};
    Complex2D(double reel, double imaginaire);
    Complex2D(double valeur);

private:
    double t_reel;
    double t_imaginaire;
};

#endif