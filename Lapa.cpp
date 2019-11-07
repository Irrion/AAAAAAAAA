#include <iostream>
using namespace std;

struct JoJo
{
	int Elin;
	JoJo *nextJoJo;
	JoJo(int Volodya, JoJo *next = nullptr)
	{
		this->Elin = Volodya;
		this->nextJoJo = next;
	}
};
class List
{
public:
	List()
	{
		size = 0;
		DANIIL = nullptr;
	}
    ~List()
	{
		mrproper();
	}
	void add(int e)
	{
		if (size == 0)
		{
			DANIIL = new JoJo(e);
		}
		else
		{
			JoJo *last_elem = DANIIL;
			while (last_elem->nextJoJo != nullptr)
			{
				last_elem = last_elem->nextJoJo;
			}
			// last_elem
			last_elem->nextJoJo = new JoJo(e);
		}
		size++;
	}
	int retorn()
	{
		return size;
	}
	
	void popfrant()
	{
		JoJo *current = DANIIL;
		DANIIL = DANIIL->nextJoJo;
		delete current;
		size--;
	}
	void mrproper()
	{
		int full_size = size;
		for (; 0 < size; ) // 4
		{
			popfrant();
			//4
			
		}
	}
	int find(int index)
	{
		
		JoJo * current = this->DANIIL;
		int counter = 1;
		while (current != nullptr)
		{
			if (index == counter)
			{
				return current->Elin;
			}
			current = current->nextJoJo;
			counter++;
		}
		return 0;
	}
	void alllist()
	{
		
		JoJo *current = DANIIL;
		while (current != nullptr)
		{
			cout << current->Elin << endl;
			current = current->nextJoJo;
		}
		
	
	}
	void pop(int index)
	{
		if (DANIIL != nullptr)
		{

			if (index==1)
			{
				popfrant();
			}
			else if (index > 1)
			{
				if (size < index)
				{
					cout << "I NOT FOUND ELEMENT!!! AAAAAAAAA" << endl;
				}
				else if (size == index || size > index)
				{
					
					JoJo *current = DANIIL; 
					int mama = index - 2 ;
					for (int i = 0; i < mama; i++)
					{
						current = current->nextJoJo;
					}
					JoJo *mamulya = current;
					current = current->nextJoJo;
					if (current->nextJoJo != nullptr)
					{
						mamulya->nextJoJo = current->nextJoJo;
						delete current;
						--size;
					}
					else
					{
						mamulya->nextJoJo = nullptr;
						delete current;
						size--;
					}

				}

			}
			else
			{
				cout << "Are you diabetic? Tut net takogo" << endl;
			}
	
		}
		else
		{
			cout << "Net ego" << endl;
		}
	}
	bool empty()
	{
		if (size == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
private:
	int size;
	
	JoJo *DANIIL;
};


int main()
{
	List Vedeneev;
	
	Vedeneev.add(1);
	Vedeneev.add(2);
	Vedeneev.add(3);
	Vedeneev.add(4);
	Vedeneev.add(5);
	Vedeneev.add(6);
	cout <<"Size= " << Vedeneev.retorn() << endl;
	Vedeneev.alllist();
	
	cout<<"The element at index = "<<Vedeneev.find(3)<<endl;

	
	Vedeneev.mrproper();
	system("pause");
	return 0;
}








