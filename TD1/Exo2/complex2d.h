#ifndef COMPLEX2D_H
#define COMPLEX2D_H

class Complex2D
{
public:
    Complex2D() {};
    Complex2D(double reel, double imaginaire);
    Complex2D(double valeur);
    Complex2D(const Complex2D& complex_copy_obj);

    Complex2D operator+(const Complex2D& complex_copy_obj) const;
    Complex2D operator-(const Complex2D& complex_copy_obj) const;
    Complex2D operator*(const Complex2D& complex_copy_obj) const;
    Complex2D operator/(const Complex2D& complex_copy_obj) const;
    
    bool operator<(const Complex2D& complex_copy_obj) const;
    bool operator>(const Complex2D& complex_copy_obj) const;

    void setReel(double reel);
    void setImaginaire(double imaginaire);
    double getReel() const;
    double getImaginaire() const;

private:
    double t_reel;
    double t_imaginaire;
};

#endif