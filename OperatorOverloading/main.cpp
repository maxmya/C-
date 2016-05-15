

/*
 * File:   main.cpp
 * Author: maxmya
 *
 * Created on 24 February 2016, 17:42
 */

#include <cstdlib>

#include "Rational.h"

using namespace std;

/*
 *
 */
int main() {



    Rational rOne(8, 28);
    rOne.printRational();

    Rational rTwo(15, 135);
    rTwo.printRational();

    Rational rSum;
    rSum = rSum.adding(rOne, rTwo);
    rSum.printRational();
    rSum = rOne + rTwo ;

    Rational rSub;
    rSub = rSub.Subtracting(rOne, rTwo);
    rSub.printRational();

    Rational rMult;
    rMult = rMult.mult(rOne, rTwo);
    rMult.printRational();


    Rational rDiv;
    rDiv = rDiv.div(rOne, rTwo);
    rDiv.printRational();


    return 0;
}

