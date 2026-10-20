#include <iostream>
#include <string>
#include <cctype>

double current = 0;

void add(double n) { current+=n; }
void sub(double n) { current-=n; }
void mul(double n) { current*=n; }
void div(double n) { if(n==0)return; current/=n; }

int main()
{
    std::string choice;
	
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
		
		for (size_t i = 0; i < choice.length(); i++)
		{			
			if (choice[i] == '+' || choice[i] == '-' || choice[i] == '*' || choice[i] == '/')
			{
				char op = choice[i];
				double onto;
				i++;
				
				if (std::isdigit(choice[i]))
				{
					std::string num = "";
					while ((std::isdigit(choice[i]) || choice[i] == '.') && i < choice.length())
					{
						num += choice[i];
						i++;
					}
					
					i--;
					onto = std::stod(num);
				}
				
				else break;
				
				switch(op)
				{
					case '+': add(onto); break;
					case '-': sub(onto); break;
					case '*': mul(onto); break;
					case '/': div(onto); break;
					default: break;
				}
			}
		}
	} while (choice != "x");
}