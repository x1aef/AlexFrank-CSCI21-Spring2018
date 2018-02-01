#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

/*
    Links to helpful informations and sources used.
        
        1.) ifstream/ofstream:
            https://learn.zybooks.com/zybook/BUTTECSCI21BrowneSpring2018/chapter/4/section/2
        
        2.) Converting Strings to Numbers and back:
            http://www.cplusplus.com/articles/D9j2Nwbp/
            
        3.) Convert string to char array in C++
            https://www.geeksforgeeks.org/convert-string-char-array-cpp/


        Objective of this Program
            Accept input from a text file.  Each line of the text file is a
            sequence of digits with no spaces between digits, representing a 
            credit card number. Your program will read in each line of text 
            from the file and determine the credit card type by checking the
            BIN.  It is possible that the data file contains card numbers from
            a bank/issuer other than the 4 major credit card companies. 
            Any other card types other than the 4 card companies described 
            above are not acceptable in your application.  A message
            of “Unknown card type” should be displayed and the card number will
            be rejected.
*/  


int main ()
{
    string line;
    vector <string> cardNumbersS;
    vector <long int> cardNumbersI;
    
    string stringConvert;
    long int intConvert;
    
    stringstream ss;
    //istringstream convert;
    ifstream ifFS;
    
    ifFS.open("text.txt");

    while ( getline (ifFS, line) )
    {
        cardNumbersS.push_back(line);
    } 
       
        
    for (int i = 0; i < cardNumbersS.size(); i++)
    {
        stringConvert = cardNumbersS.at(i);
        long int intConvert = 0;
        
        istringstream convert(stringConvert); 
        
        if ( !(convert >> intConvert) )
            cardNumbersI.push_back(0); 
        else 
        {
             cardNumbersI.push_back(intConvert);
        }
    }   
        
        
    /*
    for( int i = 0; i < cardNumbersS.size(); i++)  
    {
        cout << i+1 << ".) card number as string:  " << cardNumbersS.at(i) << endl;
        cout << "     card number as integer: " << cardNumbersI.at(i) << endl;
      
    }
    */
       
    /*
        4 types of cards
    
            Card Name               BIN                                             Length
            American Express        34 | 37                                         15
            Discover                6011 | 622126 – 622925 | 644 – 649 | 65         16
            MasterCard              51 – 55                                         16
            Visa                    4                                               13 – 16
    */  
       
     
    string str1 = "";
    string str2 = "";

    for (int i = 0; i < cardNumbersS.size(); i++) 
    {
        str1 = cardNumbersS.at(i);
 
        int n = str1.length(); 
     
        // declaring character array
        char char_array[n+1]; 
     
        // copying the contents of the 
        // string to char array
        strcpy(char_array, str1.c_str()); 
     
        cout << "Char array: ";
        for (int i=0; i<n; i++) 
        cout << char_array[i];

        // IFF American Express  34 | 37 (15)
        if( (char_array[0] == '3' && char_array[1] == '4') || (char_array[0] == '3' && char_array[1] == '7') ) 
        {
                cout << " , which is an Amercian Express card" << endl;
        }
        // IFF Discover: BIN( 6011 | 622126 – 622925 | 644 – 649 | 65 ) / Length( 16 )
        else if ( char_array[0] == '6' && char_array[1] == '0' ||
                  char_array[0] == '6' && char_array[1] == '2' ||
                  char_array[0] == '6' && char_array[1] == '4' ||
                  char_array[0] == '6' && char_array[1] == '5' )
        {
            cout << " , which is a Discover card" << endl;
        }
        else if (char_array[0] == '4' )
        {
            cout << " , which is a Visa" << endl;
        }
        else if (char_array[0] == '5' && char_array[1] == '1' ||
                  char_array[0] == '5' && char_array[1] == '2' ||
                  char_array[0] == '5' && char_array[1] == '3' ||
                  char_array[0] == '5' && char_array[1] == '4' ||
                  char_array[0] == '5' && char_array[1] == '5' )
        {
            cout << " , which is a MasterCard" << endl; 
        }
        else
        {
            cout << ", Card Type Unknown" << endl;
        }
        
        // IFF MasterCard: BIN( 51 – 55 ) /  Length( 16 )
        
        // IFF Visa: BIN( 4 ) / Lenth( 13 – 16 )
    
    }
    
    
    
    cout << endl << endl;
        
        string str3 = "";
        string str4 = "3353423";
        str3.append(str4);
        
        cout << "String 3: " << str3;
    
    
    return 0;
}