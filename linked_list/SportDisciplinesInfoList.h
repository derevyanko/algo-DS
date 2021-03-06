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

	void print() {
		cout << "Discipline: " << this->disciplineName << " " << this->countOfParticipant << "\n";
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
	SportDisciplineInfo* find(string disciplineName)
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
	void deleteDiscipline(string disciplineName, StandingsList &standingsList)
	{
		if (isEmpty())
			return;

		if (first->disciplineName == disciplineName)
		{
			SportDisciplineInfo *node = first;
			first = node->next;
			delete node;

			standingsList.deleteDiscipline(disciplineName);
			
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

		standingsList.deleteDiscipline(disciplineName);
	}

	// Вывод списка
	// key = 5
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