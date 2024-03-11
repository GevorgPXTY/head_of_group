#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Структура для хранения информации о кандидате
struct Candidate {
    string name; // Имя кандидата
    int votes;   // Количество голосов, полученных кандидатом

    // Конструктор для установки имени кандидата и начального количества голосов
    Candidate(string n) {
        name = n;
        votes = 0;
    }
};

// Функция для определения длины самого длинного имени кандидата
int candidatesLongestName(const vector<Candidate>& candidates) {
    int candidatesLongestNameLength = 0;
    // Проходим по всем кандидатам и находим самое длинное имя
    for (const auto& candidate : candidates) {
        if (candidate.name.length() > candidatesLongestNameLength) {
            candidatesLongestNameLength = candidate.name.length();
        }
    }
    return candidatesLongestNameLength;
}

// Функция для вывода результатов выборов
void outputElection(const vector<Candidate>& candidates) {
    // Длина самого длинного имени кандидата
    int candidatesLongestNameLength = candidatesLongestName(candidates);
    // Выводим информацию о самом длинном имени
    cout << "\nСамое длинное имя составляет " << candidatesLongestNameLength << " символов" << endl;
    cout << "\nРезультаты выборов:" << endl;
    // Верхняя разграничивающая строка
    for (int i = 0; i < 16 + candidatesLongestNameLength; i++) {
        cout << "@";
    }
    cout << endl;
    // Выводим результаты для каждого кандидата
    for (size_t i = 0; i < candidates.size(); i++) {
        // Выводим номер кандидата, имя, количество голосов
        cout << "@ " << i + 1 << ". " << candidates[i].name << ": " << candidates[i].votes << " голосов";
        // Выравниваем пробелами по длине самого длинного имени кандидата
        int neededSpacesAmount = candidatesLongestNameLength - candidates[i].name.length();
        for (int j = 0; j < neededSpacesAmount + 1; j++) {
            cout << " ";
        }
        cout << "@" << endl;
    }
    // Нижняя разграничивающая строка
    for (int i = 0; i < 16 + candidatesLongestNameLength; i++) {
        cout << "@";
    }
}

// Функция для проведения голосования
void conductElection(vector<Candidate>& candidates) {
    // Выводим заголовок для начала голосования
    cout << "Голосование за выбор главы!" << endl;

    // Выводим список кандидатов
    cout << "Кандидаты:" << endl;
    for (size_t i = 0; i < candidates.size(); i++) {
        cout << i + 1 << ". " << candidates[i].name << endl;
    }

    // Цикл голосования
    while (true) {
        // Просим пользователя ввести номер кандидата, за которого он хочет проголосовать
        cout << "Введите номер кандидата, за которого хотите проголосовать (0 - завершение голосования): ";
        int choice;
        cin >> choice;

        // Проверяем валидность выбора
        if (choice < 0 || choice > static_cast<int>(candidates.size())) {
            cout << "Недопустимый выбор!" << endl;
            continue;
        }
        else if (choice == 0) {
            break; // Завершаем голосование, если пользователь ввел 0
        }

        // Увеличиваем количество голосов выбранного кандидата
        candidates[choice - 1].votes++;
    }

    // Сортируем кандидатов по количеству голосов в порядке убывания
    sort(candidates.begin(), candidates.end(), [](const Candidate& a, const Candidate& b) {
        return a.votes > b.votes;
        });

    // Вывод результатов голосования
    outputElection(candidates);
}

int main() {
    // Установка русской локали для корректного вывода сообщений
    setlocale(LC_ALL, "Russian");

    // Ввод количества кандидатов
    int numCandidates;
    cout << "Введите количество кандидатов: ";
    cin >> numCandidates;

    // Ввод имен кандидатов
    vector<Candidate> candidates;
    for (int i = 0; i < numCandidates; i++) {
        string name;
        cout << "Введите имя кандидата #" << i + 1 << ": ";
        cin >> name;
        candidates.push_back(Candidate(name));
    }

    // Проведение голосования
    conductElection(candidates);

    return 0;
}
