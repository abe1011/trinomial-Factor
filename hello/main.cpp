#include <iostream>
#include <iomanip>

using namespace std;

//This simply introduces the program and shows the form the user
//will use
void intro();

//this function is where the math is worked out to find out if the trinomial
// is factorable and if so what the factors are
int findFactors(int valueA, int valueB, int valueC, int& valueOne, double& valueTwo);


int main()
{
    // integer values of A,B,and C to hold
    int valueOfA;
    int valueOfB;
    int valueOfC;
    
    //two factors that are found
    int firstFactor;
    double secondFactor;
    
    //print the introduction of the program
    intro();
    
    //keeps looping unless user chooses to stop the program
    for(int i = 0; i < 1; i++)
    {
        // asks user to enter values of A,B, and C
        cout << "Please enter A value :" << endl;
        cin >> valueOfA;
        cout << "Please enter B value :" << endl;
        cin >> valueOfB;
        cout << "Please enter C value :" << endl;
        cin >> valueOfC;
        
        // if the function returns 0 it means that there werent any
        // factors found, the only other option is that the function
        // returns 1 and the 2 factors are found
        if (findFactors(valueOfA, valueOfB, valueOfC, firstFactor, secondFactor) == 0)
            cout << "No factors Found" << endl;
        else
            cout << firstFactor << " and " << secondFactor;
    }
    return 0;
}

void intro()
{
    cout << "Polynomial Factor Program" << endl;
    cout << "Ax^2 + Bx + C" << endl;
}

int findFactors(int valueA, int valueB, int valueC, int& valueOne, double& valueTwo)
{
    //default declaration for bool values
    bool factorFound = false;
    bool unfactorable = false;
    
    // start value and second value are the 2 factors
    // that start at intial values until a factor is
    // found
    int startValue = 1;
    double secondValue;
    
    // value of A times C
    int valueOfMultiplied = valueA * valueC;
    
    // this for loop keeps repeating either until two factors are found
    // or until the trinomial is deemed unfactorable
    for(;factorFound == false && unfactorable == false; startValue++)
    {
        // the second value is found by dividing the start value by the value multiplied
        // to try to find all possible common factors of the value multiplied(A times C)
        secondValue = double(valueOfMultiplied) / double(startValue);
        
        // if the "B" value is equal to the sum of the "A" and "C" values then
        // assign true to factorfound and assign values to reference variables
        if(secondValue + startValue == valueB)
        {
            valueOne = startValue;
            valueTwo = secondValue;
            factorFound = true;
        }
        
        // if all possible combinations have been tried then the trinomial is deemed unfactorable
        if(startValue == valueOfMultiplied - 1)
        {
            unfactorable = true;
        }
    }
    
  // return the value that correlates with whether the trinomial is factorable or not
  if (factorFound == true)
      return 1;
    else
        return 0;;
    
}
