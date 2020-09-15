#include<iostream>
using namespace std;
#include<cmath>
#include<cstring>
#include<cctype>
#include<fstream>

// used to grab entry from the user
struct input
{
	input(); 
	char * input1; // dynamic arrays to get entries from users
	char * input2;
	char * input3;
	char * input4;
	char * input5;
	~input();
	void clean(void); // cleans upp entries in struct

};


// used to create concerts to add to the table
struct concert
{
	concert();
	char * band; // dynamic arrays to hold concert info
	char * event;
	char * date;
	char * time;
	char * price;

	int display (void) const; // displays elemtns in object
	int copy_concert(const concert & copy_from); // hard copies elements
	void clean_junk(void); // cleans out object
	int create_event(const input & entry); // creates a new event from passed int input

	~concert();

};


// holds concerts int the hash table and created chains in table indices

struct node
{


	node();
	concert a_concert; // object concert in node
	node * next; // pointer to next node
	~node();

};




class table
{

	public:
		table ();
		int build ( concert & add,  input & entry); // wrapper for building table from txt file
		int build_two ( concert & add, input & entry); // implementation for reading from txt file
		int display(int index); // displays all elements in hash table
		int insert( char * key_value, const concert & to_add); // inserts element into table
		int search( char * find, concert & found);  // searches hash table for a match
		int hash_function(char * key); // creates the index for opertions to go to
		int remove(char * key);	 // removes events by band name
		~table();



	private:
		node ** hash_table; // hash table array
		int hash_table_size; // size of hash table
		int display_two(node * link); // second function used to display table elements
		ifstream infile; // file to read from

};
