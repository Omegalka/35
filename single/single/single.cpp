
//?????? ?????? ??????? 

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

bool EndsWith(const string& str, const string& suffix) {
    size_t str_len = str.length();
    size_t suffix_len = suffix.length();

    if (str_len < suffix_len) {
        return false;
    }

    return str.compare(str_len - suffix_len, suffix_len, suffix) == 0;
}

vector<string> FindWordsWithSuffix(const vector<string>& words, const string& suffix) {
    vector<string> result;

    for (const string& word : words) {
        if (word.size() >= 3 && EndsWith(word, suffix)) {
            result.push_back(word);
        }
    }

    return result;
}

int main() {
    ifstream file("Slovnik8Bclass.txt");

    if (!file.is_open()) {
        cout << "Unable to open Slovnik.\n";
        return 1;
    }

    vector<string> words;
    string word;
    while (file >> word) {
        words.push_back(word);
    }

    file.close();

    for (const string& current_word : words) {
        string suffix = current_word.substr(current_word.size() - 3);

        vector<string> matching_words = FindWordsWithSuffix(words, suffix);

        if (!matching_words.empty()) {
            cout << "Word " << current_word << "\n";
            cout << "Combinations: " << "\n";
            for (const string& match : matching_words) {
                if (match != current_word) {
                    cout << "  " << current_word << match.substr(3);
                }
            }
        }
    }

    return 0;
}


