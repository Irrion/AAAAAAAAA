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
			JoJo *current = new JoJo(e);
			DANIIL = current;
		}
		else
		{
			JoJo *current = DANIIL;
			while (current->nextJoJo != nullptr)
			{
				current = current->nextJoJo;
			}
			current->nextJoJo = new JoJo(e);
		}
		size++;
	}
	int retorn()
	{
		return size;
	}
	int & operator[](unsigned int index);
	void popfrant()
	{
		JoJo *current = DANIIL;
		DANIIL = DANIIL->nextJoJo;
		delete current;
		size--;
	}
	void mrproper()
	{
		for (int i = 0; i < size; i++)
		{
			popfrant();
		}
	}
	void insert()
	{

	}
	void pop(unsigned int index)
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

int & List::operator[](unsigned int index)
{
	JoJo *current = DANIIL;
	for (int i = 0; i < size; i++)
	{
		if (i == index)
		{
			return current->Elin;
		}
		else
		{
			current = current->nextJoJo;
		}
	}
	abort();
}

int main()
{
	List Vedeneev;
	Vedeneev.add(1);
	Vedeneev.add(2);
	Vedeneev.add(3);
	Vedeneev.add(4);
	Vedeneev.add(5);
	Vedeneev.add(6);
	Vedeneev.pop(1);
	
	for (int i = 0; i < Vedeneev.retorn(); i++)
	{
		cout << "[" << i + 1 << "]" << Vedeneev[i] << endl;
	}
	cout << Vedeneev.retorn() << endl;
	
	system("pause");
	return 0;
}

