#include <iostream>
#include <string>
#include <tuple>

std::tuple<bool, int, int> parse_params(int argc, const char* const* argv, int& numerator, int& denominator)
{
    const std::tuple<bool, int, int> error { false, 0, 0 };

    if (argc != 3)
    {
        std::cerr << "Program expects 2 parameters!" << std::endl;
        return error;
    }

    std::string num_str = argv[1];
    std::string den_str = argv[2];

    try
    {
        numerator   = std::stoi(num_str);
        denominator = std::stoi(den_str);
    }
    catch (const std::exception&)
    {
        std::cerr << "Program expects 2 integer parameters!" << std::endl;
        return error;
    }

    if (denominator == 0)
    {
        std::cerr << "Denominator cannot be null!" << std::endl;
        return error;
    }

    return std::tuple { true, numerator, denominator };
}

int divide(int numerator, int denominator, int& reminder)
{
    reminder = numerator % denominator;
    return numerator / denominator;
}

int main(int argc, char** argv)
{
    int        numerator   = 0;
    int        denominator = 0;
    const auto res         = parse_params(argc, argv, numerator, denominator);
    numerator              = std::get<1>(res);
    denominator            = std::get<2>(res);

    if (!std::get<0>(res))
    {
        return 1;
    }

    int       reminder = 0;
    const int quotient = divide(numerator, denominator, reminder);

    std::cout << numerator << " = " << denominator << " * " << quotient << " + " << reminder << std::endl;

    return 0;
}