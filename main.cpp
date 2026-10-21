#include <iostream>
#include <string>
#include <cctype>
#include <vector>

std::vector<double> current = {0};
int selectedThread = 0;

void add(double n) { current[selectedThread]+=n; }
void sub(double n) { current[selectedThread]-=n; }
void mul(double n) { current[selectedThread]*=n; }
void div(double n) { if(n==0){std::cout << "ERR: Attempted to divide by 0, result ignored." << std::endl; return;} current[selectedThread]/=n; }
void set(double n) { current[selectedThread]=n;}

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
		std::cout << "  =  Set to Value" << std::endl;
		std::cout << std::endl;
		std::cout << " THREAD FUNCTIONS" << std::endl;
		std::cout << "  T  New Thread" << std::endl;
		std::cout << "  tn Switch to Thread n," << std::endl; 
		std::cout << "   may also be used as a parameter in an operation." << std::endl;
		std::cout << std::endl;
		std::cout << " APPLICATION COMMANDS" << std::endl;
		std::cout << "  x  Exit" << std::endl;
		std::cout << std::endl;
		std::cout << "]======CURRENT=VALUES=======[" << std::endl;
		for (int i = 0; i < current.size(); i++)
			std::cout << " THREAD-" << i << ": " << current[i] << std::endl;
	
		std::cin >> choice;
		
		for (size_t i = 0; i < choice.length(); i++)
		{			
			if (choice[i] == '+' || choice[i] == '-' || choice[i] == '*' || choice[i] == '/' || choice[i] == '=')
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
				
				else if (choice[i] == 't')
				{
					double thread;
					i++;
				
					if (std::isdigit(choice[i]))
					{
						std::string num = "";
						while ((std::isdigit(choice[i])) && i < choice.length())
						{
							num += choice[i];
							i++;
						}
					
						i--;
						thread = std::stoi(num);
					}
					
					if (thread < current.size()) onto = current[thread];
					else std::cout << "ERR: Attempted to access a thread which was not yet created." << std::endl;
				}
				
				else break;
				
				switch(op)
				{
					case '+': add(onto); break;
					case '-': sub(onto); break;
					case '*': mul(onto); break;
					case '/': div(onto); break;
					case '=': set(onto); break;
					default: break;
				}
			}
			
			else if (choice[i] == 'T') current.push_back(0);
			
			else if (choice[i] == 't')
			{
				double onto;
				i++;
				
				if (std::isdigit(choice[i]))
				{
					std::string num = "";
					while ((std::isdigit(choice[i])) && i < choice.length())
					{
						num += choice[i];
						i++;
					}
					
					i--;
					onto = std::stoi(num);
				}
				
				else break;
				
				if (onto < current.size()) selectedThread = onto;
				else std::cout << "ERR: Attempted to access a thread which was not yet created." << std::endl;
			}
		}
	} while (choice != "x");
}