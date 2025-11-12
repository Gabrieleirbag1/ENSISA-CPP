#include <iostream>
#include <cmath>
#include "complex2d.h"

Complex2D::Complex2D(double reel, double imaginaire) : t_reel(reel), t_imaginaire(imaginaire)
{
    t_reel = reel;
    t_imaginaire = imaginaire;
}

Complex2D::Complex2D(double valeur) : t_reel(valeur), t_imaginaire(valeur)
{
    t_reel = valeur;
    t_imaginaire = valeur;
}

Complex2D::Complex2D(const Complex2D& complex_copy_obj) {
    t_reel = complex_copy_obj.t_reel;
    t_imaginaire = complex_copy_obj.t_imaginaire;
}

Complex2D Complex2D::operator+(const Complex2D& complex_copy_obj) const {
    return Complex2D(t_reel + complex_copy_obj.t_reel, t_imaginaire + complex_copy_obj.t_imaginaire);
}

Complex2D Complex2D::operator-(const Complex2D& complex_copy_obj) const {
    return Complex2D(t_reel - complex_copy_obj.t_reel, t_imaginaire - complex_copy_obj.t_imaginaire);
}

Complex2D Complex2D::operator*(const Complex2D& complex_copy_obj) const {
    double new_reel = t_reel * complex_copy_obj.t_reel - t_imaginaire * complex_copy_obj.t_imaginaire;
    double new_imaginaire = t_reel * complex_copy_obj.t_imaginaire + t_imaginaire * complex_copy_obj.t_reel;
    return Complex2D(new_reel, new_imaginaire);
}


Complex2D Complex2D::operator/(const Complex2D& complex_copy_obj) const {
    double denominator = complex_copy_obj.t_reel * complex_copy_obj.t_reel + 
                        complex_copy_obj.t_imaginaire * complex_copy_obj.t_imaginaire;
    
    if (denominator == 0) {
        std::cerr << "Erreur: Division par zéro!" << std::endl;
        return Complex2D(0, 0);
    }
    
    double new_reel = (t_reel * complex_copy_obj.t_reel + t_imaginaire * complex_copy_obj.t_imaginaire) / denominator;
    double new_imaginaire = (t_imaginaire * complex_copy_obj.t_reel - t_reel * complex_copy_obj.t_imaginaire) / denominator;
    return Complex2D(new_reel, new_imaginaire);
}

// Correction : comparaison basée sur le module (norme) du nombre complexe
// |z| = √(a² + b²)
bool Complex2D::operator<(const Complex2D& complex_copy_obj) const {
    double module1 = sqrt(t_reel * t_reel + t_imaginaire * t_imaginaire);
    double module2 = sqrt(complex_copy_obj.t_reel * complex_copy_obj.t_reel + 
                          complex_copy_obj.t_imaginaire * complex_copy_obj.t_imaginaire);
    return module1 < module2;
}

bool Complex2D::operator>(const Complex2D& complex_copy_obj) const {
    double module1 = sqrt(t_reel * t_reel + t_imaginaire * t_imaginaire);
    double module2 = sqrt(complex_copy_obj.t_reel * complex_copy_obj.t_reel + 
                          complex_copy_obj.t_imaginaire * complex_copy_obj.t_imaginaire);
    return module1 > module2;
}

void Complex2D::setReel(double reel)
{
    t_reel = reel;
}

void Complex2D::setImaginaire(double imaginaire)
{
    t_imaginaire = imaginaire;
}

double Complex2D::getReel() const
{
    return t_reel;
}

double Complex2D::getImaginaire() const
{
    return t_imaginaire;
}