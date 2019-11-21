#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *nElem;
	Node *pElem;
	Node(int data, Node *next = nullptr, Node*prev = nullptr)
	{
		this->data = data;
		this->nElem = next;
		this->pElem = prev;
	}
};
class List
{
public:
	List()
	{
		size = 0;
		HEAD = nullptr;
		tail = nullptr;
	}
	~List()
	{
		mrproper();
	}
	void add_end(int e)
	{		
		Node *last_elem = new Node(e);
		last_elem->nElem = nullptr;

		if (HEAD != nullptr)
		{
			last_elem->pElem = tail;
			tail->nElem = last_elem;
			tail = last_elem;
		}
		else
		{
			last_elem->pElem = nullptr;
			HEAD = tail = last_elem;
		}
		size++;
	}
	void add_begin(int data)
	{
		Node*new_elem = HEAD;
		if (HEAD != nullptr)
		{
			HEAD = new Node(data, HEAD);
			new_elem->pElem = HEAD;
		}
		else
		{
			HEAD = tail = new Node(data, HEAD, tail);
		}	
		size++;
	}
	int retorn()
	{
		return size;
	}
	void popfrant()
	{
		if (HEAD != nullptr)
		{
			Node *current = HEAD;
			if (HEAD->nElem != nullptr)
			{
				HEAD = HEAD->nElem;
				delete current;
			}
			else
			{
				delete HEAD;
				HEAD = nullptr;
				tail = nullptr;
			}
		}
		else
		{
			cout << "The list is empty\n";
		}
		size--;
	}
	void popback()
	{
		if (tail != nullptr)
		{
			Node*current = tail;
			if (tail->pElem != nullptr)
			{
				tail = tail->pElem;
				delete current;
			}
			else
			{
				delete tail;
				HEAD = nullptr;
				tail = nullptr;
			}
		}
		else
		{
			cout << "The list is empty\n";
		}
		size--;
	}
	void mrproper()
	{
		int full_size = size;
		for (; 0 < size; )
		{
			popfrant();
		}
	}
	int find(int index)
	{		
		int counter = 1;
		if (index > this->size / 2)
		{
			Node*current = HEAD;
				while (current != nullptr)
				{
					if (index == counter)
					{
						return current->data;
					}
					current = current->nElem;
					counter++;
				}
		}
		else
		{
			Node*current = tail;
			while (current != nullptr)
			{
				if (index == counter)
				{
					return current->data;
				}
				current = current->pElem;
				counter++;
			}
		}
		return 0;
	}
	void alllist()
	{
		cout << "Starts from the head\n";
		Node *current = HEAD;
		while (current != nullptr)
		{
			cout << current->data << endl;
			current = current->nElem;
		}
		cout << "\n";

		cout << "Starts from the tail\n";
		current = tail;
		while (current != nullptr)
		{
			cout << current->data << endl;
			current = current->pElem;
		}
		cout << "\n";
	}
	void print_from_head()
	{
		cout << "Starts from the head\n";
		Node *current = HEAD;
		while (current != nullptr)
		{
			cout << current->data << endl;
			current = current->nElem;
		}
		cout << "\n";
	}
	void print_from_tail()
	{
		Node *current = tail;
		cout << "Starts from the tail\n";
		while (current != nullptr)
		{
			cout << current->data << endl;
			current = current->pElem;
		}
		cout << "\n";
	}
	void pop(int index)
	{
		if (HEAD != nullptr)
		{
			if (index == 1)
			{
				popfrant();
			}
			else if (index > 1)
			{
				if (size < index)
				{
					cout << "I NOT FOUND ELEMENT!!!" << endl;
				}
				else if (size == index || size > index)
				{
					if (index <= size)
					{
						Node *current = HEAD;
						int mama = index - 2;
						for (int i = 0; i < mama; i++)
						{
							current = current->nElem;
						}
						Node *daughter = current;
						current = current->nElem;
						if (current->nElem != nullptr)
						{
							daughter->nElem = current->nElem;
							delete current;
							--size;
						}
						else
						{
							daughter->nElem = nullptr;
							delete current;
							size--;
						}
					}
					else if (index > size / 2)
					{
						Node*current = tail;						
						for (int i = size - 2; i > index; i--)
						{
							current = current->pElem;
						}
						Node*prev = current;
						current = current->pElem;
						if (current->pElem!=nullptr)
						{
							prev->pElem = current->pElem;
							delete current;
							size--;
						}
						else
						{
							prev->pElem = nullptr;
							delete current;
							size--;
						}
					}

				}

			}
			else
			{
				cout << "There's no such thing here" << endl;
			}

		}
		else
		{
			cout << "List is empty" << endl;
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
	Node *tail;
	Node *HEAD;
};

void origin() {
	List lst;

	lst.add_end(1);
	lst.add_end(2);
	lst.add_end(3);
	lst.add_end(4);
	lst.add_end(5);
	lst.add_end(6);
	lst.add_begin(9);

	lst.print_from_head();
	cout << "Size= " << lst.retorn() << endl;
	cout << "\n";

	lst.pop(6);
	lst.print_from_head();
}



void test_1() {
	List ll;
	ll.add_end(1);
	ll.pop(1);
	ll.print_from_tail();
}

void test_2() {
	List ll;
	ll.add_end(1);
	ll.add_end(2);
	ll.pop(1);
	ll.print_from_head();
}
void test_3() {
	List ll;
	ll.add_end(1);
	ll.add_begin(3);
	ll.mrproper();
	ll.print_from_head();
}
void test_4() {
	std::cout << "start test_4...\n";
	while (1) {
		List ll;

		ll.add_end(1);
		ll.add_begin(3);
		ll.mrproper();
		ll.print_from_head();

	}

}


int main()
{
	test_3();
	
	system("pause");
	return 0;
}











