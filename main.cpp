/*
 Project 4 - Part 2 / 9
 Video: Chapter 3 Part 6

 Create a branch named Part2

New/This/Pointers/References conclusion

    Build/Run often with this task to make sure you're not breaking the code
with each step. I recommend committing after you get each step working so you
can revert to a working version easily if needed.

 0) in the blank space below, declare/define an empty struct named 'A' on a
single Line. on the lines below it, write a struct named 'HeapA' that correctly
shows how to own an instance of 'A' on the heap without leaking, without using
smart pointers.
 */

struct A
{
};

struct HeapA
{
    explicit HeapA(A& a_) { a = new A(a_); } //FIXME since you're copying, you should pass by const ref, not ref.
    ~HeapA() { delete a; }
    A* a;
};

/*
1) Edit your 3 structs so that they own a heap-allocated primitive type without
using smart pointers IntType should own a heap-allocated int, for example.

2) give it a constructor that takes the appropriate primitive
   this argument will initialize the owned primitive's value.
        i.e. if you're owning an int on the heap, your ctor argument will
initialize that heap-allocated int's value.

3) modify those add/subtract/divide/multiply member functions from chapter 2 on
it a) make them modify the owned numeric type b) set them up so they can be
chained together. i.e. DoubleType dt(3.5);
            dt.add(3.0).multiply(-2.5).divide(7.2); //an example of chaining

4) write some add/subtract/divide/multiply member functions for each type that
take your 3 UDTs for example, IntType::divide(const DoubleType& dt);

5) print out the results with some creative couts
   i.e.
        FloatType ft(0.1f);
        IntType it(3);
        std::cout << "adding 3 and subtracting 'it' from 'ft' results in the
following value: " << *ft.add(2.f).subtract( it ).value << std::endl;  //note
the dereference of the `value` member of `ft`

6) Don't let your heap-allocated owned type leak!

7) click the [run] button.  Clear up any errors or warnings as best you can.

Commit your changes by clicking on the Source Control panel on the left,
entering a message, and click [Commit and push].

Send me the the link to your repl.it in a DM on Slack

Wait for my code review.
*/

#include <iostream>
#include <limits>

struct FloatType;
struct DoubleType;
struct IntType;

struct FloatType
{
    explicit FloatType(const float& f);
    ~FloatType();
    FloatType& add(const float& rhs);
    FloatType& add(const FloatType& rhs);
    FloatType& add(const DoubleType& rhs);
    FloatType& add(const IntType& rhs);

    FloatType& subtract(const float& rhs);
    FloatType& subtract(const FloatType& rhs);
    FloatType& subtract(const DoubleType& rhs);
    FloatType& subtract(const IntType& rhs);

    FloatType& multiply(const float& rhs);
    FloatType& multiply(const FloatType& rhs);
    FloatType& multiply(const DoubleType& rhs);
    FloatType& multiply(const IntType& rhs);

    FloatType& divide(const float& rhs);
    FloatType& divide(const FloatType& rhs);
    FloatType& divide(const DoubleType& rhs);
    FloatType& divide(const IntType& rhs);

    float* value; FIXME this needs a default value of nullptr!
};
struct DoubleType
{
    explicit DoubleType(const double& f);
    ~DoubleType();
    DoubleType& add(const double& rhs);
    DoubleType& add(const FloatType& rhs);
    DoubleType& add(const DoubleType& rhs);
    DoubleType& add(const IntType& rhs);

    DoubleType& subtract(const double& rhs);
    DoubleType& subtract(const FloatType& rhs);
    DoubleType& subtract(const DoubleType& rhs);
    DoubleType& subtract(const IntType& rhs);

    DoubleType& multiply(const double& rhs);
    DoubleType& multiply(const FloatType& rhs);
    DoubleType& multiply(const DoubleType& rhs);
    DoubleType& multiply(const IntType& rhs);

    DoubleType& divide(const double& rhs);
    DoubleType& divide(const FloatType& rhs);
    DoubleType& divide(const DoubleType& rhs);
    DoubleType& divide(const IntType& rhs);

    double* value; FIXME this needs a default value of nullptr!
};
struct IntType
{
    explicit IntType(const int& f);
    ~IntType();
    IntType& add(const int& rhs);
    IntType& add(const FloatType& rhs);
    IntType& add(const DoubleType& rhs);
    IntType& add(const IntType& rhs);

    IntType& subtract(const int& rhs);
    IntType& subtract(const FloatType& rhs);
    IntType& subtract(const DoubleType& rhs);
    IntType& subtract(const IntType& rhs);

    IntType& multiply(const int& rhs);
    IntType& multiply(const FloatType& rhs);
    IntType& multiply(const DoubleType& rhs);
    IntType& multiply(const IntType& rhs);

    IntType& divide(const int& rhs);
    IntType& divide(const FloatType& rhs);
    IntType& divide(const DoubleType& rhs);
    IntType& divide(const IntType& rhs);

    int* value; FIXME this needs a default value of nullptr!
};

FloatType::FloatType(const float& f) { value = new float(f); }
FloatType::~FloatType() { delete value; }

FloatType& FloatType::add(const float& rhs)
{
    *value += rhs;
    return *this;
}

FloatType& FloatType::add(const FloatType& rhs)
{
    if (rhs.value == nullptr)
    {
        std::cout << "value null ptr\n";
        return *this;
    }
    *value += *rhs.value;
    return *this;
}

FloatType& FloatType::add(const DoubleType& rhs)
{
    if (rhs.value == nullptr)
    {
        std::cout << "value null ptr\n";
        return *this;
    }
    *value += static_cast<float>(*rhs.value);
    return *this;
}

FloatType& FloatType::add(const IntType& rhs)
{
    if (rhs.value == nullptr)
    {
        std::cout << "value null ptr\n";
        return *this;
    }
    *value += static_cast<float>(*rhs.value);
    return *this;
}

FloatType& FloatType::subtract(const float& rhs)
{
    *value -= rhs;
    return *this;
}

FloatType& FloatType::subtract(const FloatType& rhs)
{
    if (rhs.value == nullptr)
    {
        std::cout << "value null ptr\n";
        return *this;
    }
    *value -= *rhs.value;
    return *this;
}

FloatType& FloatType::subtract(const DoubleType& rhs)
{
    if (rhs.value == nullptr)
    {
        std::cout << "value null ptr\n";
        return *this;
    }
    *value -= static_cast<float>(*rhs.value);
    return *this;
}

FloatType& FloatType::subtract(const IntType& rhs)
{
    if (rhs.value == nullptr)
    {
        std::cout << "value null ptr\n";
        return *this;
    }
    *value -= static_cast<float>(*rhs.value);
    return *this;
}

FloatType& FloatType::multiply(const float& rhs)
{
    *value *= rhs;
    return *this;
}

FloatType& FloatType::multiply(const FloatType& rhs)
{
    if (rhs.value == nullptr)
    {
        std::cout << "value null ptr\n";
        return *this;
    }
    *value *= *rhs.value;
    return *this;
}

FloatType& FloatType::multiply(const DoubleType& rhs)
{
    if (rhs.value == nullptr)
    {
        std::cout << "value null ptr\n";
        return *this;
    }
    *value *= static_cast<float>(*rhs.value);
    return *this;
}

FloatType& FloatType::multiply(const IntType& rhs)
{
    if (rhs.value == nullptr)
    {
        std::cout << "value null ptr\n";
        return *this;
    }
    *value *= static_cast<float>(*rhs.value);
    return *this;
}

FloatType& FloatType::divide(const float& rhs)
{
    if (rhs == 0) FIXME make the 0 a 0.f
    {
        std::cout << "divide by zero\n";
        return *this;
    }
    *value /= rhs;
    return *this;
}

FloatType& FloatType::divide(const FloatType& rhs)
{
    if (rhs.value == nullptr)
    {
        std::cout << "value null ptr\n";
        return *this;
    }
    if (*rhs.value == 0) FIXME make the 0 a 0.f
    {
        std::cout << "divide by zero\n";
        return *this;
    }
    *value /= *rhs.value;
    return *this;
}

FloatType& FloatType::divide(const DoubleType& rhs)
{
    if (rhs.value == nullptr)
    {
        std::cout << "value null ptr\n";
        return *this;
    }
    if (*rhs.value == 0) FIXME make the 0 a 0.0
    {
        std::cout << "divide by zero\n";
        return *this;
    }
    *value /= static_cast<float>(*rhs.value);
    return *this;
}

FloatType& FloatType::divide(const IntType& rhs)
{
    if (rhs.value == nullptr)
    {
        std::cout << "value null ptr\n";
        return *this;
    }
    if (*rhs.value == 0)
    {
        std::cout << "divide by zero\n";
        return *this;
    }
    *value /= static_cast<float>(*rhs.value);
    return *this;
}

DoubleType::DoubleType(const double& d) { value = new double(d); }
DoubleType::~DoubleType() { delete value; }

DoubleType& DoubleType::add(const double& rhs)
{
    *value += rhs;
    return *this;
}

DoubleType& DoubleType::add(const FloatType& rhs)
{
    if (rhs.value == nullptr)
    {
        std::cout << "value null ptr\n";
        return *this;
    }
    *value += static_cast<double>(*rhs.value);
    return *this;
}

DoubleType& DoubleType::add(const DoubleType& rhs)
{
    if (rhs.value == nullptr)
    {
        std::cout << "value null ptr\n";
        return *this;
    }
    *value += *rhs.value;
    return *this;
}

DoubleType& DoubleType::add(const IntType& rhs)
{
    if (rhs.value == nullptr)
    {
        std::cout << "value null ptr\n";
        return *this;
    }
    *value += static_cast<double>(*rhs.value);
    return *this;
}

DoubleType& DoubleType::subtract(const double& rhs)
{
    *value -= rhs;
    return *this;
}

DoubleType& DoubleType::subtract(const FloatType& rhs)
{
    if (rhs.value == nullptr)
    {
        std::cout << "value null ptr\n";
        return *this;
    }
    *value -= static_cast<double>(*rhs.value);
    return *this;
}

DoubleType& DoubleType::subtract(const DoubleType& rhs)
{
    if (rhs.value == nullptr)
    {
        std::cout << "value null ptr\n";
        return *this;
    }
    *value -= *rhs.value;
    return *this;
}

DoubleType& DoubleType::subtract(const IntType& rhs)
{
    if (rhs.value == nullptr)
    {
        std::cout << "value null ptr\n";
        return *this;
    }
    *value -= static_cast<double>(*rhs.value);
    return *this;
}

DoubleType& DoubleType::multiply(const double& rhs)
{
    *value *= rhs;
    return *this;
}

DoubleType& DoubleType::multiply(const FloatType& rhs)
{
    if (rhs.value == nullptr)
    {
        std::cout << "value null ptr\n";
        return *this;
    }
    *value *= static_cast<double>(*rhs.value);
    return *this;
}

DoubleType& DoubleType::multiply(const DoubleType& rhs)
{
    if (rhs.value == nullptr)
    {
        std::cout << "value null ptr\n";
        return *this;
    }
    *value *= *rhs.value;
    return *this;
}

DoubleType& DoubleType::multiply(const IntType& rhs)
{
    if (rhs.value == nullptr)
    {
        std::cout << "value null ptr\n";
        return *this;
    }
    *value *= static_cast<double>(*rhs.value);
    return *this;
}

DoubleType& DoubleType::divide(const double& rhs)
{
    if (rhs == 0) FIXME make the 0 a 0.0
    {
        std::cout << "divide by zero\n";
        return *this;
    }
    *value /= rhs;
    return *this;
}

DoubleType& DoubleType::divide(const FloatType& rhs)
{
    if (rhs.value == nullptr)
    {
        std::cout << "value null ptr\n";
        return *this;
    }
    if (*rhs.value == 0) FIXME make the 0 a 0.f
    {
        std::cout << "divide by zero\n";
        return *this;
    }
    *value /= static_cast<double>(*rhs.value);
    return *this;
}

DoubleType& DoubleType::divide(const DoubleType& rhs)
{
    if (rhs.value == nullptr)
    {
        std::cout << "value null ptr\n";
        return *this;
    }
    if (*rhs.value == 0) FIXME make the 0 a 0.0
    {
        std::cout << "divide by zero\n";
        return *this;
    }
    *value /= *rhs.value;
    return *this;
}

DoubleType& DoubleType::divide(const IntType& rhs)
{
    if (rhs.value == nullptr)
    {
        std::cout << "value null ptr\n";
        return *this;
    }
    if (*rhs.value == 0)
    {
        std::cout << "divide by zero\n";
        return *this;
    }
    *value /= static_cast<double>(*rhs.value);
    return *this;
}

IntType::IntType(const int& i) { value = new int(i); }
IntType::~IntType() { delete value; }

IntType& IntType::add(const int& rhs)
{
    *value += rhs;
    return *this;
}

IntType& IntType::add(const FloatType& rhs)
{
    if (rhs.value == nullptr)
    {
        std::cout << "value null ptr\n";
        return *this;
    }
    *value += static_cast<int>(*rhs.value);
    return *this;
}

IntType& IntType::add(const DoubleType& rhs)
{
    if (rhs.value == nullptr)
    {
        std::cout << "value null ptr\n";
        return *this;
    }
    *value += static_cast<int>(*rhs.value);
    return *this;
}

IntType& IntType::add(const IntType& rhs)
{
    if (rhs.value == nullptr)
    {
        std::cout << "value null ptr\n";
        return *this;
    }
    *value += *rhs.value;
    return *this;
}

IntType& IntType::subtract(const int& rhs)
{
    *value -= rhs;
    return *this;
}

IntType& IntType::subtract(const FloatType& rhs)
{
    if (rhs.value == nullptr)
    {
        std::cout << "value null ptr\n";
        return *this;
    }
    *value -= static_cast<int>(*rhs.value);
    return *this;
}

IntType& IntType::subtract(const DoubleType& rhs)
{
    if (rhs.value == nullptr)
    {
        std::cout << "value null ptr\n";
        return *this;
    }
    *value -= static_cast<int>(*rhs.value);
    return *this;
}

IntType& IntType::subtract(const IntType& rhs)
{
    if (rhs.value == nullptr)
    {
        std::cout << "value null ptr\n";
        return *this;
    }
    *value -= *rhs.value;
    return *this;
}

IntType& IntType::multiply(const int& rhs)
{
    *value *= rhs;
    return *this;
}

IntType& IntType::multiply(const FloatType& rhs)
{
    if (rhs.value == nullptr)
    {
        std::cout << "value null ptr\n";
        return *this;
    }
    *value *= static_cast<int>(*rhs.value);
    return *this;
}

IntType& IntType::multiply(const DoubleType& rhs)
{
    if (rhs.value == nullptr)
    {
        std::cout << "value null ptr\n";
        return *this;
    }
    *value *= static_cast<int>(*rhs.value);
    return *this;
}

IntType& IntType::multiply(const IntType& rhs)
{
    if (rhs.value == nullptr)
    {
        std::cout << "value null ptr\n";
        return *this;
    }
    *value *= *rhs.value;
    return *this;
}

IntType& IntType::divide(const int& rhs)
{
    if (rhs == 0)
    {
        std::cerr << "divide by zero error\n";
        *value = std::numeric_limits<int>::max();
    }
    else
    {
        *value /= rhs;
    }
    return *this;
}

IntType& IntType::divide(const FloatType& rhs)
{
    if (rhs.value == nullptr)
    {
        std::cout << "value null ptr\n";
        return *this;
    }
    if (*rhs.value == 0) FIXME make the 0 a 0.f
    {
        std::cerr << "divide by zero error\n";
        *value = std::numeric_limits<int>::max();
    }
    else
    {
        *value /= static_cast<int>(*rhs.value);
    }
    return *this;
}

IntType& IntType::divide(const DoubleType& rhs)
{
    if (rhs.value == nullptr)
    {
        std::cout << "value null ptr\n";
        return *this;
    }
    if (*rhs.value == 0) FIXME make the 0 a 0.0
    {
        std::cerr << "divide by zero error\n";
        *value = std::numeric_limits<int>::max();
    }
    else
    {
        *value /= static_cast<int>(*rhs.value);
    }
    return *this;
}

IntType& IntType::divide(const IntType& rhs)
{
    if (rhs.value == nullptr)
    {
        std::cout << "value null ptr\n";
        return *this;
    }
    if (*rhs.value == 0)
    {
        std::cerr << "divide by zero error\n";
        *value = std::numeric_limits<int>::max();
    }
    else
    {
        *value /= *rhs.value;
    }
    return *this;
}

int main()
{
    FloatType ft {2.0f};
    DoubleType dt {1.0};
    IntType it {20};

    std::cout << "Float 2.0 - 1.0  * 3.3 / 2.5: "
              << *ft.add(1.0f).subtract(dt).multiply(3.3f).divide(2.5f).value
              << '\n';
    std::cout << "Int 20 / 3 + 1 - 2: "
              << *it.divide(3).add(dt).subtract(2).value << '\n';

    std::cout
        << "Double 1.0 / 2 / 2 / 20: "
        << *dt.divide(FloatType {2.0}).divide(2.0).divide(IntType {20}).value
        << '\n';
}
