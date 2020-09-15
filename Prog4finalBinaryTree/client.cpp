
/*

   Jaylen Figueroa CS163
   Program #4
   8/6/2019

 This program reads in concerts from a file called event.txt and stores them in a binary search tree
 sorting items by the first letter of the band name. This alogorithm is alos used to add items to the
 binary search tree as well. The program also removes, seraches for elements, and displays all
 elements that are placed into the binary search tree.

*/




#include "contents.h"


int main ()
{
	input entry, n_entry; // used to  get entry from the user
	tree my_tree; // the main tree
	concert add, add_n, found; // used to call or edit elements from function
	int complete; // used to display success or failure
	int height; // used to show height of the tree at end of the execution
	char detail [1000] = {'\0'}; // arrays to get details of concert
	char detail_two[1000] = {'\0'};	
	char detail_three [1000] = {'\0'};	
	char detail_four [1000] = {'\0'};	
	char detail_five [1000] = {'\0'};	


	char option; // used to extract option from user


	my_tree.build( add, entry); // build list from txt file
	do
	{
		//	add.clean_junk(); // clean up previous entries
		//	entry.clean(); // clean from previous entries

		for(int k = 0; k < 1000 ; ++k) // clean up previous entries
		{

			detail[k] = '\0';
			detail_two[k] = '\0';
			detail_three[k] = '\0';
			detail_four[k] = '\0';
			detail_five[k] = '\0';

		}	

		cout << " Welcome to the concert date finder.." << endl;
		cout << " Please choose an option. " << endl;
		cout << " press 'd' for displaying concerts. " << endl;
		cout << " press 's' for searching for concerts. " << endl;
		cout << " press 'a' for adding a concert." << endl;
		cout << " Enter a 'r' for removing an event." << endl;	
		cout << " or enter a 'q' to quit." << endl;
		cin >> option;
		cin.ignore(100, '\n');


		if(option == 'd') // user wants to display data
		{
			my_tree.display();


		}



		if(option == 'a') // user wants to add an element
		{
			n_entry.clean(); // clean previoud entries
			add_n.clean_junk(); // clean previous entries
			cout << " please enter the band name." << endl;
			cin.get(detail , 1000, '\n');
			cin.ignore(100, '\n');
			n_entry.input1 = new char [strlen(detail) + 1];
			strcpy(n_entry.input1, detail);
			cout << " please enter the descritpiton of the concert." << endl;
			cin.get(detail_two , 1000, '\n');
			cin.ignore(100, '\n');
			n_entry.input2 = new char [strlen(detail_two) + 1];
			strcpy(n_entry.input2, detail_two);

			cout << " please enter the date of the concert." << endl;
			cin.get(detail_three, 1000, '\n');
			cin.ignore(100, '\n');
			n_entry.input3 = new char [strlen(detail_three) + 1];
			strcpy(n_entry.input3, detail_three);

			cout << " please enter the start time of the event." << endl;
			cin.get(detail_four, 1000, '\n');
			cin.ignore(100, '\n');
			n_entry.input4 = new char [strlen(detail_four) + 1];
			strcpy(n_entry.input4, detail_four);

			cout << "please enter the price for a ticket" << endl;
			cin.get(detail_five, 1000 , '\n');
			cin.ignore(100, '\n');
			n_entry.input5 = new char [strlen(detail_five) + 1];
			strcpy(n_entry.input5, detail_five);
			add_n.create_event(n_entry); // copy elements into the struct
			complete = my_tree.insert(n_entry.input1, add_n); // insert into binary tree
			if(complete) cout << " data added!" << endl;  // adding data was sucessful
			if(!complete) cout << " the data could not be added" << endl;  // adding data was not successful


		}


		if(option == 's') // user wants to search for data
		{
			found.clean_junk(); // clean up previous entries
			cout << " Please enter the name of the band you wish to search for. " << endl;
			cin.get(detail, 1000, '\n'); // extract the name to search for
			cin.ignore(100, '\n');
			complete = my_tree.search(detail, found);
			if(!complete) // nothing found
			{

				cout << " Sorry your entry could not be found" << endl;

			}


			if(complete) // an event was found
			{
				cout << " Result found.." << endl;
				found.display(); // the result

			}


		}




		if(option == 'r') // user wants to remove an event
		{


			cout << " Please enter the name of the band for which concert you choose to remove." << endl;
			cin.get(detail, 1000, '\n');
			cin.ignore(100, '\n');
			complete = my_tree.remove(detail);
			if(!complete) // data was not removed
			{
				cout << " The data could not be removed..." << endl;

			}
			if(complete) // data was removed
			{


				cout << " The data was removed" << endl;

			}

		}












	} while (option != 'q');




        // shows the height of the tree
	height = my_tree.show_height();
        cout << " The height of the tree is " << height << endl;
















	return 0;



}
