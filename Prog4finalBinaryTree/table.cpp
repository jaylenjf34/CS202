#include "contents.h"

tree :: tree ()
{
	root = NULL;
	height = 0;


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
	right = NULL;
	left = NULL;
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

   cleans up the object so previous entries are not a problem
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
   This function is for the concert struct and simply outputs the 
   information stored in the the dynamic arrays of the object of the concert
   that is found from a search function or stored in the binary search tree.


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

   this function allocates the details for the concert object by passing in
   an object of input into the function.
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
   This function is used for copying data into the objects in the table,
   as well as hard copying. this is used ervytime we add an element to our
   binary serach tree or retrieve an element. copy_from is a concert element that is passed in
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

   this is the wrapper part for the build function. it frist sets up the file to read from, check if it
   exists, the proceeeds to call the second function where we read the data.


*/


int tree :: build ( concert & add,  input & entry)
{
	infile.open("event.txt");

	if(!infile) return 0;

	build_two( add, entry); // call the sedcond function

	return 1;

}




/*

   This is the second part to the build function.
   This function reads in all of the elements from the text
   file to fill in the binary searc tree with these elements in a while loop.
   after it has fully filled a input object, it calls create_concert
   with an object of concert to create something to hard copy into the
   binary search tree.
   */


int tree :: build_two (  concert & add,  input & entry)
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

	while (infile && !infile.eof()) // not end of file
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
		insert(entry.input1, add); // insert into tree
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
   this function inserts a element into the binary tree by comparing the frist intital
   of the band that is playing the even.. it also takes a concert element that
   is used to hard copy an object into the hash table.
   the first part to the function is the wrapper or helper that keeps the nodes
   in the private section of the class by calling the second implementation with elements
  received. 
   */
int tree :: insert( char * key_value, const concert & to_add)
{



	return insert(key_value, to_add, root);


}

int tree :: insert( char * key_value, const concert & to_add, node * & root)
{



	if(!root) // sinsert a node when there is no node
	{

		root = new node;
		root->a_concert.copy_concert(to_add);
		root->left = NULL;
		root->right = NULL;
		return 1;


	}

	if(toupper(key_value[0]) < toupper(root->a_concert.band[0])) // intial is less than root
	{
		return insert(key_value, to_add, root->left);

	}

	if( toupper(key_value[0]) > toupper(root->a_concert.band[0])) // intial is greater than root
	{
		return insert(key_value, to_add, root->right);



	}


	if( toupper(key_value[0]) ==  toupper(root->a_concert.band[0])) //  equal values
	{


           
		return insert(key_value, to_add, root->right);

	}


}

/*

   first part of the display function. it is a wrapper that is used to 
   pass root to a private display function.

*/

int tree :: display ()
{


	return display_two(root);

}



/*

   This is the second part that displays all of the nodes in the binary search tree. It uses
   recusion to travel to the farthes right of the binary search tree. It uses in order traversal
   to display the furthest left concerts  stored into the tree to the last concert farthest right.
   */


int tree :: display_two ( node * link)
{

	if(!link) return 0; // if link is NULL get out
	display_two(link->left); // call with left
	link->a_concert.display(); // display concert
	cout << endl;
	display_two(link->right); // return with right node

}
/*

   This function takes in a character pointer that is used to find a concert element,
   that goes to a specific node in a binary search tree.  If there is no data found it returns 
  with a value indicating it was not found.
  If there is a node there it deletes the elements at the node in the tree.
  the first public remove calls the private remove to remove the node.


*/
int tree :: remove( char * key)
{




	return remove(key, root);

}

/*
 
 This function seraches by comparing the char pointer key to a band name of a conert object inside
of a node in the binary search tree. It compares the key to the band name of the root and travels left or
right if the first iniial is less or greater. Once it finds the correct item, it remvoves
it based or whether it is a a leaf, has one child, or has two children.
 
 
 */
int tree :: remove ( char * key, node * & root)
{


	if(!root) return 0;

	if(toupper(key[0]) < toupper(root->a_concert.band[0]))
	{
		return remove(key, root->left);
	}

	if(toupper(key[0]) > toupper(root->a_concert.band[0]))
	{

		return remove(key, root->right);

	}

	else
	{

		// it is a leaf
		if( strcmp(key, root->a_concert.band) == 0 && !root->left && !root->right)
		{

			delete root;
			root = NULL;
			return 1;

		}

		// one right child 
		if( strcmp(key, root->a_concert.band) == 0 && !root->left )
		{
			node * temp = root;
			root = root->right;
			delete temp;
			return 1;

		}

		// one left child 
		if(strcmp(key, root->a_concert.band) == 0  && !root->right)
		{

			node * temp = root;
			root = root->left;
			delete temp;
			return 1;

		} 

		// there is two children
		else if (strcmp(key, root->a_concert.band) == 0)
		{
			concert ios;
			ios.clean_junk(); 
			minimum(root->right, ios); // find the in order sucessor
			root->a_concert.clean_junk();
			root->a_concert.copy_concert(ios); // copy in order sucessors data into the node
			return 1;

		}   


	}


}


/*
  This function is used to find the in order sucessor of the the node you want to delete,
 and copies the concert item into the one passed in, and then deletes the in order sucessor after it 
has traveled all the way to the left of the right subtree of the node. 
 
 */

int tree :: minimum ( node * & root, concert & ios)
{

	if(!root->left) // we have found the in order sucessor
	{

		node * temp = root;
		ios.copy_concert(temp->a_concert);
		root = root->right;
		delete temp;
		temp = NULL;
		return 1;
	}


	return  minimum( root->left, ios); // ios not reached yet


}





/*
  This function finds a node that the client is looking for by taking in a char pointer
 and a concert object and looks for a node that cotains a band name that macthed the passed
in char pointer. The first wrapper calls the private seacrh with the root, and the passed in arguements.
*/



int tree ::  search( char * find, concert & found)
{

	return search( find, found, root);

}


int tree :: search( char * find, concert & found, node * & root)
{

	if(!root) return 0;

	if(strcmp(find, root->a_concert.band) == 0) // we have found our item
	{

		found.copy_concert(root->a_concert);

		return 1;
	}

	else if(toupper(find[0]) < toupper(root->a_concert.band[0])) // item is to the left
	{

		return search(find, found, root->left); 

	}

	else if (toupper(find[0]) > toupper(root->a_concert.band[0])) // item is to the right
	{
		return search(find, found, root->right);

	}	




}


/*
 
 this function deletes all of the nodes in the binary seach tree by using post order traversal.
It is called in the destructore of the the class tree. 
 */

void tree :: delete_all ( node * & root)
{

	if(!root) return;
	delete_all(root->left);
	delete_all(root->right);

	delete root;

}


/*
 
 This fucntion is a private wrapper that calles the implmented get height fucntion by giving it the root.
 
 
 */

void tree :: get_height ()
{


	height = get_height(root);

	return;



}

/*
 This is the implementation of height find function,
 it used the max function to find out which number is bigger from traveling all the
 way left and right from the tree and sets it to the height of tree in the private section.
*/


int tree :: get_height(node * root)
{

	if(!root) return 0;

	return 1 + max(get_height(root->left) , get_height(root->right));



}


/*
 This function returns the height so we can see the height of the 
tree at the end of the program. it also calls the two private get height functions to 
calculate the height of the tree
 
 */

int tree :: show_height()
{
  get_height();

  return height;


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
	right = NULL;
	left = NULL;


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


tree :: ~tree ()
{

	delete_all(root); // deletes entire tree.

	root = NULL;

}
