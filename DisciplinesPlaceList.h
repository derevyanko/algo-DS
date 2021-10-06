struct DisciplinePlace
{
	string name;
	int place;
	DisciplinePlace *next;

	DisciplinePlace()
	{
		string name = "";
		place = 0;
		next = NULL;
	}

	DisciplinePlace(string name, int place)
	{
		this->name = name;
		this->place = place;
		next = NULL;
	}
};

struct DisciplinesPlaceList
{
	DisciplinePlace *first;
	DisciplinePlace *last;

	DisciplinesPlaceList()
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
	void push(string name, int place)
	{
		DisciplinePlace *node = new DisciplinePlace(name, place);

		if (isEmpty())
		{
			first = node;
			last = node;

			return;
		}

		if (first->place > node->place)
		{
			node->next = first;
			first = node;

			return;
		}

		DisciplinePlace *current = first;
		DisciplinePlace *next = first->next;
		while (next)
		{
			if (current->place < node->place && node->place <= next->place)
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
	}

	// Нахождение первого вхождения по значению
	// key = 2
	DisciplinePlace *findDiscipline(string name)
	{
		DisciplinePlace *node = first;

		while (node && node->name != name)
		{
			node = node->next;
		}

		return node;
	}

	// Удаление элемента по значению
	// key = 4
	void deleteDiscipline(string name)
	{
		if (isEmpty())
			return;

		if (first->name == name)
		{
			DisciplinePlace *node = first;
			first = node->next;
			delete node;

			return;
		}

		DisciplinePlace *current = first;
		DisciplinePlace *next = first->next;
		while (next && next->name != name)
		{
			current = current->next;
			next = next->next;
		}

		if (!next)
			return;

		current->next = next->next;
		delete next;
	}

	// Вывод списка
	// key = 5
	void print()
	{
		if (isEmpty())
			return;

		DisciplinePlace *node = first;
		for (int index = 1; node; ++index)
		{
			cout << index << ". " << node->name << " " << node->place << "\n";
			node = node->next;
		}
		cout << "\n";
	}
};