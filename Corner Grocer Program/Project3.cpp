#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <stdio.h>
#include <fstream>

using namespace std;

int showHistogram() {
	//Declaring object/variables
	string items;
	int frequency;
	ifstream inFile;
    ofstream outFile;

    //Opening the file "frequency.dat" using the input file object
	inFile.open("frequency.dat");

	//Checks if input file cannot be opened
	if (!inFile) 
	{
		cout << "File cannot be opened." << endl;
	}
	else 
	{
		//Loops till end of the file
		//Reads items and frequency in each line of file
		while (inFile >> items >> frequency)
		{
			cout << "\n" << items << " " << frequency << endl;
		}
		inFile.close();
	}

}
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("PyProject3");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}


int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PyProject3");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}


void menu()
{
	do
	{
		int num;
		// Call up menu
		cout << "\nWhat would you like to do?"
			    "\n1: Produce a list of all purchased items in a day + number of times each item was purchased\n"
			    "2: View number of times a item was purchased in a day\n"
			    "3: View a text-based histogram listing all items purchased in a day + number of times each item was purchased\n"
			    "4: Exit\n\nEnter your selection as a number 1, 2, 3, or 4: ";
		cin >> num;
		if (num == 4)
		{
			cout << "\nYou chose to Exit the program. Good bye!\n";
			exit(0);
		}
		else if (num == 1)
		{
			 
			CallProcedure("itemCount");
			menu();
			break;
		}
		else if (num == 2)
		{
			string userInput;
			cout << "\nPlease enter the name of the item: ";
			cin >> userInput;
			cout << "Number of times " + userInput + " was purchased: ";
			cout << callIntFunc("itemFrequency", userInput) << endl;
			menu();
			break;
		}
		else if (num == 3)
		{
			cout << showHistogram() << endl;
			menu();
			break;

		}
		else
		{
			cout << "\nNot a valid entry. Please enter a valid selection" << endl;
			menu();
		}

	} while (true);
}

int main()
{
	menu();
	return 0;
}