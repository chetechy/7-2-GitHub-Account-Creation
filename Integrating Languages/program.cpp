#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>

using namespace std;


void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("pCode");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}


void menu()
{
	do
	{
		int num;
		// Call up menu
		cout << "\n1: Display a Multiplication Table\n2: Double a Value\n3: Exit\nEnter your selection as a number 1, 2, or 3: ";
		cin >> num;
		if (num == 3)
		{
			cout << "\nYou chose to Exit the program. Good bye!\n";
			exit(0);
		}
		else if (num == 1)
		{
			
			CallProcedure("MultiplicationTable");
			menu();
			break;
		}
		else if (num == 2)
		{
		
			CallProcedure("DoubleValue");
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
