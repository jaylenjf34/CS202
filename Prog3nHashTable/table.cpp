 #include "table.h"

table :: table ()
{
	hash_table_size = 60001; // set size of hash table
	hash_table = new node * [hash_table_size]; // allocate hash table
	for(int i = 0; i < hash_table_size ; ++i) // initialize each element int table to NULL
	{

		hash_table[i] = NULL;

	}



}


input :: input ()
{

	// initialize

	input1 = NULL;
	input2 = NULL;
	input3 = NULL;
	input4 = NULL;
	input5 = NULL;




}



node :: node () 
{
	// initialize
	next = NULL;
}

concert :: concert ()
{
	// initalize 	
	band = NULL;
	event = NULL;
	date =  NULL;
	time = NULL;
	price = NULL;

}

/*

   cleans up the object so previous are not a problem
   when grabbing information from the user.

*/



void input :: clean (void)
{


	if(input1 != NULL)
	{

		delete [] input1;
		input1 = NULL;


	}
	if(input2 != NULL)
	{

		delete [] input2;
		input2 = NULL;
	}


	if(input3 != NULL)
	{
		delete [] input3;
		input3 = NULL;


	}


	if(input4 != NULL)
	{
		delete [] input4;
		input4 = NULL;


	}

	if(input5 != NULL)
	{

		delete [] input5;
		input5 = NULL; 



	}

	return;
}



/*
   This funtion is for the concert struct and siply outputs the 
   information stored in the the dynamic arrays of the object 


*/
int concert :: display (void) const
{
	if(band == NULL) // if there is nothing stored
		return 0;

	cout << " Artist: " << band << endl;
	cout << " Description: " << event << endl;
	cout << " Date: " << date << endl;
	cout << " Time: " << time << endl;
	cout << " Price: " << price << endl;
	return 1;





}


/*

   this function allocates the details for the object by passing in
   a object of input into the function.
   first it cleans the data in struct your allocating data into,
   then it copies details from entry into the concert object.

*/
int concert :: create_event (const input & entry)
{

	clean_junk(); // clean up junk values
	band = new char [strlen(entry.input1) + 1];
	strcpy(band, entry.input1);
	event = new char [strlen(entry.input2) + 1];
	strcpy(event, entry.input2);
	date = new char [strlen(entry.input3) + 1];
	strcpy(date, entry.input3);
	time = new char [strlen(entry.input4) + 1];
	strcpy(time, entry.input4);
	price = new char [strlen(entry.input5) + 1];
	strcpy(price, entry.input5);
	return 1;




};


/*
   This functio is used for copying data into the objects in the table,
   as well as hard copying. this is used ervytime we add an element to our
   list or retrieve an element. copy_from is a concert element tat is passed in
   that is used to copy from.


*/

int concert :: copy_concert(const concert & copy_from)
{

	if(!copy_from.band) // if there is no data in copy_from
	{

		return 0;
	}

	// gets rid of junk values 
	clean_junk();

	band = new char [strlen(copy_from.band) + 1];
	strcpy(band, copy_from.band);
	event = new char [strlen(copy_from.event) + 1];
	strcpy(event, copy_from.event);
	date = new char [strlen(copy_from.date) + 1];
	strcpy(date, copy_from.date);
	time = new char [strlen(copy_from.time) + 1];
	strcpy(time, copy_from.time);
	price = new char [strlen(copy_from.price) + 1];
	strcpy(price, copy_from.price);




	return 1;
}


/*
   Cleans up previous entries inside of the concert object.
   checks to see if they are not null, then deletes the memory
   and the sets it to NULL.

*/
void  concert :: clean_junk(void)
{

	if(band != NULL)
	{

		delete [] band;
		band = NULL;

	}

	if(event != NULL)
	{

		delete [] event;
		event = NULL;


	}

	if(date != NULL)
	{

		delete [] date;
		date = NULL;


	}


	if(time != NULL)
	{

		delete [] time;
		time = NULL;



	}


	if(price != NULL)
	{

		delete [] price;
		price = NULL;


	}

	return;

}

/*
   This hash_function is used everytime we add, remove, build, or do any modification to our table.
   it takes a array if characters as a key to go to a certain index in out hash table
   through a set of mathematical operations.



*/
int table :: hash_function(char * key)
{

	int sum = 0;

	for(int i = 0; i < strlen(key); ++i) // operation to create index for table insert
	{

		if(key[i] < 0) // if the ascii value is negative
		{

			key[i] = -key[i]; // make it positive

		}

		sum += key[i]; // add up all ascii values together 



	}


	sum = sum % hash_table_size; // take the remainder of the sum from the hash_table size




	return sum; // return index vlaue

}


/*

   this is the wrapper part for the build function. it frist sets upt the file to read from, check if it
   exists, the proceeeds to call the second function where we read the data.


*/


int table :: build ( concert & add,  input & entry)
{
	infile.open("event.txt");

	if(!infile) return 0;

	build_two( add, entry); // call the sedcond function

	return 1;

}




/*

   This is the second part to the build function.
   This function reads in all of the elements from the text
   file to fill in the hash table with these elements in a while loop.
   after it has fully filled a input object, it calls create_concert
   with an object of concert to create something to hard copy into the
   hash_table itself.
   */


int table :: build_two (  concert & add,  input & entry)
{
	int i = 0; // used to add concerts iteratively 
	char detail_i[1000] = {'\0'}; 
	char detail [1000] = {'\0'}; // array to get details of concert
	char detail_two[1000] = {'\0'};	
	char detail_three [1000] = {'\0'};	
	char detail_four [1000] = {'\0'};	
	char detail_five [1000] = {'\0'};	
	entry.clean(); // clean input struct
	add.clean_junk(); // clean up previous entries

	// prime the pump
	infile.get(detail_i, 1000,'|' );
	infile.ignore(100, '\n');
	entry.input1 = new char [strlen(detail_i) + 1];
	strcpy(entry.input1, detail_i);

	while (infile && !infile.eof() && i < hash_table_size) // not end of file
	{

		// second element
		infile.get(detail_two, 1000, '|');
		infile.ignore(100, '\n');
		entry.input2 = new char [strlen(detail_two) + 1];
		strcpy(entry.input2, detail_two);
		// third element
		infile.get(detail_three, 1000, '|');
		infile.ignore(100, '\n');
		entry.input3 = new char [strlen(detail_three) + 1];
		strcpy(entry.input3, detail_three);
		// fourth element
		infile.get(detail_four, 1000, '|');
		infile.ignore(100, '\n');
		entry.input4 = new char [strlen(detail_four) + 1];
		strcpy(entry.input4, detail_four);
		// fifth element
		infile.get(detail_five, 1000, '|');
		infile.ignore(100, '\n');
		entry.input5 = new char [strlen(detail_five) + 1];
		strcpy(entry.input5, detail_five);

		add.create_event(entry); // hard copy elements
		insert(entry.input1, add); // insert into hash table
		entry.clean(); // clean input struct
		add.clean_junk(); // clean up previous entries
		for(int k = 0; k < 1000 ; ++k) // clean up previous entries
		{

			detail[k] = '\0';
			detail_two[k] = '\0';
			detail_three[k] = '\0';
			detail_four[k] = '\0';
			detail_five[k] = '\0';

		}	
		++i; 
		// first element 
		infile.get(detail, 1000,'|' );
		infile.ignore(100, '\n');
		entry.input1 = new char [strlen(detail) + 1];
		strcpy(entry.input1, detail);



	}

	infile.close(); // close the file
	infile.clear(); // to reuse file

	return 1;

}


/*
   this function inserts a element into the hash table based on 
   a index created from the name of the band
   playing that is passed into the hash function. it also take a concert element that
   is used to hard copy an object into the hash table.
   */
int table :: insert( char * key_value, const concert & to_add)
{

	int index = 0; // get index to insert at

	index = hash_function(key_value); // call the hash function

	if(!hash_table[index]) // no node at index
	{

		hash_table[index] = new node;
		hash_table[index]->a_concert.copy_concert(to_add);
		hash_table[index]->next = NULL;
		return 1;



	}

	// exisiting node at spot insert at beginning
	node * temp = hash_table[index];
	hash_table[index] = new node;
	hash_table[index]->a_concert.copy_concert(to_add);
	hash_table[index]->next = temp;





	return 1;
}



/*

   first part of the display function. has a integer initialized to zero
   passed in to goe through the idices of the hash table using recursion.
   Once it reaches the hash_table last index it kicks out of the function.

*/

int table :: display ( int index )
{


	if(index < hash_table_size )// if the index is within the bounds of the table
	{

		if(hash_table[index] != NULL) // if index if filled
		{

			display_two(hash_table[index]); // display

		}


		return display(index+1); // call function again

	}


	return 1;



}



/*

   This is the second part that displays all of the nodes in the index. It uses
   recusion to travel to the end of the chain the returns bacl to the first display
   to go to the next hash table index.
   */


int table :: display_two ( node * link)
{

	if(!link) return 0; // if link is NULL get out

	link->a_concert.display(); // display concert
	cout << endl; // space
	return display_two(link->next); // return with next node

}
/*

   This function takes in a character array that is used to call the hash function,
   the goes to the index found by the hash function. If there is no data there
   it returns. If there is a node there it deletes the elements in the index



*/
int table :: remove( char * key)
{

	int index = 0;
	index = hash_function(key);

	if(hash_table[index] == NULL) return 0; // if there it no data

	if(hash_table[index]->next == NULL) // there is one element
	{

		delete hash_table[index];
		hash_table[index] = NULL;
		return 1;

	}


	if(hash_table[index]->next != NULL) // there is mutiple nodes
	{
		node * temp = hash_table[index]->next;
		delete hash_table[index];
		hash_table[index] = NULL;
		return 1;
	}

}

/*
   This function finds an elemtent in the table by using a character array and once it find the
   elemtn at the indes it returns the element back to the user by hardcopying data into the
   parameter found.
   */



int table ::  search( char * find, concert & found)
{

	int index = 0;
	index = hash_function(find); // get index

	if(hash_table[index] == NULL) return 0; // if there is no data allocated

	else
	{
		found.copy_concert(hash_table[index]->a_concert); // copy element into the found object
		return 1;
	}



}


input :: ~input ()
{
	// delete all elements in the input object
	if(input1)
	{
		delete [] input1;
		input1 = NULL;
	}
	if(input2)
	{ 
		delete [] input2;
		input2 = NULL;
	}

	if(input3)
	{ 
		delete [] input3;
		input3 = NULL;
	}

	if(input4)
	{  
		delete [] input4;
		input4 = NULL;
	}


	if(input5)
	{
		delete [] input5;
		input5 = NULL;
	}



}





node :: ~ node () 
{

	// delete next element connceted to node
	if(next)
	{

		delete next;


	}
}

concert :: ~concert ()
{

	// delete all dynamic memory in the object
	if(band)
	{ 
		delete [] band;	
		band = NULL;

	}

	if(event)
	{
		delete [] event;
		event = NULL;

	}


	if(date)
	{
		delete [] date;
		date = NULL;

	}

	if(time)
	{
		delete [] time;	
		time = NULL;

	}


	if(price)
	{

		delete [] price;
		price = NULL;


	}



}


table :: ~table ()
{
	// if we allcated a table
	if(hash_table)
	{

		for(int i = 0; i < hash_table_size; ++i) // loop thourgh the whole table
		{

			delete	hash_table[i] ; // delete the node at the index
			hash_table[i] = NULL; // set that index pointer to null

		}

		delete [] hash_table; // get rid of hash table



	}


	hash_table_size = 0;

}
