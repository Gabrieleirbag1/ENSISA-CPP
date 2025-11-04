#ifndef COMPLEX2D_H

#define COMPLEX2D_H

class Complex2D
{
public:
    Complex2D() {};
    Complex2D(double reel, double imaginaire);
    Complex2D(double valeur);

    void Complex2D::setReel(double reel);
    void Complex2D::setImaginaire(double imaginaire);
    double Complex2D::getReel() const;
    double Complex2D::getImaginaire() const;

private:
    double t_reel;
    double t_imaginaire;
};

#endif