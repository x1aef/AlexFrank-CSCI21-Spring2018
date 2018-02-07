/*
 * Project 1: Part A 
 *
 *      Accept input from a text file.  Each line of the text file is a
 *      sequence of digits with no spaces between digits, representing a 
 *      credit card number. Your program will read in each line of text 
 *      from the file and determine the credit card type by checking the
 *      BIN.  It is possible that the data file contains card numbers from
 *      a bank/issuer other than the 4 major credit card companies. 
 *      Any other card types other than the 4 card companies described 
 *      above are not acceptable in your application.  A message
 *      of “Unknown card type” should be displayed and the card number will
 *      be rejected.
 *
 * RESOURCES
 *  1.) ifstream/ofstream:
 *          https://learn.zybooks.com/zybook/BUTTECSCI21BrowneSpring2018/chapter/4/section/2
 *  2.) Converting Strings to Numbers and back:
 *          http://www.cplusplus.com/articles/D9j2Nwbp/
 *  3.) Convert string to char array in C++
 *          https://www.geeksforgeeks.org/convert-string-char-array-cpp/
 *  4.) STOI
            http://www.cplusplus.com/reference/string/stoi/
 
 
 * Alexander Frank
 * Date created: 02.01.2018
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main ()
{
	string line;
    vector <string> cardNumbersS;
    vector <long int> cardNumbersI;
    vector <long int> sumVector;
    
    string stringConvert;
    long int intConvert;
    
    stringstream ss;
    stringstream ss2;
    stringstream ss3;
    stringstream ss4;
    ifstream ifFS;
    
    ifFS.open("card_numbers.txt");

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
    This block of code is to display the card numbers as their integer values or string values.
    for( int i = 0; i < cardNumbersS.size(); i++)  
    {
        cout << i+1 << ".) card number as string:  " << cardNumbersS.at(i) << endl;
        cout << "     card number as integer: " << cardNumbersI.at(i) << endl;
      
    }
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
     
        //cout << "Char array: ";
        cout << i+1 << ".)  CARD NUMBER: ";
        for (int i=0; i<n; i++) 
        cout << char_array[i];
        
        
        

        // IFF American Express  34 | 37 (15)
        if( (char_array[0] == '3' && char_array[1] == '4') || (char_array[0] == '3' && char_array[1] == '7') ) 
        {
            cout << endl << "     CARD TYPE: Amercian Express" << endl;
              
            int checkDigit = static_cast<int>(str1.back())-48;  
            
            str1.pop_back();
               
            int count1 = 0;
            int int1 = 0;
            for (int k = str1.length()-1; k >= 0  ; k = k-2)
            {
                char a = str1.at(k);
                int1 = static_cast<int>(str1[k])-48;
                    
                //cout << "int1: " << int1 << endl;

                int int2 = int1*2;
                if (int2 > 9)
                    int2 -= 9;
                   
                count1 += int2;
                //cout << "count1: " << count1 << endl;
            }
            
            for (int k = str1.length()-2; k >= 0  ; k = k-2)
            {
                char a = str1.at(k);
                int1 = static_cast<int>(str1[k])-48;
                    
                //cout << "int1: " << int1 << endl;
                count1 += int1;
                //cout << "count2: " << count1 << endl;
            }
                
            count1 *= 9;
            //cout << "count1: " << count1 << endl;
            count1  %= 10;
            //cout << "count1: " << count1 << endl;
            cout << "Check digit: " << checkDigit << endl;
                
            if (count1 == checkDigit)
            {
                cout << "     This card passed the LUHN" << endl;
            } 
            else if (count1 != checkDigit)
            {
                 cout << "INVALID CARD BY LUHN" << endl;
            }
            
            cout << endl;
        }
        // IFF Discover: BIN( 6011 | 622126 – 622925 | 644 – 649 | 65 ) / Length( 16 )
        else if ( char_array[0] == '6' && char_array[1] == '0' ||
                  char_array[0] == '6' && char_array[1] == '2' ||
                  char_array[0] == '6' && char_array[1] == '4' ||
                  char_array[0] == '6' && char_array[1] == '5' )
        {
            cout << endl << "     CARD TYPE: Discover card" << endl;
            
            int checkDigit = static_cast<int>(str1.back())-48;  
            
            str1.pop_back();
               
            int count1 = 0;
            int int1 = 0;
            for (int k = str1.length()-1; k >= 0  ; k = k-2)
            {
                char a = str1.at(k);
                int1 = static_cast<int>(str1[k])-48;
                    
                //cout << "int1: " << int1 << endl;

                int int2 = int1*2;
                if (int2 > 9)
                    int2 -= 9;
                   
                count1 += int2;
                //cout << "count1: " << count1 << endl;
            }
            
            for (int k = str1.length()-2; k >= 0  ; k = k-2)
            {
                char a = str1.at(k);
                int1 = static_cast<int>(str1[k])-48;
                    
                //cout << "int1: " << int1 << endl;
                count1 += int1;
                //cout << "count2: " << count1 << endl;
            }
                
            count1 *= 9;
            // << "count1: " << count1 << endl;
            count1  %= 10;
            //cout << "count1: " << count1 << endl;
            cout << "Check digit: " << checkDigit << endl;
                
            if (count1 == checkDigit)
            {
                cout << "     This card passed the LUHN" << endl;
            } 
            else if (count1 != checkDigit)
            {
                 cout << "INVALID CARD BY LUHN" << endl;
            }
            
            cout << endl;
            
        }
        // IFF Visa: BIN( 4 ) / Lenth( 13 – 16 )
        else if (char_array[0] == '4' )
        {
            cout << endl << "     CARD TYPE: Visa" << endl;
            
            int checkDigit = static_cast<int>(str1.back())-48;  
            
            str1.pop_back();
               
            int count1 = 0;
            int int1 = 0;
            for (int k = str1.length()-1; k >= 0  ; k = k-2)
            {
                char a = str1.at(k);
                int1 = static_cast<int>(str1[k])-48;
                    
                //cout << "int1: " << int1 << endl;

                int int2 = int1*2;
                if (int2 > 9)
                    int2 -= 9;
                   
                count1 += int2;
                //cout << "count1: " << count1 << endl;
            }
            
            for (int k = str1.length()-2; k >= 0  ; k = k-2)
            {
                char a = str1.at(k);
                int1 = static_cast<int>(str1[k])-48;
                    
                //cout << "int1: " << int1 << endl;
                count1 += int1;
                //cout << "count2: " << count1 << endl;
            }
                
            count1 *= 9;
            //cout << "count1: " << count1 << endl;
            count1  %= 10;
            //cout << "count1: " << count1 << endl;
            cout << "Check digit: " << checkDigit << endl;
                
            if (count1 == checkDigit)
            {
                cout << "     This card passed the LUHN" << endl;
            } 
            else if (count1 != checkDigit)
            {
                 cout << "INVALID CARD BY LUHN" << endl;
            }
            
            cout << endl;
                
        }
        // IFF MasterCard: BIN( 51 – 55 ) /  Length( 16 )
        else if (char_array[0] == '5' && char_array[1] == '1' ||
                  char_array[0] == '5' && char_array[1] == '2' ||
                  char_array[0] == '5' && char_array[1] == '3' ||
                  char_array[0] == '5' && char_array[1] == '4' ||
                  char_array[0] == '5' && char_array[1] == '5' )
        {
            cout << endl << "     CARD TYPE: MasterCard" << endl;
            
            int checkDigit = static_cast<int>(str1.back())-48;  
            
            str1.pop_back();
               
            int count1 = 0;
            int int1 = 0;
            for (int k = str1.length()-1; k >= 0  ; k = k-2)
            {
                char a = str1.at(k);
                int1 = static_cast<int>(str1[k])-48;
                    
                //cout << "int1: " << int1 << endl;

                int int2 = int1*2;
                if (int2 > 9)
                    int2 -= 9;
                   
                count1 += int2;
                //cout << "count1: " << count1 << endl;
            }
            
            for (int k = str1.length()-2; k >= 0  ; k = k-2)
            {
                char a = str1.at(k);
                int1 = static_cast<int>(str1[k])-48;
                    
                //cout << "int1: " << int1 << endl;
                count1 += int1;
                //cout << "count2: " << count1 << endl;
            }
                
            count1 *= 9;
            //cout << "count1: " << count1 << endl;
            count1  %= 10;
            //cout << "count1: " << count1 << endl;
            cout << "Check digit: " << checkDigit << endl;
                
            if (count1 == checkDigit)
            {
                cout << "     This card passed the LUHN" << endl;
            } 
            else if (count1 != checkDigit)
            {
                 cout << "INVALID CARD BY LUHN" << endl;
            }
            
            cout << endl;
        }
        else
        {
            cout << endl << "     CARD TYPE: UNKNOWN" << endl;
            
            int checkDigit = static_cast<int>(str1.back())-48;  
            
            str1.pop_back();
               
            int count1 = 0;
            int int1 = 0;
            for (int k = str1.length()-1; k >= 0  ; k = k-2)
            {
                char a = str1.at(k);
                int1 = static_cast<int>(str1[k])-48;
                    
                //cout << "int1: " << int1 << endl;

                int int2 = int1*2;
                if (int2 > 9)
                    int2 -= 9;
                   
                count1 += int2;
                //cout << "count1: " << count1 << endl;
            }
            
            for (int k = str1.length()-2; k >= 0  ; k = k-2)
            {
                char a = str1.at(k);
                int1 = static_cast<int>(str1[k])-48;
                    
                //cout << "int1: " << int1 << endl;
                count1 += int1;
                //cout << "count2: " << count1 << endl;
            }
                
            count1 *= 9;
            //cout << "count1: " << count1 << endl;
            count1  %= 10;
            //cout << "count1: " << count1 << endl;
            cout << "Check digit: " << checkDigit << endl;
                
            if (count1 == checkDigit)
            {
                cout << "     This card passed the LUHN" << endl;
            } 
            else if (count1 != checkDigit)
            {
                 cout << "INVALID CARD BY LUHN" << endl;
            }
            
            cout << endl;
               
        }
    }
    
	return 0;
}


