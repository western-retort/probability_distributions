// P(A|B) = P(A INTERSECTION B)/P(B)

#include<iostream>

long double conditional_probability(long double B , long double intersection){
    return intersection/B;
}


int main(){

    std::cout << conditional_probability(0.8,0.4);
    return 0;
}


//Bayes’ Theorem is derived using the definition of conditional probability. It is used to find the reverse probability
//For any two events A and B, then the formula for the Bayes theorem is given by:  P(A|B) = P(B|A)XP(A) / P(B)
// Bayes Theorem Formula
 
// where,
// P(A) and P(B) are the probabilities of events A and B also P(B) is never equal to zero.
// P(A|B) is the probability of event A when event B happens
// P(B|A) is the probability of event B when A happens