#include <iostream>
#include <string>

using namespace std;

class node
{
public:
	node * next;
	char data;
	int location;

	node()
	{
		next = NULL;
	}
};

class stack
{
public:
	node * top;
	int count;

	stack()
	{
		top = NULL;
		count = 0;
	}

	void push(char value, int loc);
	char peek();
	bool is_empty();
	void pop();
};

bool stack::is_empty()
{
	if (top == NULL)
	{
		return true;
	}

	else
	{
		return false;
	}
}

void stack::push(char value, int loc)
{
	node * new_node = new node;
	new_node->data = value;
	new_node->location = loc;
	if (top == NULL)
	{
		new_node->next = top;
		top = new_node;
		count++;
	}

	else
	{
		new_node->next = top;
		top = new_node;
		count++;
	}
}

char stack::peek()
{
	if (top == NULL)
	{
		cout << "Stack Empty" << endl;
		return NULL;
	}

	else
	{
		//cout << top->data << endl;
		return top->data;
	}
}

void stack::pop()
{
	node * trav;
	if (top == NULL)
	{
		cout << "Stack Empty" << endl;
	}

	else
	{
		trav = top;
		top = trav->next;
		delete trav;
		count--;
		trav = NULL;
	}
}

int main()
{
	stack myStack;
	stack temp_stack;
	stack check_stack;
	bool correct_equation = true;
	bool incorrect_signs = false;

	//string equation = "1+2*[3*3+{4–5(6(7/8/9)+10)–11+(12*8)]+14";
	char sign_check[10];
	string equation;
	cout << "Enter Equation:" << endl;
	cin >> equation;

	for (int j = 0; j < equation.length(); j++)
	{
		if (equation[j] == '+' || equation[j] == '-' || equation[j] == '*' || equation[j] == '/')
		{
			temp_stack.push(equation[j], j);
		}

		if (equation[j + 1] == temp_stack.peek())
		{
			cout << "Incorrect expression, two signs are coming together!" << endl;
			incorrect_signs = true;
			break;
		}

		if (j == equation.length())
		{
			cout << "End of statement" << endl;
			break;
		}

		if (equation[j] == '*' || equation[j] == '/')
		{
			check_stack.push(equation[j], j);
		}

		if (check_stack.peek() == '*')
		{
			if (equation[j + 1] == '/')
			{
				cout << "Incorrect expression, two signs are coming together!" << endl;
				incorrect_signs = true;
			}
			
			//break;
		}

		if (check_stack.peek() == '/')
		{
			if (equation[j + 1] == '*')
			{
				cout << "Incorrect expression, two signs are coming together!" << endl;
				incorrect_signs = true;
			}

			//break;
		}

		if (j == equation.length())
		{
			cout << "End of statement" << endl;
			break;
		}

	}

	/*if (incorrect_signs == true)
	{
		cout << endl;
		system("pause");
		return 0;
	}*/

	for (int i = 0; i < equation.length(); i++)
	{
		
		switch (equation[i])
		{
		case '(':
			myStack.push('(', i);
			break;

		case ')':
			if (myStack.peek() == '(')
			{
				myStack.pop();
			}

			else
			{
				//cout << "Error in sequence at location " << i << endl;
				correct_equation = false;
				system("pause");
				return 0;
			}

			break;

		case '{':
			myStack.push('{', i);
			break;

		case '}':
			if (myStack.peek() == '{')
			{
				myStack.pop();
			}

			else
			{
				//cout << "Error in sequence at location " << i << endl;
				correct_equation = false;
				system("pause");
				return 0;
			}

			break;

		case '[':
			myStack.push('[', i);
			break;

		case ']':
			if (myStack.peek() == '[')
			{
				myStack.pop();
			}

			else
			{
				//cout << "Error in sequence at location " << i << endl;
				correct_equation = false;
				system("pause");
				return 0;
			}

			break;
		}
	}

	while (!myStack.is_empty())
	{
		cout << "Missing closing bracket for: " << myStack.top->data << " at location: " << myStack.top->location << endl;
		myStack.pop();
		correct_equation = false;
		cout << endl;
	}

	if (correct_equation)
	{
		cout << "No bracket errors in equation!" << endl;
	}

	cout << endl;
	system("pause");
	return 0;
}
