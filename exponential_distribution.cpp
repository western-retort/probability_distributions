//https://www.youtube.com/watch?v=J3KSjZFVbis  // solved part c of this 
//probability its gonna last between 3 and 10 years

#include <iostream>
#include <vector>   // Include the vector header
#include <numeric>  // Include the numeric header for std::accumulate
#include<cmath>

long double mean(const std::vector<long double>& ly) {
    // Calculate the mean of the elements in the vector
    long double sum = std::accumulate(ly.begin(), ly.end(), 0.0);
    return sum / ly.size();
}

//if x = 4 we will find value at x=4
long double calculate_to_left(long double lambda,long double x){
    //1-e^-lambda x X
    long double power = -lambda*x;
    long double p2 = std::exp(power);
    return 1 - p2;
}

int main() {
    std::vector<long double> laptop_year = {5};
    long double lambda = 1.0 / mean(laptop_year); // Use 1.0 to ensure floating-point division

    std::cout << "Enter 2 values bw u wanna find laptops life";
    long double ul;
    long double ll;

    std::cout << "==>";
    std::cin >> ul;
    std::cout << "==>";
    std::cin >> ll;

    if (ll>ul){
        long double t = ul;
        ul = ll;
        ll = t;
    }

    //probability the laptop survives between 4 and 7 years
    //using what if value less than 7
    long double seven = calculate_to_left(lambda,ul);
    long double four = calculate_to_left(lambda,ll);

    std::cout << seven - four;

    return 0;
}
