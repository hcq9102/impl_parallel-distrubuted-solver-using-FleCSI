#include <iostream>
#include <fstream>
#include <iomanip>
#include <random>
#include <string>

int main() {
    int n;  // lines
    double displacement = 1.0;  //initial displacement

    std::cout << "enter number of lines：";
    std::cin >> n;

    std::ofstream file("spring_system_" + std::to_string(n) + ".txt");
    if (!file.is_open()) {
        std::cerr << "cannot create files" << std::endl;
        return 1;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> displacement_increment_distribution(0.5, 1.0);

    for (int i = 0; i < n; ++i) {
        int mass = (i % 4) + 3;  
        double stiffness = 1.0 / 6.0;
        double velocity = 0.0;

        file << mass << " " << stiffness << " " << std::fixed << std::setprecision(2) << displacement << " " << velocity << std::endl;

        displacement += displacement_increment_distribution(gen); 
    }

    file.close();
    std::cout << "generated file 'spring_system_" << n << ".txt'。" << std::endl;

    return 0;
}
