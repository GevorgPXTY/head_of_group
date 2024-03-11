//Используйте вектор для хранения результатов голосования.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Структура для хранения информации о кандидате
struct Candidate {
    string name;
    int votes;

    Candidate(string n) {
        name = n;
        votes = 0;
    }
};
// Searching for the length of the longest name of candidate
int canditatesLongestName(vector<Candidate>& candidates) {
    int candidates_longest_name_length = 0;
    for (int i = 0; i < candidates.size(); i++) {
        if (candidates[i].name.length() > candidates_longest_name_length) {
            candidates_longest_name_length = candidates[i].name.length();
        }
    }
    return candidates_longest_name_length;
}
void outputElection(vector<Candidate>& candidates) {
    // Длина самого длинного имени кандидата
    int candidates_longest_name_length = canditatesLongestName(candidates);
    cout << "\nСамое длинное имя составляет " << candidates_longest_name_length << " символов" << endl;
    cout << "\nРезультаты выборов:" << endl;
    // Верхняя разграничивающая строка
    for (int i = 0; i < 16 + candidates_longest_name_length; i++) {
        cout << "@";
    }
    cout << endl;
    // Вывод результатов
    for (int i = 0; i < candidates.size(); i++) {
        cout << "@ " << i + 1 << ". " << candidates[i].name << ": " << candidates[i].votes << " голосов";
        int needed_spaces_amount = 0;
        needed_spaces_amount = candidates_longest_name_length - candidates[i].name.length();
        for (int j = 0; j < needed_spaces_amount + 1; j++) {
            cout << " ";
        }
        cout << "@" << endl;
    }
    // Нижняя разграничивающая строка
    for (int i = 0; i < 16 + candidates_longest_name_length; i++) {
        cout << "@";
    }
}
// Функция для проведения голосования
void conductElection(vector<Candidate>& candidates) {
    cout << "Голосование за выбор главы!" << endl;

    // Вывод списка кандидатов
    cout << "Кандидаты:" << endl;
    for (int i = 0; i < candidates.size(); i++) {
        cout << i + 1 << ". " << candidates[i].name << endl;
    }

    // Цикл голосования
    while (true) {
        cout << "Введите номер кандидата, за которого хотите проголосовать (0 - завершение голосования):";
        int choice;
        cin >> choice;

        if (choice < 0 || choice > candidates.size()) {
            cout << "Недопустимый выбор!" << endl;
            continue;
        }
        else if (choice == 0) {
            break;
        }

        // Увеличение количества голосов кандидата
        candidates[choice - 1].votes++;
    }

    // Сортировка кандидатов по убыванию голосов
    sort(candidates.begin(), candidates.end(), [](const Candidate& a, const Candidate& b) {
        return a.votes > b.votes;
        });

   
    // Вывод результатов голосования
    // cout << "Результаты голосования:" << endl;
    outputElection(candidates);
}
// // test 1
// void testInvalidCandidateCount() { 
//     int numCandidates = -10;

//     if (numCandidates > 0) {
//         cout << "Test 1 Passed: Valid input." << endl;
//         // return true;
//     }
//     else {
//         cout << "Test 1 Failed: Invalid input. Try again." << endl;
//         // return false;
//     }
// }
// void testCandidateNameWithSpaces() {
//     int numCandidates = 1;

//     string name = "Haruki Murakami";

//     if (name.find(' ') == string::npos) {
//         cout << "Test 2 Passed: Valid input." << endl;
//     } else {
//         cout << "Test 2 Failed: Invalid input." << endl;
//     }
// }

int main() {
    setlocale(LC_ALL, "Russian");
    //Тесты
    //testInvalidCandidateCount();
    //testCandidateNameWithSpaces();
    //Ввод количества кандидатов
    int numCandidates;
    cout << "Введите количество кандидатов: ";
    cin >> numCandidates;
    // while(!testInvalidCandidateCount(numCandidates)){
    //     cin >> numCandidates;
    // }
    // Ввод имён кандидатов
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
