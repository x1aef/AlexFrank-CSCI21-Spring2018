#include <iostream>
#include <sstream>

#include <iomanip>
#include <locale>

#include <string>
using namespace std;


int main ()
{
	/*
    std::stringstream sstream;


	int number = 123;
	sstream << number;//read integer into stringstream object.
	std::string numberString = sstream.str();//assignment.

	std::cout << numberString << std::endl; //Print the entire string.
	for(unsigned i=0; i<numberString.size(); i++) {//Unnecessary loop just to demonstrate.
		std::cout << numberString[i];
	}
	std::cout << std::endl;

	sstream.str("");/*Don't forget to clear the stringstream object!
					If you don't clear it, any content you read into the stringstream will just append 
					to anything you've previously read.

	std::cin.sync();
	std::cin.get();
	return 0;
	*/
	stringstream ss;
					string str1 = "6";
					int int1 = 0;
                    ss << str1;
                    ss >> int1;
                    cout << "int1: " << int1/2;
}
    /*
    long int num1 = 5467367467467;
    long int num2 = 3453647356;
    
    
    cout << num1 << " mod 10: " << num1%10 << endl;
    cout << num2 << " mod 10: " << num1%10 << endl;
    
    cout << endl << endl;
        
    string str3 = "";
    string str4 = "3353423";
    str3.append(str4);
        
    cout << "String 3: " << str3;
    */
    
