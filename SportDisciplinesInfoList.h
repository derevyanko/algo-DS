struct SportDisciplineInfo
{
	string disciplineName;
	int countOfParticipant;
	SportDisciplineInfo *next;

	SportDisciplineInfo()
	{
		string disciplineName = "";
		countOfParticipant = 0;
		next = NULL;
	}

	SportDisciplineInfo(string disciplineName, int countOfParticipant)
	{
		this->disciplineName = disciplineName;
		this->countOfParticipant = countOfParticipant;
		next = NULL;
	}
};

struct SportDisciplinesInfoList
{
	SportDisciplineInfo *first;
	SportDisciplineInfo *last;

	SportDisciplinesInfoList()
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
	void pushBack(string disciplineName, int countOfParticipant)
	{
		SportDisciplineInfo *node = new SportDisciplineInfo(disciplineName, countOfParticipant);

		if (isEmpty())
		{
			first = node;
			last = node;

			return;
		}

		last->next = node;
		last = node;
	}

	// Добавление элемента в начало
	// key = 2
	void pushFront(string disciplineName, int countOfParticipant)
	{
		SportDisciplineInfo *node = new SportDisciplineInfo(disciplineName, countOfParticipant);

		if (isEmpty())
		{
			first = node;
			last = node;
		}

		node->next = first;
		first = node;
	}

	// Нахождение первого вхождения по значению
	// key = 3
	SportDisciplineInfo *findDiscipline(string disciplineName)
	{
		SportDisciplineInfo *node = first;

		while (node && node->disciplineName != disciplineName)
		{
			node = node->next;
		}

		return node;
	}

	// Удаление элемента по значению
	// key = 4
	void deleteDiscipline(string disciplineName)
	{
		if (isEmpty())
			return;

		if (first->disciplineName == disciplineName)
		{
			popFront();
			return;
		}

		SportDisciplineInfo *current = first;
		SportDisciplineInfo *next = first->next;
		while (next && next->disciplineName != disciplineName)
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

	// Удаление первого элемента
	// key = 5
	void popFront()
	{
		if (isEmpty())
			return;

		SportDisciplineInfo *node = first;
		first = node->next;
		delete node;
	}

	// Удаление последнего элемента
	// key = 6
	void popBack()
	{
		if (isEmpty())
			return;

		if (first == last)
		{
			popFront();

			return;
		}

		SportDisciplineInfo *node = first;
		while (node->next != last)
		{
			node = node->next;
		}

		node->next = NULL;
		delete last;
		last = node;
	}

	// Вывод списка
	// key = 7
	void print()
	{
		if (isEmpty())
			return;

		SportDisciplineInfo *node = first;
		cout << "Disciplines and number of participants: \n";
		for (int index = 1; node; ++index)
		{
			cout << index << ". " << node->disciplineName << " " << node->countOfParticipant << "\n";
			node = node->next;
		}
		cout << "\n";
	}
};