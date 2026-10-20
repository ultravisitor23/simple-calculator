#include <iostream>

double current = 0;

double ask() 
{
	double num;
	std::cin >> num;
	return num;
}

void add(double n) { current+=n; }
void sub(double n) { current-=n; }
void mul(double n) { current*=n; }
void div(double n) { current/=n; }

int main()
{
    char choice;
	
	do
	{
		std::cout << "]========SIMPLE=CALC========[" << std::endl;
		std::cout << " MATHEMATICAL OPERATIONS" << std::endl;
		std::cout << "  +  Addition" << std::endl;
		std::cout << "  -  Subtraction" << std::endl;
		std::cout << "  *  Multiplication" << std::endl;
		std::cout << "  /  Division" << std::endl;
		std::cout << std::endl;
		std::cout << " APPLICATION COMMANDS" << std::endl;
		std::cout << "  x  Exit" << std::endl;
		std::cout << std::endl;
		std::cout << "]======CURRENT=VALUES=======[" << std::endl;
		std::cout << " " << current << std::endl;
	
		std::cin >> choice;
		
		switch(choice) 
		{
			case '+': add(ask()); break;
			case '-': sub(ask()); break;
			case '*': mul(ask()); break;
			case '/': div(ask()); break;
			default: break;
		}
	} while (choice != 'x');
}