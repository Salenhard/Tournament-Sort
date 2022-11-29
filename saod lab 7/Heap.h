#pragma once
#include <iostream>
template<class T>
class Heap
{
private:
	// hlist указывает на массив, который может быть динамически создан
	// конструктором (inArray == 0) или передан как параметр (inArray == 1)
	T* hlist;     
	int inArray;

	// максимальный и текущий размер пирамиды
	int maxheapsize;
	int heapsize;				// опеределяет конец списка


	// функция вывода сообщений об ошибке
	void error(std::string errmsg) {
		std::cerr << "Ошибка: " << errmsg;
		exit(1);
	}
	// утилита воостановления структуры пирамиды
	void filterDown(int i) {
		// начать с узла i и присвоить его значения переменной target
		int currentpos, childpos;
		T target;
		currentpos = i;
		target = hlist[i];

		// вычислить индекс левого сына и начать движение вниз по пути,
		// проходящему	через меньших сыновей до конца списка
		childpos = 2 * i + 1;
		while (childpos < heapsize) // пока не конец списка
		{
			// индекс правого сына равен childpos+ 1. присвоить переменной
			// childpos индекс наименьшего из двух сыновей
			if ((childpos + 1 < heapsize) && (hlist[childpos + 1] <= hlist[childpos]))
				childpos++;
			// если родитель меньше сына, пирамида в порядке. выход
			if (target <= hlist[childpos])
				break;
			else {
				// переместить значение меньшего сына в родительский узел
				// теперь позиция меньшего сына не занята
				hlist[currentpos] = hlist[childpos];

				// обновить индексы и продолжать сканирование
				currentpos = childpos;
				childpos = 2 * currentpos + 1;

			}
		}
		// переместить target в только что ставшую незанятой позицию
		hlist[currentpos] = target;
	}

	// утилита воостановления структуры пирамиды
	void filterUp(int i) {

		int currentpos, parentpos;
		T target;

		// currentpos - индекс текущей позиции на пути предков.
		// target - вставляемое значение, для которого выбирается
		// правильная позиция в пирамиде


		currentpos = i;
		parentpos = (i - 1) / 2;
		target = hlist[i];


		// поднимаеться к корню по пути родителей
		while (currentpos != 0) {
			// если родитель <= target, то все в порядке.
			if (hlist[parentpos] <= target)
				break;
			else
			{
				// переместить данные из родительской позиции в текущую.
				// назаначить родительскую позицию текущей.
				// проверить следующего родителя
				hlist[currentpos] = hlist[parentpos];
				currentpos = parentpos;
				parentpos = (currentpos - 1) / 2;
			}
		}
		// правильная позиция найдена
		hlist[currentpos] = target;
	}
public:
	// конструкторы и деструкторы
	Heap(int maxsize) {			// создать пустую пирамиды
		hlist = new T[maxsize];
		maxheapsize = maxsize;
		heapsize = 0;
		inArray = 0;
	}

	Heap(T arr[], int n) {	// преобразовать arr в пирамиду
		int j, currentpos;
		if (n <= 0)
			error("Неправильная размерность массива!");
		maxheapsize = n;
		heapsize = n;
		hlist = arr;
		currentpos = (heapsize - 2) / 2;
		while (currentpos >= 0)
		{
			filterDown(currentpos);
			currentpos--;
		}
		inArray = 1;
	}

	Heap(const Heap<T>& H) {		// конструктор копий
		this = H;
	}

	~Heap() {					// деструктор
		clearList();
	}
	// перегруженные операторы:
	Heap<T> operator= (const Heap<T>& rhs) {		
		if (!rhs.listEmpty())
			error("Пустой Heap");
		hlist = rhs.hlist;
		maxheapsize = rhs.maxheapsize;
		heapsize = rhs.heapsize;
		inArray = 1;
	}

	const T& operator[](int i) {
		if (i > heapsize)
			error("Выход за границы массива!");
		else
			return hlist[i];
	}


	// методы обработки списков
	int listSize() const {
		return heapsize;
	}

	int listEmpty() const {
		if (heapsize == 0)
			return 1;
		else return 0;
	}

	int listFull() const {
		if (heapsize == maxheapsize)
			return 1;
		else return 0;

	}



	// вставить в пирамиду новый элемент и восстановить её струтуру 
	void insert(const T& item) {
		// проверить, заполнена ли пирамида и выйти, если да
		if (heapsize == maxheapsize)
			error("Пирамида заполнена!");
		// записать элемент в конец пирамиды и увеличить текущий размер heapsize.
		// вызвать filterUp для восстановления пирамидального упорядочения
		hlist[heapsize] = item;
		filterUp(heapsize);
		heapsize++;
	}
	// возвратить значение корневого элемента и обновить пирамиду.
	// попытка удаления элемента из пустой пирамиды влечет за собой
	// выдачу сообщений об ошибке и прекращения работы программы
	T Delete() {
		T tempitem;

		// проверить, пустая ли пирамида
		// проверить, пустая ли пирамида
		if (heapsize == 0)
			error("Пирамида пуста!");
		// копировать корень в tempitem. заменить корень последним элементом
		// пирамиды и произвести декремент переменой heapsize
		tempitem = hlist[0];
		hlist[0] = hlist[heapsize - 1];
		heapsize--;
		// вызвать filterDown для установки нового значения корня
		filterDown(0);
		// возвратить исходное значение корня
		return tempitem;
	}

	void clearList() {
		while (!listEmpty())
		{
			Delete();
		}
	}
};

