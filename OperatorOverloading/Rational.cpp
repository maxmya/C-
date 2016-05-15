/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Rational.cpp
 * Author: maxmya
 *
 * Created on 24 February 2016, 18:25
 */

#include "Rational.h"
#include <iostream>

Rational::Rational(int nom, int dom) {
    setNumerator(nom);
    setDenominator(dom);
    int gcdV = gcd(getNumerator(), getDenominator());
    setNumerator(getNumerator() / gcdV);
    setDenominator(getDenominator() / gcdV);

}

void Rational::setDenominator(int dom) {
    if (dom != 0)
        denominator = dom;
    else
        std::cout << "Denominator cant be Zero , it had set by 1";
}

void Rational::setNumerator(int nom) {

    numerator = nom;

}

int Rational::getDenominator() {
    return denominator;


}

int Rational::gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int Rational::getNumerator() {
    return numerator;
}

Rational Rational::adding(Rational num1, Rational num2) {

    Rational sum;
    sum.setDenominator(num1.denominator * num2.denominator);
    sum.setNumerator((num1.numerator * num2.denominator) + (num1.denominator * num2.numerator));
    int gcdV = gcd(sum.numerator, sum.denominator);
    sum.setDenominator(sum.getDenominator() / gcdV);
    sum.setNumerator(sum.getNumerator() / gcdV);

    return sum;
}

Rational Rational::Subtracting(Rational num1, Rational num2) {

    Rational sum;
    sum.setDenominator(num1.denominator * num2.denominator);
    sum.setNumerator((num1.numerator * num2.denominator) - (num1.denominator * num2.numerator));
    int gcdV = gcd(sum.numerator, sum.denominator);
    sum.setDenominator(sum.getDenominator() / gcdV);
    sum.setNumerator(sum.getNumerator() / gcdV);

    return sum;

}

Rational Rational::mult(Rational num1, Rational num2) {

    Rational sum;
    sum.setDenominator(num1.getDenominator() * num2.getDenominator());
    sum.setNumerator(num1.getNumerator() * num2.getNumerator());
    int gcdV = gcd(sum.numerator, sum.denominator);
    sum.setDenominator(sum.getDenominator() / gcdV);
    sum.setNumerator(sum.getNumerator() / gcdV);
    return sum;
}

Rational Rational::div(Rational num1, Rational num2) {

    Rational sum;
    sum.setDenominator(num1.getDenominator() * num2.getNumerator());
    sum.setNumerator(num1.getNumerator() * num2.getDenominator());
    int gcdV = gcd(sum.numerator, sum.denominator);
    sum.setDenominator(sum.getDenominator() / gcdV);
    sum.setNumerator(sum.getNumerator() / gcdV);
    return sum;

}

const Rational operator+( Rational &num1 , Rational &num2) {

    Rational sum;
    sum.setDenominator(num1.getDenominator() * getDenominator());
    sum.setNumerator((num1.getNumerator() * getDenominator()) + (num1.getDenominator() * getNumerator()));
    int gcdV = gcd(sum.getNumerator(), sum.getDenominator());
    sum.setDenominator(sum.getDenominator() / gcdV);
    sum.setNumerator(sum.getNumerator() / gcdV);

    return sum;

}


//Rational Rational::operator-(Rational f, Rational s) {
//
//
//
//
//    return  0;
//}

//
//Rational Rational::operator*(Rational f, Rational s) {
//
//
//}

//Rational Rational::operator/(Rational f, Rational s) {
//
//
//}
//
//Rational Rational::operator>>(Rational f, Rational s) {
//
//
//}
//
//Rational Rational::operator<<(Rational f, Rational s) {
//
//
//}


void Rational::printRational() {

    std::cout << "Number IS " << getNumerator() << "/" << getDenominator() << " = " <<
    ((float) getNumerator() / (float) getDenominator()) << std::endl;

}