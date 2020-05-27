#include <iomanip>
#include <iostream>

#define DAYS 30

using namespace std;

void write_mas(int* m, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << m[i] << " ";
	}
	cout << "\n";
}

void randomize_weather(int* m)
{
	for (int i = 0; i < DAYS; i++)
	{
		m[i] = rand() % 2;
	}
}

int count_days(int* m, int type, int left, int right)
{
	int count = 0;
	for (int i = left; i < right; i++)
	{
		if (m[i] == type)
		{
			count++;
		}
	}
	return count;
}

int main()
{
	setlocale(LC_ALL, "russian");

	cout << "Выполнила Минаева Полина Валерьевна УТН - 111\n";
	cout << "Программа для исследования скорости улитки\n";

	double s1, s2;

	cout << "Введите скорость в солнечный день: ";
	cin >> s1;
	cout << "Введите скорость в пасмурный день: ";
	cin >> s2;

	int weather[DAYS];
	randomize_weather(weather);

	cout << "Погода в этом месяце (0 - пасмурный, 1 - солнечный): \n";
	write_mas(weather, DAYS);

	int total_count_sunny = count_days(weather, 1, 0, DAYS);
	int total_count_rainy = count_days(weather, 0, 0, DAYS);

	cout << "Всего солнечных дней: " << total_count_sunny << "\n";
	cout << "Всего пасмурных дней: " << total_count_rainy << "\n";

	double total_sunny_s = s1 * total_count_sunny;
	double total_rainy_s = s2 * total_count_rainy;

	double total_s = total_sunny_s + total_rainy_s;
	double average_speed = total_s / DAYS;

	cout << "Средняя скорость: " << average_speed << "\n";

	system("pause");

	return 0;
}
