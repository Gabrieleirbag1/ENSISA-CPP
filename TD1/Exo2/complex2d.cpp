#include <iostream>
#include "complex2d.h"

Complex2D::Complex2D() : t_reel(0.0f), t_imaginaire(0.0f) {}

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