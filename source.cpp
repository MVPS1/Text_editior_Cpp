#include <iostream>
#include <string>
#include <sstream>
#include <conio.h>

#define word_limit 300 // the limit of words
#define KEY_RIGHT 77
#define KEY_LEFT 75
#define KEY_SPACE 32
 
using namespace std;

struct Stack
{
	string ar[word_limit];
	int top = -1;
	
}st;

void push(string word)
{
	if(st.top == word_limit - 1)
	{
		cout << "(the text full of words)\n";
	}
	else
	{
		
        st.top++;
        st.ar[st.top] = word;
	}
}

void undo()
{
	if(st.top <= -1)
	{
		cout << "The text is empty \n";
	}
	else
	{
		st.top--;
	}
}

void redo()
{
	if(st.top >= word_limit - 1)
	{
		cout << "(the text reach the limit of words)";
	}
	else
	{
		st.top++;
	}
}

void display()
{
	if(st.top <= -1)
	{
		cout << "(Text is empty) \n";
	}
	else
	{
		cout << "\n\n-------------THE TEXT-------------\n\n";
		
		for(int i = 0; i <= st.top; i++)
		cout << st.ar[i] << " ";
		
	}
}

int main()
{
	
	int choice, press, save_top;
	string text;
	
	do{
	
	display();
	
	cout << "\n\n1-insert new words\n2-Undo/Redo\n3-delete the text\nelse-to exit\n\n---->";
	cin >> choice;
	
			if(choice == 1)
			{
			 
			 
			 cout << "(type (*) then (Enter) to end your text)\n";
			 
			 display();
			 getline(cin, text, '*');
			 
			
			 istringstream part(text);
			 
			 while(getline(part, text, ' '))
			 {
			 	push(text);
			 }
			 
			
			 
			}
			else if(choice == 2)
			{
				save_top = st.top;
				
			cout << "\n\n\nPress (<-) to undo\nPress (->) to redo\nPress (SPACE) to save";
			display();
			
			do{
				
					press = getch();
					
					if(press == KEY_RIGHT)
					{
						if(st.top < save_top)
						{
							redo();
							display();
						}
					}
					else if(press == KEY_LEFT)
					{
						undo();
						display();
					}
					
				}while(press != KEY_SPACE);
			
			}
			else if(choice == 3)
			{
				st.top = -1;
			}
	
}while(choice == 1 || choice == 2 || choice == 3);
	
	return 0;
}
