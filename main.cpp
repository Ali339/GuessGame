#include "BinaryTree.cpp"
#include <string>
#include <iostream>
#include<fstream>
using namespace std ;

void play(BinaryTreeNode<string>* current_ptr);
void learn(BinaryTreeNode<string>*& leaf_ptr);

int main() {
    ifstream infile ("input.txt");
    string rootques, Lques, Rques ;
    BinaryTreeNode<string> * root_node ;
    while (!infile.eof())
    {
        getline(infile,rootques);
        root_node = create_node(rootques);
        getline(infile,Lques);
        root_node->left = create_node(Lques);
        getline(infile,Rques);
        root_node->right = create_node(Rques);

    }
	bool playGame = true;



	while(playGame) {
		play(root_node);
		string input;
		cout << "Play again? (y or n)";
		cin >> input;
		cin.ignore();
		playGame = (input == "y" || input == "Y");
	}

	return 0;
}

void play(BinaryTreeNode<string>* current_ptr)
{
	std::cout << "Think of anything. Press enter when ready." << std::endl;
	while (cin.get() != '\n');
	string input;
	while (!is_leaf(*current_ptr))
	{
		cout << current_ptr->data << " ";
		cin >> input;
		cin.ignore();
		if (input == "y" || input == "Y" || input == "yes" || input == "Yes")
			current_ptr = current_ptr->left;
		else
			current_ptr = current_ptr->right;
	}

	cout << "Is it a(n) " << current_ptr->data << "? ";
	cin >> input;
	cin.ignore();
	if (input == "y" || input == "Y" || input == "yes" || input == "Yes")
		cout << "Ha! Knew it!" << endl;
	else
		learn(current_ptr);
}

void learn(BinaryTreeNode<string>*& leaf_ptr)
{
	string guess_thing;
	string correct_thing;
	string new_question;

	guess_thing = leaf_ptr->data;
	cout << "I give up. What are you? A(n) ";
	getline(cin, correct_thing);


	cout << "Please type a yes/no question that will distinguish a(n) "
			<< correct_thing << " from a(n) " << guess_thing << "." << endl;
	getline(cin, new_question);


	leaf_ptr->data = new_question;
	cout << "As a(n) " << correct_thing << ", " << new_question << endl;

	string input;
	cin >> input;
	cin.ignore();
	if (input == "y" || input == "Y" || input == "yes" || input == "Yes")
	{
		leaf_ptr->left = create_node(correct_thing);
		leaf_ptr->right = create_node(guess_thing);
	}
	else
	{
		leaf_ptr->left = create_node(guess_thing);
		leaf_ptr->right = create_node(correct_thing);
	}
}
