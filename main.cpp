// Based on youtube serie
// https://www.youtube.com/watch?v=F9JWpTXFOzM

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

// Globals
//------------------------------------------------------------
class PERSON
{
	public:
		// Constructor and Destructor
		PERSON() { cout << "\n\tBuilding a PERSON."; };
		~PERSON() { cout << "\n\tDestroying a PERSON."; };
	
	// Member methods
	
	//Accessor methods
		void setPersonName(string setName) { PersonName = setName; }
		void setOccupation(string setOccupation) {	Occupation = setOccupation; }
		void setLocation(string setLocation) {	Location = setLocation; }
		void setReferences(string setReferences) { References = setReferences;	}
		string getPersonName() { return PersonName;	}
		string getOccupation() { return Occupation;	}
		string getLocation() { return Location;	}
		string getReferences() { return References;	}
	
	private:
		string PersonName;
		string Occupation;
		string Location;
		string References;
};


// Functions prototypes
void createPerson();
void editPerson();
void displayPerson();
void savePerson();
void loadPerson();

PERSON * Monka;
static bool isCreated = false;

//--------------------------------------------------------------
int main(int argc, char** argv) 
{	
	char CHOICE[10];
			
	cout << "\n\n\t Personnel Database Example \n";
	while (CHOICE[0] != 'q')
	{		
		cout << "\n\n\t|-----------------MAIN MENU--------------------|";
		cout << "\n\t|                                              |";
		cout << "\n\t|  1. Create a Person                          |";
		cout << "\n\t|  2. Edit Person's Information                |";
		cout << "\n\t|  3. Display a Person                         |";
		cout << "\n\t|  4. Save a Person                            |";
		cout << "\n\t|  5. Load a Person                            |";
		cout << "\n\t|  (Q)uit                                      |";
		cout << "\n\t|                                              |";
		cout << "\n\t|----------------------------------------------|";
		cout << "\n\tPlease select your CHOICE and pres ENTER: ";		
		
		cin >> CHOICE;
		cout << endl;
		
		switch(CHOICE[0])
		{
			case '1' : 
			{
				createPerson();
				break;
			}
			case '2' :
			{
				editPerson();
				break;
			}
			case '3' : 
			{
				displayPerson();
				break;
			}
			case '4' : 
			{
				savePerson();
				break;
			}
			case '5' : 
			{
				loadPerson();
				break;
			}						
			case 'q': //return 0; //break;
			case 'Q': cout << "\n\n\tQuit!"; break;
			default : cout << "\n\n\tInvalid CHOICE option!";
		}

		cout << "\n\n\t";
		system("pause");
		system("cls");	
		CHOICE[0] = tolower(CHOICE[0]);	// if Q then replace with q
	}	
	
	// Delete an object in the Heap
	if (isCreated) delete Monka;	
	
	//--------------------------------------------------
	cout << "\n\n\t";
	system("pause");
	return 0;
}

//------------------------------------------------------
void createPerson()
{
	if(!isCreated)
	{
		Monka = new PERSON();
		isCreated = true;		
	}
	else
	{
		cout << "\n\n\tA PERSON has already been created!";
	}	
}
//-------------------------------------------------------

void editPerson()
{
	if (isCreated) 
	{
		string temp;
		system("cls");
		cout << "\n\n\t--------------Edit a Person----------------";
		cout << "\n\tName: ";
	// cin = console in.
	// Simple use of cin >> PersonName would not work due to spaces
	// use getline() instead !
	// only very first time use cin.ignore to remove dummy symbol enter
		cin.ignore(); 							// only before the first getline() !!
		getline(cin, temp);
		Monka->setPersonName(temp);
	
		cout << "\n\tOccupation: ";
		getline(cin, temp);
		Monka->setOccupation(temp);
	
		cout << "\n\tLocation: ";
		getline(cin, temp);
		Monka->setLocation(temp);
	
		cout << "\n\tReferences: ";
		getline(cin, temp);
		Monka->setReferences(temp);
	}
	else
	{
		cout << "\n\n\tError! Please first create a PERSON!";
	}

				
}
//-------------------------------------------------------

void displayPerson()
{
	if (isCreated)
	{
		cout << "\n\n\t----------------PERSON Information----------------";
		cout << "\n\tName: " 		<< Monka->getPersonName();
		cout << "\n\tOccupation: " 	<< Monka->getOccupation();
		cout << "\n\tLocation: " 	<< Monka-> getLocation();
		cout << "\n\tReferences: " 	<< Monka->getReferences();	
		cout << "\n\t---------------------------------------------------";
		cout << "\n";		
	}
	else
	{
		cout << "\n\n\tError! Please first create a PERSON!";
	}

}
//-------------------------------------------------------

void savePerson()
{
	if(isCreated)
	{
		try
		{
			ofstream DATAFILE;
			DATAFILE.open("data1.file", ios::out);
			
			DATAFILE << Monka->getPersonName() 	<< "\n";
			DATAFILE << Monka->getOccupation() 	<< "\n";
			DATAFILE << Monka->getLocation() 	<< "\n";
			DATAFILE << Monka->getReferences() 	<< "\n";	
			
			DATAFILE.close();
			
			cout << "\n\n\tSuccess! DATA was saved to file data1.file !";					
		}
		catch(exception X)
		{
			cout << "\n\n\tFile Error! Could not SAVE PERSON!";
		}		
	}
	else
	{
		cout << "\n\n\tError! Please first create a PERSON!";	
	}

}
//--------------------------------------------------------

void loadPerson()
{
	if (isCreated)
	{
		try
		{
			ifstream DATAFILE;
			DATAFILE.open("data1.file", ios::in);
			string temp;
			
			// This method would not work as we have spaces in the data1.file lines
			// Spaces will chop the information streamed by the operator >>
		//		DATAFILE >> PersonName;
		//		DATAFILE >> Occupation;
		//		DATAFILE >> Location;
		//		DATAFILE >> References;
			
			// Using getline() will return a line/row from DATAFILE file into string variable
			getline(DATAFILE, temp);
			Monka->setPersonName(temp);
			
			getline(DATAFILE, temp);
			Monka->setOccupation(temp);
			
			getline(DATAFILE, temp);
			Monka->setLocation(temp);
			
			getline(DATAFILE, temp);
			Monka->setReferences(temp);
					
			DATAFILE.close();
			
			cout << "\n\n\tSuccess! DATA was loaded from a file data1.file !";					
		}
		catch(exception X)
		{
			cout << "\n\n\tFile Error! Could not open data1.file!";
		}		
	}
	else
	{
		cout << "\n\n\tError! Please first create a PERSON!";
	}
		

}
//--------------------------------------------------------