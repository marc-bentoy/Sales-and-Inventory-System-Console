#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
#include <ctime>

#include <string.h>
#include <windows.h>
#include <dir.h>
#include <conio.h>

using namespace std;

// Class representation for shop products
class Item
{
public:
	string code, name, category;
	double price;
	int qty;

	Item(string code, string name, string category, string price, string qty)
	{
		this->code = code;
		this->name = name;
		this->category = category;
		this->price = (double)stoi(price);
		this->qty = stoi(qty);
	}
};

// Class for performing utility/extra functions such as changing colors, showing formatted texts and others..
class Util
{
public:
	/// <summary>
	/// Changing the text color into 5 different colors
	/// </summary>
	/// <param name="color"></param>
	static void color(string color)
	{
		if (color == "white") SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		else if (color == "blue") SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		else if (color == "orange") SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		else if (color == "green") SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		else if (color == "red") SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	}

	/// <summary>
	/// Use for displaying formatted strings 
	/// </summary>
	/// <param name="type">type of format</param>
	/// <param name="content">string to display</param>
	static void screens(string type, string content)
	{
		if (type == "title")
		{
			system("cls");
			Util::color("blue");
			cout << "\t\t\t --------------------------------------------------" << endl;
			Util::color("white");
			int spaceLength = (100 - content.length()) / 2;
			for (int i = 0; i < spaceLength / 8; ++i)
			{
				cout << "\t";
			}
			for (int i = 0; i < spaceLength % 8; ++i)
			{
				cout << " ";
			}
			cout << content << endl;
			Util::color("blue");
			cout << "\t\t\t --------------------------------------------------" << endl << endl;
		}

		else if (type == "center")
		{
			Util::color("white");
			int spaceLength = (100 - content.length()) / 2;
			for (int i = 0; i < spaceLength / 8; ++i)
			{
				cout << "\t";
			}
			for (int i = 0; i < spaceLength % 8; ++i)
			{
				cout << " ";
			}
			cout << content << endl;
		}

		else if (type == "left")
		{
			Util::color("white");
			cout << "\n\t\t\t " << content << endl;
		}

		else if (type == "leftBlue")
		{
			Util::color("blue");
			cout << "\n\t\t\t " << content << endl;
		}

		else if (type == "input")
		{
			Util::color("orange");
			cout << "\t\t\t " << content << endl << "\t\t\t ";
			Util::color("blue");
			cout << ">> ";
			Util::color("white");
		}

		else if (type == "alertRed")
		{
			Util::color("red");
			cout << "\n\t\t\t " << content << endl;
		}

		else if (type == "alertGreen")
		{
			Util::color("green");
			int spaceLength = (100 - content.length()) / 2;
			for (int i = 0; i < spaceLength / 8; ++i)
			{
				cout << "\t";
			}
			for (int i = 0; i < spaceLength % 8; ++i)
			{
				cout << " ";
			}
			cout << content;
			cout << endl << endl;
		}
	}

	/// <summary>
	/// Use for displaying menus with one or more commands
	/// </summary>
	/// <param name="title">Menu title</param>
	/// <param name="subTitle">Menu subitle</param>
	/// <param name="commands">list of commands</param>
	static void menuScreens(string title, string subTitle, vector<string> commands)
	{
		system("cls");
		Util::screens("title", title);
		Util::screens("center", subTitle);

		// displaying the command number 
		for (int i = 0; i < commands.size(); ++i)
		{
			Util::color("orange");
			cout << "\t\t\t [" << i + 1 << "] ";
			Util::color("white");
			cout << commands[i] << endl;
		}

		Util::color("blue");
		cout << "\t\t\t >> ";
		Util::color("white");
	}

	/// <summary>
	/// Displaying a structured and formatted presentation of items
	/// </summary>
	/// <param name="items">list of items to display</param>
	/// <param name="isFullView">Option for displaying items with 0 quantity</param>
	static void displayItems(vector<Item> items, int isFullView = 1)
	{
		#pragma region Printing Item Header Properties 
		Util::color("blue");
		cout << "+";
		for (int i = 0; i < 98; ++i)
		{
			cout << "-";
		}
		cout << "+" << endl;

		Util::color("green");
		cout << "|Code    |";
		cout << "Name                         |";
		cout << "Category                     |";
		cout << "Price         |";
		cout << "Qty           |" << endl;

		Util::color("blue");
		cout << "+";
		for (int i = 0; i < 98; ++i)
		{
			cout << "-";
		}
		cout << "+" << endl;
		#pragma endregion

		#pragma region Printing Item Properties in format
		Util::color("white");
		for (int i = 0; i < items.size(); ++i)
		{
			if (!isFullView && items[i].qty == 0) continue;

			cout << "|" << items[i].code;
			for (int j = 0; j < 8 - items[i].code.length(); ++j)
			{
				cout << " ";
			}

			cout << "|" << items[i].name;
			for (int j = 0; j < 29 - items[i].name.length(); ++j)
			{
				cout << " ";
			}

			cout << "|" << items[i].category;
			for (int j = 0; j < 29 - items[i].category.length(); ++j)
			{
				cout << " ";
			}

			cout <<	setiosflags(std::ios::fixed) << setprecision(2) << "|" << items[i].price;
			for (int j = 0; j < 18 - (to_string(items[i].price).length()); ++j)
			{
				cout << " ";
			}

			cout << "|" << items[i].qty;
			for (int j = 0; j < 14 - (to_string(items[i].qty).length()); ++j)
			{
				cout << " ";
			}
			cout << "|" << endl;
		}
		#pragma endregion

		#pragma region Line Breaker
		Util::color("blue");
		cout << "+";
		for (int i = 0; i < 98; ++i)
		{
			cout << "-";
		}
		cout << "+" << endl;
		#pragma endregion
	}

	/// <summary>
	/// Input number checker
	/// </summary>
	/// <param name="inputtedString">inputted string</param>
	/// <returns>0 if a valid number and -1 if invalid</returns>
	static int isValidNumber(string inputtedString)
	{
		// checks all of the inputtedString characters if it is a number
		for (int i = 0; i < inputtedString.length(); ++i)
		{
			if ((inputtedString[i] != '1') && (inputtedString[i] != '2') && (inputtedString[i] != '3') && (inputtedString[i] != '4') && (inputtedString[i] != '5') && (inputtedString[i] != '6') && (inputtedString[i] != '7') && (inputtedString[i] != '8') && (inputtedString[i] != '9') && (inputtedString[i] != '0'))
			{
				// if not a number
				return -1;
			} 
		}
		// if all characters are number
		return 0;
	}

	/// <summary>
	/// File reader for faster and efficient implementation 
	/// </summary>
	/// <param name="path">file path</param>
	/// <returns>The content of the file</returns>
	static string readFile(string path)
	{
		ifstream reader;
		reader.open(path, ios::in);
		string readLine, content;

		// returns an empty string if file does not exist
		if (!reader.is_open()) return "";

		// reading the file line by line and storing into the content
		while(getline(reader, readLine))
		{
			content += readLine;
			content += '\n';
		}
		reader.close();
		return content;
	}

	/// <summary>
	/// Writing a file
	/// </summary>
	/// <param name="path">file destination</param>
	/// <param name="content">file content</param>
	/// <param name="isAppending">Option for appending items</param>
	static void writeFile(string path, string content, int isAppending = 0)
	{
		// creating db folder in case if not created
		mkdir("db");

		ofstream writeFile;

		// appends data if isAppending == 1
		if (isAppending) writeFile.open(path, ios::out | ios::app);

		// else, creates a file or replacing existing
		else writeFile.open(path, ios::out);
		writeFile << content << endl;
		writeFile.close();
	}

	/// <summary>
	/// Custom string splitter
	/// </summary>
	/// <param name="rawContent">string to be split</param>
	/// <param name="charSplitter">character which splits the rawContent</param>
	/// <returns>a list of string splitted from rawContent</returns>
	static vector<string> split(string rawContent, char charSplitter = '\n')
	{
		vector<string> splittedContent;
		string lineContent;
		for (int i = 0; i < rawContent.length(); ++i)
		{
			// check if the current character is equal to the charSplitter
			if (rawContent[i] == charSplitter)
			{
				// adds the lineContent to the splittedContent
				splittedContent.push_back(lineContent);
				lineContent = "";
				continue;
			}
			lineContent += rawContent[i];
		}
		return splittedContent;
	}
};

// Class for reading saved logs
class Log
{
public:
	/// <summary>
	/// Displaying a formatted view of the saved logs
	/// </summary>
	static void showLogs()
	{
		Util::screens("title", "Purchases and Login Records");

		vector<char> rawLogsData;
		// reading logs.dat
		string logs = Util::readFile("db/logs.dat");
		if (logs == "")
		{
			Util::screens("alertRed", "No existing logs..");
			Util::screens("input", "press enter key to continue..");
			cin.get();
			return;
		}

		Util::color("white");
		cout << logs << endl;
		cin.ignore();
		Util::screens("input", "press enter key to continue..");
		cin.get();
	}
};

// Class for system inventory : use for managing items
class Inventory
{
public:
	/// <summary>
	/// Inventory Constructor for linking the global items list
	/// </summary>
	/// <param name="items">global items address</param>
	Inventory(vector<Item> *items)
	{
		// setting the global items to inventory items
		this->items = items;

		// reading code list
		string fullCodesList = Util::readFile("db/list.dat");
		vector<string> codeItems = Util::split(fullCodesList);

		// reading all items 
		for (int i = 0; i < codeItems.size(); i++)
		{
			// first, check if item exists and reading data
			string itemDataPath = "db/" + codeItems[i] + ".dat";
			string itemData = Util::readFile(itemDataPath);
			vector<string> itemProperties = Util::split(itemData);
			
			// store data into items
			Item itemToAdd(codeItems[i], itemProperties[0], itemProperties[1], itemProperties[2], itemProperties[3]);
			this->items->push_back(itemToAdd);
		}
	}

	/// <summary>
	/// Prompting for addition of items with complete format 
	/// </summary>
	void addItem()
	{
		// initialization of item properties for user inputs
		string code, name, category, price, qty;

		#pragma region Item Properties Input
		// ask for code
		do
		{
			Util::screens("title", "Add an Item");
			Util::screens("input", "Item code: ");
			cin >> code;
			if (code.length() > 8 || code.length() <= 1)
			{
				Util::screens("alertRed", "Invalid item code.");
				Util::screens("input", "Enter again? [y/n]");
				char option;
				cin >> option;
				if (option == 'y') continue;
				else if (option == 'n') return;
				else return;
			}			
		} while (code.length() > 8);
		// check if unique code
		for (int i = 0; i < items->size(); ++i)
		{
			if (items[0][i].code == code) 
			{
				Util::screens("alertRed", "Invalid, code must be unique.");
				Util::screens("input", "Enter again? [y/n]");
				char option;
				cin >> option;
				cin.ignore();
				if (option == 'y') addItem();
				return;
			}
		}
		cin.ignore();

		// ask for name 
		Util::screens("input", "Item name: ");
		getline(cin, name);
		while (name.length() > 30 || name.length() <= 1)
		{
			Util::screens("alertRed", "Invalid item name.");
			Util::screens("input", "Enter again? [y/n]");
			char option;
			cin >> option;
			if (option == 'y') addItem();
			return;
		}

		// ask for category
		Util::screens("input", "Item category: ");
		getline(cin, category);
		while (category.length() > 30 || category.length() <= 1)
		{
			Util::screens("alertRed", "Invalid item category.");
			Util::screens("input", "Enter again? [y/n]");
			char option;
			cin >> option;
			if (option == 'y') addItem();
			return;
		}

		// ask for price
		Util::screens("input", "Item price: ");
		cin >> price;
		// check if valid characters entered
		if (Util::isValidNumber(price) == -1) 
		{
			Util::screens("alertRed", "Invalid price!");

			Util::screens("input", "Enter again? [y/n]");
			char option;
			cin >> option;
			if (option == 'y') addItem();
			return;
		}
		try
		{
			double convertedPrice = (double)stoi(price);
		}
		catch(const char* e)
		{
			cerr << e << endl;
		}

		// ask for qty
		Util::screens("input", "Item quantity: ");
		cin >> qty;
		// check if valid characters entered
		if (Util::isValidNumber(qty) == -1) 
		{
			Util::screens("alertRed", "Invalid quantity!");

			Util::screens("input", "Enter again? [y/n]");
			char option;
			cin >> option;
			if (option == 'y') addItem();
			return;
		}
		try
		{
			int convertedQty = stoi(qty);
		}
		catch(const char* e)
		{
			cerr << e << endl;
		}
		#pragma endregion

		#pragma region Adding the item to the items list
		// add item to items
		Item itemToAdd(code, name, category, price, qty);
		items->push_back(itemToAdd);

		// creating items databse directory
		mkdir("db");
		#pragma endregion

		#pragma region Writing item data to the database
		// append item code to list.dat
		Util::writeFile("db/list.dat", code, 1);

		// create item to database
		string itemFilePath = "db/" + code + (string)".dat";
		string itemProperties = name + '\n' + category + '\n' + price + '\n' + qty;
		Util::writeFile(itemFilePath, itemProperties);
		cin.ignore();
		Util::screens("alertGreen", "Item created successfully!");
		#pragma endregion

		// ask to add another item
		char option;
		Util::screens("input", "Add another item? [y/n]");
		cin >> option;
		if (option == 'y') addItem();
		return;
	}

	/// <summary>
	/// removing an item to the items list and to the database
	/// </summary>
	void deleteItem()
	{	
		#pragma region Asking for item code to remove
		Util::screens("title", "Remove an Item");
		Util::screens("input", "Item code to remove: ");
		// ask for code item to delete
		string itemToRemove;
		cin >> itemToRemove;

		string itemPathToRemove = "db/" + itemToRemove + (string)".dat";

		// check if item exists
		ifstream infile;
		infile.open(itemPathToRemove.c_str());
		if (!infile)
		{
			Util::screens("alertRed", "Item does not exist.");

			// ask to delete other item
			Util::screens("input", "Delete other item? [y/n]");
			char option;
			cin >> option;
			if (option == 'y') deleteItem();
			else if (option == 'n') return;
			return;
		}
		infile.close();
		#pragma endregion

		#pragma region Deleting item to the database and items list
		// remove item from items
		for (int i = 0; i < items->size(); ++i)
		{
			if (items[0][i].code == itemToRemove)
			{
				items->erase(items->begin() + i);
				break;
			}
		}
		// remove item code from list.dat
		ofstream writeFile;
		writeFile.open("db/list.dat", ios::out);
		for (int i = 0; i < items->size(); ++i)
		{
			writeFile << items[0][i].code << endl;
		}
		writeFile.close();

		// delete item file
		int isItemDeleted;
		isItemDeleted = remove(itemPathToRemove.c_str());
		cin.ignore();
		if (!isItemDeleted)
		{
			Util::screens("alertGreen", "File successfully deleted!");
		}
		else cout << "File not deleted!" << endl;
		#pragma endregion

		// ask to delete another
		Util::screens("input", "Delete another item? [y/n]");
		char option;
		cin >> option;
		if (option == 'y') deleteItem();
		else if (option == 'n')
		{
			cin.ignore();
			return;
		}
		cin.ignore();
		return;
	}

	/// <summary>
	/// Edits an item from items list and database
	/// </summary>
	void editItem()
	{
		#pragma region Asking for item code to edit
		Util::screens("title", "Edit an Item");
		Util::screens("input", "Item code to edit: ");
		// ask for code item to edit
		string itemToEdit;
		cin >> itemToEdit;

		string itemPathToEdit = "db/" + itemToEdit + (string)".dat";

		// check if item exists
		ifstream infile;
		infile.open(itemPathToEdit.c_str());
		if (!infile)
		{
			Util::screens("alertRed", "Item does not exist.");

			// ask to delete other item
			Util::screens("input", "Edit other item? [y/n]");
			char option;
			cin >> option;
			if (option == 'y') editItem();
			else if (option == 'n') return;
			return;
		}
		infile.close();
		#pragma endregion

		#pragma region Retrieving the item data
		// initializing item index
		int itemIndex;
		for (int i = 0; i < items->size(); ++i)
		{
			if (items[0][i].code == itemToEdit)
			{
				itemIndex = i;
				break;
			}
		}

		// ask for item property to edit
		char optionToEdit;
		vector<string> itemProperties = { "name", "category", "price", "quantity" };
		Util::menuScreens("Editing an Item", "Choose item property to edit", itemProperties);
		cin >> optionToEdit;

		// declaration of item properties to edit
		string newName, newCategory, newPrice, newQty;

		// setting all new properties to old properties
		newName = items[0][itemIndex].name;
		newCategory = items[0][itemIndex].category;
		newPrice = to_string(items[0][itemIndex].price);
		newQty = to_string(items[0][itemIndex].qty);
		#pragma endregion

		#pragma region Asking for new item property
		// options
		if (optionToEdit == '1')
		{
			Util::screens("leftBlue", "Current item name: " + items[0][itemIndex].name);
			do
			{
				cin.ignore();
				Util::screens("input", "New item name: ");
				getline(cin, newName);
				if (newName.length() > 30)
				{
					Util::screens("alertRed", "Invalid, name too long.");
					Util::screens("input", "Enter again? [y/n]");
					char option;
					cin >> option;
					if (option == 'y') continue;
					else if (option == 'n') return;
					else return;
				}
			} while (newName.length() > 30);
		}
		else if (optionToEdit == '2')
		{
			Util::screens("leftBlue", "Current item category: " + items[0][itemIndex].category);
			do
			{
				cin.ignore();
				Util::screens("input", "New item category: ");
				getline(cin, newCategory);
				if (newCategory.length() > 30)
				{
					Util::screens("alertRed", "Invalid, category too long.");
					Util::screens("input", "Enter again? [y/n]");
					char option;
					cin >> option;
					if (option == 'y') continue;
					else if (option == 'n') return;
					else return;
				}
			} while (newCategory.length() > 30);
		}
		else if (optionToEdit == '3')
		{
			cin.ignore();
			// TODO
			cout << setiosflags(std::ios::fixed) << setprecision(2);
			Util::screens("leftBlue", "Current item price: " + to_string(items[0][itemIndex].price));
			Util::screens("input", "New item price: ");
			cin >> newPrice;
			// check if valid characters entered
			try
			{
				double convertedNewPrice = (double)stoi(newPrice);
			}
			catch (const char* e)
			{
				cerr << e << endl;
			}
		}
		else if (optionToEdit == '4')
		{
			cin.ignore();
			Util::screens("leftBlue", "Current item quantity: " + to_string(items[0][itemIndex].qty));
			Util::screens("input", "New item quantity: ");
			cin >> newQty;
			// check if valid characters entered
			try
			{
				int convertedNewQty = stoi(newQty);
			}
			catch (const char* e)
			{
				cerr << e << endl;
			}
		}
		else
		{
			cin.ignore();
			char tryAgainOption;
			Util::screens("alertRed", "Invalid command.");
			Util::screens("input", "Enter again? [y/n]");
			cin >> tryAgainOption;
			if (tryAgainOption == 'y') editItem();
			else if (tryAgainOption == 'n') return;
			else return;
		}
		#pragma endregion

		#pragma region Updating old item properties
		// updating old properties
		Item editedItem(itemToEdit, newName, newCategory, newPrice, newQty);
		items[0][itemIndex] = editedItem;

		// updating the item database
		ofstream writeFile;
		writeFile.open(itemPathToEdit.c_str(), ios::out);
		writeFile << newName << endl;
		writeFile << newCategory << endl;
		writeFile << newPrice << endl;
		writeFile << newQty << endl;
		writeFile.close();
		Util::screens("alertGreen", "Item edited successfully!");
		#pragma endregion

		// ask to edit another
		Util::screens("input", "Edit another item? [y/n]");
		char option;
		cin >> option;
		if (option == 'y') editItem();
		else if (option == 'n')
		{
			cin.ignore();
			return;
		}
		cin.ignore();
		return;
	}

	/// <summary>
	/// Displaying all items including items with 0 quantity
	/// </summary>
	void displayItems()
	{
		system("cls");
		if (items->size() == 0)
		{
			Util::screens("title", "Inventory Items");
			Util::screens("alertRed", "Your inventory is empty..");
			Util::screens("input", "press enter key to go back..");
			cin.ignore();
			cin.get();
			return;
		}
		Util::screens("center", "Inventory Items");
		Util::displayItems(*items);

		Util::color("orange");
		Util::screens("input", "press enter key to go back..");
		cin.ignore();
		cin.get();
	}

	/// <summary>
	/// Showing out and low of stock items as reports
	/// </summary>
	void reports()
	{
		system("cls");
		Util::screens("title", "Reports");

		Util::color("white");
		cout << "Out of stock items: " << endl;

		vector<Item> outOfStockItems;
		for (int i = 0; i < items->size(); ++i)
		{
			if (items[0][i].qty == 0)
			{
				outOfStockItems.push_back(items[0][i]);
			}
		}

		Util::displayItems(outOfStockItems);

		Util::color("white");
		cout << "Low of stock items: " << endl;

		vector<Item> lowOfStockItems;
		for (int i = 0; i < items->size(); ++i)
		{
			if (items[0][i].qty < 10 && items[0][i].qty != 0)
			{
				lowOfStockItems.push_back(items[0][i]);
			}
		}
		Util::displayItems(lowOfStockItems);
		cin.ignore();
		cin.get();
	}

	/// <summary>
	/// Specific inventory menu
	/// </summary>
	void menu()
	{
		// show inventory menu
		while (true)
		{
			vector<string> inventoryCommands = {"Add item", "Remove item", "Edit item", "Display all items", "Back"};
			Util::menuScreens("INVENTORY", "Inventory Menu", inventoryCommands);

			char menuOption;
			cin >> menuOption;
			if (menuOption == '1') addItem();
			else if (menuOption == '2') deleteItem();
			else if (menuOption == '3') editItem();
			else if (menuOption == '4') displayItems();
			else if (menuOption == '5') return;
			else
			{
				cout << "Invalid command, Enter again? [y/n]" << endl;
				char backToMenu;
				cin >> backToMenu;
				if (backToMenu == 'y') menu();
				else if (backToMenu == 'n') return;
				return;
			}
		}
	}

private:
	vector<Item> *items;
};

// Class for system sales : use for selling items
class Sales
{
public:
	/// <summary>
	/// Sales constructor for linking global items
	/// </summary>
	/// <param name="items">global items</param>
	Sales (vector<Item> *items)
	{
		this->items = items;
	}

	/// <summary>
	/// Showing products/items excluding items with 0 quantity
	/// </summary>
	void showProducts()
	{
		system("cls");
		Util::screens("center", "Products");
		Util::displayItems(*items, 0);
		if (items->size() == 0) cout << "Inventory is empty." << endl;
		Util::color("orange");
		cout << "\n\npress enter to go back..";
		cin.ignore();
		cin.get();
	}

	/// <summary>
	/// Displaying the items inside the cart list
	/// </summary>
	void viewCart()
	{
		system("cls");
		if (cart.size() == 0)
		{
			Util::screens("title", "Your Cart");
			Util::screens("alertRed", "Your cart is empty..");
			Util::screens("input", "press enter key to go back..");
			cin.ignore();
			cin.get();
			return;
		}
		Util::screens("center", "Your Cart");
		Util::displayItems(cart, 0);
		
		Util::screens("input", "press enter key to go back..");
		cin.ignore();
		cin.get();
	}

	/// <summary>
	/// Adding an item to cart
	/// </summary>
	void addItemToCart()
	{
		system("cls");
		Util::screens("center", "Add Item to Cart");

		#pragma region Asking for item code to add
		// ask for item code to add 
		Util::displayItems(*items, 0);
		if (items->size() == 0)
		{
			cout << "Inventory is empty." << endl;
			Util::color("orange");
			cout << "\n\npress enter to go back..";
			cin.ignore();
			cin.get();
			return;
		}
		Util::screens("input", "Item code to add: ");
		string itemCodeToAddCart;
		cin >> itemCodeToAddCart;
		cin.ignore();

		// check if item already added to cart
		for (int i = 0; i < cart.size(); ++i)
		{
			if (cart[i].code == itemCodeToAddCart)
			{
				Util::screens("alertRed", "Item already added to cart.");
				Util::screens("input", "press enter to go back..");
				cin.get();
				return;
			}
		}

		// check if valid item code
		int itemIndex;
		for (int i = 0; i < items->size(); ++i)
		{
			// setting the item index base on items
			if (items[0][i].code == itemCodeToAddCart && items[0][i].qty != 0)
			{
				itemIndex = i;
				break;
			}
			else if (itemCodeToAddCart == items[0][i].code && items[0][i].qty == 0)
			{
				Util::screens("alertRed", "Invalid item code");
				Util::screens("input", "Enter again? [y/n]");
				char invalidCodeOption;
				cin >> invalidCodeOption;
				if (invalidCodeOption == 'y') addItemToCart();
				return;
			}
			else if (i == items->size() - 1 && items[0][i].code != itemCodeToAddCart)
			{
				Util::screens("alertRed", "Invalid item code");
				Util::screens("input", "Enter again? [y/n]");
				char invalidCodeOption;
				cin >> invalidCodeOption;
				if (invalidCodeOption == 'y') addItemToCart();
				return;
			}
		}
		#pragma endregion

		// ask the quantity to purchase 
		Util::screens("input", "Item quantity to purchase: ");
		string itemQtyToPurchase;

		cin >> itemQtyToPurchase;

		// check if added qty exceeds to stocked item quantity
		try
		{
			if (Util::isValidNumber(itemQtyToPurchase) != 0) 
			{
				Util::screens("alertRed", "Invalid, inputted quantity is not a number.");
				Util::screens("input", "Enter again? [y/n]");
				char invalidQtyOption;
				cin >> invalidQtyOption;
				if (invalidQtyOption == 'y') addItemToCart();
				return;
			}
			if (stoi(itemQtyToPurchase) > items[0][itemIndex].qty || stoi(itemQtyToPurchase) <= 0)
			{
				Util::screens("alertRed", "Invalid, desired quantity to purchase exceeds stocked item quantity.");
				Util::screens("input", "Enter again? [y/n]");
				char invalidQtyOption;
				cin >> invalidQtyOption;
				if (invalidQtyOption == 'y') addItemToCart();
				return;
			}
		}
		catch (const char* e)
		{
			cerr << e << endl;
		}
		// setting the values of selected item to add to cart

		totalPrice += items[0][itemIndex].price * stoi(itemQtyToPurchase);
		Item itemToAdd(items[0][itemIndex].code, items[0][itemIndex].name, items[0][itemIndex].category, to_string(items[0][itemIndex].price), itemQtyToPurchase);
		cart.push_back(itemToAdd);

		Util::screens("alertGreen", "Item added to cart.");
		cin.get();
	}

	/// <summary>
	/// Removing an item to cart
	/// </summary>
	void removeItemFromCart()
	{
		#pragma region Asking for item code to remove
		system("cls");
		if (cart.size() == 0)
		{
			Util::screens("title", "Your Cart");
			Util::screens("alertRed", "Your cart is empty..");
			Util::screens("input", "press enter key to go back..");
			cin.ignore();
			cin.get();
			return;
		}
		Util::color("white");
		cout << "Your Cart: " << endl;
		Util::displayItems(cart, 0);
		Util::screens("input", "Item code to remove: ");
		string itemCodeToRemove;
		cin >> itemCodeToRemove;

		// check if item code entered exists in cart
		for (int i = 0; i < cart.size(); ++i)
		{
			if (i == cart.size() - 1 && cart[i].code != itemCodeToRemove)
			{
				Util::screens("alertRed", "Invalid item code");
				Util::screens("input", "Enter again? [y/n]");
				char invalidCodeOption;
				cin >> invalidCodeOption;
				if (invalidCodeOption == 'y') removeItemFromCart();
				return;
			}
		}
		#pragma endregion

		#pragma region Removing the selected item
		try
		{
			for (int i = 0; i < cart.size(); ++i)
			{
				if (itemCodeToRemove == cart[i].code)
				{
					totalPrice -= (cart[i].price * cart[i].qty);
					cart.erase(cart.begin() - i);
					break;
				}
			}
		}
		catch (const char* e)
		{
			cerr << e << endl;
		}
		Util::screens("alertGreen", "Item removed from cart.");
		cin.get();
		#pragma endregion
	}

	/// <summary>
	/// Proceeding to checkout
	/// </summary>
	void checkout()
	{
		system("cls");
		if (cart.size() == 0)
		{
			Util::screens("title", "Checkout");
			Util::screens("alertRed", "Your cart is empty..");
			Util::screens("input", "press enter key to go back..");
			cin.ignore();
			cin.get();
			return;
		}
		Util::screens("center", "Checkout");
		Util::displayItems(cart, 0);

		Util::screens("input", "Confirm purchase? [y/n]");
		char confirmOption;
		cin >> confirmOption;

		if (confirmOption == 'y') 
		{
			#pragma region Updating the database and items list
			for (int i = 0; i < cart.size(); ++i)
			{
				for (int j = 0; j < items->size(); ++j)
				{
					if (cart[i].code == items[0][j].code)
					{
						items[0][j].qty = items[0][j].qty - cart[i].qty;

						string itemPathToEdit = "db/" + cart[i].code + (string)".dat";

						ofstream writeFile;
						writeFile.open(itemPathToEdit.c_str(), ios::out);
						writeFile << cart[i].name << endl;
						writeFile << items[0][j].category << endl;
						writeFile << cart[i].price << endl;
						writeFile << items[0][j].qty << endl;
						writeFile.close();
						break;
					}
				}
			}
			#pragma endregion

			printReciept();
			logPurchase();
			cart.clear();
			cin.get();
		}

	}

	/// <summary>
	/// Displaying the receipt purchased
	/// </summary>
	void printReciept()
	{
		system("cls");
		Util::screens("title", "Reciept");
		Util::displayItems(cart, 0);

		Util::color("white");
		for (int i = 0; i < 95 - to_string(totalPrice).length(); ++i)
		{
			cout << " ";
		}
		cout << "TOTAL : " << setiosflags(std::ios::fixed) << setprecision(2) << totalPrice << endl;

		Util::screens("input", "press enter key to continue..");
		cin.get();
	}

	/// <summary>
	/// Appending a purchase log the database
	/// </summary>
	void logPurchase()
	{
		ofstream outfile;

		time_t currentTime = time(0);
		char* dt = ctime(&currentTime);

		outfile.open("db/logs.dat", ios::out | ios::app);
		outfile << "- Item Purchase : " << dt;
		for (int i = 0; i < cart.size(); ++i)
		{
			outfile << "[" << cart[i].code << ", " << cart[i].name << ", " << cart[i].price << ", " << cart[i].qty << "]" << endl;
		}
		outfile.close();
	}

	/// <summary>
	/// Sales sub menu for purchasing items
	/// </summary>
	void purchase()
	{ 
		// show purchase options
		vector<string> purchaseCommands = {"Show products", "Add an item to cart", "Remove an item from cart", "View cart", "Proceed to checkout", "Cancel purchasing"};
		Util::menuScreens("SALES", "Purchase Commands", purchaseCommands);

		char salesOption;
		cin >> salesOption;

		if (salesOption == '1') showProducts();
		else if (salesOption == '2') addItemToCart();
		else if (salesOption == '3') removeItemFromCart();
		else if (salesOption == '4') viewCart();
		else if (salesOption == '5')
		{
			checkout();
			return;
		}
		else if (salesOption == '6') return;
		else
		{
			cout << "Invalid command, enter again? [y/n]" << endl;
			char invalidOption;
			if (invalidOption == 'y') purchase();
			return;
		}
		purchase();
	}	

private:
	vector<Item> *items;
	vector<Item> cart;
	double totalPrice;
};

// Class for system accounts : use for first account creation and system logins 
class Account
{
public:
	/// <summary>
	/// Logging in to the system
	/// </summary>
	static void login()
	{
		#pragma region First System Open 
		system("cls");
		Util::screens("title", "SALES AND INVENTORY SYSTEM");

		string password;
		ifstream infile;
		infile.open("db/pass", ios::in);

		mkdir("db");

		if (!infile)
		{
			Util::screens("center", "Welcome!");
			Util::color("white");
			cout << "\t\t\t SIS is an application for storing products in \n\t\t\t an Inventory system and selling products using \n\t\t\t a Sales system." << endl;

			Util::screens("left", "Let's setup a system password first.");
			Util::screens("input", "Enter system password: ");

			password = Account::askPassword();
			while (password.length() < 8)
			{
				Util::screens("alertRed", "Password must be a minimum of 8 characters");
				Util::screens("input", "Enter again: ");
				password = Account::askPassword();
			}
			string confirmPassword;
			Util::screens("input", "Confirm password: ");
			confirmPassword = Account::askPassword();
			while (password != confirmPassword)
			{
				Util::screens("alertRed", "Password not the same");
				Util::screens("input", "Enter again: ");
				confirmPassword = Account::askPassword();
			}
			infile.close();
			ofstream outfile;
			outfile.open("db/pass", ios::out);
			outfile << Account::encrypt(password) << endl;
			outfile.close();

			time_t currentTime = time(0);
			char* dt = ctime(&currentTime);

			outfile.open("db/logs.dat", ios::out | ios::app);
			outfile << "- System Password Creation and Login : " << dt;
			outfile.close();

			Util::screens("alertGreen", "password creation successful");
			cin.ignore();
			cin.get();
			return;
		}
		#pragma endregion

		#pragma region Subsequent System Open
		string storedPassword;
		infile >> storedPassword;
		infile.close();

		Util::screens("input", "Enter system password: ");
		password = Account::askPassword();
		while (password.length() < 8)
		{
			Util::screens("alertRed", "Password must be a minimum of 8 characters");
			Util::screens("input", "Enter again: ");
			password = Account::askPassword();
		}
		if (password == Account::decrypt(storedPassword))
		{
			Util::screens("alertGreen", "Logged in successfully");
			return;
		}
		else
		{
			Util::screens("alertRed", "Incorrect password");
			Util::screens("input", "Enter again? [y/n]");
			char invalidPassOption;
			cin >> invalidPassOption;
			if (invalidPassOption == 'y') login();
			else exit(0);
		}
		#pragma endregion

		#pragma region Logging login
		time_t currentTime = time(0);
		char* dt = ctime(&currentTime);
		ofstream outfile;
		outfile.open("db/logs.dat", ios::out | ios::app);
		outfile << "- System Login : " << dt;
		outfile.close();
		#pragma endregion
	}

private:
	/// <summary>
	/// Private Account function for changing input chars into *
	/// </summary>
	/// <returns>raw string input</returns>
	static string askPassword()
	{
		string password = "";
		char charPassword;

		charPassword = getch();

		// keeps on asking if inputted char is not "enter" key
		while (charPassword != '\r')
		{
			if (charPassword == '\b' && password.length() == 0)
			{
				charPassword = getch();
				continue;
			}
			else if (charPassword == '\b')
			{
				cout << "\b" << " " << "\b";
				password = password.substr(0, password.size() - 1);
				charPassword = getch();
				continue;
			}
			password += charPassword;
			cout << "*";
			charPassword = getch();
		}
		cout << endl;
		return password;
	}

	/// <summary>
	/// Encrypting a string with caesar cipher
	/// </summary>
	/// <param name="content">string to ecnrypt</param>
	/// <returns>encrypted string</returns>
	static string encrypt(string content)
	{
		string encryptedContent;
		for (int i = 0; i < content.length(); ++i)
		{
			encryptedContent += (char)(content[i] + 5);
		}
		return encryptedContent;
	}

	/// <summary>
	/// Decrypting a string, either encrypted or normal 
	/// </summary>
	/// <param name="content">string to decrypt</param>
	/// <returns>decrypted string</returns>
	static string decrypt(string content)
	{
		string decryptedContent;
		for (int i = 0; i < content.length(); ++i)
		{
			decryptedContent += (char)(content[i] - 5);
		}
		return decryptedContent;
	}
};

// main function of the system
int main()
{
	// creating the global items 
	vector<Item> items;
	Account::login();

	// creating inventory and sales class as systems 
	Inventory inventory(&items);
	Sales sales(&items);

	// main system loop
	while (true)
	{
		vector<string> mainMenuCommands = {"Sales", "Inventory", "Reports", "Records", "Quit"};

		// displaying main menu
		Util::menuScreens("SALES AND INVENTORY SYSTEM", "Main Menu", mainMenuCommands);		

		char mainMenuOption;
		cin >> mainMenuOption;

		// user inputs handler 
		if (mainMenuOption == '1') sales.purchase();
		else if (mainMenuOption == '2') inventory.menu();
		else if (mainMenuOption == '3') inventory.reports();
		else if (mainMenuOption == '4') Log::showLogs();
		else if (mainMenuOption == '5') return 0;
	}

	cin.get();
	return 0;
}