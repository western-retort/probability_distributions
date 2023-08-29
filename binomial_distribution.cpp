// f(x) = lamba x e**(-lambda x X)

//n=trial number
//p=succes chance
//q=number of failures

#include<iostream>
#include<cmath>

long double mean(long double p , long double n){
    return n*p;
}


long double sd(long double p , long double n){
    long double q = 1 - p;
    return sqrt(n*p*q);
}

int factorial(int n) {
    if (n > 1) {
        return n * factorial(n - 1);
    } else {
        return 1;
    }
}

//ncx x px x qn-x
long double success_in_given_amount_of_trials(long double p , long double n , long double x){
    
    long double ncx = factorial(n)/(factorial(x)*factorial(n-x));
    long double px = pow(p,x);
    long double nq = pow((1-p),(n-x));

    return ncx*px*nq;
}

int main(){

    std::cout << "mean : " << mean(0.01,23) << "\n";
    std::cout << "sd :" << sd(0.01,23) << "\n";
    std::cout << "succes in given amount :" << sd(0.23,23);

    return 0;
}

