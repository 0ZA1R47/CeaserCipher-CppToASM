//Including Libraries
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

//Encryption Module
string Encryption(string text, int key)		//Text and key passed as arguments
{
	int i;	//Loop variable
	char ch;	//Char variable
	
	for(i = 0; text[i] != '\0'; ++i)	// For Loop running until text ends
	{
		ch = text[i];	//Storing current (ith)character of text in ch
		
		if(ch >= 'a' && ch <= 'z') 	//Checking if current character is lowercase
		{
			ch = ch + key;	//Adding key to ch
			if(ch > 'z')	//If character is greater than lowercase 'z'. 
			{
				ch = ch - 'z' + 'a' - 1;	//Subtracting 'z' from ch and adding one less than 'a'
			}

		text[i] = ch;	//Replacing the current character with ch

		}
		else if(ch >= 'A' && ch <= 'Z') //Checking if current character is uppercase
		{
			ch = ch + key;	//Adding key to ch
			
			if(ch > 'Z')	//If character is greater than uppercase 'Z'
			{
				ch = ch - 'Z' + 'A' - 1;	//Subtracting 'Z' from ch and adding one less than 'A'
			}
			
			text[i] = ch; //Replacing the current character with ch
		}
	}
	
	return text; //Returning text to the calling function
}


//Decryption Module
string Decryption(string text, int key)		//Text and Key passed as arguments
{
	int i;	//Loop variable
	char ch; //Character variable 
	
	for(i = 0; text[i] != '\0'; ++i)	//For loop running until the text ends
	{
		ch = text[i]; //Storing current character in ch
		
		if(ch >= 'a' && ch <= 'z') //Checking if the ch is lowercase
		{
			ch = ch - key; //Subtracting the key from ch
			
			if(ch < 'a')	//if ch is less than 'a'
			{
				ch = ch + 'z' - 'a' + 1;	//adding 'z' to ch and subtracting one more than 'a'
			}
			
			text[i] = ch; //Replacing the current character with ch
		}
		else if(ch >= 'A' && ch <= 'Z') //Checking if the ch is uppercase
		{
			ch = ch - key; //Subtracting key from ch
			if(ch < 'A') //If ch is less than 'A'
			{
				ch = ch + 'Z' - 'A' + 1;	//Adding 'Z' to ch and subtracting one more than 'A'
			}
				
			
		}
	}
	
	return text; //Returning text to the calling function
}

//Main Function / Driver Code
int main()
{
	cout<<"                                   CAESER CIPHER                                      "<<endl;
	cout<<"                                COAL SEMESTER PROJECT                                 "<<endl;
	cout<<"                                     GROUP 05                                        "<<endl;
	cout<<"                         190774 | 190798 | 190826 | 190828                            "<<endl;
	cout<<"======================================================================================="<<endl<<endl;
	
	//Variables for use in program
	int operation, key;
	char choice;
	
	//Using do-while loop
	do
	{
		//Asking the user to choose operation
		cout<<"Choose the operation that you want to perform: "<<endl;
		cout<<"Press '1' for Encryption."<<endl;
		cout<<"Press '2' for Decryption. "<<endl;
		cout<<"Input: "; 
		cin>>operation;	//Taking input from user
			
		cout<<endl; //Printing line
			
		//Validating input
		while(!((operation == 1) || (operation == 2)))
		{
			cout<<"Invalid Entry! Enter a Valid Choice (1 or 2): ";
			cin>>operation;
		}
			
		//If user want to encrypt plain text 
		if(operation == 1)
		{
			cout<<"\n=============================== ENCRYPTION  MODULE ===================================\n\n";
			char c;
		   	string allFile; //Declaring string allFile to hold the contents of file
			
			cout<<"Opening File........"<<endl;
		    ifstream file( "Plain_text.txt" ); //Accessing file Plain_Text.txt
		    
		    
		    cout<<"Copying the Contents of .txt File........"<<endl;
		    file >> noskipws; //Copying the contents of file without any skip
		    while ( file >> c ) 
				allFile += c; //Storing each character to allFile variable
		    
		    cout<<"Done........"<<endl;
		    file.close(); //Closing file
		
		   	cout << "\nFile contents: " << allFile <<endl<<endl; //Displaying the contents of the file
		   	
		   	cout<<"Enter Encryption key: ";
			cin>>key; 	//Taking input for key
			cout<<"\nEncrypted Text: "<<Encryption(allFile,key)<<endl; //Displaying Encrypted Text by calling Encryption Function
			cout<<"\n=====================================================================================\n";
		}
			
		//If user wants to decrypt the encrypted text
		if(operation==2)
		{
			cout<<"\n=============================== DECRYPTION  MODULE ===================================\n\n";
			char c;
		   	string allFile;	//Declaring string allFile to hold the contents of file
			
			cout<<"Opening File........"<<endl;
		    ifstream file( "Encrypted_text.txt" );	//Accessing file Encrypted_Text.txt
		    
		    
		    cout<<"Copying the Contents of .txt File........"<<endl;
		    file >> noskipws;	//Copying the contents of file without any skip
		    while ( file >> c ) 
				allFile += c;	//Storing each character to allFile variable
		    
		    cout<<"Done........"<<endl;
		    file.close();	//Closing file
		
		   	cout << "\nFile contents: " << allFile <<endl<<endl;	//Displaying the contents of the file
		   	cout<<"Enter Decryption key: ";
		   	cin>>key; 	//Taking input for key
			cout<<"\nDecrypted Text: "<<Decryption(allFile,key)<<endl; //Displaying Decrypted Text by calling Decryption Function
			cout<<"\n======================================================================================\n";
		}
		
		cout<<"\nDo you want to perform another operation? (Y/N): ";
		cin>>choice;	//Taking input for choice
		
		cout<<endl; 	//Printing line
		
	}while(choice == 'Y' || choice == 'y');		//Validating Condition
	
	//Exiting Program
	cout<<"\nExiting Program........"; 	//Printing string
	return 0;	//Returning string
	cout<<endl<<endl;	//Printing two lines
}

