//mean and variance are the the2 only thing we need from a probability distributions
//mean (E[X])= sum of proabability of eventx#occurance
//variance = E[X square] - (E[X])square

#include <iostream>
#include <vector>  // Include the vector header

long double mean(std::vector<long double> X, std::vector<long double> P) {

    long double ans=0;
    for (size_t n = 0; n < X.size(); ++n) {  // Use semicolon here
        ans += X[n] * P[n];
    }
    return ans;
}

long double variance(std::vector<long double> X, std::vector<long double> P) {

    long double ans=0;
    for (size_t n = 0; n < X.size(); ++n) {  // Use semicolon here
        ans += X[n] * X[n] * P[n];
    }
    
    long double me = mean(X,P) * mean(X,P);
    return ans - me;
}




int main() {
    std::vector<long double> X = {1, 2,3};
    std::vector<long double> P = {0.1, 0.1, 0.1};

    std::cout << "Mean : " << mean(X,P) << std::endl;
    std::cout << "VAR : " << variance(X,P);

    return 0;
}
