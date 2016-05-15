/*
 * File:   Rational.h
 * Author: maxmya
 *
 * Created on 24 February 2016, 18:25
 */


class Rational {
public:
    Rational(int = 0, int = 1);
    void setNumerator(int);
    int getNumerator();
    void setDenominator(int);
    int getDenominator();
    Rational adding(Rational, Rational);
    Rational Subtracting(Rational, Rational);
    void printRational();
    Rational mult(Rational, Rational);
    Rational div(Rational, Rational);

    const    Rational operator+( Rational&  , Rational& );

//    Rational operator-(Rational, Rational);
//    Rational operator*(Rational, Rational);
//    Rational operator/(Rational, Rational);
//    Rational operator>>(Rational, Rational);
//    Rational operator<<(Rational, Rational);s


private:
    int numerator;
    int denominator;

    int gcd(int, int);
};


