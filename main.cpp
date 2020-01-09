#include <iostream>
#include <limits>

/*
 Chapter 2 Part 7
 Returning Values tasks

 1) write 3 UDTs named FloatType, DoubleType, IntType.

 2) give each UDT the following member functions:
        add( lhs, rhs );
        subtract( lhs, rhs );
        multiply( lhs, rhs );
        divide( lhs, rhs );

 3) make them return the correct primitive type. e.g. if you're implementing the FloatType::add
 function, your implementation would start like this: float FloatType::add( float lhs, float rhs )

 4) declare a few instances of each class in main() and call the member functions with the
 appropriate arguments. FloatType ft; auto result = ft.add(3.2f, 23.f );

 5) print out those results using std::cout:
        std::cout "result of ft.add(): " << result << std::endl;

 6) After you finish defining each type/function, click the [run] button.  Clear up any errors or
 warnings as best you can.

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and
 click [Commit and push].

 Wait for my code review.
 */

struct FloatType {
    float add(float lhs, float rhs) { return lhs + rhs; }

    float subtract(float lhs, float rhs) { return lhs - rhs; }

    float multiply(float lhs, float rhs) { return lhs * rhs; }

    float divide(float lhs, float rhs)
    {
        if (rhs == 0)
        {
            std::cerr << "divide by zero error\n";
            return std::numeric_limits<float>::infinity();
        }
        return lhs / rhs;
    }
};

struct DoubleType {
    double add(double lhs, double rhs) { return lhs + rhs; }

    double subtract(double lhs, double rhs) { return lhs - rhs; }

    double multiply(double lhs, double rhs) { return lhs * rhs; }

    double divide(double lhs, double rhs)
    {
        if (rhs == 0)
        {
            std::cerr << "divide by zero error\n";
            return std::numeric_limits<double>::infinity();
        }
        return lhs / rhs;
    }
};

struct IntType {
    int add(int lhs, int rhs) { return lhs + rhs; }

    int subtract(int lhs, int rhs) { return lhs - rhs; }

    int multiply(int lhs, int rhs) { return lhs * rhs; }

    int divide(int lhs, int rhs)
    {
        if (rhs == 0)
        {
            std::cerr << "divide by zero error\n";
            return std::numeric_limits<int>::max();
        }
        return lhs / rhs;
    }
};

int main()
{
    FloatType ft;
    DoubleType dt;
    IntType it;

    std::cout << "result of ft.add(): " << ft.add(1.0f, 3.0f) << '\n';
    std::cout << "result of ft.subtract(): " << ft.subtract(1.0f, 3.0f) << '\n';
    std::cout << "result of ft.multiply(): " << ft.multiply(2.0f, 3.0f) << '\n';
    std::cout << "result of dt.add(): " << dt.add(1.0, 3.0) << "\n";
    std::cout << "result of dt.divide(): " << dt.divide(1.0, 3.0) << "\n";
    std::cout << "result of it.add(): " << it.add(100, 3) << "\n";

    std::cout << "result of ft.divide(): " << ft.divide(1, 0) << '\n';
    std::cout << "result of dt.divide(): " << dt.divide(1, 0) << '\n';
    std::cout << "result of it.divide(): " << it.divide(1, 0) << '\n';
}
