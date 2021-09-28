struct Country
{
	string name;
	DisciplinesPlaceList disciplinesPlace;
	Country *next;

	Country(string name)
	{
		this->name = name;
		this->disciplinesPlace = DisciplinesPlaceList();
		next = NULL;
	}

	Country(string name, DisciplinesPlaceList disciplinesPlace)
	{
		this->name = name;
		this->disciplinesPlace = disciplinesPlace;
		next = NULL;
	}

	void print()
	{
		cout << "Country: " << this->name << "\n";
		disciplinesPlace.print();
	}
};

struct StandingsList
{
	Country *first;
	Country *last;

	StandingsList()
	{
		first = NULL;
		last = NULL;
	}

	// Проверка на пустоту
	// key = 0
	bool isEmpty()
	{
		return first == NULL;
	}

	// Добавление элемента в конец
	// key = 1
	void push(string name, string disciplineName, int place)
	{
		Country *node = new Country(name);
		node->disciplinesPlace.push(disciplineName, place);

		if (isEmpty())
		{
			first = node;
			last = node;

			return;
		}

		// if node < first
		if (first->name > node->name)
		{
			node->next = first;
			first = node;

			return;
		}

		Country *current = first;
		Country *next = first->next;
		while (next)
		{
			if (current->name == node->name)
			{
				current->disciplinesPlace.push(disciplineName, place);

				return;
			}

			if (next->name == node->name) 
			{
				next->disciplinesPlace.push(disciplineName, place);

				return;
			}

			if (current->name < node->name && node->name < next->name)
			{
				// вставка в середину
				current->next = node;
				node->next = next;

				return;
			}

			current = next;
			next = next->next;
		}

		last->next = node;
		last = node;

		cout << "\n";
	}

	// Нахождение первого вхождения по значению
	// key = 2
	Country *findCountry(string name, int place)
	{
		Country *node = first;

		while (node && node->name != name)
		{
			node = node->next;
		}

		return node;
	}

	// Удаление элемента по значению
	// key = 3
	void deleteCountry(string name)
	{
		if (isEmpty())
			return;

		if (first->name == name)
		{
			Country *node = first;
			first = node->next;
			delete node;

			return;
		}

		Country *current = first;
		Country *next = first->next;
		while (next && next->name != name)
		{
			current = current->next;
			next = next->next;
		}

		if (!next)
		{
			return;
		}

		current->next = next->next;
		delete next;
	}

	// Вывод списка
	// key = 4
	void print()
	{
		if (isEmpty())
			return;

		Country *node = first;
		for (int index = 1; node; ++index)
		{
			node->print();
			node = node->next;
		}
		cout << "\n";
	}
};
