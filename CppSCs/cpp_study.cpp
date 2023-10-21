#include <iostream> // 'i' stands for input (cin) 'o' stands for output (cout) this is required to have output and user input
#include <cmath> // there are different functions from cmath check references to see the different functions
#include <cstdlib> // you can call a random number (fixed)
#include <ctime> // use a timer to change the fixed random number

using namespace std; // global std (standard library) this is required! without this you would have to do it manually in every statement (i.e std::cout >> "Hello, world!";)

/* only 1 main function is required to compile the entire file, main function will always be called/run.
In order to compile a function, you need to call it inside the main and its called recursion.*/ 

// Declare functions below main so the compiler will notice it
void HelloWorld();
void variableSwapping();
void constants();
void operations();
void incrementDecrement();
void pmdas();
void stringVariables();
void inputCalculator();
void circleArea();
void rng();

int main() {
    HelloWorld(); // this a sample on how to call a function, try this out to the other voided functions
    return 0;
}

// BASIC FUNCTIONS ----------------------------------------------------------------

void HelloWorld() { // Hello World!
    cout << "Hello World!" << endl;
}

void variableSwapping() { // variable swapping
    int a = 1;
    int b = 2;
    int temp = a;
    a = b;
    b = temp;
    cout << a;
}

void constants() { // constants
    const double pi = 3.14159265;
    // int pi = 0 commented out because you can't change a constant value
    cout << pi << endl;
}

void operations() { // mathematical
    double x = 10; // double data type is required for division
    int y = 3;
    int add = x + y;
    int subtract = x - y;
    int multiply = x * y;
    int divide = x / y;
    // int modulus = x % y; commented out because the value of x is double
    cout << add;
    cout << subtract;
    cout << multiply;
    cout << divide;
    // cout << modulus;
}

void incrementDecrement() { // increment and decrement
    int num = 10;
    int num2 = num++; // num2 = 10, num = 11 postfix
    cout << num << " " << num2 << endl;
    int num3 = 10;
    int num4 = ++num3; // num3 = 11, num = 11 prefix
    cout << num3 << " " << num4 << endl;
}

void pmdas() { // order of operations
    // () can change the order of operations
    double x = 10;
    double y = 5;
    double z = (x + 10) / (3 * y); // make this so that z = 1.3
    cout << z;
}

void stringVariables() { // string + variables
    // int x = 10;
    // int y = 20;
    // cout << "x = " << x << endl // use indentations to be clean and nice 
    //      << "y = " << y;
       
    // variables
    int sales = 95000;
    const double state_tax_rate = 0.04;
    const double county_tax_rate = 0.02;
    // formula
    double state_tax = sales * state_tax_rate;
    double county_tax = sales * county_tax_rate;
    double total_tax = state_tax + county_tax;
    double gross_sales = sales - total_tax;
    // output
    cout << "Sales: $" << sales << endl
     << "State tax: $" << state_tax << endl
    << "County tax: $" << county_tax << endl
     << "Total tax: $" << total_tax << endl
   << "Gross sales: $" << gross_sales << endl;   
}

// FUNCTIONS WITH INPUT ----------------------------------------------------------------

void inputCalculator() { // simple input output calculator
    // cout << "Enter values for x and y: ";
    // double x;
    // double y;
    // cin >> x >> y;
    // cout << x + y; 
    // return 0;
    
    cout << "Enter fahrenheit temperature: ";
    double fahrenheit;
    double celcius;
    cin >> fahrenheit;
    celcius = (fahrenheit - 32) * 5/9;
    cout << "Converted to celsius: " << celcius;
}

void circleArea() { // using cmath module
    // double flooring = floor(1.2); // rounded down, ceil is rounded up
    // cout << flooring << endl;
   
    // double powering = pow(2, 3); // first index is base and second index is exponent
    // cout << powering << endl;
   
    // double sqrting = sqrt(25); // squares the value
    // cout << sqrting << endl;
   
    cout << "Radius: "; // calculate the radius
    double radius;
    cin >> radius;
    const double pi = 3.14159265;
    cout << "Area of the circle: " << pi * pow(radius, 2) << endl;
}

void rng() { // random number generator
    long elapsed_seconds = time(nullptr); // nullptr means 0
    srand(elapsed_seconds);
    int number =  rand() % 10; // sets the limit to 10
    cout << number << endl;
}

// RETURN FUNCTIONS (int) will be updated later I need sleep --------------------------------
