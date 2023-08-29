#include <iostream>
#include <cmath>
#include <iomanip>
#include<vector>
#include<fstream>


std::vector<long double> data_reader() {
    std::ifstream inputFile("data.txt");
    std::vector<long double> numbers;

    if (!inputFile.is_open()) {
        std::cout << "Failed to open the file." << std::endl;
        return numbers; // Return an empty vector
    }

    std::string line;

    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        long double num; // Use long double for more precision

        // Read each number from the line and add it to the vector
        while (iss >> num) {
            numbers.push_back(num);
        }
    }

    inputFile.close();
    return numbers;
}


long double arthematic_mean(std::vector<long double> numbers){
        
    long double total = 0;

    for(int i=0;i<numbers.size();i++){
        total += numbers[i];
    }
    
    return total/numbers.size();
}   


long double standard_deviation(std::vector<long double> numbers) {
    long double mean = arthematic_mean(numbers);

    long double total = 0;
        
    for(int i=0;i<numbers.size();i++){
        long double num = numbers[i] - mean;
        num = num * num;
        total += num;
    }

    long double variance =  total/numbers.size();
    return sqrt(variance);
    //return pow(numbers,0.5);
}

double calculateProbability(double z) {
    // Calculate the cumulative distribution function (CDF) using the erf function
    double probability = 0.5 * (1 + std::erf(z / std::sqrt(2.0)));

    return probability;
}


double z_calc(double x , double meu , double sd){
    return (x-meu)/sd;
}

int main() {

    std::vector<long double> numbers = data_reader();
    long double mean = arthematic_mean(numbers);
    long double sd = standard_deviation(numbers);

    long double x;
    std::cout << "x? : ";
    std::cin >> x;

    long double z = z_calc(x,mean,sd);

    std::cout << "probability : " << calculateProbability(z);

    return 0;
}
