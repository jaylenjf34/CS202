#include<iostream>
using namespace std;
#include<cmath>
#include<cstring>
#include<cctype>
#include<fstream>



struct input // used to grab input from the user
{
	input ();
	char * input1;
	char * input2;
	char * input3;
	char * input4;
	char * input5;
	void clean (); 	
	~input();




};



struct concert // makes events (concerts) to attend
{

	concert();
	char * band; // dynamic arrays to hold details
	char * event;
	char * date;
	char * time;
	char * price;


	int display(void) const; // displays concert elements
	int copy_concert(const concert & copy_from); // had copies concert details
	void clean_junk(void); // cleans up junk values or previous entry
	int create_event(const input & entry); // creates an event from scratch
	~concert();





};

struct node
{

	node ();
	concert a_concert; // concert element
	node * right; // right pointer
	node * left; // left pointer
	~node();





};


class tree // manages the binary search tree.
{


	public :
		tree(); 
		int build(concert & add, input & entry); // build tree from txt file
		int build_two(concert & add, input & entry); // builds tree from txt file
		int display(); // display nodes in tree
		int insert( char * key_value, const concert & to_add);
		int search(char * find, concert & found); // searches for concert in tree
		int remove(char * find); // removes a found object;
	        int show_height(); // shows the height of the binary search tree.
		~tree();

	private:

		int height ; // height of the tree
		void get_height(); // calls the function to calulate the height
		int get_height(node * root); // calulates the height
		int display_two(node * link); // displays the node in the tree
		int insert( char * key_value, const concert & to_add, node * & root); // inserts elements into the bst
		int search( char * find, concert & found, node * & root); // priavte search implmentation
		int remove ( char * key, node * & root); // private implementation to remove elements
		int minimum ( node * & root, concert & ios); // finds the in order sucessor
		node * root; // start of the tree
		ifstream infile; // used to open txt file
		


		void delete_all(node * & root); // deallcoates and destroys entire BST

};
